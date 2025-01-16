#pragma once
#define MAX_POWER 10
#include "myList.h"
#include <iostream>

template<typename D>
struct cmpMonom
{
	bool operator()(std::pair<int, D> lhs, std::pair<int, D> rhs) { return lhs.first < rhs.first; }
};

class polinom {
	myList<std::pair<int, double>, cmpMonom<double>> data;
	const int maxPower;
	int getDegX();
	int getDegY();
	int getDegZ();
public:
	polinom();
	polinom(const myList<std::pair<int, double>, cmpMonom<double>>& l);
	polinom(const polinom& p);
	polinom(polinom&& p);
	polinom& operator=(const polinom& p);
	polinom& operator=(polinom&& p);

	polinom operator+ (const polinom& p);
	polinom operator* (const double& v);
	friend polinom operator* (const double& v, const polinom& p);
	polinom operator* (const polinom& p);
	double calculate(const double& x, const double& y, const double& z);

	friend std::ostream& operator<< (std::ostream& s, const polinom& p);
	friend std::istream& operator>> (std::istream& s, polinom& p);

};

polinom operator* (const double& v, const polinom& p);
