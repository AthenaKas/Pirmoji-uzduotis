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

		if ((anw == "n") || (anw == "N")) //rankiniu budu ivedami pazymiai
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
		else if ((anw == "y") || (anw == "Y"))//generuoja atsitinktinai pazymiai
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
			cout << "Ar atsitiktinai generuoti pazymius? [y/n] "; cin >> anw;
		}
	} while (y == 0);

}
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << " | " << setw(20) << a.pav << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult << " | ";

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}
bool rikiavimas(const data& a, const data& b)
{
	return a.vard < b.vard;
}
void isvedimas(data& a)
{
	std::ofstream out_f("sugeneruotas_cop.txt");
	
		out_f << setw(20) << a.vard << " | " << setw(20) << a.pav << " | ";

		out_f << setw(20) << setprecision(2) << fixed << a.vidrezult << " | ";

		out_f << setw(20) << setprecision(2) << fixed << a.medrezult;
	
}