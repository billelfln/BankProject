#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include"clsMainScreen.h"
#include "clsScreen.h"
#include <iomanip>

class clsUpdateClientScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter FirstName: ";
		Client.FirstName = clsString::ReadString();
		cout << "Enter LastName: ";
		Client.LastName = clsString::ReadString();
		cout << "Enter Email: ";
		Client.Email = clsString::ReadString();
		cout << "Enter Phone: ";
		Client.Phone = clsString::ReadString();
		cout << "Enter PinCod: ";
		Client.PinCode = clsString::ReadString();
		cout << "Enter Balance: ";
		Client.AccountBalance = stod(clsString::ReadString());
	}
public:

	static void  ShowUpdateClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen");
		string AccontNuber = "";
		cout << "\nPlease Enter Client Accont Number: ";
		AccontNuber = clsString::ReadString();
		while (!clsBankClient::IsClientExist(AccontNuber))
		{
			cout << "\nAccont Number is not found, Chouse another one: ";
			AccontNuber = clsString::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccontNuber);
		_PrintClient(Client);


		cout << "\nAre you sure you want to Update this client y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{

			cout << "\nUpdate Client Info: ";
			cout << "\n-----------------------\n";
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsBankClient::svFaildEmptyObject:
				cout << "\nError Accont was not Saved because it's Empty";
				break;
			case clsBankClient::svSucceeded:
				cout << "\nAccont Update Successfully :-)\n";
				_PrintClient(Client);
				break;
			}
		}

	}
};

