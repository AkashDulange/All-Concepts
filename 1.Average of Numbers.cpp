//1.INHERITANCE :-
#include<iostream>
using namespace std;

class AverageCalculator {
protected:
    int n;
    int* numbers;

public:
    AverageCalculator(int size) : n(size) {
        numbers = new int[n];
    }

    void getInput() {
        cout << "\nEnter the no of elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the number " << i + 1 << ": "<<endl;
            cin >> numbers[i];
        }
    }

    double calculateAverage() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        return (n == 0) ? 0 : sum / n;
    }
};

class DerivedCalculator : public AverageCalculator {
public:
    DerivedCalculator(int size) : AverageCalculator(size) {}
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    DerivedCalculator calculator(size);
    calculator.getInput();
    cout << "Avg of " << size << " numbers: " << calculator.calculateAverage() << endl;

    return 0;
}


//2.EXCEPTION HANDLING :-
#include<iostream>
#include<exception>
using namespace std;

class InvalidInputException : public exception {
public:
    const char* what() const throw() {
        return "Invalid input. Please enter a valid number.";
    }
};

class AverageCalculator {
protected:
    int n;
    int* numbers;

public:
    AverageCalculator(int size) : n(size) {
        numbers = new int[n];
    }

    ~AverageCalculator() {
        delete[] numbers;
    }

    void getInput() {
        cout << "\nEnter the no of elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the number " << i + 1 << ": "<<endl;
            try {
                cin >> numbers[i];
                if (cin.fail()) {
                    throw InvalidInputException();
                }
            } catch (const InvalidInputException& e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--; 
            }
        }
    }

    double calculateAverage() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        return (n == 0) ? 0 : sum / n;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    AverageCalculator calculator(size);
    calculator.getInput();
    cout << "Avg of " << size << " numbers: " << calculator.calculateAverage() << endl;

    return 0;
}


//3.FRIEND FUNCTION
#include<iostream>
using namespace std;

class AverageCalculator;

void printAverage(const AverageCalculator& calculator);

class AverageCalculator {
private:
    int n;
    int* numbers;

public:
    AverageCalculator(int size) : n(size) {
        numbers = new int[n];
    }

    friend void printAverage(const AverageCalculator& calculator);

    void getInput() {
        cout << "\nEnter the no of elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the number " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    double calculateAverage() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        return (n == 0) ? 0 : sum / n;
    }
};

void printAverage(const AverageCalculator& calculator) {
    cout << "Avg of " << calculator.n << " numbers: " << calculator.calculateAverage() << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    AverageCalculator calculator(size);
    calculator.getInput();
    printAverage(calculator);

    return 0;
}


//4.VIRTUAL FUNCTION :-
#include<iostream>
using namespace std;

class AverageCalculator {
protected:
    int n;
    int* numbers;

public:
    AverageCalculator(int size) : n(size) {
        numbers = new int[n];
    }

    virtual void getInput() {
        cout << "\nEnter the no of elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the number " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    virtual double calculateAverage() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        return (n == 0) ? 0 : sum / n;
    }
};

class DerivedCalculator : public AverageCalculator {
public:
    DerivedCalculator(int size) : AverageCalculator(size) {}

    void getInput() override {
        cout << "\nEnter " << n << " elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    double calculateAverage() override {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i] * 2; // Modify or extend the calculation
        }
        return (n == 0) ? 0 : sum / n;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    DerivedCalculator calculator(size);
    calculator.getInput();
    cout << "Avg of " << size << " numbers: " << calculator.calculateAverage() << endl;

    return 0;
}
