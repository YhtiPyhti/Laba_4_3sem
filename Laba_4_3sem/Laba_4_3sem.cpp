#include "Birga.h"

const double MAX_VALUE = 1.7976931348623157E308;
const string PASSWORD = "111";

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
    string choice, user_pass;
    while (true)
    {
        cout << "\nWhat do you need?\n1)Show stock quotes\n2)Replace value\n3)Exit\n";
        cin >> choice;
        if (choice == "1") {
            system("cls");
            cout << quotes;
        }
        else if (choice == "2") {
            cout << "\nProcedure for entering data: Aeroflot  GAZPROM  MTS\n";
            cin >> quotes;
            cout << "\nIf you want to continue, enter the password( " << PASSWORD <<" ): ";
            cin >> user_pass;
            if (user_pass == PASSWORD) {
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
            else cout << "\nIncorrect input!!!\n";

        }
        else if (choice == "3") {
            system("cls");
            cout << "\nGoodbuy\n";
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
