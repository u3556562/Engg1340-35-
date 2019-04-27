#include <iostream>
#include "Random_customer.h"
#include "sort v2.h"

using namespace std;

int main(){
  char response='Y';
  int day=1;
  while (true){

  cout << "Day " << day << ": " << endl;
  cout << "How many customers today? ";
  random50customers();
  sort();



  cout << "Go to the next day? (Y/N): ";
  cin >> response;
  cout << endl;
  if (response =='Y'){
    response = 'Y';
    day++;
  }
  else if (response =='N'){
    cout << "End of the game." << endl;
    break;
  }
  while (response!= 'Y'){
    cout << "Unknown Command! Please try again! (Y/N): ";
    cin >> response;
    cout << endl;
    if (response =='N'){
      cout <<  "End of the game." << endl;
      return 0;
    }
    else if (response == 'Y'){
      day++;
    }
  }
  }

  return 0;
  }
