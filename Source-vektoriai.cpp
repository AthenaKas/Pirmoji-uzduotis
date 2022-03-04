//Source-vektoriai MAIN
#include "header.h"


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
