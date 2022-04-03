#include "header.h"
#include "Hvid_med.h"

void galutinisvid(data& a, int& n) //su vidurkiu
{
	vid = 0;
	suma = 0;

	for (int i = 0; i < n; i++)
	{
		suma += a.paz[i];
	}

	vid = suma / (double)(n);

	a.vidrezult = 0.4 * vid + 0.6 * a.egz;
}