#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>
class clsCurrencyListScreen :protected clsScreen
{
private:
	static void PrintCurrencyRecordLine(clsCurrency & Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}

public:


	static void ShowCurrencyListScreen()
	{
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();

		system("cls");
		string Titel = "\tCurrencies List Screen";
		string SubTitel = "\t(" + to_string(vCurrencies.size()) + ") Currency";
		_DrawScreenHeader(Titel, SubTitel);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Cuuntry";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1&)";


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\t\tNo Currency Available In the System!";
		}
		else
		{
			for (clsCurrency& C : vCurrencies)
			{
				PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

