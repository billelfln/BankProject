#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsDeliteUserScreen:protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.UserName;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}
public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\tDelite UserScreen");

		string UserName = "";

		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name  is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser Client1 = clsUser::Find(UserName);
		_PrintUser(Client1);

		cout << "\nAre you sure you want to delete this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{


			if (Client1.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";

				_PrintUser(Client1);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}
	}
};

