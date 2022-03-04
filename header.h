#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::fixed;
using std::sort;
using std::vector;
using std::ifstream;



struct data
{
	string vard{}, pav{};
	int paz[20]{}, egz{};
	double vidrezult{}, medrezult{};
};

//---
void ivestis(data& a, int& n);
void galutinisvid(data& a, int& n);
void galutinismed(data& a, int& n);
bool rikiavimas(const data& a, const data& b);
void rezultatai(data& a);
//---

const char CDfv[] = "kursiokai.txt";

