# UŽDUOTIS

##INSTRUKCIJA

Vartotojas turi 3 pasirinkimus:
1. Nuskaityti studentų duomenis iš failo;
2. Įvesti duomenis rankiniu būdu: Įvesti vardą, pavardę, pasirinkti ar pažymius vesti rankiniu būdu ar sugeneruoti;
3. Sugeneruoti studentų duomenų failą: Pasirinkti ar nuskaityti failą ar ne;

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
Analizė: 
Greičiausias uskirstymas studentu į skirtingus konteinerius - Deque;
Greičiausias failo nuskaitymas ir suskaičiavimas - List;
4. Sistemos parametrai:
CPU - AMD Ryzen 7 x64, 8 CORES, 2000MHz; RAM - 2x8 GB RAM; SSD - 500GB;

## Šeštoji užduotis v1.0
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo ištestuotos 2 strategijos - vector, deque, list konteineriams
<img width="296" alt="image" src="https://user-images.githubusercontent.com/99173750/163682620-919d9cf6-a9f6-4ba7-97bf-6b2f641d2f6c.png">
Analizė:
1 strategija greitesnė - Vector ir Deque konteineriais;
2 strategija greitesnė - List konteineriu;
2. Pritaikyti algoritmai studentų dalijimo procedūrai paspartinti (vector - konteinerio).

