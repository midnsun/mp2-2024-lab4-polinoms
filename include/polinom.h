#pragma once
#define MAX_POWER 9
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
public:
	polinom();
	polinom(const polinom& p);
	polinom(polinom&& p);
	polinom& operator=(const polinom& p);
	polinom& operator=(polinom&& p);

	polinom& operator+ (const polinom& p);
	polinom& operator* (const double& v);
	polinom& operator* (const polinom& p);
	const double& calculate(const double& v);

	friend std::ostream& operator<< (std::ostream& s, const polinom& p);
	friend std::istream& operator>> (std::istream& s, const polinom& p);

};

polinom& operator* (const double& v, const polinom& p);
