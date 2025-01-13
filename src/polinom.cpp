#include "polinom.h"
#include "parser.h"
#include <string>

polinom::polinom() : maxPower(MAX_POWER), data() {}

polinom::polinom(const myList<std::pair<int, double>, cmpMonom<double>>& l) : maxPower(MAX_POWER), data(l) {}

polinom::polinom(const polinom& p) : maxPower(MAX_POWER), data(p.data) {}

polinom::polinom(polinom&& p) : maxPower(MAX_POWER), data(p.data) {}

polinom& polinom::operator=(const polinom& p) {
	data = p.data;
	return *this;
}

polinom& polinom::operator=(polinom&& p) {
	data = p.data;
	return *this;
}

polinom& polinom::operator+(const polinom& p) {
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


	data = newData;
	return *this;
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
//	p = polinom() + p;

	return s;
}
