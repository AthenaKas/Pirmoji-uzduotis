# UŽDUOTIS

## Pirmoji užduotis v0.1
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Vartotojas įvedą studento vardą ir pavardę. Studentų kiekis nėra ribojamas. Suvedus reikiamus duomenis apie studentą, vartotojas gauna užkalausą: "Ar norite ivesti dar vieno studento duomenis: [y/n]";
2. Vartotojas turi pasirinkimą namų darbų pažymius ir egzamino rezultatą suvesti rankiniu būdų arba sugeneruoti atsitiktinai. Užklausa:  "Ar norite atsitiktinai generuoti pazymius? [y/n]";
  2.2 Jei pazymius vartotojas veda pats. Vartotojas įvedą egzamino pažymį ir taip pat iki 10 namų darbų pažymių;
3. Galutinis pažymys yra apsakičiaujamas tiek su pažymių vidurkiu, tiek ir su mediana;

Programa išvedą studentų vardus ir pavardes bei studentų galutinius pažymius suskaičiuotus su pažymiu vidurkiu ir mediana.

## Antroji užduotis v0.2
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. v0.1 buvo papildyta, tuo kad dabar galima duomenis ne tik įvesti bet ir nuskaityti iš failo. Vartotojui suteikiamas pasirinkimas.
2. Studentai yra surūšiuojami pagal vardus.

## Trečioji užduotis v0.3
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Funkcijos, nauji duomenų tipai buvo perkelti į antraštinius (header) failus, bei sukurti trys nauji .cpp failai.
2. Minimaliai panaudotas išimčių valdymas.

## Ketvirtoji užduotis v0.4
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Atsirado nauja funkcija Failų generacija. Vartotojas pasirenka kiek studentų ir kiek studentų pažymių bus.
2. Studentai yra surušiuojami į dvi grupes; vargšiukai ( x>5 ) ir gudročiai ( x<5 ).
3. Studentai atspausdinami į du skirtingus failus.
4. Laiko skaičiavimas:
<img width="529" alt="4" src="https://user-images.githubusercontent.com/99173750/161427869-a602335f-7628-452c-9173-81698ac3673d.png">

## Penktoji užduotis v0.5
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo sukurtos trys atskiros programos su trijais skirtingais konteineriais: vector, list, deque.
2. Buvo atlikti laiko matavymai šių trijų konteinerių spartumo.
3. Laiko matavimai:
<img width="472" alt="5" src="https://user-images.githubusercontent.com/99173750/161427791-2aa6fcce-2c4d-4d1b-b3e5-b70b0de01c25.png">
4. Sistemos parametrai:
CPU - AMD Ryzen 7 x64, 8 CORES, 2000MHz; RAM - 2x8 GB RAM; SSD - 500GB;

## Šeštoji užduotis v1.0
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo ištestuotos 2 strategijos - vector, deque, list konteineriams
2. Pritaikyti algoritmai studentų dalijimo procedūrai paspartinti (vector - konteinerio).
KONTEINERIS | KIEKIS   | 1 STRATEGIJA | 2 STRATEGIJA |
Vector      | 1000     | 0.0002s      | 0.0044s      |
            | 10000    | 0.0022s      | 0.0213s      |
            | 100000   | 0.0266s      | 0.3164s      |
            | 1000000  | 0.3210s      | 3.3060s      |
            | 10000000 | 2.3910s      | 15.568s      |

List        | 1000     | 0.0002s      | 0.0001s      |
            | 10000    | 0.0038s      | 0.0013s      |
            | 100000   | 0.0233s      | 0.0113s      |
            | 1000000  | 0.3400s      | 0.1418s      |
            | 10000000 | 1.9960s      | 0.9335s      |

Deque       | 1000     | 0.0001s      | 0.0008s      |
            | 10000    | 0.0021s      | 0.1458s      |
            | 100000   | 0.0186s      | 27.503s      |
            | 1000000  | 0.1758s      | -            |
            | 10000000 | 1.7858s      | -            |
