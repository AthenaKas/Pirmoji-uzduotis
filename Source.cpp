#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::fixed;

struct data
{
	string vard{}, pav{};
	int paz[10]{}, egz{}; //n{}; //n - pazymiu kiekis
	double vidrezult{}, medrezult{};

};

//---
void ivestis(data& a, int& n);
void galutinisvid(data& a, int& n);
void galutinismed(data& a, int& n);
void rezultatai(data& a);
//---

int main()
{
	data* mas;
	mas = new data[1];
	string anw;
	int n = 1; //kiekis pazymiu
	
	for (data* A = mas; A < mas + 1; A++)
	{
		ivestis(*A, n);
		cout << "Ar norite ivesti dar vieno studento duomenis: "; cin >> anw;
		if (anw != "yes") break;

	}

	for (data* A = mas; A < mas + 1; A++)
	{
		galutinisvid(*A, n);
	}

	for (data* A = mas; A < mas + 1; A++)
	{
		galutinismed(*A, n);
	}

	cout << setw(20) << "Vardas";
	cout << setw(20) << "Pavarde";
	cout << setw(20) << "Galutinis (Vid.)";
	cout << setw(20) << "Galutinis (Med.)" << endl;
	cout << endl;
	for (data* A = mas; A < mas + 1; A++)
	{
		rezultatai(*A);
	}
	
	delete[] mas;
}

void ivestis(data& a, int& n)
{
	string anw;
	cout << "Iveskite varda: "; cin >> a.vard;
	cout << "Iveskite pavarde: "; cin >> a.pav;

	//cout << "Iveskite kiek pazymiu turi studentas: ";  cin >> a.n;
	cout << "Iveskite iki 10 pazymiu, kai nusprendziate, kad pazymiu uztenka rasykite 0 " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Iveskite " << i + 1 << " pazymi: ";
		cin >> a.paz[i];
		if (a.paz[i] == 0)
		{
			break;
		}
		else {
			n++;
		}
	}
	n--;

	cout << "Iveskite egzamino ivertinima: "; cin >> a.egz;

}

void galutinisvid(data& a, int& n) //su vidurkiu
{
	double vid = 0;
	int suma = 0;

	for (int i = 0; i < n; i++)
	{
		suma += a.paz[i];
	}

	vid = suma / (double)n;

	a.vidrezult = 0.4 * vid + 0.6 * a.egz;
}

void galutinismed(data& a, int& n)//su mediana
{
	double med;

	if (n % 2 != 0)
	{
		med = a.paz[n / 2];
	}
	else
	{
		med = (double)(a.paz[n / 2] + a.paz[(n / 2) - 1]) / 2;
	}

	a.medrezult = 0.4 * med + 0.6 * a.egz;

}
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << setw(20) << a.pav;

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult;

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}