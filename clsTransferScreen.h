#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsString.h"
#include"clsInputValidate.h"
class clsTransferScreen :protected clsScreen
{
private:

	static string readAccontNumber(string TransferFromOrTo)
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number To Transfer "<< TransferFromOrTo<<" :";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static void _PrintClientCard(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static int ReadAmount(clsBankClient SourceClient)
	{
		int Amount = 0;
		cout << "Enter Transfer Amount?";
		Amount = clsInputValidate::ReadIntNumber();
		while (Amount>SourceClient.AccountBalance)
		{
			cout << "Amount Exceeds The available Balance, Enter Another Amount?";
			Amount = clsInputValidate::ReadIntNumber();

		}
		return Amount;
	}
public:

	static void ShowTransferScreen()
	{
		system("cls");
		_DrawScreenHeader("\tTransfer Screen");

		string AccountNumberSourceClient = readAccontNumber("From");
		clsBankClient SoursClient = clsBankClient::Find(AccountNumberSourceClient);
		_PrintClientCard(SoursClient);

		string AccountNumberDestinationClient = readAccontNumber("To");

		while (AccountNumberSourceClient == AccountNumberDestinationClient)
		{
			cout << "\nIt is not possible to transfer to the same client, choose another one: ";
			 AccountNumberDestinationClient = readAccontNumber("To");
		}

		clsBankClient DestinationClient = clsBankClient::Find(AccountNumberDestinationClient);
		_PrintClientCard(DestinationClient);

		int Amount = ReadAmount(SoursClient);

		char Answer = 'n';
		cout << "Are you sure Do you want to Perform this Opiration?y/n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SoursClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "Transfer Done Successfully :-)" << endl;

			}
			else
			{
				cout << "Thise Opiration Was failsed" << endl;
			}
			_PrintClientCard(SoursClient);
			_PrintClientCard(DestinationClient);
		}
	}

};

