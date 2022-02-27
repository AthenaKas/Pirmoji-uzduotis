#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <fstream>

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
	int paz[15]{}, egz{};
	double vidrezult{}, medrezult{};
};

const char CDfv[] = "kursiokai.txt";