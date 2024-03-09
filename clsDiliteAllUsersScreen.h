#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include<iostream>

using namespace std;
class clsDiliteAllUsersScreen:protected clsScreen
{
private:



public:

	static void ShowDiliteAllUserScreen()
	{
		system("cls");
		_DrawScreenHeader("\tDilite All Users Screen");

		cout << "Are You sure do you want to dilite all User y / n?	" << endl;
		char Answer;
		cin >> Answer;
		while (Answer == 'Y' || Answer == 'y')
		{
			clsUser::DeliteAll();
			break;
		}
	}

};

