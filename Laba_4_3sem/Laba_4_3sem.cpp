#include "Birga.h"

static double MAX_VALUE = 1.7976931348623157E308;

void showStockQuotes(Stock& quotes) {
    cout << "Aeroflot: " << quotes.aeroflot << " rub.\n";
    cout << "GAZPROM: " << quotes.gazprom << " rub.\n";
    cout << "MTS: " << quotes.mts << " rub.\n";
    cout << "VTB: " << quotes.getVtb() << " rub.\n";
    cout << "Sberbank: " << getSberbank(quotes) << " rub.\n";

}

void replaceValue(Stock& quotes, string choice) {
    double replacement;

    cout << "\nInput value: ";
    cin >> replacement;

    if (cin.fail() || replacement < 0 || replacement > MAX_VALUE) {
        cin.clear();
        cout << "\nIncorrect input!!!\n";
        exit(1);
    }
    if (choice == "1") {
        quotes.setVtb(replacement);
    }
    else {
        setSberbank(quotes, replacement);
    }
}

void menu(Stock& quotes) {
    string choice;
    while (true)
    {
        cout << "\nWhat do you need?\n1)Show stock quotes\n2)Replace value\n3)Exit\n";
        cin >> choice;
        if (choice == "1") {
            system("cls");
            showStockQuotes(quotes);
        }
        else if (choice == "2") {
            while (true)
            {
                cout << "\n1)VTB\n2)Sberbank\n";
                cin >> choice;

                if (choice != "1" && choice != "2") {
                    cout << "\nIncorrect input!!!\n";
                    choice.clear();
                    system("cls");
                }
                else break;
            }

            system("cls");
            replaceValue(quotes, choice);

        }
        else if (choice == "3") {
            exit(1);
        }
        else {
            cout << "\nIncorrect input!!!\n";
            choice.clear();
            system("cls");
            menu(quotes);
        }
    }
}


int main(){

    Stock quotes;

    menu(quotes);
}
