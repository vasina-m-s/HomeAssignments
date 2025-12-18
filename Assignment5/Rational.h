/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment5
*/

#ifndef RATIONAL
#define RATIONAL

#include <cstdint>
#include <stdexcept>
#include <string>
#include <ostream>

class Rational {
	private:
    		int64_t num; //numirator
    		int64_t den; //denominator

    		int64_t  gcd(int64_t a, int64_t b);
    		void normalize();

	public:
    		Rational(int64_t num = 0, int64_t den = 1); // Constructor
		~Rational(); // Destructor

		// Getters
    		int64_t getNumerator() const;
    		int64_t getDenominator() const;

    		Rational operator+(const Rational& other) const;
		Rational operator-(const Rational& other) const;
    		Rational operator*(const Rational& other) const;
		Rational operator/(const Rational& other) const;
	
		bool operator==(const Rational& other) const;
    		bool operator!=(const Rational& other) const;
    		bool operator<(const Rational& other) const;
    		bool operator<=(const Rational& other) const;
    		bool operator>(const Rational& other) const;
    		bool operator>=(const Rational& other) const;

};

#endif