/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Account
{
private:
  string first_name;
  string last_name;
  float balance;
  int account_number;
  static int total_accounts;

public:
    Account ()
  {
    this->account_number = -1;
  }

  Account (string f, string l, float b)
  {
    static int total_accounts;
    ++total_accounts;

    this->first_name = f;
    this->last_name = l;
    this->balance = b;
    this->account_number = total_accounts;
  }

  void deposit_balance (float b)
  {
    this->balance += b;
  }

  void withdrawal_balance (float b)
  {
    this->balance -= b;
  }

  void close_account ()
  {
    this->account_number = -1;
  }

  string const get_first_name ()
  {
    return this->first_name;
  }

  string const get_last_name ()
  {
    return this->last_name;
  }

  float const get_balance ()
  {
    return this->balance;
  }

  int const get_account_number ()
  {
    return this->account_number;
  }

  void const display_account ()
  {
    if (this->get_account_number () != -1)	// Check if not empty account
      {
	cout << "First Name: " << this->get_first_name () << endl;
	cout << "Last Name:" << this->get_last_name () << endl;
	cout << "Account Number:" << this->get_account_number () << endl;
	cout << "Balance:" << this->get_balance () << endl;
      }
  }

  bool operator == (Account & other)
  {
    if (this->get_account_number () == other.get_account_number ())
      return true;
    return false;
  }

};

int
  Account::total_accounts = 0;

void
menu ()
{
  cout << "Select one option below" << endl;
  cout << "1 Open an Account" << endl;
  cout << "2 Balance Enquiry" << endl;
  cout << "3 Deposit" << endl;
  cout << "4 Withdrawal" << endl;
  cout << "5 Close an Account" << endl;
  cout << "6 Show All accounts" << endl;
  cout << "7 Quit" << endl;
}

Account
open_account ()
{
  //1 Open an Account
  string
    first_name,
    last_name;
  float
    balance;

  cout << endl << "Enter First Name: ";
  cin >> first_name;
  cout << "Enter Last Name: ";
  cin >> last_name;
  cout << "Enter Initial Balance: ";
  cin >> balance;

  Account
    a = Account (first_name, last_name, balance);

  cout << endl << "Congradulation Account is created" << endl;
  a.display_account ();

  return a;
}

void
display_all_accounts ()
{
  static
    Account
    accounts[10];
  static int
    accounts_counter;

for (Account a:accounts)
    {
      if (a.get_account_number () != -1)	// Check if not empty account
	{
	  cout << endl << "Account " << endl;
	  a.display_account ();
	  cout << endl;
	}

    }
}

void
control_panel (int choice)
{
  static
    Account
    accounts[10];
  static int
    accounts_counter = 0;
  int
    account_number;
  float
    amount;

  switch (choice)
    {
    case 1:
      accounts[accounts_counter] = open_account ();
      ++accounts_counter;
      break;

    case 2:
      cout << "Enter Account Number: ";
      cin >> account_number;
      cout << endl;
      accounts[account_number - 1].display_account ();
      cout << endl;
      break;

    case 3:
      cout << "Enter Account Number: ";
      cin >> account_number;
      cout << "Enter Balance: ";
      cin >> amount;
      accounts[account_number - 1].deposit_balance (amount);
      cout << endl;
      accounts[account_number - 1].display_account ();
      cout << endl;
      break;

    case 4:
      cout << "Enter Account Number: ";
      cin >> account_number;
      cout << "Enter Balance: ";
      cin >> amount;
      accounts[account_number - 1].withdrawal_balance (amount);
      cout << endl;
      accounts[account_number - 1].display_account ();
      cout << endl;
      break;

    case 5:
      cout << "Enter Account Number: ";
      cin >> account_number;
      cout << "Account is Closed";
      accounts[account_number - 1].display_account ();
      accounts[account_number - 1].close_account ();

    for (Account a:accounts)
	{
	  if (a.get_account_number () != -1)	// Check if not empty account
	    {
	      cout << endl << "Account " << endl;
	      a.display_account ();
	      cout << endl;
	    }
	}
      break;

    case 6:
    for (Account a:accounts)
	{
	  if (a.get_account_number () != -1)	// Check if not empty account
	    {
	      cout << endl << "Account " << endl;
	      a.display_account ();
	      cout << endl;
	    }
	}
      break;

    case 7:
      cout << "Bye Bye!!!" << endl;
      exit (0);
      break;

    default:
      cout << "invalid input\n\n";
    }
}

int
main ()
{
  cout << "********** Banking System **********" << endl;
  int
    choice;

  static
    Account
    accounts[10];
  static int
    accounts_counter = 0;

  do
    {
      menu ();
      cout << "Enter your choice: ";
      cin >> choice;
      control_panel (choice);

    }
  while (choice != 7);

  return 0;
}
