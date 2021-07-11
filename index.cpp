#include<iostream>
#include<ctime>
using namespace std;

void transaction();
void goodBye();

void welcome() {
  cout<<"Welcome to an ATM Simulator"<< endl << endl;
}

string askForName() {
  string name;
  cout<<"May I know your name?"<< endl;
  cin>>name;
  return name;
}

string greeting(string name) {
  string greet;
  time_t currTime;
  currTime = time(NULL);

  tm *tmLocal = localtime(&currTime);

  if((tmLocal->tm_hour > 0) && (tmLocal->tm_hour < 12)) greet = "Morning";
  else if((tmLocal->tm_hour >= 12) && (tmLocal->tm_hour < 17)) greet = "Afternoon";
  else if((tmLocal->tm_hour >= 17) && (tmLocal->tm_hour < 20)) greet ="Evening";
  else greet = "Night";

  greet = greet.append(" " + name + ",");
  return greet;
}

float balance = 0;
int reTransaction;

void anotherTransaction() {
  cout<< endl <<"Do you want another transaction?\nPress 1 to proceed or 2 to exit"<< endl <<">>";
  cin>>reTransaction;
  if(reTransaction == 1) 
    transaction();
  else 
    goodBye();
}

void transaction() {
  int amountWithDraw, amountDeposit;
  int option;
  cout<<"Enter any option to be served!"<< endl<<"1. Withdraw"<< endl<<"2. Deposit"<< endl<<"3. Balance"<< endl<<endl;
  cin>>option;

  switch(option) {
    // withdraw
    case 1: 
      cout<<"Enter the amount to withdraw: ";
      cin>>amountWithDraw;
      if(amountWithDraw > balance) {
        cout<<"There is NO INSUFFICIENT balance in your account." <<endl;
        anotherTransaction();
        break;
      } else {
        balance -= amountWithDraw;
        cout<<"You have withdrawn Rs " << amountWithDraw << ".00 and you remaining balance is Rs " << balance << ".00" << endl;
        anotherTransaction();
        break;
      }

    // deposit
    case 2: 
      cout<<"Enter the amount to deposit: ";
      cin>>amountDeposit;
      balance += amountDeposit;
      cout<<"Thank you for depositing, New balance is: Rs "<< balance <<".00"<< endl;
      anotherTransaction();
      break;

    // to check the balance
    case 3: 
      cout<<"You net bank balance is: Rs "<< balance << endl;
      anotherTransaction();
      break;
    
    default: 
      cout<<"Ooh ! That's not the correct responce.";
      anotherTransaction();
      break;
  }
}

void goodBye() {
  cout<<"Thanks for using our service!!!"<< endl;
  cout<<"Have a nice day !!"<< endl;
  return;
}

int main() {
  welcome();
  cout<<"Good "<<greeting(askForName())<< endl;
  transaction();
  return 0;
}
