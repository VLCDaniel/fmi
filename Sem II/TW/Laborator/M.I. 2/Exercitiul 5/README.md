Identificator: ex_mi_css_selectori_

Se da urmatorul fisier html:

<details>
<summary>Click me</summary>

```
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"/>
	<title>Titlu</title>
</head>
<body>
	<table id="tab_fl">
		<thead>
			<tr>
				<th>Nume</th>
				<th>Prenume</th>
				<th>Ocupatie</th>
				<th>Hobby-uri</th>
				<th>Poza</th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td>Flutureanu</td>
				<td>Petala</td>
				<td>instructor de zbor</td>
				<td>
					<ol>
						<li>acrobatiile in aer</li>
					</ol>
				</td>
				<td><img src="http://irinaciocan.ro/tehnici_web/imagini/fluture1a.png" alt="Flutureanu"></td>
			</tr>
			<tr>
				<td>Fluflututurescu</td>
				<td>Flu-flu</td>
				<td>lo-logoped</td>
				<td>
					<ol>
						<li>zbu-zbu-zburatul pe-pe c-c-campie</li>
					</ol>
				</td>
				<td><img src="http://irinaciocan.ro/tehnici_web/imagini/fluture2a.png" alt="Fluflututurescu"></td>
			</tr>
			<tr>
				<td>Fluturache</td>
				<td>Ion</td>
				<td>negustor de polen</td>
				<td>
					<ol>
						<li>botanica</li>
						<li>pictura</li>
					</ol>
				</td>
				<td><img src="http://irinaciocan.ro/tehnici_web/imagini/fluture3a.png" alt="Fluturache"></td>
			</tr>
			<tr>
				<td>Omiduta</td>
				<td>Omidon</td>
				<td>mancator de frunze</td>
				<td>
					<ol>
						<li>actoria</li>
						<li>deghizatul in fluture</li>
					</ol>
				</td>
				<td><img src="http://irinaciocan.ro/tehnici_web/imagini/fluture4a.png" alt="Omiduta"></td>
			</tr>
			<tr>
				<td>Fluturong</td>
				<td>Zbarr</td>
				<td>luptator profesionist</td>
				<td>
					<ol>
						<li>artele martiale</li>
						<li>batut paianjenii</li>
					</ol>
				</td>
				<td><img src="http://irinaciocan.ro/tehnici_web/imagini/fluture5a.png" alt="Omiduta"></td>
			</tr>
		</tbody>
		<tfoot>
			<tr>
				<td>
					Concluzii:
				</td>
				<td colspan="4">
					Toti fluturii sunt frumosi!
				</td>
			</tr>
		</tfoot>

	</table>
	<div>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
	</div>
		<div>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
	</div>
	<div>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
	</div>
	<hr/>
	<div>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
		<p>paragraf</p>
	</div>	
</body>
</html>
```

</details>


si printscreenul ajutator:
![Printscreen](https://user-images.githubusercontent.com/38056943/77864089-5b5be580-722f-11ea-8a89-8b0c3fc2ee42.png)

Realizati urmatoarele cerinte fara a utiliza stil inline si fara a modifica html-ul prin adaugare atributelor class sau id, decat daca
acest lucru e permis in mod explicit in cerinta (nu se vor puncta astfel de rezolvari). Puneti comentarii in CSS in care sa aratati unde
ati rezolvat subpunctele.

1) Formatati primul rand al tabelului astfel incat sa aiba fundal navy, iar textul sa fie scris cu culoare alba,
Arial Black, Gadget, sans-serif

2) Formatati ultimul rand astfel incat sa aiba fundal lime, scrisul italic, cu Comic Sans MS.

3) Liniile despartitoare intre celule sa fie negre, tabelul sa aiba un border albastru outset de 4px. Intre celule sa nu existe spatii.

4) Folositi un singur selector, astfel incat prima celula de pe fiecare rand (inclusiv primul rand, cu headerul) sa aiba textul subliniat.
   (Gasiti doua variante pentru a rezolva acest subpunct - una din variante va fi pusa intr-un comentariu CSS).

5) Modificati html-ul si adaugati un caption. Textul din caption trebuie sa fie o propozitie despre fluturi. Captionul tabelului trebuie
   sa fie afisat sub tabel si sa contina text taiat si supraliniat. Captionul trebuie sa aiba un margin in partea de sus de 5px.
   Textul caption-ului il puneti voi sa fie ce vreti.

6) Celulele de pe ultima coloana contin fiecare cate o imagine . In momentul in care veniti cu cursorul pe o imagine, acesta trebuie sa
   fie de tip crosshair iar imaginea sa capete un outline roz, punctat, de grosime 2px.

7) Modificati listele de hobby-uri (aici aveti voie sa modificati si HTML-ul) astfel incat:
	Indicii listei vor fi numere armenesti, italice, scrise cu rosu.
	Textul efectiv al elementelor listei va fi albastru si bold, cu scris neitalic.

8) Prima litera a fiecarei celule din tabel, cu exceptia celulelor din primul rand, din ultimul rand si a celor de pe coloana cu listele
   sa aiba proprietatea ca pentru celulele pare litera sa fie lightblue, iar pentru imapre pink.

9) Adaugati la sfarsitul paginii (aici puteti modifica HTML-ul) si un link catre google, care la hover sa schimbe dimensiunea literelor in
   20px, iar la momentul click-ului pe el (link activ) sa aiba background galben.

10) Sub tabel sunt 3 divuri in care exista 3,4,respectiv 5 paragrafe. Folosind un singur selector si fara a va defini o clasa
 (adica nu veti folosi atributul class pentru paragrafe), faceti astfel incat in fiecare div (doar cele 3 divuri de sub tabel, nu si
  cel de sub hr, de la al 4-lea paragraf incolo, textul sa aiba spatiul intre caractere de -3px).