#include <iostream>
#include "a.h"

using namespace std;

struct customertrolley{
  int order;
  int totalprice;
};

int main(){
  const int custumerno = 50;

  customertrolley customerlist[custumerno];
  int numbergrocery[custumerno];
  srand(time(NULL));
  for (int i=0;i<custumerno;i++){
    numbergrocery[i] = 1+rand()%10;
    customerlist[i].order = i+1;
    customerlist[i].totalprice =0;
  }

  for (int i=0; i<custumerno; i++){
    for (int j=0; j<numbergrocery[i]; j++){
      int whatgrocery = rand()%12;
      randomgroceryprice();

      customerlist[i].totalprice+=arr[whatgrocery].random;

    }
  }
  for (int i=0;i<custumerno;i++){
    cout << customerlist[i].order <<" " << customerlist[i].totalprice << endl;
  }
}
