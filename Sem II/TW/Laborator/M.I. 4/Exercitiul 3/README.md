Identificator: ex_css_flex_introductiv

Folositi html-ul:

<details>
<summary> Click me (HTML)</summary>
    
```
<!DOCTYPE html>
<html lang="ro">
	<head>
		<meta charset="UTF-8"/>
		<title>Titlu foarte interesant</title>
		<link rel="stylesheet" type="text/css" href="ex_css_flex_introductiv.css"/>
	</head>
	<body>
		<h1>Flexbox</h1>
		<div id="container_taburi">
			<div class="buton" id="ord_dr_s">ordonare dreapta stanga</div>
			<div class="buton" id="ord_3124">ordonare 3124</div>
			<div class="buton" id="img_invers">img invers</div>
			<div id="coloane">
				<section>
					<h2>Coloana 1</h2>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean egestas dui leo, ultrices suscipit odio pulvinar quis. Ut lobortis mauris a est ultricies, commodo facilisis ex scelerisque. Nullam viverra massa ac ligula ornare, nec interdum tortor gravida. Sed at nulla interdum, dictum lacus sit amet, interdum magna. Nullam suscipit non felis non mattis. Nunc eleifend dapibus urna vitae semper. Donec egestas a lacus in vehicula. Duis vulputate ac erat tristique luctus.</p>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean egestas dui leo, ultrices suscipit.</p>
				</section>
				<section>
					<h2>Coloana 2</h2>
					<p>In hac habitasse platea dictumst. Phasellus quis enim placerat, egestas arcu sit amet, porttitor lectus. Etiam finibus arcu bibendum, commodo ligula nec, lacinia elit. Proin mauris ante, venenatis eu sem eget, sollicitudin efficitur risus. Aenean elementum ipsum id lectus commodo, eget malesuada ligula sollicitudin. Ut nec lacinia arcu. Vivamus a erat cursus, ullamcorper elit a, pharetra libero. Vivamus blandit elementum purus, quis iaculis ipsum pulvinar vel. Donec vel venenatis mi. In rhoncus, turpis ut blandit hendrerit, ipsum lectus placerat urna, sed pretium purus enim eget risus. Mauris ac felis et nulla aliquet molestie. Nulla at vestibulum enim. Suspendisse fringilla semper felis, quis dapibus justo rhoncus nec. Nunc ut metus arcu. Duis ultricies felis a risus tincidunt ullamcorper. </p>
					<p>Nam ante nisl, suscipit eu dignissim sit amet, auctor vel ipsum. Sed ac consequat libero. Pellentesque ac iaculis leo. Quisque congue lobortis tortor, non condimentum enim tincidunt ac. Sed tempor vitae est at fringilla. Aliquam erat volutpat. Vestibulum bibendum eros et nisi hendrerit congue. Phasellus molestie pulvinar tortor, eu laoreet eros scelerisque non. Cras ornare ac leo vitae malesuada. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. </p>
					<p>Nam ante nisl, suscipit eu dignissim sit amet, auctor vel ipsum. Sed ac consequat libero. Pellentesque ac iaculis leo. Quisque congue lobortis tortor, non condimentum enim tincidunt ac. Sed tempor vitae est at fringilla. Aliquam erat volutpat. Vestibulum bibendum eros et nisi hendrerit congue. Phasellus molestie pulvinar tortor, eu laoreet eros scelerisque non. Cras ornare ac leo vitae malesuada. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. </p>
				</section>
				<section>
					<h2>Coloana 3</h2>
					<p>Nam ante nisl, suscipit eu dignissim sit amet, auctor vel ipsum. Sed ac consequat libero. Pellentesque ac iaculis leo. Quisque congue lobortis tortor, non condimentum enim tincidunt ac. Sed tempor vitae est at fringilla. Aliquam erat volutpat. Vestibulum bibendum eros et nisi hendrerit congue. Phasellus molestie pulvinar tortor, eu laoreet eros scelerisque non. Cras ornare ac leo vitae malesuada. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. </p>
				</section>
				<section id="s_imag">
					<h2>Coloana 4</h2>
					<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean egestas dui leo, ultrices suscipit odio pulvinar quis. Ut lobortis mauris a est ultricies, commodo facilisis ex scelerisque. Nullam viverra massa ac ligula ornare, nec interdum tortor gravida. Sed at nulla interdum, dictum lacus sit amet, interdum magna. Nullam suscipit non felis non mattis. Nunc eleifend dapibus urna vitae semper. Donec egestas a lacus in vehicula. Duis vulputate ac erat tristique luctus.</p>
					<section id="imagini">
						<h3>Imagini</h3>
						<img src="http://irinaciocan.ro/imagini/fluture1a.png" alt="floricica" />
						<img src="http://irinaciocan.ro/imagini/cheie1.png" alt="floricica" />
						<img src="http://irinaciocan.ro/imagini/clepsidra.png" alt="floricica" />
						<img src="http://irinaciocan.ro/imagini/calculator_mov.png" alt="floricica" />
						<img src="http://irinaciocan.ro/imagini/om_cu_palarie.png" alt="floricica" />
					</section>
				</section>
			</div>
		</div>
	</body>
</html>
```

