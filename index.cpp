#include<iostream>
#include<ctime>
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

int main() {
  welcome();
  cout<<"Good "<<greeting(askForName())<<endl;
  // transaction();
  return 0;
}
