#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <list>
//
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
using std::to_string;
using std::list;

struct data
{
	string vard{}, pav{};
	int paz[20]{}, egz{};
	double vidrezult{}, medrezult{};
};

//---
void ivestis(data& a, int& n);
void galutinisvid(data& a, int& n);
//void galutinismed(data& a, int& n);
bool rikiavimas(const data& a, const data& b);
void rezultatai(data& a);
void fskaitymas(data& a, int& n, list<data>& sarasas, list<data>& kietiakai, list<data>& vargsiukai);
void firasimas(data& a, int& n, list<data>& sarasas);
bool mazvidurkis(const data& a);
void generacija(std::stringstream& my_buffer, int& n, int& s);

//---

const char CDfv[] = "kursiokai.txt";


class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};