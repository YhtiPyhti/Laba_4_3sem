#include "Birga.h"
void Stock::setVtb(double a) {
    vtb = a;
}

const double Stock::getVtb() {
    return vtb;
}

void setSberbank(Stock& quotes, double a) {
    quotes.sberbank = a;
}

double getSberbank(Stock& quotes) {
    return quotes.sberbank;
}