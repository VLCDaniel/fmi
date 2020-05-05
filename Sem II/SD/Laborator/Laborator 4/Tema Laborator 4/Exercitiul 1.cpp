#include <iostream>

struct arbore
{
    int info;
    arbore* stang, * drept;
} *radacina;

void insert(int x)
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
			if (r->info > x)
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
			else if (r->info < x)
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

bool search(int x)
{
	if (radacina == nullptr)
		return false;

	arbore* r = radacina;

	while (r != nullptr)
	{
		if (r->info > x)
			r = r->stang;
		else if (r->info < x)
			r = r->drept;
		else
			return true;
	}
	return false;
}

void SRD(arbore* nod)
{
	if (nod)
	{
		SRD(nod->stang);
		std::cout << nod->info << " ";
		SRD(nod->drept);
	}
}

void RSD(arbore* nod)
{
	if (nod)
	{
		std::cout << nod->info << " ";
		RSD(nod->stang);
		RSD(nod->drept);
	}
}

void remove(int val)
{
	if (!search(val))
	{
		std::cout << "Nodul nu exista!";
		return;
	}

	arbore* r = radacina;
	arbore* parent = r;

	while (r)
	{
		if (r->info > val)
		{
			parent = r;
			r = r->stang;
		}
		else if (r->info < val)
		{
			parent = r;
			r = r->drept;
		}
		else
		{
			if (!r->drept && !r->stang)
			{
				if (parent->stang == r)
					parent->stang = nullptr;
				else
					parent->drept = nullptr;
				delete r;
			}
			else if (!r->stang)
			{
				if (parent->stang == r)
					parent->stang = r->drept;
				else
					parent->drept = r->drept;
				delete r;
			}
			else if (!r->drept)
			{
				if (parent->stang == r)
					parent->stang = r->stang;
				else
					parent->drept = r->stang;
				delete r;
			}
			else
			{
				arbore* temp = r;
				temp = r->drept;
				while (temp->stang)
				{
					temp = temp->stang;
				}
				int value = temp->info;
				remove(temp->info);
				r->info = value;
			}
			return;
		}
	}
	return;
}

int main()
{
	insert(5);
	insert(4);
	insert(7);
	insert(3);
	std::cout << search(1) << search(3) << '\n';
	SRD(radacina);
	std::cout << '\n';
	RSD(radacina);
	std::cout << '\n';
	remove(3);
	SRD(radacina);
    return 0;
}
