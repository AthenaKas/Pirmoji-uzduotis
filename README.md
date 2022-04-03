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

KIEKIS   | F!KŪRIMAS | F!NUSKAITYMAS IR SKAIČIAVIMAI | SUSKIRSTYMAS/RŪŠIAVIMAS Į VEKTORIUS | IŠVEDIMAS
1000     | 0.005s    | 0.002s                        | 0.00014s                            | 0.0015s
10000    | 0.06s     | 0.017s                        | 0.00227s                            | 0.0126s
100000   | 0.23s     | 0.176s                        | 0.02284s                            | 0.1239s
1000000  | 2.37s     | 1.720s                        | 0.23170s                            | 1.2997s
10000000 | 23.6s     | 17.49s                        | 2.58585s                            | 12.219s

## Penktoji užduotis v0.5
Šioje versijoje yra apskaičiuojamas studento ar studentų galutinis įvertinimas;
1. Buvo sukurtos trys atskiros programos su trijais skirtingais konteineriais: vector, list, deque.
2. Buvo atlikti laiko matavymai šių trijų konteinerių spartumo.
3. Laiko matavimai:
<img width="472" alt="5" src="https://user-images.githubusercontent.com/99173750/161427791-2aa6fcce-2c4d-4d1b-b3e5-b70b0de01c25.png">


KONTEINERIS | KIEKIS   | F!NUSKAITYMAS IR SKAIČIAVIMAI | SUSKIRSTYMAS/RŪŠIAVIMAS Į VEKTORIUS
 Vector     | 1000     | 0.002s                        | 0.00014s                 
            | 10000    | 0.017s                        | 0.00227s                
            | 100000   | 0.176s                        | 0.02284s                
            | 1000000  | 1.720s                        | 0.23170s                
            | 10000000 | 17.49s                        | 2.58585s 
            
 List       | 1000     | 0.002s                        | 0.00014s 
            | 10000    | 0.018s                        | 0.00132s
            | 100000   | 0.165s                        | 0.01868s
            | 1000000  | 1.695s                        | 0.18678s
            | 10000000 | 16.88s                        | 1.91396s
            
Deque       | 1000     | 0.001s                        | 0.00015s
            | 10000    | 0.017s                        | 0.00186s
            | 100000   | 0.168s                        | 0.01805s
            | 1000000  | 1.682s                        | 0.17581s
            | 10000000 | 16.90s                        | 1.78502s
           
4. Sistemos parametrai:
CPU - AMD Ryzen 7 x64, 8 CORES, 2000MHz
RAM - 2x8 GB RAM
SSD - 500GB
