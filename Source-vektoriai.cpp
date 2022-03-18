//Source-vektoriai MAIN
#include "header.h"


int main()
{
	int N = 1;
	vector<data> sarasas;
	data laik;
	string anw; // ats: apie dar vieno studento duomenu vedima
	string Ranw; //ats: duomenu gavimo pasirinkimas
	int n = 0; //kiekis pazymiu
	int y = 0; //ar nuskaityti duomenis loop
	int k = 0; //failo studentu kiekis
	int p, s;


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
				out_f << "-----------------------------------------------------------------------------------------------------";

				for (const auto& el : sarasas) //ispauzdinimas i faila
				{
					out_f << setw(20)<< el.vard << " | " << setw(20) << el.pav << " | ";
	
					out_f << setw(20) << setprecision(2) << fixed << el.vidrezult << " | ";

					out_f << setw(20) << setprecision(2) << fixed << el.medrezult;
				}
				out_f.close();

				y++;
		}
		else if (Ranw == "3") //failo generacija
		{
			//---
			using hrClock = std::chrono::high_resolution_clock;
			std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
			std::uniform_int_distribution<int> dist(1, 10);
			//---
			std::stringstream my_buffer;
			//int p, s;
			string var = "Vardas", pav = "Pavarde";
			string nd = "ND", egz = "Egz.";

			cout << "Kiek pazymiu tures studentas? "; cin >> p;
			cout << "Kiek studentu bus? "; cin >> s;

			my_buffer << var << " " << pav << " ";
			for (int i = 0; i < p; i++)
			{
				my_buffer << nd << i + 1<<" ";
			}
			my_buffer << egz << endl;

			for (long long int i = 0; i < s; i++)
			{
				my_buffer << var <<i+1<< " " << pav <<i+1<<" ";
				for (int j = 0; j < p; j++) my_buffer << dist(mt) <<" "; //pazymiai
				my_buffer << dist(mt) << endl; //egz paz;
			}

			std::ofstream out_f("sugeneruotas.txt");
			out_f << my_buffer.str();
			out_f.close();
			my_buffer.clear();
			
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

		std::ifstream open_f("sugeneruotas.txt");
	
		string tittle; //zodzio string
		while (tittle != "Egz.") {
			open_f >> tittle;
			if (tittle == "Egz.") break;
			else if (tittle.substr(0, 2) == "ND") {
				n++;
			}
		}

		cout << n << endl;
			
		        
		while (open_f) {
			if (!open_f.eof()) {

				std::getline(open_f, laik.vard, ' ');
				std::getline(open_f, laik.pav, ' ');

				for (int i = 0; i < p; i++)
				{
					open_f >> laik.paz[i];
				}
				open_f >> laik.egz;

				galutinisvid(laik, n);

				galutinismed(laik, n);

				sarasas.push_back(laik);

			}
			else break;
		}
		
		open_f.close();

		sort(sarasas.begin(), sarasas.end(), rikiavimas);
		//------------------------------------------------------------------------
		std::ofstream out_f("sugeneruotas_cop.txt");

		out_f << std::left << setw(20) << "Vardas" << "| ";
		out_f << setw(20) << "Pavarde" << " | ";
		out_f << setw(20) << "Galutinis (Vid.)" << " | ";
		out_f << setw(20) << "Galutinis (Med.)" << endl;
		out_f << "-----------------------------------------------------------------------------------------------------";
		for (int i = 1; i < sarasas.size(); i++)
		{
			out_f << setw(20) << sarasas[i].vard << " | " << setw(20) << sarasas[i].pav << " | ";

			out_f << setw(20) << setprecision(2) << fixed << sarasas[i].vidrezult << " | ";

			out_f << setw(20) << setprecision(2) << fixed << sarasas[i].medrezult;
		}
		out_f.close();
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
}
