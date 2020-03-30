Identificator: ex_css_display

Porniti de la fisierul html dat si rezolvati cerintele intr-un fisier css extern (nu folositi atributul style). Raspunsurile la intrebari se scriu pe scurt in comentarii.

<details>
<summary> Click me </summary>

```
<!DOCTYPE html>
<html lang="ro">
	<head>
		<meta charset="UTF-8"/>
		<title>Trei paragrafe si doua divuri</title>
		<link rel="stylesheet" type="text/css" href="stil.css"/>
	</head>
	
	<body>
		<p id="a">Acesta este un <span>paragraf</span> foarte dragut.</p>
		<p id="b">Acesta este un <span>paragraf</span> foarte dragut.</p>
		<p id="c">Acesta este un <span>paragraf</span> foarte dragut.</p>
		<div>Un div</div><div> si inca un div</div>
	</body>
</html>
```

</details>

- orice div din pagina sa aiba display inline si observati ca se afiseaza acum pe un singur rand.
- orice span din pagina sa aiba background rosu, width de 70px si height de 50 px. Se aplica width si height? De ce? Tineti cont ca elementul span are in mod implicit display-ul inline.
- in paragraful cu id-ul a faceti ca span-ul sa aiba display block. Cum se afiseaza fata de restul continutului paragrafului? Se aplica width si height acum?
- in paragraful cu id-ul b faceti ca span-ul sa aiba display inline-block. Cum se afiseaza fata de restul continutului paragrafului? Se aplica width si height acum? De ce apare o spatiere sub paragraf?
- Folositi valoarea corespunzatoare pentru proprietatea display astfel incat sa nu se mai afiseze span-ul din al treilea paragraf.