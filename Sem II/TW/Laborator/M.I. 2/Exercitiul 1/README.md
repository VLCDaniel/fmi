Identificator: ex_css_introductiv
Porniti de la pagina text_exe_css.txt, salvand fisierul cu extensia html.

Pentru acest exercitiu veti folosi:

[Referinta pentru selectori](https://www.w3schools.com/cssref/css_selectors.asp)  
[Referinta pentru proprietati](https://www.w3schools.com/cssref/default.asp)

Cerinte: (Atentie, se va trece in comentariu numarul fiecarei cerinte rezolvate!)

1) Sa se puna culoarea de background: #EEEEEE si imaginile de background (folositi URL-ul lor):  
![Carouri](https://user-images.githubusercontent.com/38056943/77860743-791e5000-7219-11ea-8dd2-3f1d4c735dda.png)
![Mazgaleala](https://user-images.githubusercontent.com/38056943/77860759-8d624d00-7219-11ea-9c32-6439b62cc6b9.png)

Ambele imagini trebuie sa se repete si pe orizontala si verticala.

2) Adaugati in stanga paginii o spatiere de 50 px si in dreapta de 5px. Folositi imaginea gri ![imagine gri](https://user-images.githubusercontent.com/38056943/77860771-a7039480-7219-11ea-84e9-681919ca4155.png)
   pentru a trasa o linie verticala in stanga paginii, care sa inceapa de la 40px. Aliniati carourile astfel in sus si stanga sa nu avem
   patratele taiate (hint: imaginea e de 10px x 10px).

3) Sa se defineasca o regula css care face ca toate paragrafele sa fie scrise cu roz. Se va observa rezultatul.

4) Sa se defineasca apoi o regula care face toate paragrafele sa se scrie cu gri (dedesubtul primei reguli).
   Ce observati? Scrieti intr-un comentariu CSS.

5) Creati un fisier cu extensia .css. In acest fisier creati un set de reguli pentru paragrafe, astfel incat sa fie
   scrise cu verde si cu font Comic Sans MS. Introduceti acest fisier ca stil extern, mai intai dupa tagul style
   (dupa tagul de inchidere, bineinteles) cu care am lucrat pana acum, apoi inainte de tagul style. Ce observati?
    Lasati-l inainte de tagul style pentru a nu afecta culoarea de dinainte a paragrafelor.

6) Sa defineasca o regula pentru h1 astfel incat sa fie subliniat si scris cu culoare rosie.

7) Sa se formateze h1 cu ajutorul atributului style astfel incat sa fie de culoare albastra si cu background lightblue.
   Ce observati?

8) Sa se defineasca o regula css prin care numai paragrafele imediat de dupa h3 (frati) sa aiba border albastru punctat de 2 pixeli
   si sa aiba culoare fuchsia.

9) Faceti ca toate paragrafele surori cu un h3, aflate dupa el sa fie scrise cu culoarea rgb(0, 95, 76). Adaugati-le si imaginea de background:

![Pink Background](https://user-images.githubusercontent.com/38056943/77860797-d3b7ac00-7219-11ea-9c32-696dccbf7581.png)

astfel incat sa ramana fixa, atunci cand se face scroll in pagina.

10) Creati o clasa, c1, care face background-ul mov. Observati ca al doilea h2 si paragrafele de dupa el sunt intr-un div.
    Atribuiti-i divului clasa c1. In paragraful 1.1 avem un span. Alocati-i span-ului clasa c1. Ce observati?

11) Creati clasa c2 cu font italic si background galben si atribuiti-o primelor 2 paragrafe (1.1, 1.2) si primului h3 (cu ajutorul atributului class).

12) Creati setul de de reguli pentru o clasa c3 astfel incat textul sa fie scris cu small-caps si background lime si puneti
    clasa c3 pentru primul h3 (Subcapitol 3.1) si paragrafele: 3.1, 3.2, 3.3 si 3.4. Definiti selectorul h3.c3 astfel incat
    sa aiba background portocaliu si literele sa fie toate mari(uppercase). Puneti selctorul h3.c3 inainte de .c3, ce observati?

13) Adaugati clasei c2 o regula astfel incat textul sa fie taiat cu o linie, adaugati clasei c3 o regula astfel incat textul
    sa fie "supra-liniat" (adica sa aiba linia deasupra). Faceti astfel incat paragrafele 3.3 si 3.4 sa apartina ambelor clase. Ce observati?

14) Scrieti un selector care selecteaza doare elementele care au atat clasa c2 cat si clasa c3 si le face fontul normal (neitalic) si
    culoarea textului va fi rgb(220, 20, 60).

15) Dati un id unuia din paragrafe. Creati un set de reguli astfel incat paragraful sa fie scris cu culoare portocalie, sa fie bold,
    si subliniat si supraliniat. Puneti acest set de reguli inaintea regulilor generale pentru paragraf. Ce observati?

16) Faceti ca paragrafele din subarborele sectiunii cu id-ul abc sa aiba un box-shadow de culoare rosie.

17) Faceti ca paragrafele fii directi din sectiunea cu id-ul abc sa aiba un box-shadow de culoare verde si un text shadow de culoare rosie.

18) Scrieti elementele din lista ordonata cu indici - cifre romane. Elementele din lista vor avea si un border ridge de 4 px,
    culoare mov si colturi rotunjite doar in partea de sus.

19) Scrieti un selector astfel incat toate paragrafele care au atributul title setat sa aiba prima litera cu font-size de 20px.

20) Scrieti un selector astfel incat toate paragrafele care au atributul title setat la valoarea "altceva" sa isi schimbe culoarea
    de background in roz cand venim cu cursorul pe ele.

21) Scrieti un selector astfel incat cand venim cu cursorul pe paragrafele de mai sus (care au atributul title setat la valoarea "altceva")
    elementul imediat de dupa ele sa fie ascuns (visibility:hidden).

22) Scrieti un selector astfel incat toate paragrafele de la al doilea incolo in cadrul unei sectiuni sa aiba un aliniat de 25px.

23) Faceti astfel incat elementele de pe pozitii pare din lista sa fie aliniate la dreapta.

24) Scrieti un selector astfel incat prima sectiune din pagina sa aiba un border verde de 4px dashed care sa apara doar sus si in stanga.

25) Scrieti un selector astfel incat dupa primul fiu (indiferent de tip) din fiecare sectiune sa apara textul "primul".

26) Scrieti un selector astfel incat inaintea oricarui heading sa apara imaginea.

27) Faceti ca paragrafele care nu au atributele class sau id setate sa aiba cursor crosshair.

28) Pentru toate elementele din pagina (selectorul *) sa se adauge un outline albastru, dashed, de 2 px.

29) Cand se vine cu cursorul pe sectiunea cu id-ul "abc", toate paragrafele (din subsectiunile sectiunii cu id-ul "abc") care nu se afla
    sub un paragraf-frate cu atributul title setat vor avea un spatiu intre litere de 15px (se face prin 2 selectori).

30) Verificati corectitudinea CSS-ului, atat din tagul <style> cat si din fisier folosind validatorul pentru CSS
   (se va atasa printscreen cu rezultatul validarii).

Verificare CSS
![Verificare CSS](https://user-images.githubusercontent.com/38056943/77860707-3ceaef80-7219-11ea-8a5f-5797366a9f19.png)

Verificare HTML
![Verificare HTML](https://user-images.githubusercontent.com/38056943/77860829-019cf080-721a-11ea-8ebd-ea1bb8f05dc2.png)
