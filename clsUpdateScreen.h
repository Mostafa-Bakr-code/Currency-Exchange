#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateScreen : protected clsScreen
{

private:

    static void _printCurrencyLine(clsCurrency curr)
    {   
        cout << "\nCurrency Card";
        cout << "\n---------------------------\n";
        cout << "Currency Country :" << curr._getCountry() << endl;
        cout << "Currency Code    :" << curr._getCurrCode() << endl;
        cout << "Currency Name    :" << curr._getCurrName() << endl;
        cout << "Currency Rate(1$):" << to_string(curr.getCurrRate()) << endl;
        cout << "---------------------------\n";
    }

public:

    static void showUpdateScreen() {

        _drawScreenHeader("\t Update Currency Screen");

        cout << "Entre currency code: ";

        string currCode = clsInputValidate::readString();

        while (!clsCurrency::isCurrExist(currCode)) {

            cout << "Currency doesn't exist, please entre another code..\n";
            currCode = clsInputValidate::readString();
        }

        clsCurrency curr = clsCurrency::findByCode(currCode);
        _printCurrencyLine(curr);

        cout << "Entre new currency rate: ";

        float newRate = clsInputValidate::ReadFloatNumber();

        cout << "Are you sure you want to update rate from " << curr.getCurrRate() << " to " << newRate << "? y/n ";

        if (clsInputValidate::readChar() == 'y') {

            curr.setCurrRate(newRate);
            curr.save();
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _printCurrencyLine(curr);
        }

        else {
            cout << "\nUpdate canceled ...\n";
        }
    }

};

