//Source-vektoriai MAIN
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::fixed;
using std::sort;
using std::vector;
using std::ifstream;

struct data
{
	string vard{}, pav{};
	int paz[20]{}, egz{};
	double vidrezult{}, medrezult{};
};

const char CDfv[] = "kursiokai.txt";

//---
void ivestis(data& a, int& n);
void galutinisvid(data& a, int& n);
void galutinismed(data& a, int& n);
bool rikiavimas(const data& a, const data& b);
void rezultatai(data& a);
//---


int main()
{
	int N = 1;
	vector<data> sarasas;
	data laik;
	string anw; // ats: apie dar vieno studento duomenu vedima
	string anw2; //ats: ar skaityti is failo
	int n = 0; //kiekis pazymiu
	int y = 0; //ar nuskaityti duomenis loop
	int k = 0; //failo studentu kiekis

	cout << "Ar nuskaityti studentu duomenys is failo? [y/n] "; cin >> anw2;
	
	ifstream fd(CDfv);


	do {
		if ((anw2 == "n") || (anw2 == "N"))
		{
			for (int i = 0; i < N; i++)
			{
				ivestis(laik, n);

				galutinisvid(laik, n);

				galutinismed(laik, n);

				sarasas.push_back(laik);

				cout << "Ar norite ivesti dar vieno studento duomenis: [y/n] "; cin >> anw;
				if (anw != "y")
				{
					break;
				}
				else
				{
					N++;
					sarasas.reserve(N);
				}
			}
			y++;
		}
		else if ((anw2 == "y") || (anw2 == "Y"))
		{
				//----------------------------------------------------------------------
				std::ifstream open_f("kursiokai.txt");
				string tittle; //zodzio string
				while (tittle != "Egz.") {
					open_f >> tittle;
					if (tittle == "Egz.") break;
					else if (tittle.substr(0, 2) == "ND") {
						n++;
					}
				}
				while (open_f) {
					if (!open_f.eof()) {

						std::getline(open_f, laik.vard, ' ');
						std::getline(open_f, laik.pav, ' ');

						for (int i = 0; i < n; i++)
						{
							open_f>>laik.paz[i];
						}
						open_f >> laik.egz;

						galutinisvid(laik, n);

						galutinismed(laik, n);

						sarasas.push_back(laik);
						k++;
						

					}
					else break;
				}

				open_f.close();
				k = N;
				sort(sarasas.begin(), sarasas.end(), rikiavimas);
		   //------------------------------------------------------------------------
				std::ofstream out_f("kursiokai_cop.txt");

				out_f << std::left<< setw(20) << "Vardas" << "| ";
				out_f << setw(20) << "Pavarde" << " | ";
				out_f << setw(20) << "Galutinis (Vid.)" << " | ";
				out_f << setw(20) << "Galutinis (Med.)" << endl;

				for (const auto& el : sarasas) 
				{
					out_f << setw(20)<< el.vard << " | " << setw(20) << el.pav << " | ";
	
					out_f << setw(20) << setprecision(2) << fixed << el.vidrezult << " | ";

					out_f << setw(20) << setprecision(2) << fixed << el.medrezult << endl;
				}
				out_f.close();

				y++;
		}
		else
		{
			cout << "Ar nuskaityti studentu duomenys is failo? [y/n] "; cin >> anw2;
		}
	} while (y == 0);

	

	if ((anw2 == "n") || (anw2 == "N"))
	{
		sort(sarasas.begin(), sarasas.end(), rikiavimas);
		cout << setw(20) << "Vardas" << " | ";
		cout << setw(20) << "Pavarde" << " | ";
		cout << setw(20) << "Galutinis (Vid.)" << " | ";
		cout << setw(20) << "Galutinis (Med.)" << endl;
		cout << setw(23) << " | " << setw(23) << " | " << setw(23) << " | " << endl;

		for (int i = 0; i < sarasas.size(); i++)
		{
			rezultatai(sarasas[i]);
		}
	}

		sarasas.clear();
}
void ivestis(data& a, int& n)
{
	string anw; //ats: suvesti ar generuoti pazymius
	char x; //skirtas patikrinti ar ivedamas pazymys yra skaicius
	int y = 0; // generacija/suvedimas


	cout << "Iveskite varda: "; cin >> a.vard;
	cout << "Iveskite pavarde: "; cin >> a.pav;

	cout << "Ar atsitiktinai sugeneruoti pazymius ? [y/n] "; cin >> anw;

	do
	{

		if ((anw == "n") || (anw == "N"))
		{
			n = 1;
			cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite: [s] " << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "Iveskite " << i + 1 << " pazymi: ";
				cin >> x;
				if ((x == 's') || (x == 'S'))//jei iveda [s]
				{
					if (n > 1) //daugiau nebegalima vesti pazymiu
					{
						break;
					}
					else
					{
						cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite : [s]" << endl; //ivesta maziau nei vienas pazymys
						i--;
					}
				}
				else
				{
					if (isdigit(x)) //tiktina ar ivesta reiksme skaicius
					{
						a.paz[i] = x - 48;
						n++;
					}
					else
					{
						cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite : [s]" << endl; //ivede ne skaiciu
						i--;
					}

				}
			}
			n--;
			cout << "Iveskite egzamino ivertinima: "; cin >> a.egz;

			y++;
		}
		else if ((anw == "y") || (anw == "Y"))
		{
			using hrClock = std::chrono::high_resolution_clock;
			std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
			std::uniform_int_distribution<int> dist(1, 10);

			n = dist(mt);

			for (int i = 0; i < n; i++) {
				a.paz[i] == dist(mt);
			}

			a.egz = dist(mt);

			y++;
		}
		else
		{
			cout << "Suvesti ar atsitiktinai generuoti pazymius? [y/n] "; cin >> anw; //jei nebuvo irasyta suvesti/generuoti
		}
	} while (y == 0);

}
void galutinisvid(data& a, int& n) //su vidurkiu
{
	double vid = 0;
	int suma = 0;

	for (int i = 0; i < n; i++)
	{
		suma += a.paz[i];
	}

	vid = suma / (double)(n);

	a.vidrezult = 0.4 * vid + 0.6 * a.egz;
}
void galutinismed(data& a, int& n)//su mediana
{
	double med;
	sort(a.paz, a.paz + n);

	if (n % 2 != 0)
	{
		med = (double)a.paz[n / 2];
	}
	else
	{
		med = (double)(a.paz[(n - 1) / 2] + a.paz[n / 2]) / 2;
	}

	a.medrezult = 0.4 * med + 0.6 * a.egz;

}
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << " | " << setw(20) << a.pav << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}
bool rikiavimas(const data& a, 