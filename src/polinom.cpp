#include "polinom.h"

polinom::polinom() : maxPower(MAX_POWER), data() {}

polinom::polinom(const polinom& p) : maxPower(MAX_POWER), data(p.data) {}

polinom::polinom(polinom&& p) : maxPower(MAX_POWER), data(p.data) {}

polinom& polinom::operator=(const polinom& p) {
	data = p.data;
}

polinom& polinom::operator=(polinom&& p) {
	data = p.data;
}

polinom& polinom::operator+(const polinom& p) {
	p.data.toBegin();
	while (!p.data.isEnd()) {
		data.append(p.data.value());
		p.data.next();
	}
	data.toBegin();
	p.data.toBegin();

	data.mergeSort();
	if (data.isEmpty()) return *this;
	myList<std::pair<int, double>, cmpMonom<double>> newData(data.value());
	double maxValue, eps;
	maxValue = abs(data.value().second);
	data.next();

	while (!data.isEnd()) {
		if (newData.value().first == data.value().first) {
			newData.value().second += data.value().second;
		}
		else {
			newData.append(data.value());
		}
		maxValue = abs(data.value().second) > maxValue ? abs(data.value().second) : maxValue;
		data.next();
	}
	data.toBegin();
	newData.toBegin();
	eps = maxValue * 1.0e-15;

	while (!newData.isEnd()) {
		if (abs(newData.value().second) < eps) newData.del();
		newData.next();

	}
	newData.toBegin();


	data = newData;
	return *this;
}
