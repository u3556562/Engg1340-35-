#ifndef GETINFO
#define GETINFO

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

struct grocerytypeprice{
  string name;
  unsigned random;
};
grocerytypeprice arr[12];
int upper[12];
int lower[12];
void randomgroceryprice(){
  srand(time(NULL));
  ifstream grocery;
  grocery.open("grocery_file.txt");
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
  unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
  uniform_int_distribution<int> uniform_dist(lower[i],upper[i]);
  default_random_engine pb(seed);
  arr[i].random = uniform_dist(pb);
  //arr[i].random = prng;
  //cout << arr[i].name << " " << arr[i].random  << endl;

}

grocery.close();









}

#endif
