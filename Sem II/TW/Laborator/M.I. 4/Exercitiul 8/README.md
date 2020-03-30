Identificator: ex_mi_countere

Fiecare subpunct are 2 puncte din nota 10.

Se da o pagina html:

<details>
<summary> Click me (HTML)</summary>
<p>
    
```
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<title>Cazul lui Monsieur Gandac de Cuisine</title>
	<link rel="stylesheet" href="stil_test_countere_gandacescu.css" type="text/css"/>
</head>
<body>
	<div id="container">
		<h1>Document referitor la tragicul sfarsit al lui Monsieur Gandac de Cuisine</h1>
		<p>Azi, <time datetime="2015-04-12">12 aprilie 2015</time>, s-a intamplat un tragic accident in care respectabilul Monsieur Gandac de Cuisine a fost calcat, fara de mila, pe intuneric, de catre un rauvoitor.</p>

		<p>Iata listele celor prezenti la locul faptei (primele 2 liste nu sunt trecute aici - in ele erau 4 suspecti fara alibi):</p>
		<div class="cont_lista">
			<ol>
				<li> Mitza </li>
				<li class="fara_alibi"> Mimi </li>
				<li> Miau </li>
				<li> Motanette </li>
			</ol>
			<p class="concluzie" id="pisici"></p>
		</div>
		<div class="cont_lista">
			<ol>
				<li> Soricescu </li>
				<li class="fara_alibi"> Rontziski </li>
				<li class="fara_alibi"> Sir Mouse </li>
				<li> Shoricello </li>
			</ol>
			<p class="concluzie" id="soareci"></p>
		</div>
		<div class="cont_lista">
		<ol>
			<li> Pufulete </li>
			<li class="fara_alibi"> Ciupicete </li>
		</ol>
		<p class="concluzie" id="papuci"></p>
		</div>
	</div>
</body>
</html>
```

</details>

 si un fisier de stil:

<details>
<summary>Click me (CSS)</summary>

```
body
{
	background:skyblue;
}
		
div#container
{
	margin-left:15%;
	margin-right:15%;
	border-left:2px solid grey;
	border-right:2px solid grey;
	background:white;
	padding:5%;
}

li.fara_alibi
{
	color:red;
	font-weight:bold;
}
```

</details>

 folosit in acea pagina. Sa se realizeze cerintele <b color="red">fara a modifica pagina html</b>:

1) Fiecare element din lista sa aiba inlocuit indicele item-ului cu un indice de forma numar_lista.numar_element_in lista

2) Sa se calculeze folosind countere si sa se afiseze un continut generat (proprietatea content) cu ajutorul fiecarui paragraf de dupa fiecare lista, numarul total de elemente din lista. De asemenea, tipul de elemente din lista se va lua prin CSS din id-ul paragrafului.

3) Fara a muta paragraful in HTML, sa se afiseze paragraful corespunzator fiecarei liste inaintea listei

4) In dreptul fiecarui suspect fara alibi sa se afiseze, cu ajutorul CSS, dupa numele acestuia imaginea ![Smiley](https://user-images.githubusercontent.com/38056943/77872756-8dca0a80-7250-11ea-8737-b4fab2382fa4.png)
 delicvent si in paranteza al catelea suspect fara alibi este.

5) Numararea listelor sa inceapa de la 3. Indicii elementelor din lista sa fie numerotati cu litere mici latine, nu cu numere. Numararea celor fara alibi sa porneasca de la 5. Pentru suspectii fara alibi sa nu se afiseze cu rosu si litere aldine decat numele, nu si indicele.

Printscreen-uri ajutatoare:

![Print Screen](https://user-images.githubusercontent.com/38056943/77872811-be11a900-7250-11ea-8f69-ed5f9e69d2c6.png)
