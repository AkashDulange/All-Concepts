//1.INHERITANCE :-
#include<iostream>
using namespace std;

class PowerCalculator {
public:
    double calculatePower(double base, int exponent) {
        double result = 1;
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
        return result;
    }
};

class DefaultPowerCalculator : public PowerCalculator {
};

int main() {
    DefaultPowerCalculator calculator;
    double base;
    int exponent;

    cout << "Enter the base value and power: "<<endl;
    cin >> base >> exponent;

    double result = calculator.calculatePower(base, exponent);
    cout << "Power of number is: " << result << endl;

    return 0;
}


//2.EXCEPTION HANDLING :-
#include<iostream>
#include<stdexcept>
using namespace std;

class PowerCalculator {
public:
    double calculatePower(double base, int exponent) {
        if (exponent < 0) {
            throw invalid_argument("Exponent must be a non-negative integer.");
        }

        double result = 1;
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
        return result;
    }
};

int main() {
    PowerCalculator calculator;
    double base;
    int exponent;

    cout << "Enter the base value and power: ";
    cin >> base >> exponent;

    try {
        double result = calculator.calculatePower(base, exponent);
        cout << "Power of number is: " << result << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}


//3.VIRTUAL FUNCTION :-
#include<iostream>
using namespace std;

class PowerCalculator {
public:
    virtual double calculatePower(double base, int exponent) = 0;
};

class DefaultPowerCalculator : public PowerCalculator {
public:
    double calculatePower(double base, int exponent) override {
        double result = 1;
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
        return result;
    }
};

class RecursivePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double base, int exponent) override {
        if (exponent == 0) {
            return 1;
        } else if (exponent == 1) {
            return base;
        } else {
            return base * calculatePower(base, exponent - 1);
        }
    }
};

int main() {
    DefaultPowerCalculator defaultCalculator;
    RecursivePowerCalculator recursiveCalculator;

    double base;
    int exponent;

    cout << "Enter the base value and power: "<<endl;
    cin >> base >> exponent;

    double resultDefault = defaultCalculator.calculatePower(base, exponent);
    cout << "Default Power Calculator, Power of number is: " << resultDefault << endl;

    double resultRecursive = recursiveCalculator.calculatePower(base, exponent);
    cout << "Recursive Power Calculator, Power of number is: " << resultRecursive << endl;

    return 0;
}


//4.FRIEND FUNCTION:-
#include<iostream>
using namespace std;

class PowerCalculator;

void printPower(const PowerCalculator& calculator);

class PowerCalculator {
private:
    int n;

public:
    PowerCalculator(int size) : n(size) {}

    friend void printPower(const PowerCalculator& calculator);
};

void printPower(const PowerCalculator& calculator) {
    cout << "Power of number is: " << calculator.n << endl;
}

int main() {
    int size;
    cout << "Enter the power value: "<<endl;
    cin >> size;

    PowerCalculator calculator(size);
    printPower(calculator);

    return 0;
}
