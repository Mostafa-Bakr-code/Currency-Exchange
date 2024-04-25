#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindScreen.h"
#include "clsListScreen.h"
#include "clsUpdateScreen.h"
#include "clsCurrCalculatorScreen.h"


class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenuOption { ListCurrency = 1, FindCurrency = 2, UpdateCurrency = 3, CurrencyCalculator = 4 };

    static short _readMainMenuOption() {

        cout << setw(37) << left << "" << "\tChoose your option [1 - 4] ";
        return clsInputValidate::ReadShortNumberBetween(1, 4);
    }

    static void _returnToMainMenu() {

        cout << "\n\nPress any key to return to main menu\n\n";
        system("pause > 0");
        showMainScreen();
    }

    static void _showListCurrenciesScreen(){
        
        clsListScreen::showListCurrenciesScreen();
    }

    static void _showFindCurrencyScreen() {

        clsFindScreen::showfindScreen();
    }

    static void _showUpdateCurrencScreen() {

        clsUpdateScreen::showUpdateScreen();
    }

    static void _showCurrencyCalculatorScreen() {

        clsCurrCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _performMainMenuOption(enMainMenuOption mainMenuOption) {

         switch (mainMenuOption) {

         case enMainMenuOption::ListCurrency:

             system("cls");
             _showListCurrenciesScreen();
             _returnToMainMenu();
             break;


         case enMainMenuOption::FindCurrency:

             system("cls");
             _showFindCurrencyScreen();
             _returnToMainMenu();
             break;

         case enMainMenuOption::UpdateCurrency:

             system("cls");
             _showUpdateCurrencScreen();
             _returnToMainMenu();
             break;

         case enMainMenuOption::CurrencyCalculator:

             system("cls");
             _showCurrencyCalculatorScreen();
             _returnToMainMenu();
             break;

         }
    
    }


public:

	static void showMainScreen() {

		
        system("cls");
        _drawScreenHeader("\t     Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency-Exchange Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performMainMenuOption(enMainMenuOption(_readMainMenuOption()));

	}

   

};

