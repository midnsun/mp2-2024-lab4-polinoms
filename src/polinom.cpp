#include "polinom.h"
#include "parser.h"
#include <string>

polinom::polinom() : maxPower(MAX_POWER), data() {}

polinom::polinom(const myList<std::pair<int, double>, cmpMonom<double>>& l) : maxPower(MAX_POWER), data(l) {}

polinom::polinom(const polinom& p) : maxPower(MAX_POWER), data(p.data) {}

polinom::polinom(polinom&& p) : maxPower(MAX_POWER), data(p.data) {}

int polinom::getDegX() {
	return data.value().first / (maxPower * maxPower);
}

int polinom::getDegY() {
	return (data.value().first % (maxPower * maxPower)) / maxPower;
}

int polinom::getDegZ() {
	return data.value().first % maxPower;
}

polinom& polinom::operator=(const polinom& p) {
	data = p.data;
	return *this;
}

polinom& polinom::operator=(polinom&& p) {
	data = p.data;
	return *this;
}

polinom polinom::operator+(const polinom& p) {
	myList<std::pair<int, double>, cmpMonom<double>> l = p.data;
	l.toBegin();
	while (!l.isEnd()) {
		data.append(l.value());
		l.next();
	}
	data.toBegin();
	l.toBegin();

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

	polinom res(newData);
	return res;
}

std::ostream& operator<<(std::ostream& s, const polinom& p) {
	myList<std::pair<int, double>, cmpMonom<double>> l = p.data;
	if (p.data.isEmpty()) s << "0";
	while (!l.isEnd()) {
		s << l.value().second << " * ";
		s << "x" << l.value().first / (p.maxPower * p.maxPower) << " ";
		s << "y" << (l.value().first % (p.maxPower * p.maxPower)) / p.maxPower << " ";
		s << "z" << l.value().first % p.maxPower << " ";
		l.next();
	}
	return s;
}

std::istream& operator>>(std::istream& s, polinom& p) { // format is: +- <number> * x<degx> y<degy> z<degz>
	std::string str;
	std::string tmp = "";
	myList<std::pair<int, double>, cmpMonom<double>> l;
	std::pair<int, double> monom;
	monom.first = 0;
	std::getline(s, str);
	auto it = str.begin();

	while (it != str.end() && *it != ' ') {
		tmp += *it;
		++it;
	}
	try {
		monom.second = parser(tmp);
	}
	catch (std::exception&) {
		throw std::exception("bad input");
	}
	tmp = "";
	if (it != str.end() && *it == ' ') ++it;
	else throw std::exception("bad input");
	if (it != str.end() && *it == '*') ++it;
	else throw std::exception("bad input");
	if (it != str.end() && *it == ' ') ++it;
	else throw std::exception("bad input");

	if (it != str.end() && *it == 'x') ++it;
	else throw std::exception("bad input");
	while (it != str.end() && *it != ' ') {
		tmp += *it;
		++it;
	}
	monom.first += std::stoi(tmp) * p.maxPower * p.maxPower;
	tmp = "";
	if (it != str.end() && *it == ' ') ++it;
	else throw std::exception("bad input");

	if (it != str.end() && *it == 'y') ++it;
	else throw std::exception("bad input");
	while (it != str.end() && *it != ' ') {
		tmp += *it;
		++it;
	}
	monom.first += std::stoi(tmp) * p.maxPower;
	tmp = "";
	if (it != str.end() && *it == ' ') ++it;
	else throw std::exception("bad input");

	if (it != str.end() && *it == 'z') ++it;
	else throw std::exception("bad input");
	while (it != str.end() && *it != ' ') {
		tmp += *it;
		++it;
	}
	monom.first += std::stoi(tmp);
	tmp = "";
	if (it != str.end() && *it == ' ') ++it;
	l.append(monom);

	double sign;
	while (it != str.end()) {
		if (*it == '+') {
			sign = 1.0;
			++it;
		}
		else if (*it == '-') {
			sign = -1.0;
			++it;
		}
		else throw std::exception("bad input");

		if (it != str.end() && *it == ' ') ++it;
		else throw std::exception("bad input");

		while (it != str.end() && *it != ' ') {
			tmp += *it;
			++it;
		}
		try {
			monom.second = parser(tmp) * sign;
		}
		catch (std::exception&) {
			throw std::exception("bad input");
		}
		tmp = "";
		if (it != str.end() && *it == ' ') ++it;
		else throw std::exception("bad input");
		if (it != str.end() && *it == '*') ++it;
		else throw std::exception("bad input");
		if (it != str.end() && *it == ' ') ++it;
		else throw std::exception("bad input");

		if (it != str.end() && *it == 'x') ++it;
		else throw std::exception("bad input");
		while (it != str.end() && *it != ' ') {
			tmp += *it;
			++it;
		}
		monom.first += std::stoi(tmp) * p.maxPower * p.maxPower;
		tmp = "";
		if (it != str.end() && *it == ' ') ++it;
		else throw std::exception("bad input");

		if (it != str.end() && *it == 'y') ++it;
		else throw std::exception("bad input");
		while (it != str.end() && *it != ' ') {
			tmp += *it;
			++it;
		}
		monom.first += std::stoi(tmp) * p.maxPower;
		tmp = "";
		if (it != str.end() && *it == ' ') ++it;
		else throw std::exception("bad input");

		if (it != str.end() && *it == 'z') ++it;
		else throw std::exception("bad input");
		while (it != str.end() && *it != ' ') {
			tmp += *it;
			++it;
		}
		monom.first += std::stoi(tmp);
		tmp = "";
		l.append(monom);
		if (it != str.end() && *it == ' ') ++it;
	}

	l.mergeSort();

	p = polinom(l);
	p = p + polinom();

	return s;
}

polinom polinom::operator*(const double& v) {
	polinom res = *this;
	res.data.toBegin();

	while (!data.isEnd()) {
		res.data.value().second *= v;
		res.data.next();
	}

	res.data.toBegin();
	return res;
}

polinom operator* (const double& v, const polinom& p) {
	polinom res = p;
	res.data.toBegin();

	while (!res.data.isEnd()) {
		res.data.value().second *= v;
		res.data.next();
	}

	res.data.toBegin();
	return res;
}

polinom polinom::operator*(const polinom& p) {
	polinom res;
	polinom mutableP = p;
	polinom tmp;
	std::pair<int, double> monom;
	mutableP.data.toBegin();
	
	while (!mutableP.data.isEnd()) {
		tmp = *this;

		tmp.data.toBegin();
		while (!tmp.data.isEnd()) {
			tmp.data.value().second = tmp.data.value().second * mutableP.data.value().second;
			if (tmp.getDegX() + mutableP.getDegX() >= 10) throw std::exception("Degree over X is too big");
			if (tmp.getDegY() + mutableP.getDegY() >= 10) throw std::exception("Degree over Y is too big");
			if (tmp.getDegZ() + mutableP.getDegZ() >= 10) throw std::exception("Degree over Z is too big");
			tmp.data.value().first = tmp.data.value().first + mutableP.data.value().first;
			tmp.data.next();
		}

		res = res + tmp;
		mutableP.data.next();
	}

	return res;
}

double polinom::calculate(const double& x, const double& y, const double& z) {
	double res = 0.0;
	data.toBegin();

	while (!data.isEnd()) {
		res += data.value().second
			* pow(x, getDegX())
			* pow(y, getDegY())
			* pow(z, getDegZ());
		data.next();
	}
	data.toBegin();

	return res;
}
