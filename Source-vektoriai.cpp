#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <fstream>

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
	int paz[5]{}, egz{};
	double vidrezult{}, medrezult{};
};

//---
void ivestis(data& a, int& n);
void nuskaitymas(data& a, int & n);
void galutinisvid(data& a, int& n);
void galutinismed(data& a, int& n);
void rezultatai(data& a);
//---

const char CDfv[] = "kursiokai.txt";

int main()
{
	int N = 1;
	vector<data> sarasas;
	data laik;
	string anw; // ats: apie dar vieno studento duomenu vedima
	string anw2; //ats: ar skaityti is failo
	int n = 0; //kiekis pazymiu

	cout << "Ar nuskaityti studentu duomenys is failo? [y/n] "; cin >> anw2;

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
			else if (anw == "y")
			{
				N++;
				sarasas.reserve(N);
			}
		}
	}
	else if ((anw2 == "y") || (anw2 == "Y"))
	{	
		ifstream fd(CDfv);
		
		for (int i = 0; i < 2; i++)
		{
			//nuskaitymas(laik, n);

				fd >> laik.vard >> laik.pav;
				for (int i = 0; i < 5; i++)
				{
					fd >> laik.paz[i];
					cout << laik.paz[i] << endl;;
				}
				fd >> laik.egz;
				n = 5;
			galutinisvid(laik, n);

			galutinismed(laik, n);

			sarasas.push_back(laik);
			N++;
			sarasas.reserve(N);

		}

	}

		cout << setw(20) << "Vardas";
		cout << setw(20) << "Pavarde";
		cout << setw(20) << "Galutinis (Vid.)";
		cout << setw(20) << "Galutinis (Med.)" << endl;
		cout << endl;
		for (int i = 0; i < sarasas.size(); i++)
		{
			rezultatai(sarasas[i]);
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

		if ((anw == "n")||(anw == "N"))
		{
			n = 1;
			cout << "Iveskite nuo 1 iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite: [s] " << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "Iveskite " << i + 1 << " pazymi: ";
				cin >> x;
				if ((x == 's')||(x == 'S'))//jei iveda [s]
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
		else if ((anw == "y")|| (anw =="Y"))
		{
			n = rand() % 10 + 1;

			srand(time(0));

			for (int i = 0; i < n; i++)
			{
				a.paz[i] = rand() % 10 + 1;
			}

			a.egz = rand() % 10 + 1;

			y++;
		}
		else
		{
			cout << "Suvesti ar atsitiktinai generuoti pazymius? [suvesti/generuoti] "; cin >> anw; //jei nebuvo irasyta suvesti/generuoti
		}
	} while (y == 0);




}
void nuskaitymas(data& a, int& n)
{
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
	cout << "MMEED " << med << endl;

	a.medrezult = 0.4 * med + 0.6 * a.egz;

}
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << setw(20) << a.pav;

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult;

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}
