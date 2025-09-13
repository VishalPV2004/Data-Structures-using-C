#include <bits/stdc++.h>
using namespace std;

class OperatorOverloading
{
protected:
    int hours;
    int mins;

public:
    OperatorOverloading() {
        hours = 0;
        mins = 0;
    }

    OperatorOverloading(int hours, int mins) {
        this->hours = hours;
        this->mins = mins;
    }

    void displayTime() {
        cout << hours << ":" << mins << endl;
    }

    OperatorOverloading operator + (const OperatorOverloading& obj) {
        OperatorOverloading o;
        int total_mins = this->mins + obj.mins;
        o.mins = total_mins % 60;
        int extra_hours = total_mins / 60;
        o.hours = this->hours + obj.hours + extra_hours;
        return o;
    }
};

int main()
{
    OperatorOverloading a1(11,10);
    OperatorOverloading a2(12,50);

    OperatorOverloading a3 = a1 + a2;

    a1.displayTime();
    a2.displayTime();
    a3.displayTime();
}
