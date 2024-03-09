#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsLoginRegisterScreen :protected clsScreen
{

private:
	static void PrintLoginRecordLine(clsUser::stLoginRegisterRecord & LoginRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(12) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(12) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Permissions;

	}
public:

	static void ShowLoginRegisterScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}	
		system("cls");
		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Titel = "\tLogin Register List Screen";
		string SubTitel = "\t( " + to_string(vLoginRegisterRecord.size()) + " ) Record(s).";
		_DrawScreenHeader(Titel, SubTitel);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(12) << "User Name";
		cout << "| " << left << setw(12) << "PassWord";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		if (vLoginRegisterRecord.size() == 0)
			cout << "No Logins Avalable in The system!!" << endl;
		else
		{

			for (clsUser::stLoginRegisterRecord& L : vLoginRegisterRecord)
			{
				PrintLoginRecordLine(L);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

