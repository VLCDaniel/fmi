Identificator: ex_css_anim_rot_trans

Sa facem soarele sa rasara si apoi sa apuna... Realizati urmatoarea animatie pornind de la fisierul:

<details>
<summary>Click me</summary>

```
<!DOCTYPE html>
<html>
<head>


</head>
<body>

<div id="fereastra">
<div id="soare"></div>
</div>

</body>
</html>
```

</details>

[Video 1](http://irinaciocan.ro/tehnici_web/video/ex_css_anim_rot_trans.ogv)

"Soarele" este de dimensiune 100px*100px si trece de la background rosu la galben si apoi iar la rosu.

Fereastra are o dimensiune de 500px*250px, borderul e maro, inset, de dimensiune 7px. Animatia cerului dureaza 5 secunde
intai e negru, apoi la un sfert din timpul animatiei la navy, apoi la sfarsitul animatiei la lightblue. Trecerea soarelui dureaza 10 secunde.

Dupa ce ati realizat miscarea soarelui pe orizontala si ati aratat acest lucru la laborator, puteti incepe sa lucrati la al
doilea tip de miscare a soarelui. In partea a doua a exercitiului o sa il si rotim un pic. Soarele se va roti cu 180 de grade.
Alegem punctul de plecare al soarelui astfel incat sa aiba drept centru coltul din stanga-jos al ferestrei. Originea pentru
realizarea rotatiei se va considera la 300=(250+50, adica juma de fereastra+juma de soare)px,70px. A doua coordonata, 70, a
fost aleasa astfel ca soarele sa nu depaseasca rama de sus a ferestrei. Nu puteam lasa soarele sa faca un semicerc, din cauza
ca fereastra e prea putin inalta. De aceea soarele se deplaseaza in partea dreapta un pic mai mult in jos.

[Video 2](http://irinaciocan.ro/tehnici_web/video/ex_css_anim_rot_trans2.ogv)

Realizati urmatoarea structura (doar din divuri):

![Raze](https://user-images.githubusercontent.com/38056943/77865594-d9bc8580-7237-11ea-9f05-b5658c0af84d.png)

Aici puteti folosi 12 divuri insa e mai usor cu doar 6 mai lungi, rotite la jumatate. Un astfel de div va avea latimea de
200px si inaltimea de 10px (pastrati, va rog, dimensiunile precizate in laborator ca sa se potriveasca si cu calculul facut pe tabla).

In final veti adauga "razele" la soarele de dinainte. Animatia de mai jos arata rezultatul final. (Apare un pic intrerupt in
video, dar asta e de la CamSudio, programul cu care fac inregistrarile, deoarece soarele se misca prea repede si rata cu
care CamStudio salveaza frameurile e ceva mai redusa, si nu prinde si pozitiile intermediare).

[Video 3](http://irinaciocan.ro/tehnici_web/video/ex_css_anim_rot_trans_final.ogv)