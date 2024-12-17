// fraction.h
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <numeric> // For std::gcd

class Fraction {
private:
    long numerator;
    long denominator;

    void simplify() {
        long gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(long num = 0, long denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    // Unary - operator
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    // Prefix ++ operator
    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    // Prefix -- operator
    Fraction& operator--() {
        numerator -= denominator;
        return *this;
    }

    // Compound assignment operators
    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        simplify();
        return *this;
    }

    // Friend functions for binary operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
        Fraction result = lhs;
        result += rhs;
        return result;
    }

    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
        Fraction result = lhs;
        result -= rhs;
        return result;
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
        Fraction result = lhs;
        result *= rhs;
        return result;
    }

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
        Fraction result = lhs;
        result /= rhs;
        return result;
    }

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& frac) {
        char slash;
        is >> frac.numerator >> slash >> frac.denominator;
        if (frac.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        frac.simplify();
        return is;
    }
};

#endif // FRACTION_H
