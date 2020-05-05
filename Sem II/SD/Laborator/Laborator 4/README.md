<h1 align="center">Laborator 4: Arbori binari</h1>

<h2> Teorie </h2>

Un arbore binar de cautare este:
- Un arbore **binar** in care fiecare nod are maxim doi fii
- De **cautare** in sensul in care pentru fiecare nod **x**: subarborele stang contine chei mai mici sau egale decat **x**, iar subarborele drept chei mai mari decat **x**

Se implementeaza cu pointeri:

```c++
struct arbore
{
	int info;
	arbore* stang, * drept;
} *radacina;

```

Intr-un arbore binar de cautare avem o metoda specifica pentru inserat o valoare **x** in asa fel incat sa verificam cele doua conditii de mai sus:

- Se incepe cu pozitia radacinii arborelui
- Daca in pozitia curenta nu exista nod, **x** se leaga in arbore la aceasta pozitie
- Daca exista nod cu valoarea **t** la pozitia curenta, atunci **x** se insereaza in subarborele stanga daca **x <=t**, sau in subarborele drept, altfel

Exemplu: creati arborele binar de cautare obtinut prin inserarea pe rand a cheilor 6 4 9 2 1 5 3 7 8:

![Arbore](https://user-images.githubusercontent.com/38056943/81076861-de3e2300-8ef4-11ea-836f-87a81711dee9.png)

In orice nod este verificata proprietatea arborelui de cautare.

![Arbore](https://user-images.githubusercontent.com/38056943/81077015-18a7c000-8ef5-11ea-8692-55f0cac06bc8.png)

Avem mai multe modalitati de a afisa arborele prin recursie de la radacina catre frunze:

- Stanga-Radacina-Dreapta sau inordine e o recursie care
	1) merge recursiv in stanga,
	2) afiseaza valoarea nodului curent,
	3) merge recursiv in dreapta

```c++
void SRD(arbore* r)
{
    if (r != NULL)
    {
        SRD(r->stang);
        cout << r->info;
        SRD(r->drept);
    }
}
```

Pe exemplul dat, SRD: **1 2 3 4 5 6 7 8 9**
Pe exemplul dat SRD cu apel in radacina, pas cu pas:

sunt in 6, ma duc in stanga

    sunt in 4, ma duc in stanga,

        sunt in 2, ma duc in stanga,

            sunt in 1, ma duc in stanga,

                sunt in NULL, ma intorc,

            sunt in 1, **afisez 1**, ma duc in dreapta,

                sunt in NULL, ma intorc,

            sunt in 1, ma intorc,

        sunt in 2, **afisez 2**, ma duc in dreapta,        

            sunt in 3, ma duc in stanga,

                sunt in NULL, ma intorc,

            sunt in 3, **afisez 3**, ma duc in dreapta,

                sunt in NULL, ma intorc,

            sunt in 3, ma intorc,

        sunt in 2, ma intorc,

    sunt in 4, **afisez 4**, merg in dreapta, ETC

- similar celelalte afisari, RSD si SDR, doar se modifica ordinea afisarii si intrarii in recursie

Pe exemplul dat, RSD: **6 4 2 1 3 5 9 7 8**

- **IMPORTANT:** exista multi arbori care au acelasi SRD
- **IMPORTANT: un arbore poate fi reconstruit unic din doua afisari diferite, de exemplu SRD si RSD**
- **CONSECINTA: la tema, trebuie sa aveti 2 afisari de fiecare data cand printati un arbore, altfel poate sa arate oricum, SRD la arbore binar de cautare va fi mereu format din colectia sortata.**

![Arbore](https://user-images.githubusercontent.com/38056943/81077604-daf76700-8ef5-11ea-92c0-1a2427e894d5.png)

Daca stergem un nod, dar vrem sa pastram **calitatea de arbore de cautare**, atunci nu e trivial:

- Daca stergem un nod fara fii, de exemplu 1:

**2->stanga = NULL**

- Daca stergem un nod cu un singur fiu, de exemplu 7:

**9->stanga = 7->dreapta**

- **!!!!** Daca stergem un nod cu ambii fii, de exemplu 6, candidatii care il pot inlocui sunt:
	- **5** cel mai mare nod (mai mic decat 6)
	- **7** cel mai mic nod (mai mare decat 6)

Cum se gaseste nodul 5: merg o data in stanga si apoi numai in dreapta pana cand nu se mai poate.

Dupa ce pun valoarea nodului 5 sau 7 in radacina, apoi **vechiul nod se sterge** cu unul din cazurile mai simple: pentru ca are cel mult un fiu **!!!!**

<h2> Exercitii </h2>

**Termen  <= ora 23:59 / 29 aprilie 2020**

Punctaj acumulabil: 3(+3)/1/1= 5 bază (+3 bonus)