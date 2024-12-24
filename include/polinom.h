#pragma once
#define MAX_POWER 9
#include "myList.h"


class polinom {
	myList<double> data;
	const int maxPower;
public:
	polinom();
	polinom(const polinom& p);
	polinom& operator=(const polinom& p);

};
