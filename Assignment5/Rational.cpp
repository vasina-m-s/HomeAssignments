/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment5
*/

#include "Rational.h"
#include <stdexcept>
#include <numeric>

int64_t Rational::gcd(int64_t a, int64_t b) { return std::gcd(a, b); }

void Rational::normalize() {
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int64_t d = std::gcd(num, den);
    num /= d;
    den /= d;
}

Rational::Rational(int64_t n, int64_t d) : num(n), den(d) {
    normalize();
}

Rational::~Rational() {}

//Getters
int64_t Rational::getNumerator() const { return num; }
int64_t Rational::getDenominator() const { return den; }

Rational Rational::operator+(const Rational& other) const {
	return Rational(num * other.den + other.num * den, den * other.den);
}

Rational Rational::operator-(const Rational& other) const {
	return Rational(num * other.den - other.num * den, den * other.den);
}

Rational Rational::operator*(const Rational& other) const {
	return Rational(num * other.num, den * other.den);
}

Rational Rational::operator/(const Rational& other) const {
	if (other.num == 0) {
        throw std::invalid_argument("Division by zero");
    	}
    	return Rational(num * other.den, den * other.num);
}



bool Rational::operator==(const Rational& other) const {
	return num == other.num && den == other.den;
}

bool Rational::operator!=(const Rational& other) const {
	return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
	return num * other.den < other.num * den;
}

bool Rational::operator<=(const Rational& other) const {
	return num * other.den <= other.num * den;
}

bool Rational::operator>(const Rational& other) const {
	return num * other.den > other.num * den;
}

bool Rational::operator>=(const Rational& other) const {
	return num * other.den >= other.num * den;
}


std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.getNumerator() << "/" << r.getDenominator();
	return os;
}