#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsString.h"
#include <iomanip>
class clsAddNewClientScreen :protected clsScreen
{
private:


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

	static void _PrintClient(clsBankClient Client)
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

public:

	static void AddNewClient()
	{
		_DrawScreenHeader("\tAdd New Client Screen");
		string AccontNuber = "";
		cout << "\nPlease Enter Client Accont Number: ";
		AccontNuber = clsString::ReadString();
		while (clsBankClient::IsClientExist(AccontNuber))
		{
			cout << "\nAccont Number Is Already Used, Chouse another one: ";
			AccontNuber = clsString::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccontNuber);

		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}
	}
};

