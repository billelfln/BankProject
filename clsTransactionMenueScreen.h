#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositeScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
class clsTransactionMenueScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions
	{
		eDeposit = 1,
		eWithdraw = 2,
		eShowTotalBalance = 3,
		eTransfer=4,
		eTransferLog=5,
		eShowMainMenue = 6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << "" << left << "Choose what do you want to do? [1 to 4]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static  void _ShowDepositScreen()
	{
		//cout << "\n_ShowDepositScreen Will Be hire" << endl;
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
		//cout << "\_ShowWithDrawScreen Will Be hire" << endl;
		clsWithDrawScreen::ShowWithDrawScreen();

	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\_ShowTotalBalancesScreen Will Be hire" << endl;
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		/*cout << "Will Be here." << endl;*/
		clsTransferScreen::ShowTransferScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\nPress any key to go back to Transaction menue screen " << endl;
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}


		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{

		}
		}

	}

public:

	static void ShowTransactionsMenue()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransaction Menue Screen");
		cout << setw(37) << "" << left << "===========================================\n";
		cout << setw(37) << "" << left << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << "" << left << "===========================================\n";
		cout << setw(37) << "" << left << "\t[1] Deposit.\n";
		cout << setw(37) << "" << left << "\t[2] Withdraw.\n";
		cout << setw(37) << "" << left << "\t[3] Total Balances.\n";
		cout << setw(37) << "" << left << "\t[4] Transfer." << endl;
		cout << setw(37) << "" << left << "\t[5] Transfer Log." << endl;
		cout << setw(37) << "" << left << "\t[6] Main Menue.\n";
		cout << setw(37) << "" << left << "===========================================\n";
		_PerfromTranactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}
};

