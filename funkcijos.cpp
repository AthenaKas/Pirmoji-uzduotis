#include "header.h"

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
void rikiavimas(data& a, int n, vector<data>& sarasas, int N)
{
	string tempvard = sarasas[0].vard;
	string temppav = sarasas[0].pav;
	double tempvid = sarasas[0].vidrezult;
	double tempmed = sarasas[0].medrezult;
	N = 3;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sarasas[i].vard <= tempvard)
			{
				tempvard = sarasas[i].vard;
				sarasas[i].vard = sarasas[j].vard;
				sarasas[j].vard = tempvard;

				temppav = sarasas[i].pav;
				sarasas[i].pav = sarasas[j].pav;
				sarasas[j].pav = temppav;

				tempvid = sarasas[i].vidrezult;
				sarasas[i].vidrezult = sarasas[j].vidrezult;
				sarasas[j].vidrezult = tempvid;

				tempmed = sarasas[i].medrezult;
				sarasas[i].medrezult = sarasas[j].medrezult;
				sarasas[j].medrezult = tempmed;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sarasas[i].vard == sarasas[j].vard)
			{
				if (sarasas[i].pav < sarasas[j].pav)
				{
					tempvard = sarasas[i].vard;
					sarasas[i].vard = sarasas[j].vard;
					sarasas[j].vard = tempvard;

					temppav = sarasas[i].pav;
					sarasas[i].pav = sarasas[j].pav;
					sarasas[j].pav = temppav;

					tempvid = sarasas[i].vidrezult;
					sarasas[i].vidrezult = sarasas[j].vidrezult;
					sarasas[j].vidrezult = tempvid;

					tempmed = sarasas[i].medrezult;
					sarasas[i].medrezult = sarasas[j].medrezult;
					sarasas[j].medrezult = tempmed;
				}
			}
		}
	}

} //vardu
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << " | " << setw(20) << a.pav << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}