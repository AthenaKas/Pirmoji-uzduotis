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
	int N = 1;
	data* mas;
	mas = new data[N];
	data* tempmas;
	string anw;
	int n = 1; //kiekis pazymiu
	
	for (int i = 0; i < N; i++)
	{
		ivestis(mas[i], n);
		cout << "Ar norite ivesti dar vieno studento duomenis: [yes/no] "; cin >> anw;
		if (anw != "yes")
		{
			break;
		}
		else if (anw == "yes")
		{
			tempmas = new data[N+1];
			for (int i = 0; i < N; i++)
			{
				tempmas[i] = mas[i];
			}
			delete[] mas;
			N++;
			mas = new data[N];
			for (int i = 0; i < N; i++)
			{
				mas[i] = tempmas[i];
			}
			delete[] tempmas;
		}
	}

	for (data* A = mas; A < mas + N; A++)
	{
		galutinisvid(*A, n);
	}

	for (data* A = mas; A < mas + N; A++)
	{
		galutinismed(*A, n);
	}

	cout << setw(20) << "Vardas";
	cout << setw(20) << "Pavarde";
	cout << setw(20) << "Galutinis (Vid.) /";
	cout << setw(20) << "Galutinis (Med.)" << endl;
	cout << endl;
	for (data* A = mas; A < mas + N; A++)
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