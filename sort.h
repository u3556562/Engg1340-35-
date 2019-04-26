#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include "extern.h"
#include "Random_customer.h"
using namespace std;

void sort(){
	int *time=new int[customerno];

	for (int i=0;i<customerno;i++){
		time[i]=customerlist[i].totalprice/10;
	}
	int temp1,temp2,temp3;
	for (int i=0;i<customerno-1;i++){
		for (int j=0;j<customerno-1-i;j++){
			if (time[j]>time[j+1]){
				temp1=time[j];
				time[j]=time[j+1];
				time[j+1]=temp1;
				temp3=customerlist[j].order;
				customerlist[j].order=customerlist[j+1].order;
				customerlist[j+1].order=temp3;
				temp2=customerlist[j].totalprice;
				customerlist[j].totalprice=customerlist[j+1].totalprice;
				customerlist[j+1].totalprice=temp2;
			}
		}
	}
	customertrolley** cashier=new customertrolley* [customerno];
	for (int i=0;i<customerno;i++){
		cashier[i]=new customertrolley[customerno];
	}
	int row=0, column=0, count=0, temp=0, n=0, end=0;
	while (count<customerno){
		for (int i=0;i<temp;i++){
			n+=cashier[i][column].totalprice/10+1;
		}
		if ((n+customerlist[count-end].totalprice/10+1)<900){
			cashier[temp][column]=customerlist[count-end];
			temp++, count++;
		}
		else{
			cashier[temp][column]=customerlist[customerno-end-1];
			if (temp>row){
				row=temp+1;
			}
			end++, column++, count++;
			temp=0;
		}
		n=0;
	}
	int waitingtime=0;
	for(int i=0;i<column;i++){
		cout<<"Cashier "<<i+1<<":"<<endl;
		for (int j=0;j<row;j++){
			if (cashier[j][i].order<=0||cashier[j][i].order>customerno){
				continue;
			}
			else{
				for (int k=0;k<j;k++){
					waitingtime+=cashier[k][i].totalprice/10+1;
				}
				cout<<"Customer "<<cashier[j][i].order<<"	"<<cashier[j][i].totalprice<<"	"<<waitingtime<<endl;;
				waitingtime=0;
			}
		}
	}
}
#endif
