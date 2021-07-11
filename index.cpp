#include<iostream>
using namespace std;

void welcome() {
  cout<<"Welcome to an ATM Simulator"<<endl;
}

string askForName() {
  string name;
  cout<<"May I know your name?"<<endl;
  cin>>name;
  return name;
}

int main() {
  welcome();
  cout<<askForName();
  // greating();
  // transaction();
  return 0;
}
