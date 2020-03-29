<h1 align="center"> Laborator 2: Stive si Cozi </h1>

Termen  <= ora 23:59 / 25 martie 2020

Punctaj acumulabil: 2/2/2/2(+2)/(+2)=8 bază (+4 bonus)

1. (2p) Implementati o stiva cu operatii push si pop folosind o lista. Push va insera elemente la inceputul listei si pop va sterge elemente de la inceputul listei.

```
struct stiva
{

    int info;

    stiva *next; 

} *pointer_global_element_varf;
```

<b>Rulare pe: push 1, pop, push 2, push 3</b>

2. (2p) Implementati o coada care permite operatii (insertie & stergere) la ambele capete (double ended queue - dequeue):

```
struct coada
{

    int info;

    coada *prev, *next; 

} *pointer_global_prim_element, *pointer_global_ultim_element;
```

<b>Rulare pe: push_left 1, push_right 2, pop_right, pop_left, push_right 3</b>

3. (Problema cu stivă 2p) Fie un număr par n de tăruși distribuiți echidistant pe un cerc numerotați de la 1 la n (vezi figura).

      Țărușii trebuie legați cu fire metalice în așa fel încât aceste fire să nu se intersecteze.

      Firele sunt reprezentate prin numere întregi, iar o soluție pentru problemă este dată printr-un vector de n întregi care reprezintă id-ul fiecărui fir asociat fiecărui tăruș. Doi țăruși i și j sunt conectați dacă au în dreptul lor același întreg (tarusi[i]==tarusi[j]).

      Determinați în timp O(n) dacă o soluție dată este corectă sau nu.
      
      Exemplu1: Pentru n = 8 si vectorul tarusi= (1, 2, 2, 1, 3, 3, 4, 4) avem configurația validă (b).

      Exemplu2: Pentru n = 8 si vectorul tarusi= (1, 2, 2, 3, 1, 4, 3, 4) avem configurația invalidă (c).

      Imagine(exemple):

      ![Exemple](https://user-images.githubusercontent.com/38056943/77861778-c1407100-721f-11ea-925a-e34e18c1307a.png)


4. (Problema cu coadă 2p) Spunem ca o imagine digitala binara M este o matrice de m x m elemente (pixeli) 0 sau 1. Un element a al matricei este adiacent cu b, daca b se afla deasupra, la dreapta, dedesubtul, sau la stanga lui a in imaginea M.

      Spunem ca doi pixeli 1 adiacenti apartin aceleiasi componente. Problema va cere sa etichetati pixelii imaginii astfel incat doi pixeli primesc aceeasi eticheta daca si numai daca apartin aceleiasi componente.

      Hint: folositi o coadă sau o pereche de cozi ca să introduceți coordonatele i și j ale primei apariții de 1. După care, câtă vreme coada nu e vidă scoateți coordonatele, colorați și puneți toți vecinii care au 1 în coadă. Repetare pentru fiecare 1 rămas în matrice.

      Bonus 2p: Problema se poate rezolva si cu paduri de multimi disjuncte (disjoint set forest - sau structura union-find), structura descrisa in Cormen.

      Imagine(exemple):

![Exemple](https://user-images.githubusercontent.com/38056943/77861861-50e61f80-7220-11ea-9cb7-8343aa213fd8.png)

5. (Problema bonus 2p) Fie v un vector de n componente intregi, neordonate.

Spunem ca un element este majoritar in v daca apare de cel putin n/2 + 1 ori in v.

Descrieti si implementati un algoritm ce ruleaza in timp <b>O(n)</b> care sa decida daca exista un element majoritar, si, daca da, sa il afiseze. <b>(!) fara vectori de frecventa :(</b>
