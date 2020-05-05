#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct arbore
{
    string info;
    arbore* stang = nullptr, * drept = nullptr;
} *radacina;

void insert(string x)
{
	if (radacina == nullptr)
	{
		radacina = new arbore;
		radacina->info = x;
		radacina->stang = nullptr;
		radacina->drept = nullptr;
	}

	else
	{
		arbore* r = radacina;
		bool stop = false;

		while (!stop)
		{
			if (strcmp(r->info.c_str(), x.c_str())>0)
				if (r->stang != nullptr)
					r = r->stang;
				else
				{
					r->stang = new arbore;
					r->stang->info = x;
					r->stang->stang = nullptr;
					r->stang->drept = nullptr;
					stop = true;
				}
			else if (strcmp(r->info.c_str(), x.c_str())<0)
			{
				if (r->drept != nullptr)
					r = r->drept;
				else
				{
					r->drept = new arbore;
					r->drept->info = x;
					r->drept->stang = nullptr;
					r->drept->drept = nullptr;
					stop = true;
				}
			}
			else
				return;
		}
	}
}

void SRD(arbore* nod)
{
	if (nod)
	{
		SRD(nod->stang);
		cout << nod->info << " ";
		SRD(nod->drept);
	}
}

int main()
{
	int n;
	string s;
	cout << "n= ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "sir: ";
		cin >> s;
		insert(s);
	}
	SRD(radacina);
    return 0;
}
