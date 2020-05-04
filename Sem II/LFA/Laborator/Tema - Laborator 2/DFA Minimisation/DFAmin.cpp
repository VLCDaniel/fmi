#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <fstream>

using namespace std;

class DFA
{
	set<int> Q, F;
	set<char> Sigma;
	int q0;
	map<pair<int, char>, int> delta;

public:
	DFA() { this->q0 = 0; }
	DFA(set<int> Q, set<char> Sigma, map<pair<int, char>, int> delta, int q0,
		set<int> F)
	{
		this->Q = Q;
		this->Sigma = Sigma;
		this->delta = delta;
		this->q0 = q0;
		this->F = F;
	}
	set<int> getQ() const { return this->Q; }
	set<int> getF() const { return this->F; }
	set<char> getSigma() const { return this->Sigma; }
	int getInitialState() const { return this->q0; }
	map<pair<int, char>, int> getDelta() const { return this->delta; }

	friend istream& operator>>(istream&, DFA&);

	bool isFinalState(int);
	int deltaStar(int, string);
	void PartitionDFA();
};

bool DFA::isFinalState(int q)
{ 
	return F.find(q) != F.end(); 
}

int DFA::deltaStar(int q, string w)
{
	if (w.length() == 1)
	{
		return delta[{q, (char)w[0]}];
	}

	int new_q = delta[{q, (char)w[0]}];
	return deltaStar(new_q, w.substr(1, w.length() - 1));
}

istream& operator>>(istream& f, DFA& M)
{
	int noOfStates;
	f >> noOfStates;
	for (int i = 0; i < noOfStates; ++i)
	{
		int q;
		f >> q;
		M.Q.insert(q);
	}
	int noOfLetters;
	f >> noOfLetters;
	for (int i = 0; i < noOfLetters; ++i)
	{
		char ch;
		f >> ch;
		M.Sigma.insert(ch);
	}
	int noOfTransitions;
	f >> noOfTransitions;
	for (int i = 0; i < noOfTransitions; ++i)
	{
		int s, d;
		char ch;
		f >> s >> ch >> d;
		M.delta[{s, ch}] = d;
	}
	f >> M.q0;
	int noOfFinalStates;
	f >> noOfFinalStates;
	for (int i = 0; i < noOfFinalStates; ++i)
	{
		int q;
		f >> q;
		M.F.insert(q);
	}
	return f;
}

void DFA::PartitionDFA()
{
	int size = this->getQ().size();
	vector<vector<bool>> M(size + 1, vector<bool>(size + 1)); // pe post de partitii

	for (int i = 2; i <= size; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (this->isFinalState(i) != this->isFinalState(j)) // Matrice completata sub diagonala principala cu 1 daca i 															
			{													// este stare finala si j nu sau invers
				M[i][j] = 1;
			}
		}
	}

	int ok = 1;
	while (ok) // cat timp facem modificari in matrice, repetam aceasta secventa
	{
		ok = 0;
		for (int i = 2; i <= size; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (M[i][j] == 0)
				{
					for (char c : this->getSigma())
					{
						if (M[this->delta[{i, c}]][this->delta[{j, c}]])
						{
							M[i][j] = 1;
						}
					}
				}
			}
		}
	}

	set<set<int>> partitions; // multimea partitiilor
	set<int> p; // partitia curenta

	for (int i = 0; i <= size; i++)
	{
		p.insert(i);
		for (int j : this->Q)
		{
			if (M[i][j] == 0)
			{
				p.insert(j);
			}
		}
		if (p.size() > 0) // daca partitia nu e nula, o adaugam la multime
		{
			partitions.insert(p);
			p.clear();
		}
	}
}

int main()
{
	DFA M;
	ifstream f("DFAmin.txt");
	f >> M;
	M.PartitionDFA();
	f.close();
	return 0;
}