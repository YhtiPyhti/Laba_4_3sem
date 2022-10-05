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

    const double getVtb();

    void setVtb(double a);

    friend void setSberbank(Stock& quotes, double a);

    friend double getSberbank(Stock& quotes);

private:
    double sberbank, vtb;//для некоторых
};

void setSberbank(Stock& quotes, double a);

double getSberbank(Stock& quotes);