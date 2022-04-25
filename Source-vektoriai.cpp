//Source-vektoriai MAIN
#include "header.h"


int main()
{
	Timer t;
	long long int N = 1;
	vector<data> sarasas;
	vector<data> vargsiukai;
	vector<data> kietiakai;
	vector<data> mokinys[100];
	data laik;
	string anw; // ats: apie dar vieno studento duomenu vedima
	string Ranw; //ats: duomenu gavimo pasirinkimas
	int n = 0; //kiekis pazymiu
	int y = 0; //ar nuskaityti duomenis loop
	int k = 0; //failo studentu kiekis
	int p, s;
	std::stringstream my_buffer;


	cout << "Ar nuskaityti studentu duomenys is failo ? [1]" << endl;
	cout << "Ar norite ivesti studentu duomenis rankiniu budu? [2]" << endl;
	cout << "Ar norite sugeneruoti studentu duomenu faila? [3] " << endl; 
	cin >> Ranw;

	
	ifstream fd(CDfv);

	if(Ranw == "1")
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
		if (Ranw == "2") //rankinis budas
		{
			for (int i = 0; i < N; i++)
			{
				ivestis(laik, n);

				galutinisvid(laik, n);

				galutinismed(laik, n);

				sarasas.push_back(laik);

				cout << "Ar norite ivesti dar vieno studento duomenis? [y/n] "; cin >> anw;
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
		else if (Ranw == "1") //is failo skaitymas
		{
			fskaitymas(laik, n, sarasas, kietiakai, vargsiukai);

			firasimas(laik, n, sarasas);
				y++;
		}
		else if (Ranw == "3") //failo generacija
		{
			cout << "Po kiek pazymiu tures studentai? "; cin >> p;
			cout << "Kiek studentu bus? "; cin >> s;
			generacija(my_buffer, s, p);
			

			y++;
		}
		else
		{
			cout << "Ar nuskaityti studentu duomenys is failo ? [1]" << endl;
			cout << "Ar norite ivesti studentu duomenis rankiniu budu? [2]" << endl;
			cout << "Ar norite sugeneruoti studentu duomenu faila? [3] " << endl;
			cin >> Ranw;
		}
	} while (y == 0);

	if (Ranw == "3")
	{
		
		string anwf;
		string anwn;
		int m = 0;
		int z = 0;
		

		cout << "Ar norite nuskaityti sugeneruota faila? [y/n] "; cin >> anwn;
		if (anwn == "y")
		{
				string file = to_string(s) + ".txt";
				Timer t2;

				std::ifstream open_f(file);
				string tittle; //zodzio string
				while (tittle != "Egz.") {
					open_f >> tittle;
					if (tittle == "Egz.") break;
					else if (tittle.substr(0, 2) == "ND") {
						m++;
					}
				}

				while (open_f) {
					if (!open_f.eof()) {

						std::getline(open_f, laik.vard, ' ');
						std::getline(open_f, laik.pav, ' ');

						for (int i = 0; i < m; i++)
						{
							open_f >> laik.paz[i];
						}
						open_f >> laik.egz;

						galutinisvid(laik, m);

						sarasas.push_back(laik);
						z++;


					}
					else break;
				}

				open_f.close();
				cout << "Duomenu nuskaitymas is failo ir galutinio pazymio suskaiciavimas: " << t2.elapsed() << " s" << endl;
				//cout << z << endl;

				sort(sarasas.begin(), sarasas.end(), rikiavimas);

				Timer t1;
				for (int i = 0; i < sarasas.size() - 1; i++)
				{

					if (sarasas[i].vidrezult < 5.0)
					{
						vargsiukai.push_back(sarasas[i]);
					}
					else if (sarasas[i].vidrezult >= 5.0)
					{
						kietiakai.push_back(sarasas[i]);
					}
				}
				cout << "Studentu isskirstymas i du vektorius: " << t1.elapsed() << " s" << endl;
				
				//---
			/*	Timer t1v;

				vector<data> ::iterator it; it = sarasas.begin(); sarasas.erase(it);
				int x = 0;
				it = sarasas.begin() + x;
				for (int i = 0; i < sarasas.size(); i++)
				{

					if (it->vidrezult < 5.0)
					{
						it = sarasas.begin() + x;
						vargsiukai.push_back(*it);
						sarasas.erase(it);
						x--;
					}x++;

				}
				cout << "Studentu isskirstymas i viena vargsiuku vektoriu: " << t1v.elapsed() << " s" << endl;*/
			
			//------------------------------------------------------------------------
			std::ofstream out_f("vargsiukai.txt");
			out_f << std::left << setw(20) << "Vardas" << "| ";
			out_f << setw(20) << "Pavarde" << " | ";
			out_f << setw(20) << "Galutinis (Vid.)" << endl;
			out_f << "-----------------------------------------------------------------------------------------------------";

			std::ofstream out_k("kietiakiai.txt");
			out_k << std::left << setw(20) << "Vardas" << "| ";
			out_k << setw(20) << "Pavarde" << " | ";
			out_k << setw(20) << "Galutinis (Vid.)" << endl;
			out_k << "-----------------------------------------------------------------------------------------------------";

	

			Timer t3;
			for (int i = 1; i < vargsiukai.size(); i++)
			{
					out_f << setw(20) << vargsiukai[i].vard << " | " << setw(20) << vargsiukai[i].pav << " | ";

					out_f << setw(20) << setprecision(2) << fixed << vargsiukai[i].vidrezult << " | ";

			}
			for (int i = 1; i < kietiakai.size(); i++)
			{

				out_k << setw(20) << kietiakai[i].vard << " | " << setw(20) << kietiakai[i].pav << " | ";

				out_k << setw(20) << setprecision(2) << fixed << kietiakai[i].vidrezult << " | ";

			}
	
			
			out_k.close();
			out_f.close();
			
			cout << "Studentu isvedimas i du naujus failus: " << t3.elapsed() << " s" << endl;
			
		}
		else
		{
			return 0;
		}
		
	}

	

	if (Ranw == "2") //isvedimas rankinio budo
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
		vargsiukai.clear();
		kietiakai.clear();

		cout << "Visos programos veikimas " << t.elapsed() << " s" << endl;
}
