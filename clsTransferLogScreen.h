#pragma once
#include"clsScreen.h"
class clsTransferLogScreen :protected clsScreen
{
	static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord& TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;

	}

public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTrnsferLogRecord> vLogTransferList = clsBankClient::GetTransfersLogList();
		system("cls");
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vLogTransferList.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		 cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogTransferList.size() == 0)
		{
			cout << "No Log Transfer in the system." << endl;
		}
		else
		{
			for (clsBankClient::stTrnsferLogRecord& Trans : vLogTransferList)
			{
				PrintTransferLogRecordLine(Trans);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

