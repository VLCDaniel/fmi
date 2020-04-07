<h1 align="center">Laborator 3: Heap si Sortari</h1>

Termen  <= ora 23:59 / 8 aprilie 2020

Punctaj acumulabil: 2/1/1/2(+2)= 6 bază (+2 bonus)

1) (2p) Implementati un min-heap cu urmatoarele operatii:

extragerea minimului din heap O(log n)
inserarea unei valori in heap O(log n)
Exista dar nu se cere la acest exercitiu o operatie numita heapify care transforma un array in heap in O(n).

2) (1p) Implementati heap-sort pentru sortat crescator folosind implementarea de heap de la punctul 1 (cu sau fara heapify).

3) (1p) Implementati Count Sort.

(Se numara elementele intr-un vector de frecvente)

4) (2p) Implementati Radix Sort.

(Se sorteaza elementele dupa cea mai nesemnificativa cifra (exemplu: 3254), folosind count sort, rezultand un alt vector; apoi noul vector se sorteaza din nou dupa a doua cifra, a treia, etc. prin aplicatii de count sort)

(Bonus 2p) Implementati Radix sort pe biti, in care in loc sa sortam dupa cea mai nesemnificativa cifra, sortam dupa cei mai nesemnificativi 4 sau 8 biti (de exemplu 3254 = 110010110110)

```
int x= 3254;

int ultimii8biti= x & 255; // 255 = 11111111

// ultimii8biti =10110110

int shiftat8biti = x >> 8 // shiftat8biti = 1100
```
