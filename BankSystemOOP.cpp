
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include <iomanip>

using namespace std;

int main()

{

	//clsMainScreen::ShowMainMenue();
	while (true)
	{
	if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
	system("pause>0");
	return 0;

}


