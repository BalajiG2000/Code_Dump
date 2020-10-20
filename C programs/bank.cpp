#include <iostream>
using namespace std;

// class
class Bank
{
private:
  int acno;
  char name[30];
  long balance;

public:
  void OpenAccount ()
  {
    cout << "Enter Account Number: ";
    cin >> acno;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter  Balance: ";
    cin >> balance;
  }
  void ShowAccount ()
  {
    cout << "Account Number: " << acno << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
  }
  void Deposit ()
  {
    long amt;
    cout << "Enter Amount U want to deposit? ";
    cin >> amt;
    balance = balance + amt;
    cout << "Balance is"<<balance;
  }
  void Withdrawal ()
  {
    long amt;
    cout << "Enter Amount U want to withdraw? ";
    cin >> amt;
    if (amt <= balance)
      {
	balance = balance - amt;
	cout << "Remaining amount is " << balance;

      }
    else
      cout << "Less Balance..." << endl;
  }
  int Search (int);
};

int
Bank::Search (int a)
{
  if (acno == a)
    {
      ShowAccount ();
      return (1);
    }
  return (0);
}

// main code
int
main ()
{
  Bank C[100];
  int num;
  cout << "Enter number of details you want to enter ";
  cin >> num;

  int found = 0, a, ch, i;
  for (i = 0; i <= num; i++)
    {
      C[i].OpenAccount ();
    }

  do
    {
      // display options
      cout <<
	"\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" <<
	endl;

      // user input
      cout << "Please input your choice: ";
      cin >> ch;

      switch (ch)
	{
	case 1:		// displating account info
	  for (i = 0; i <= 2; i++)
	    {
	      C[i].ShowAccount ();
	    }
	  break;
	case 2:		// searching the record
	  cout << "Account Number? ";
	  cin >> a;
	  for (i = 0; i <= 2; i++)
	    {
	      found = C[i].Search (a);
	      if (found)
		break;
	    }
	  if (!found)
	    cout << "Record Not Found" << endl;
	  break;
	case 3:		// deposit operation
	  cout << "Account Number To Deposit Amount? ";
	  cin >> a;
	  for (i = 0; i <= 2; i++)
	    {
	      found = C[i].Search (a);
	      if (found)
		{
		  C[i].Deposit ();
		  break;
		}
	    }
	  if (!found)
	    cout << "Record Not Found" << endl;
	  break;
	case 4:		// withdraw operation
	  cout << "Account Number To Withdraw Amount? ";
	  cin >> a;
	  for (i = 0; i <= 2; i++)
	    {
	      found = C[i].Search (a);
	      if (found)
		{
		  C[i].Withdrawal ();
		  break;
		}
	    }
	  if (!found)
	    cout << "Record Not Found" << endl;
	  break;
	case 5:		// exit
	  cout << "Have a nice day" << endl;
	  break;
	default:
	  cout << "Wrong Option" << endl;
	}
    }
  while (ch != 5);
  return 0;
}
