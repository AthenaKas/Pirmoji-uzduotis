//Source-vektoriai MAIN
#include "header.h"


int main()
{
	Timer t;
	long long int N = 1;
	list<data> sarasas;
	list<data> vargsiukai;
	list<data> kietiakai;
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
				/*ivestis(laik, n);

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
				}*/
			}
			y++;
		}
		else if (Ranw == "1") //is failo skaitymas
		{
			fskaitymas(laik, n, sarasas, kietiakai, vargsiukai);

			//firasimas(laik, n, sarasas);
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
				
				Timer t1;
				
				sarasas.sort(rikiavimas);
				

				for (const auto& elem: sarasas)
				{

					if (elem.vidrezult < 5.0)
					{
						vargsiukai.push_back(elem);
					}
					else if (elem.vidrezult >= 5.0)
					{
						kietiakai.push_back(elem);
					}
				}
				cout << "Studentu isskirstymas i du list'us: " << t1.elapsed() << " s" << endl;
				vargsiukai.clear();
				//--

				Timer t1v;
				vargsiukai = sarasas; sarasas.erase(sarasas.begin()); vargsiukai.erase(vargsiukai.begin());
				sarasas.erase(std::remove_if(sarasas.begin(), sarasas.end(), mazvidurkis), sarasas.end());
				vargsiukai.erase(std::remove_if(vargsiukai.begin(), vargsiukai.end(), [](const data& a) {return a.vidrezult >= 5.0; }), vargsiukai.end());
				cout << "Studentu isskirstymas i viena vargsiuku list'a: " << t1v.elapsed() << " s" << endl;
			
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

			std::ofstream out_s("kietiakiai.txt");
			out_s << std::left << setw(20) << "Vardas" << "| ";
			out_s << setw(20) << "Pavarde" << " | ";
			out_s << setw(20) << "Galutinis (Vid.)" << endl;
			out_s << "-----------------------------------------------------------------------------------------------------";

			Timer t3;
			for (const auto& elem : vargsiukai)
			{
				
			
					out_f << setw(20) << elem.vard << " | " << setw(20) << elem.pav << " | ";

					out_f << setw(20) << setprecision(2) << fixed << elem.vidrezult << " | ";

				

			}
			for (const auto& elem : kietiakai)
			{
				
				
					out_k << setw(20) << elem.vard << " | " << setw(20) << elem.pav << " | ";

					out_k << setw(20) << setprecision(2) << fixed << elem.vidrezult << " | ";
				
				

			}
			for (const auto& elem : sarasas)
			{


				out_s << setw(20) << elem.vard << " | " << setw(20) << elem.pav << " | ";

				out_s << setw(20) << setprecision(2) << fixed << elem.vidrezult << " | ";



			}
			out_s.close();
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
		//sort(sarasas.begin(), sarasas.end(), rikiavimas);
		cout << setw(20) << "Vardas" << " | ";
		cout << setw(20) << "Pavarde" << " | ";
		cout << setw(20) << "Galutinis (Vid.)" << " | ";
		cout << setw(20) << "Galutinis (Med.)" << endl;
		cout << setw(23) << " | " << setw(23) << " | " << setw(23) << " | " << endl;

		for (int i = 0; i < sarasas.size(); i++)
		{
			//rezultatai(sarasas[i]);
		}
	}

		sarasas.clear();
		vargsiukai.clear();
		kietiakai.clear();

		cout << "Visos programos veikimas " << t.elapsed() << " s" << endl;
}