</details>

 si css-ul dat:

<details>
<summary>Click me (CSS)</summary>

```
html
{
	font-size:12px;
}

.buton
{
	border:2px brown ridge;
	background: #ffc37a;
	font-weight:bold;
	color:white;
	text-shadow:0px 0px 4px black,0px 0px 3px black,0px 0px 2px black,0px 0px 2px black;
	box-shadow:0px -3px 2px grey;
	height:2em;
	line-height:2em;
	width:120px;
	text-align:center;
	display:inline-block;
	font-size:0.9em;
	border-top-left-radius:5px;
	border-top-right-radius:5px;
}

.buton:hover
{
	background:orange;
}

#coloane>section
{
	border: 1px solid green;
	padding:2px;
	min-width:100px;
}

div#coloane
{
	border-top: 3px inset #BBB;
}
```

</details>

Toate subpunctele de mai jos <b>se vor realiza cu ajutorul proprietatilor ce tin de flexbox.Nu aveti voie sa modificati html-ul.</b> Pentru usurinta corectarii se va uploada si html-ul impreuna cu fisierul css.

1) Afisati cele 4 sectiuni din divul cu id-ul "coloane" pe 4 coloane <b>egale</b> (aceasta va fi afisarea default). Indicatii: flex-direction:row, flex-basis, flex-grow.

2) Introduceti cod css astfel incat, cand micsoram fereastra pe orizontala, coloanele care nu mai au loc sa fie mutate dedesubt. Indicatii: flex-wrap

3) Cand venim cu cursorul pe divul "ordonare dreapta stanga", coloanele se vor afisa in ordine inversa. Indicatii: flex-direction:row-reverse.

4) Cand venim cu cursorul pe divul "ordonare 3124", coloanele se vor aranja astfel incat coloana 3 sa fie pe prima pozitie, coloana 1 pe a doua pozitie etc. In plus, coloana 4 va fi de 3 ori mai mare, in latime, decat restul. Indicatie: order.

5) Afisati imaginile din coloana 4 una sub alta. Faceti astfel incat latimea lor sa nu fie latimea containerului ci latimea initiala a fiecarei imagini, iar imaginile sa fie aliniate spre stanga. Indicatii: flex-direction:column, align-items.

6) La hover pe butonul "img invers" ordinea imaginilor se va inversa, si vor fi aliniate la dreapta. Faceti astfel incat titlul sectiunii cu imagini sa ramana aliniat la stanga si tot sus (nu sub imagini). Indicatie: aling-items, align-self, order
Pentru a va fi mai usor sa intelegeti cerintele, urmariti [videoclipul](http://irinaciocan.ro/tehnici_web/video/ex_css_flex_introductiv.mp4).

[Linkuri utile](https://css-tricks.com/snippets/css/a-guide-to-flexbox/)