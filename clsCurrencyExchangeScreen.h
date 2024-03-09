#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsCurrencyListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :protected clsScreen
{



private:

	enum enCurrencyMenueOptions
	{
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalculator = 4,
		eMainMenue = 5
	};
	static short _ReadCurrancyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 8? ");
		return Choice;
	}
	static void _ShowListCurrencies()
	{
		//cout << "List Currencies will be here" << endl;
		clsCurrencyListScreen::ShowCurrencyListScreen();
	}
	static void _ShowFindCurrency()
	{
		//cout << "List Currencies will be here" << endl;

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRate()
	{
		//cout << "List Currencies will be here" << endl;
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

	}
	static void _ShowCurrencyCalculator()
	{
		//cout << "List Currencies will be here" << endl;
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currancy exchange Menue...\n";

		system("pause>0");
		ShowMainCurrencyExchangeScreen();
	}
	static void _PerformCurrancyMenueOption(enCurrencyMenueOptions CurrancyMenueOption)
	{
		switch (CurrancyMenueOption)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowListCurrencies();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToMainMenue();
			break;
		case enCurrencyMenueOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToMainMenue();
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToMainMenue();
			break;
		case clsCurrencyExchangeScreen::eMainMenue:

			break;
		default:
			break;
		}
	}
public:

	static void ShowMainCurrencyExchangeScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pCarrancyExchange))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\tCurrancy Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Currancy Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrancyMenueOption((enCurrencyMenueOptions)_ReadCurrancyMenueOption());
	}
};

