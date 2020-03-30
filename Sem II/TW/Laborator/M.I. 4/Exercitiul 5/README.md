Identificator: ex_mi_responsive_introductiv

Porniti de la fisierul cu exemplul responsive:

<details>
<summary> Click me </summary>

```
<!doctype html>
<html>
<head>

	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<style>
	html{
		font-size: 16px;
		}
		
	*{ /* resetarea spatierilor */
		margin:0px;
		padding:0px;
		text-indent:0px;
	}
	

	main{
		padding-left:10%;
		padding-right:10%;
		padding-top:50px;
	}


/* ------------coloane ------------------*/

	p.text{
		width:60%;
		float:left;
	}
	figure.img-wrap{
		width:40%;
		float:left;
	}

	figure.img-wrap>img{
		width:100%;
		height:auto;
		
	}

/* ------------meniu ------------------*/
	nav{
		width:100%;
		position:fixed;
	}

	ul.menu>li, ul.menu>li>ul.submenu>li{
		display:block;
		
		font-size:1.2rem;
		font-weight:bold;
		height:1.2rem;
		line-height:1.2rem;
		text-align:center;		
		list-style-type:none;
		overflow:hidden;
	}
	ul.menu>li{
	 float:left;
	 width:12.5%;
	}
	ul.submenu>li{
	 width:100%;
	}
	ul.menu>li>a,ul.menu>li>div,ul.submenu>li>a{
		display:block;
		height:	100%;
		text-decoration:none;
		color:black;
	}
	ul.menu>li:nth-of-type(even) a, ul.menu>li:nth-of-type(even) div{
		background:pink;
	}
	ul.menu>li:nth-of-type(odd) a, ul.menu>li:nth-of-type(odd) div{
		background:lightblue;
	}

	ul.menu>li>ul.submenu{
		position:relative;
		top:0px;
	}

	ul.menu>li>ul.submenu>li
	{
		border-top:1px solid black;
	}
	ul.menu>li>ul.submenu>li:last-child
	{
		border-bottom:1px solid black;
	}

	ul.menu>li>a:hover, ul.submenu>li>a:hover{
		background:yellow;
	}
	ul.menu>li:hover{
		overflow:visible;
	}
	
	
	
	
	@media screen and (min-width:400px) and (max-width:700px){
		p.text{
		float:none;
		width:100%;
		}
		figure.img-wrap{
		width:100%;
		}
		
		ul.menu>li{
		 width:25%;
		}

		ul.menu>li:hover ul.submenu{
			width:100vw;
			position:absolute;
			left:0px;
			top:1.2rem;
			border-top:1px solid magenta;
			border-bottom:1px solid black;
		}
		
		ul.menu>li:nth-of-type(even):hover ul.submenu{
				background:pink;
		}
		ul.menu>li:nth-of-type(odd):hover ul.submenu{
				background:lightblue;
		}
		ul.menu>li:hover ul.submenu>li{
			float:left;
			width:15%;
			border:none;
		}
	}
	/* ce stil se aplica pentru width-ul ferestrei egal cu 400px? */
	@media screen and (max-width:400px){
		p.text{
		float:none;
		width:100%;
		}
		figure.img-wrap{
		width:100%;
		}
	}
	</style>
</head>
<body>
<header>
	<nav class="wrapper">
		<ul class="menu">
			<li><a href="#">B1</a></li>
			<li>
				<div>B2</div>
				<ul class="submenu">
					<li><a href="#">B2-SB1</a></li>
					<li><a href="#">B2-SB2</a></li>
				</ul>
			</li>
			<li>
				<div>B3</div>
				<ul class="submenu">
					<li><a href="#">B3-SB1</a></li>
					<li><a href="#">B3-SB2</a></li>
				</ul>
			</li>
			<li><a href="#">B4</a></li>
			<li><a href="#">B5</a></li>
			<li><a href="#">B6</a></li>
			<li><a href="#">B7</a></li>
			<li><a href="#">B8</a></li>
		</ul>
	</nav>
</header>
<main>
	<h2>Happy</h2>
	<p class="text">ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva ceva </p>
	<figure class="img-wrap">
		<img alt="robots image" class="responsive" src="http://image.shutterstock.com/display_pic_with_logo/285580/105987983/stock-vector-illustration-of-best-friends-ever-cat-and-dog-105987983.jpg" >
		<figcaption>Miau Ham</figcaption>
	</figure>
</main>
</body>
</html>
```

</details>

si realizati urmatoarele taskuri:

1) Modificati media query-ul pentru ecran mediu sa fie intre 400 si 650 px.

	Adaugati si un media query pentru ecran mic. In acesta realizati urmatoarele:

	- Fiecare optiune de meniu sa se intinda pe toata latimea ecranului (deci meniul sa ocupe 8 randuri). Submeniul sa se afiseze iar pe verticala, pornind de sub optiunea de meniu corespunzatoare. Imaginea in continuare sa apara sub text si nu pe coloana paralela cu textul.

2) Pentru fiecare dimensiune de ecran stabiliti o dimensiune de font de baza pentru html:

	- pentru ecran mic va fi 10px
	- pentru ecran mediu, 12px
	- pentru ecran mare, 14px

	Puteti face sa se micsoreze literele de la o dimensiune de ecran la alta printr-o tranzitie CSS? Justificati raspunsul. (raspunsul se va adauga intr-un comentariu).

3) Schimbati unitatile de masura rem din codul CSS in em, dar cu masurile potrivite, astfel incat pagina sa se afiseze la fel (cu aceleasi font-size-uri finale). Scrieti intr-un comentariu cum ati fi facut asta cu procentaje in loc de em.

4) Adaugati tranzitii pe optiunile din meniu si submeniu, astfel incat trecerea de la roz/bleu la galben sa se faca treptat pentru optiunile peste care venim cu cursorul).