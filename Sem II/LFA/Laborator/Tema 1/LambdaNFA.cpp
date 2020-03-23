#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <fstream>
using namespace std;

class LNFA
{
    set<int> Q, F;
    set<char> Sigma;
    set<int> q0;
    map<pair<int, char>, set<int>> delta;

public:
    LNFA() { this->q0 = { 0 }; }
    LNFA(set<int> Q, set<char> Sigma, map<pair<int, char>, set<int>> delta, set<int> q0, set<int> F)
    {
        this->Q = Q;
        this->Sigma = Sigma;
        this->Sigma.insert('.');
        this->delta = delta;
        this->q0 = q0;
        this->F = F;
    }

    set<int> getQ() const { return this->Q; }
    set<int> getF() const { return this->F; }
    set<char> getSigma() const { return this->Sigma; }
    set<int> getInitialState() const { return this->q0; }
    map<pair<int, char>, set<int>> getDelta() const { return this->delta; }

    friend istream& operator >> (istream&, LNFA&);
    bool intersectionNotEmpty(set<int>);
    set<int> deltaStar(set<int>, string);
    set<int> lambdaInchidere(int);
};

bool LNFA::intersectionNotEmpty(set<int>st)
{
    for (auto x : st)
        for (auto y : F)
            if (x == y)
                return true;
    return false;
}

set<int> LNFA::lambdaInchidere(int q)
{
    set<int> lambdaInchidereaLuiq = { q };
    map <int, bool> aparitii; // Pentru eficienta, voi verifica in O(1) daca starea in care am ajuns prin lambda a mai fost vizitata sau nu
    queue<int> copie; // Retin in coada toate starile in care ajung din q prin lambda( lant de lungime 1). Pentru fiecare astfel de stare, verific daca starile in care ajung prin lambda-tranzitii sunt deja vizitate(folosindu-ma de map pentru eficienta). Pentru cazul in care nu sunt vizitate, adaug starile respective in coada(pentru a fi verificate), respectiv in setul lambdaInchidereaLuiq. Am folosit coada pentru a putea sterge in O(1) starea verificata.

    for (int j : delta[{q, '.'}]) // Caut toate tranzitiile lui q cu lambda
    {
        lambdaInchidereaLuiq.insert(j); // Le adaug la inchidere
        copie.push(j); // Le adaug in coada
        aparitii[j] = true; // Le marchez ca vizitate
    }

    if (lambdaInchidereaLuiq.size() == 1) // Daca lambdaInchidereaLuiq are doar un element, il returnez, pentru ca e chiar q
        return lambdaInchidereaLuiq;

    while (!copie.empty()) // Cat timp coada are elemente
    {
        for (int j : delta[{copie.front(), '.'}]) // Caut alte stari prin lambda-tranzitii
        {
            if (aparitii[j] != true) // Daca starea respectiva nu e vizitata
            {
                lambdaInchidereaLuiq.insert(j); // O adaug la inchiderea lui q
                aparitii[j] = true; // O marchez ca vizitata
                copie.push(j); // O adaug in coada 
            }
        }
        copie.pop(); // Elimin primul element din coada
    }
    aparitii.clear();
    return lambdaInchidereaLuiq;
}

set<int> LNFA::deltaStar(set<int> s, string w)
{
    set<int> stariFinale;
    int p = 0; // Pentru parcurgerea lui w
    s = lambdaInchidere(*s.begin());

    map <int, bool> aparitii; // Pentru eficienta

    for (int i : s)
    {
        for (int j : delta[{i, w[0]}])
        {
            if (aparitii[j] != true)
            {
                stariFinale.insert(j);
                aparitii[j] = true;
            }
        }
    }

    p++;
    if (w[p] == NULL)
        return stariFinale;

    int p2 = 1;
    while (w[p]) // aplic deltastar pentru fiecare caracter
    {
        set<int> local;
        aparitii.clear();
        for (int i : stariFinale)
        {
            for (int j : lambdaInchidere(i))
            {
                for (int k : delta[{j, w[p2]}])
                {
                    if (aparitii[k] != true)
                    {
                        aparitii[k] = true;
                        local.insert(k);
                    }
                }
            }
        }
        p++;
        p2++;
        stariFinale.clear();
        for (int i : local)
        {
            stariFinale.insert(i);
        }
        local.clear();
    }
    set<int> local;
    aparitii.clear();
    for (int i : stariFinale) // Lambda-inchiderea de la final
    {
        for (int j : lambdaInchidere(i))
        {
            if (aparitii[j] != true)
            {
                aparitii[j] = true;
                local.insert(j);
            }
        }
    }
    return local;
}

istream& operator>>(istream& f, LNFA& M)
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
    M.Sigma.insert('.'); // Adaug lambda in alfabet
    for (int i = 0; i < noOfLetters; ++i)
    {
        char ch;
        f >> ch;
        M.Sigma.insert(ch);
    }
    int nrTranzitiiDelta;
    f >> nrTranzitiiDelta;
    for (int i = 0; i < nrTranzitiiDelta; ++i)
    {
        int stareInit;
        f >> stareInit;
        char ch;
        f >> ch;
        int nrStari;
        f >> nrStari;
        for (int j = 0; j < nrStari; ++j)
        {
            int legtura;
            f >> legtura;
            M.delta[{stareInit, ch}].insert(legtura);
        }
    }
    int q0;
    f >> q0;
    M.q0.insert(q0);

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

int main()
{
    LNFA M;
    int ok = 0;
    //ifstream fin("nfa.txt"); //Cuvantul: "abb"
    //ifstream fin("nfa2.txt"); //Cuvantul: "abb"
    ifstream fin("nfa3.txt"); //Cuvantul: "abbab"
    fin >> M;
    fin.close();

    set<int> ultimaStare = M.deltaStar(M.getInitialState(), "abbab"); 

    if (M.intersectionNotEmpty(ultimaStare))
    {
        cout << "Cuvant acceptat";
    }
    else
    {
        cout << "Cuvant neacceptat";
    }
    return 0;
}