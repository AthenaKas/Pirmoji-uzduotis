//Source-vektoriai MAIN

#include "header.h"

//---
void ivestis(data& a, int& n);
void galutinisvid(data& a, int& n);
void galutinismed(data& a, int& n);
void rikiavimas(data& a, int n, vector<data>& sarasas, int N);
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

	cout << "Ar nuskaityti studentu duomenys is failo? [y/n] "; cin >> anw2;
	
	ifstream fd(CDfv);

	if((anw2 == "y")||( anw2 == "Y"))
	{
		
		try {
			if (fd)
			{

			}
			else
			{
				throw 505;
			}
		}
		catch (...)//tikrina ar yra failas
		{
			cout << "Sukurkite studentu duomenu faila";
			return 1;
		}
	}

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
			for (int i = 0; i < 10000; i++)
			{
				fd >> laik.vard >> laik.pav;
				for (int i = 0; i < 15; i++)
				{
					fd >> laik.paz[i];
				}
				fd >> laik.egz;
				n = 15;

				galutinisvid(laik, n);

				galutinismed(laik, n);

				sarasas.push_back(laik);

				N++;
				sarasas.reserve(N);

				y++;
			}
		}
		else
		{
			cout << "Ar nuskaityti studentu duomenys is failo? [y/n] "; cin >> anw2;
		}
	} while (y == 0);

	//rikiavimas(laik, n, sarasas, N);
	
		cout << setw(20) << "Vardas"<< " | ";
		cout << setw(20) << "Pavarde" << " | ";
		cout << setw(20) << "Galutinis (Vid.)" << " | ";
		cout << setw(20) << "Galutinis (Med.)" << endl;
		cout << setw(23)<<" | "<< setw(23)<<" | "<< setw(23)<<" | " << endl;

		for (int i = 0; i < sarasas.size(); i++)
		{
			rezultatai(sarasas[i]);
		}

		sarasas.clear();
}
