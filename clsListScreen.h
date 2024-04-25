#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"


using namespace std;

class clsListScreen : protected clsScreen
{

private:

    static void _printCurrencyLine(clsCurrency curr)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << curr._getCountry();
        cout << "| " << setw(8) << left << curr._getCurrCode();
        cout << "| " << setw(45) << left << curr._getCurrName();
        cout << "| " << setw(10) << left << to_string(curr.getCurrRate());
    }


public:

	static void showListCurrenciesScreen() {


        vector<clsCurrency> vCurrencies = clsCurrency::getCurrenciesRecord();

        string Title = "\t     List Currencies\n";
        string subTitle = "\t   Showing " + to_string(vCurrencies.size()) + " currencies\n";

        _drawScreenHeader(Title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencies.size() == 0)

            cout << "\t\t\t\tNo currencies to show!!";

        else {

            for (clsCurrency currency : vCurrencies) {
                cout << "\n";
                _printCurrencyLine(currency);

            }
        }
	}


};

