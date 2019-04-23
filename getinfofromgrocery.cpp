#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct grocerytypeprice{
  string name;
  int random;
};
grocerytypeprice arr[12];
int upper[12];
int lower[12];
int main(){
  srand(time(NULL));
  ifstream grocery;
  grocery.open("groceryfile.txt");
  if (grocery.fail()){
    cout << "FAILED" << endl;
    exit(1);
  }
string grocerytype;

int count=0;
while(getline(grocery,grocerytype)){

  //cout << grocerytype << " " <<count << endl;
  if (count%3==0){
    arr[count/3].name = grocerytype;
  }
  else if (count%3==1){
    int a = stoi(grocerytype);
    lower[count/3] = a;
  }
  else if (count%3==2){
    int a = stoi(grocerytype);
    upper[count/3] = a;
  }

  count ++;
}

for (int i=0;i<12 ; i++){
  arr[i].random = rand()%(upper[i]-lower[i]) + lower[i];
  cout << arr[i].name << " " << arr[i].random  << endl;

}

grocery.close();

