Realizati intr-o pagina html noua tabelele desenate pe tabla din imagine:


![Tabel 1](https://user-images.githubusercontent.com/38056943/77874265-1d71b800-7255-11ea-8cfb-f0719653b2d0.png)

![Tabel 2](https://user-images.githubusercontent.com/38056943/77874295-2e222e00-7255-11ea-8b9d-445381425ae9.png)

Pentru primul tabel folositi tagurile: table, caption, thead, tbody, tfoot, tr, th, td.

Pentru al doilea tabel nu mai aveti nevoie de thead si tfoot.

Pentru afisarea corecta a tabelelor, inserati in partea head a documentului codul:

```
    <style>
        th,td{
            border:1px solid black;
            padding:5px;
        }
        td:empty{
            padding:20px;
        }
        table{
            border-collapse:collapse;
            empty-cells:show;
        }
    </style>
```
