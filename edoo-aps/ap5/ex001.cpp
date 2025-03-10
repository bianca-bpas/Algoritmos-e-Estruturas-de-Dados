#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    long numerator;
    long denominator;

public:
    // Exception class for division errors
    class DivError : public exception {
    public:
        const char* what() const noexcept override {
            return "The denominator is 0!";
        }
    };

    // Constructor
    Fraction(long num = 0, long denom = 1) {
        if (denom == 0) {
            throw DivError();
        }
        numerator = num;
        denominator = denom;
    }

    // Operator / overload
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw DivError();
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Operator >> overload
    friend istream& operator>>(istream& in, Fraction& fraction) {
        cout << "Enter numerator: ";
        in >> fraction.numerator;
        cout << "Enter denominator: ";
        in >> fraction.denominator;
        if (fraction.denominator == 0) {
            throw Fraction::DivError();
        }
        return in;
    }

    // Operator << overload
    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }
};

int main() {
    // First try/catch block: Testing constructor
    cout << "--- Testing Constructor ---\n";
    try {
        Fraction f1(1, 2);
        Fraction f2(0, 5);
        Fraction f3(3, 0); // Should throw exception
    } catch (const Fraction::DivError& e) {
        cerr << e.what() << "\n";
    }

    // Second try/catch block: Testing division
    cout << "\n--- Testing Division ---\n";
    try {
        Fraction f1(1, 2);
        Fraction f2(0, 1);
        Fraction result = f1 / f2; // Should throw exception
    } catch (const Fraction::DivError& e) {
        cerr << "No division by zero!\n";
    }

    // Third try/catch block: Testing input
    cout << "\n--- Testing Input ---\n";
    try {
        Fraction f;
        cin >> f; // If denominator is 0, retry input
        cout << "You entered: " << f << "\n";
    } catch (const Fraction::DivError& e) {
        cerr << "New denominator != 0: Program terminated.\n";
        return 1;
    }

    return 0;
}
