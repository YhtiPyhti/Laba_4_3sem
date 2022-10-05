#pragma once
#include <iostream>

using namespace std;

class Stock {
public:
    double aeroflot, gazprom, mts;//для всех
    Stock() {
        aeroflot = 23.3;
        vtb = 0.001527;
        gazprom = 210.48;
        mts = 206.3;
        sberbank = 110.83;
    }

    friend ostream& operator<<(ostream& os, const Stock& quotes) {
        os << "Aeroflot: " << quotes.aeroflot << " rub.\n";
        os << "GAZPROM: " << quotes.gazprom << " rub.\n";
        os << "MTS: " << quotes.mts << " rub.\n";
        os << "VTB: " << quotes.vtb << " rub.\n";
        os << "Sberbank: " << quotes.sberbank << " rub.\n";
        return os;
    }

    friend istream& operator>>(istream& is,Stock& quotes) {
        is >> quotes.aeroflot >> quotes.gazprom >> quotes.mts;
        if (is.fail()) {
            cout << "\nIncorrect input!!!\n";
            exit(1);
        }
        return is;
    }

    const double getVtb();

    void setVtb(double a);

    friend void setSberbank(Stock& quotes, double a);

    friend double getSberbank(Stock& quotes);

private:
    double sberbank, vtb;//для некоторых
};

void setSberbank(Stock& quotes, double a);

double getSberbank(Stock& quotes);