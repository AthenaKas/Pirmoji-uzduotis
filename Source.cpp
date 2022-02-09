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
	string vard, pav; 
	int paz[10], egz, n; //n - pazymiu kiekis
	double vidrezult, medrezult;

};

//---
void ivestis(data& a);
void galutinisvid(data& a);
void galutinismed(data& a);
void rezultatai(data& a);
//---

int main()
{
	data* mas;
	mas = new data[2];

	for (data* A = mas; A < mas + 2; A++)
	{
		ivestis(*A);
	}

	for (data* A = mas; A < mas + 2; A++)
	{
		galutinisvid(*A);
	}

	for (data* A = mas; A < mas + 2; A++)
	{
		galutinismed(*A);
	}

	cout << setw(20) << "Vardas";
	cout << setw(20) << "Pavarde";
	cout << setw(20) << "Galutinis (Vid.)";
	cout << setw(20) << "Galutinis (Med.)" << endl;
	cout << endl;
	for (data* A = mas; A < mas + 2; A++)
	{
		rezultatai(*A);
	}
	
	delete[] mas;
}

void ivestis(data& a)
{
	cout << "Iveskite varda: "; cin >> a.vard;
	cout << "Iveskite pavarde: "; cin >> a.pav;

	cout << "Iveskite kiek pazymiu turi studentas: ";  cin >> a.n;
	for (int i = 0; i < a.n; i++)
	{
		cout << "Iveskite " << i + 1 << " pazymi: ";
		cin >> a.paz[i];
	}

	cout << "Iveskite egzamino ivertinima: "; cin >> a.egz;
}

void galutinisvid(data& a) //su vidurkiu
{
	double vid = 0;
	int suma = 0;

	for (int i = 0; i < a.n; i++)
	{
		suma += a.paz[i];
	}

	vid = suma / (double)a.n;

	a.vidrezult = 0.4 * vid + 0.6 * a.egz;
}

void galutinismed(data& a)//su mediana
{
	double med;

	if (a.n % 2 != 0)
	{
		med = a.paz[a.n / 2];
	}
	else
	{
		med =(double)(a.paz[a.n / 2] + a.paz[(a.n / 2) - 1]) / 2;
	}

	a.medrezult = 0.4 * med + 0.6 * a.egz;

}
void rezultatai(data& a)
{
	cout << setw(20) << a.vard << setw(20) << a.pav;

	cout << setw(20) << setprecision(2) << fixed << a.vidrezult;

	cout << setw(20) << setprecision(2) << fixed << a.medrezult << endl;
}