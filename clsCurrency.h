#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>



class clsCurrency
{

private:

	enum enMode { UPDATE = 1, EMPTY = 2 };

	enMode _mode;

	string _country;
	string _currCode;
	string _currName;
	float _currRate;


	static clsCurrency _convertLineToCurrObj(string line, string seperator = "#//#") {

		vector<string> vCurrency = clsString::splitString(line, seperator);

		return clsCurrency(enMode::UPDATE ,vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));

	}

	static string _convertCurrObjToLine(clsCurrency curr,string seperator = "#//#") {

		string line;

		line = curr._country + seperator;
		line += curr._currCode + seperator;
		line += curr._currName + seperator;
		line += to_string(curr._currRate);
		
		return line;
	}

	static vector<clsCurrency> _loadDataFromFileToObjVec() {

		vector<clsCurrency> vCurrencies;

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open()) {

			string line;

			while (getline(myFile, line)) {

				vCurrencies.push_back(_convertLineToCurrObj(line));
			}

			myFile.close();
		}

		return vCurrencies;
	}

	static void _loadDataFromCurrObjToFile(vector<clsCurrency> vCurr) {

			fstream myFile;

			myFile.open("Currencies.txt", ios::out);

			if (myFile.is_open()) {

			for (clsCurrency curr : vCurr) {

				myFile << _convertCurrObjToLine(curr) << endl;
			}

		}

		myFile.close();
	}

	static clsCurrency _getEmptyCurrObj() {

		return clsCurrency(enMode::EMPTY, "", "", "", 0);
	}

	void _updateSave() {

		vector<clsCurrency>vCurr = _loadDataFromFileToObjVec();

		for (clsCurrency& curr : vCurr) {

			if (curr._getCurrCode() == _getCurrCode()) {

				curr = *this;
				break;
			}
		}

		_loadDataFromCurrObjToFile(vCurr);
	}

public:

	clsCurrency(enMode mode ,string country, string currCode, string currName, float currRate) {

		_country = country;
		_currCode = currCode;
		_currName = currName;
		_currRate = currRate;
		_mode = mode;
	}

	string _getCountry() {

		return _country;
	}

	string _getCurrCode() {

		return _currCode;
	}

	string _getCurrName() {

		return _currName;
	}

	void setCurrRate(float currRate) {

		_currRate = currRate;
	}

	float getCurrRate() {

		return _currRate;
	}

	static clsCurrency findByCode(string currCode){
		
		currCode = clsString::capitalizeString(currCode);

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open()) {
			
			string line;

			while (getline(myFile, line)) {
				
				clsCurrency myCurr = _convertLineToCurrObj(line);

				if (currCode == myCurr._currCode) {

					return myCurr;
				}
			}
			
			myFile.close();
		}

		return _getEmptyCurrObj();
	}

	static clsCurrency findByCountry(string country) {

		country = clsString::capitalizeString(country);

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open()) {

			string line;

			while (getline(myFile, line)) {

				clsCurrency myCurr = _convertLineToCurrObj(line);

				if (clsString::trimString(clsString::lowerCaseString(country)) == clsString::lowerCaseString(myCurr._country)) {

					myFile.close();
					return myCurr;
				}
			}
			
			myFile.close();
		}

		return _getEmptyCurrObj();
	}

	static vector<clsCurrency> getCurrenciesRecord() {

		return _loadDataFromFileToObjVec();
	}

	bool isEmpty() {

		return (_mode == enMode::EMPTY);
	}

	static bool isCurrExist(string currCode) {

		clsCurrency curr = clsCurrency::findByCode(currCode);

		return (!curr.isEmpty());

	}

	enum enSaveResults {SAVED = 1, SAVEDFAILED = 2 };

	enSaveResults save() {

		switch (_mode) {

		case enMode::EMPTY:

			return enSaveResults::SAVEDFAILED;


		case enMode::UPDATE:

			_updateSave();

			return enSaveResults::SAVED;

		}
	}

	//____________________________________________________________________________

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / getCurrRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2._getCurrCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.getCurrRate());

	}

};

