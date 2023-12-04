//1.INHERITANCE :-
#include<iostream>
using namespace std;

class Analysis {
protected:
    int id;
    int res;

public:
    void setData(int sid, int sres) {
        id = sid;
        res = sres;
    }

    void display() {
        cout << "\t" << id << "\t" << res << "\n";
    }
};

class ExtendedAnalysis : public Analysis {
public:
    void raiseTuition() {
        if (res > 8) {
            cout << "\n\tRaise Tuition..!";
        }
    }
};

int main() {
    ExtendedAnalysis a[10];
    int i;
    int sres, sid;
    int pass = 0;
    int fail = 0;

    for (i = 0; i < 10; i++) {
        cout << "Enter Student ID : ";
        cin >> sid;
        cout << "Enter 1 for pass and 2 for Fail : ";
        cin >> sres;
        if (sres == 1)
            pass++;
        else
            fail++;
        a[i].setData(sid, sres);
    }

    cout << "\tID "
         << "Result \n";
    for (i = 0; i < 10; i++) {
        a[i].display();
    }

    cout << "\tNo of Passed student :\t" << pass;
    cout << "\tNo of Failed student :\t" << fail;

    ExtendedAnalysis extended;
    extended.raiseTuition();

    return 0;
}


//2.EXCEPTION HANDLING :-
#include<iostream>
#include<stdexcept>
using namespace std;

class Analysis {
protected:
    int id;
    int res;

public:
    void setData(int sid, int sres) {
        id = sid;
        if (sres != 1 && sres != 2) {
            throw invalid_argument("Invalid result. Enter 1 for pass and 2 for fail.");
        }
        res = sres;
    }

    void display() {
        cout << "\t" << id << "\t" << res << "\n";
    }
};

int main() {
    Analysis a[10];
    int i;
    int sres, sid;
    int pass = 0;
    int fail = 0;

    try {
        for (i = 0; i < 10; i++) {
            cout << "Enter Student ID : ";
            cin >> sid;
            cout << "Enter 1 for pass and 2 for Fail : ";
            cin >> sres;
            if (sres == 1)
                pass++;
            else if (sres == 2)
                fail++;
            else
                throw invalid_argument("Invalid result. Enter 1 for pass and 2 for fail.");

            a[i].setData(sid, sres);
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }

    cout << "\tID "
         << "Result \n";
    for (i = 0; i < 10; i++) {
        a[i].display();
    }

    cout << "\tNo of Passed student :\t" << pass;
    cout << "\tNo of Failed student :\t" << fail;

    return 0;
}

#include<iostream>
using namespace std;

class Analysis {
protected:
    int id;
    int res;

public:
    virtual void setData(int sid, int sres) {
        id = sid;
        res = sres;
    }

    void display() {
        cout << "\t" << id << "\t" << res << "\n";
    }
};

class ExtendedAnalysis : public Analysis {
public:
    void raiseTuition() {
        if (res > 8) {
            cout << "\n\tRaise Tuition..!";
        }
    }
};

int main() {
    ExtendedAnalysis a[10];
    int i;
    int sres, sid;
    int pass = 0;
    int fail = 0;

    for (i = 0; i < 10; i++) {
        cout << "Enter Student ID : ";
        cin >> sid;
        cout << "Enter 1 for pass and 2 for Fail : ";
        cin >> sres;
        if (sres == 1)
            pass++;
        else
            fail++;
        a[i].setData(sid, sres);
    }

    cout << "\tID "
         << "Result \n";
    for (i = 0; i < 10; i++) {
        a[i].display();
    }

    cout << "\tNo of Passed student :\t" << pass;
    cout << "\tNo of Failed student :\t" << fail;

    ExtendedAnalysis extended;
    extended.raiseTuition();

    return 0;
}

//3.VIRTUAL FUNCTION :-
#include<iostream>
using namespace std;

class Analysis {
protected:
    int id;
    int res;

public:
    virtual void setData(int sid, int sres) {
        id = sid;
        res = sres;
    }

    void display() {
        cout << "\t" << id << "\t" << res << "\n";
    }
};

class ExtendedAnalysis : public Analysis {
public:
    void raiseTuition() {
        if (res > 8) {
            cout << "\n\tRaise Tuition..!";
        }
    }
};

int main() {
    ExtendedAnalysis a[10];
    int i;
    int sres, sid;
    int pass = 0;
    int fail = 0;

    for (i = 0; i < 10; i++) {
        cout << "Enter Student ID : ";
        cin >> sid;
        cout << "Enter 1 for pass and 2 for Fail : ";
        cin >> sres;
        if (sres == 1)
            pass++;
        else
            fail++;
        a[i].setData(sid, sres);
    }

    cout << "\tID "
         << "Result \n";
    for (i = 0; i < 10; i++) {
        a[i].display();
    }

    cout << "\tNo of Passed student :\t" << pass;
    cout << "\tNo of Failed student :\t" << fail;

    ExtendedAnalysis extended;
    extended.raiseTuition();

    return 0;
}


//4.FRIEND FUNCTION :-
#include<iostream>
using namespace std;

class Analysis {
    friend void printAnalysis(const Analysis& student);

private:
    int id;
    int res;

public:
    void setData(int sid, int sres) {
        id = sid;
        res = sres;
    }

    void display() {
        cout << "\t" << id << "\t" << res << "\n";
    }
};

void printAnalysis(const Analysis& student) {
    cout << "\tID "
         << "Result \n";
    student.display();
}

int main() {
    Analysis a[10];
    int i;
    int sres, sid;
    int pass = 0;
    int fail = 0;

    for (i = 0; i < 10; i++) {
        cout << "Enter Student ID : ";
        cin >> sid;
        cout << "Enter 1 for pass and 2 for Fail : ";
        cin >> sres;
        if (sres == 1)
            pass++;
        else
            fail++;
        a[i].setData(sid, sres);
    }

    for (i = 0; i < 10; i++) {
        printAnalysis(a[i]);
    }

    cout << "\tNo of Passed student :\t" << pass;
    cout << "\tNo of Failed student :\t" << fail;

    return 0;
}
