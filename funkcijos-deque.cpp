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
void fskaitymas(data&a, int& n, deque<data>& sarasas, deque<data>& kietiakai, deque<data>& vargsiukai)
{
	//----------------------------------------------------------------------
	int r;
	cout << "Iveskite failo pavadinima: " << endl; cin >> r;
	string file = to_string(r) + ".txt";
	std::ifstream open_f(file);

	string anwf;
	string anwn;
	int m = 0;
	int z = 0;
	//int kiek = 0;
	Timer t2;
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

				std::getline(open_f, a.vard, ' ');
				std::getline(open_f, a.pav, ' ');

				for (int i = 0; i < m; i++)
				{
					open_f >> a.paz[i];
				}
				open_f >> a.egz;

				galutinisvid(a, m);

				sarasas.push_back(a);
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
		cout << "Studentu isskirstymas i du deque's: " << t1.elapsed() << " s" << endl;
		vargsiukai.clear();
		//---
		Timer t1v;
		vargsiukai = sarasas; sarasas.erase(sarasas.begin()); vargsiukai.erase(vargsiukai.begin());
		sarasas.erase(std::remove_if(sarasas.begin(), sarasas.end(), mazvidurkis), sarasas.end());
		vargsiukai.erase(std::remove_if(vargsiukai.begin(), vargsiukai.end(), [](const data& a) {return a.vidrezult >= 5.0; }), vargsiukai.end());
		

		cout << "Studentu isskirstymas i viena vargsiuku deque: " << t1v.elapsed() << " s" << endl;

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

		std::ofstream out_s("sarasas.txt");
		out_s << std::left << setw(20) << "Vardas" << "| ";
		out_s << setw(20) << "Pavarde" << " | ";
		out_s << setw(20) << "Galutinis (Vid.)" << endl;
		out_s << "-----------------------------------------------------------------------------------------------------";

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
		for (int i = 1; i < sarasas.size(); i++)
		{

			out_s << setw(20) << sarasas[i].vard << " | " << setw(20) << sarasas[i].pav << " | ";

			out_s << setw(20) << setprecision(2) << fixed << sarasas[i].vidrezult << " | ";

		}
		out_k.close();
		out_f.close();
		out_s.close();
		cout << "Studentu isvedimas i du naujus failus: " << t3.elapsed() << " s" << endl;

	//string tittle; //zodzio string
	//while (tittle != "Egz.") {
	//	open_f >> tittle;
	//	if (tittle == "Egz.") break;
	//	else if (tittle.substr(0, 2) == "ND") {
	//		n++;
	//	}
	//}
	//while (open_f) {
	//	if (!open_f.eof()) {

	//		std::getline(open_f, a.vard, ' ');
	//		std::getline(open_f, a.pav, ' ');

	//		for (int i = 0; i < n; i++)
	//		{
	//			open_f >> a.paz[i];
	//		}
	//		open_f >> a.egz;

	//		galutinisvid(a, n);

	//		galutinismed(a, n);

	//		sarasas.push_back(a);


	//	}
	//	else break;
	//}

	//open_f.close();

	//sort(sarasas.begin(), sarasas.end(), rikiavimas);
}
bool mazvidurkis(const data& a) { return a.vidrezult < 5.0; }
void firasimas(data& a, int& n, deque<data>& sarasas)
{
	std::ofstream out_f("kursiokai_cop.txt");

	out_f << std::left << setw(20) << "Vardas" << "| ";
	out_f << setw(20) << "Pavarde" << " | ";
	out_f << setw(20) << "Galutinis (Vid.)" << " | ";
	out_f << setw(20) << "Galutinis (Med.)" << endl;
	out_f << "-----------------------------------------------------------------------------------------------------";

	for (int i = 0; i < sarasas.size(); i++) //ispauzdinimas i faila
	{
		out_f << setw(20) << sarasas[i].vard << " | " << setw(20) << sarasas[i].pav << " | ";

		out_f << setw(20) << setprecision(2) << fixed << sarasas[i].vidrezult << " | ";

		out_f << setw(20) << setprecision(2) << fixed << sarasas[i].medrezult;
	}
	out_f.close();

}
void generacija(std::stringstream& my_buffer, int& n, int &s) //n - studentai, s - paz
{

	//---
	using hrClock = std::chrono::high_resolution_clock;
	std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);
	//---
	
	string var = "Vardas", pav = "Pavarde";
	string nd = "ND", egz = "Egz.";
	
	Timer t1;
	
		my_buffer << var << " " << pav << " ";
		for (int j = 0; j < s; j++)
		{
			my_buffer << nd << j + 1 << " ";
		}
		my_buffer << egz << endl;
		

		for (int k = 0; k < n; k++)
		{
			my_buffer << var << k + 1 << " " << pav << k + 1 << " ";
			for (int j = 0; j < s; j++) my_buffer << dist(mt) << " "; //pazymiai
			my_buffer << dist(mt) << endl; //egz paz;
		}
		string file = to_string(n) + ".txt";
		std::ofstream out_f(file);
		out_f << my_buffer.str();
		out_f.close();
		cout << n << " Failo kurimas ir jo uzdarimas " << t1.elapsed() << " s" << endl;
		my_buffer.clear();
}