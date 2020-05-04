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
	void DFAtoREGEX();
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

void DFA::DFAtoREGEX()
{
	map<pair<int, char>, int> trans = this->delta;
	int size = this->getQ().size();
	vector<vector<string>> transMatrix(size + 2, vector<string>(size + 2));

	for (int i = 0; i <= size + 1; i++)
	{
		for (int j = 0; j <= size + 1; j++)
		{
			transMatrix[i][j] = ' ';
		}
	}

	for (int state : this->Q)
	{
		for (int i = 0; i <= size + 1; i++)
		{
			for (char c : this->getSigma())
			{
				if (trans[{ state, c }] != NULL && trans[{state, c}] == i)
					if (transMatrix[state][i] != " ")
					{
						transMatrix[state][i] += "+";
						transMatrix[state][i] += c;
					}
					else
					{
						transMatrix[state][i] = c;
					}
			}
		}
	}

	// Adaug starea initiala si cea finala, respectiv lambda-tranzitiile reprezentate prin "."
	transMatrix[0][this->q0] = ".";

	for (int i : this->F)
	{
		transMatrix[i][size + 1] = ".";
	}

	for (int state : this->Q) // sterg fiecare stare si refac tranzitiile pana raman cu cele doua adaugate
	{
		set<int> in;
		set<int> out;
		string final = "";

		for (int i = 0; i <= size + 1; i++) // ce iese din starea curenta
		{
			if (transMatrix[state][i] != " " && i != state)
			{
				out.insert(i);
			}
		}

		for (int i = 0; i <= size + 1; ++i) // ce intra in starea curenta
		{
			if (transMatrix[i][state] != " " && i != state)
			{
				in.insert(i);
			}
		}

		for (int i : in) // produsul cartezian, refac tranzitiile
		{
			for (int j : out)
			{
				string aux = "";
				if (transMatrix[state][state] != " ")
				{
					aux += "(" + transMatrix[state][state] + ")*";
				}

				if (state != i && state != j)
				{
					if (transMatrix[i][state] != "." && transMatrix[i][state] != " ")
					{
						final += "(" + transMatrix[i][state] + ")";
					}
					final += aux;
					if (transMatrix[state][j] != "." && transMatrix[state][j] != " ")
					{
						final += "(" + transMatrix[state][j] + ")";
					}
				}
				if (transMatrix[i][j] != " ")
				{
					transMatrix[i][j] += "+" + final;
				}
				else
				{
					transMatrix[i][j] = final;
				}
				final = "";
			}
		}

		for (int i = 0; i < size + 1; i++) // elimin starea curenta
		{
			transMatrix[i][state] = ' ';
			transMatrix[state][i] = ' ';
		}
	}

	cout << transMatrix[0][size + 1];
}

int main()
{
	DFA M;
	ifstream f("DFAtoREGEX.txt");
	f >> M;
	M.DFAtoREGEX();
	f.close();
	return 0;
}