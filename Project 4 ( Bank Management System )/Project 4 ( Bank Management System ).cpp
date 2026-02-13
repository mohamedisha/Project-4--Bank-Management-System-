#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
using namespace std;

struct sClient {
    string NameClient;
    string AccountNumber;
    int Phone;
    int PinCode;
    double Balance;
};

sClient CreateClient()
{
    sClient Account;

    cout << endl;
    cout << ("Account Number : ");
    cin >> Account.AccountNumber;
    cout << ("Pin Code") << ": ";
    cin >> Account.PinCode;
    cout << "Name " << ": ";
    cin.ignore();
    getline(cin, Account.NameClient);
    cout << ("Phone") << ": ";
    cin >> Account.Phone;
    cout << ("Balance") << ": ";
    cin >> Account.Balance;
    return Account;
}

void CreateMultipleClients(vector <sClient>& Client)
{
    char PlayAgen = 'Y';
    do {
        Client.push_back(CreateClient());

        cout << "\n\n";
        cout << ("Client added Successfully, do you add more clients? [ Y/N ]: ");
        cin >> PlayAgen;

    } while (PlayAgen == 'Y' || PlayAgen == 'y');

}

void DisplayClientTableHeader()
{
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << setw(25) << left << "| Account Number";
    cout << setw(40) << "| Client Name";
    cout << "| Balance\n";
    cout << "--------------------------------------------------------------------------------------------------------\n";
}

void DisplayClientRow(sClient& Client)
{
    cout << "| " << setw(23) << left << Client.AccountNumber;
    cout << "| " << setw(38) << left << Client.NameClient;
    cout << "| $" << left << Client.Balance;
    cout << endl;
}

void DepositToClient(vector <sClient>& Client)
{
    double TotalBalance = 0;
    for (sClient& i : Client)
    {
        DisplayClientRow(i);
        TotalBalance += i.Balance;
    }
    cout << "--------------------------------------------------------------------------------------------------------\n\n";
    cout << "\t\t\tTotal Balance = " << TotalBalance;
}

void DepositToClient(sClient& Client)
{
    float Deposit;
    char Depositamount;
    cout << endl;
    cout << ("Please enter Deposit amount? $");
    cin >> Deposit;
    cout << ("Are you sure you want lerfrom this transaction? [Y/N]: ");
    cin >> Depositamount;

    if (Depositamount == 'Y' || Depositamount == 'y')
    {
        Client.Balance += Deposit;
    }
}

void DisplayClientDetails(sClient& Client)
{
    cout << "---------------------------------------------\n";
    cout << "\t\tDeposit Screen\n";
    cout << "---------------------------------------------\n\n";
    cout << "The following is the extracted client record:\n";
    cout << "--------------------------------------------------------------------\n";
    cout << setw(20) << left << "Account Number" << ": " << Client.AccountNumber << endl;
    cout << setw(20) << left << "PinCode" << ": " << Client.PinCode << endl;
    cout << setw(20) << left << "Name" << ": " << Client.NameClient << endl;
    cout << setw(20) << left << "Phone" << ": " << Client.Phone << endl;
    cout << setw(20) << left << "Account Balance" << ": $" << Client.Balance << endl;
}

void SearchClientByNumber(vector <sClient>& Client)
{
    system("cls");
    string AccountNumber;
    int PinCode;
    cout << ("Please enter Account Number?");
    cin >> AccountNumber;
    cout << ("Please enter  Pin Code?");
    cin >> PinCode;

    for (sClient& Counter : Client)
    {
        if (AccountNumber == Counter.AccountNumber && PinCode == Counter.PinCode)
        {
            DisplayClientDetails(Counter);
            break;
        }
    }
    cout << "\n\nEnter any Press To Back Main...";
    system("pause>0");
}

void DepositToClientByNumber(vector <sClient>& Client)
{
    system("cls");
    string AccountNumber;
    int PinCode;
    cout << ("Please enter Account Number?");
    cin >> AccountNumber;
    cout << ("Please enter  Pin Code?");
    cin >> PinCode;

    for (sClient& i : Client)
    {
        if (AccountNumber == i.AccountNumber && PinCode == i.PinCode)
        {
            DisplayClientDetails(i);
            DepositToClient(i);
            break;
        }
    }

    cout << "\n\nEnter any Press To Back Main...";
    system("pause>0");
}

void DisplayMainMenu()
{
    cout << "______________________________________________________________________\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "\t\t\tMain Menue Screen\n";
    cout << "______________________________________________________________________\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "[1] Add New Client\n";
    cout << "[2] Show All Client List\n";
    cout << "[3] Find Client\n";
    cout << "[4] Deposit\n";
    //  cout << "5. Withdraw\n";
    cout << "[5] Exit\n";
    cout << "______________________________________________________________________\n";
    cout << "----------------------------------------------------------------------\n";

}

bool ValidateLogin()
{
    string Name;
    int Password, Counter = 0;

    cout << "\n";
    cout << "=====================================\n";
    cout << setw(25) << "🔐 Login System\n";
    cout << "=====================================\n\n";

    do
    {
        if (Counter == 3)
        {
            return false;
        }
        else {
            cout << ("NAME: ");
            cin >> Name;
            cout << ("Password: ");
            cin >> Password;

            Counter++;
        }
        cout << endl;
    } while (Name != "admin" || Password != 1234);

    return true;
}

void DisplayAllAccountsScreen(vector <sClient>& Client)
{
    system("cls");
    DisplayClientTableHeader();
    DepositToClient(Client);
    cout << "\n\n";

    cout << "\n\nEnter any Press To Back Main...";
    system("pause>0");
}

void CreateAccountsScreen(vector <sClient>& Client)
{
    system("cls");
    cout << "------------------------------------\n";
    cout << "\tScreen Create Client\n";
    cout << "------------------------------------\n\n";
    CreateMultipleClients(Client);

    cout << "\n\nEnter any Press To Back Main...";
    system("pause>0");
}

void RunBankSystem()
{
    vector <sClient> Account;
    bool exitProgram = false;

    while (!exitProgram) {

        short choice;

        system("cls");
        DisplayMainMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateAccountsScreen(Account);
            break;
        case 2:
            DisplayAllAccountsScreen(Account);
            break;
        case 3:
            SearchClientByNumber(Account);
            break;
        case 4:
            DepositToClientByNumber(Account);
            break;
        case 5:
            exitProgram = true;
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }
}

void RunLoginScreen()
{
    bool CheckAccounts = ValidateLogin();
    if (CheckAccounts)
    {
        system("cls");
        RunBankSystem();
    }
    else
    {
        cout << "\nAccount is looked!\n\n";
    }
}

int main()
{

    RunLoginScreen();

    return 0;
}
