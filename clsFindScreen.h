#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindScreen : protected clsScreen
{
private:

    static void _print(clsCurrency myCurr) {

        system("cls");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency-Card\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t Country : " << myCurr._getCountry() << "\n";
        cout << setw(37) << left << "" << "\t Code    : " << myCurr._getCurrCode() << "\n";
        cout << setw(37) << left << "" << "\t Name    : " << myCurr._getCurrName() << "\n";
        cout << setw(37) << left << "" << "\t Rate(1$): " << to_string(myCurr.getCurrRate()) << "\n";
        cout << setw(37) << left << "" << "===========================================\n";

    }

    static void _showResults(clsCurrency myCurr)
    {
        if (!myCurr.isEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _print(myCurr);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

    enum enFindCurrBy {FINDBYCOUNTRY = 1, FINDBYCODE = 2};

    static clsCurrency _findByCountry() {

        cout << "Entre currency name: \n";

        string countryName = clsInputValidate::readString();

        clsCurrency curr = clsCurrency::findByCountry(countryName);

        _showResults(curr);

        return curr;
    }

    static clsCurrency _findByCode() {

        cout << "Entre currency code: \n";

        string currCode = clsInputValidate::readString();

        clsCurrency curr = clsCurrency::findByCode(currCode);

        _showResults(curr);

        return curr;
    }

public:

    static void showfindScreen() {

        _drawScreenHeader("\t Find Currency Screen");

        cout << "Find currency by country [1]\n";
        cout << "Find currency by code [2]\n";

        enFindCurrBy findBy = enFindCurrBy(clsInputValidate::ReadShortNumberBetween(1, 2));
        

        switch (findBy) {

        case enFindCurrBy::FINDBYCODE:

            _findByCode();

            break;

        case enFindCurrBy::FINDBYCOUNTRY:

            _findByCountry();

            break;

        }
        
    }

};

