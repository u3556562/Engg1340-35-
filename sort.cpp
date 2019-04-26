#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include "extern.h"
#include "Random_customer.h"
using namespace std;

void sort(){
	int time[customerno];
	
	for (int i=0;i<customerno;i++){
		time[i]=customerlist[i].totalprice/10;
	}
	int sum=0;
	for (int i=0;i<customerno;i++){
		sum+=time[i];
	}
	cout<<sum<<endl;
	int cashierno = sum/900-1;
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
	int n=customerno/cashierno+1;
	customertrolley temp4;
	customertrolley **sort=new customertrolley*[n];
	for (int i=0;i<n;i++){
		sort[i]=new customertrolley[cashierno];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<cashierno;j++){
			if (i*cashierno+j>=customerno){
				sort[i][j].order=0;
				sort[i][j].totalprice=0;
			}
			else{			
				sort[i][j]=customerlist[i*cashierno+j];
			}
		}
		if (i%2==1){
			for (int k=0;k<cashierno/2;k++){
				temp4=sort[i][k];
				sort[i][k]=sort[i][cashierno-k-1];
				sort[i][cashierno-k]=temp4;
			}
		}			
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<cashierno;j++){
			cout<<sort[i][j].totalprice/10<<"	";
		}
		cout<<endl;
	}
	int waitingtime=0;
	for (int i=0;i<cashierno;i++){
		cout<<"Cashier "<<i+1<<": "<<endl;
		for (int j=0;j<n;j++){
			waitingtime=0;
			if (sort[j][i].order>customerno||sort[j][i].order<=0){
				continue;
			}
			else if (j==0){
				waitingtime=0;
			}
			else{
				for (int k=0;k<j;k++){
					waitingtime+=sort[k][i].totalprice/10+1;
				}
			}
			cout<<j+1<<":"<<"Customer "<<sort[j][i].order<<": "<<sort[j][i].totalprice<<"	"<<waitingtime<<endl;
		}
	}
}

#endif
