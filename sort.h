#ifndef SORT
#define SORT

#include <iostream>
#include <algorithm>
#include <cmath>
#include "extern.h"
#include "Random_customer.h"
using namespace std;
int netincome = 0;
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
	for(int i=0;i<column;i++){
		for (int j=0;j<row;j++){
	cout<<"i = " << i << "j = " << j <<" "<<cashier[j][i].order<<"	"<<cashier[j][i].totalprice<<"	" << endl;
}}
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








//===============================FOLLOW UP ACTION===================================





//				If the array has no bug, e.g. no elements missing and no overflow
// 				I can set column = column*2
// 				as in the photo I sent to you, the most expensive customers should be at the top of the queue
// 				and the first customer of the cashier line has waiting time < 900
// 				meaning that cashier line can handle the second customer after the first one finished
// 				so the column can double
//				and the cusotomerlist is in reverse order (i.e. last element of the customerlist is the most expensive one)
//				Below is how I add the most expensive customer's trolley price to our netincome

	//cout << column << endl;
	for (int i=0;i<column;i++){
		netincome+=customerlist[customerno-1-i].totalprice;
	}


// 				I customised some expenses to make it difficult to save money and open a new cashier line
	cout <<"NETINCOME = " << netincome << endl;
	cout << "Cashier Operating Costs = " << column*2500 << endl;
	cout << "Other Expenses = " << column*1000+500 << endl;
	netincome = netincome - column*2500 - column*1000 - 500;
	cout <<"Net Profit = " << netincome<< endl;



// 				If I can directly change the cashier line number (I'm not sure if column = number of cashier)
//				And I can't change the column either, so I left a comment there
	cout << "Do you want to open a new cashier line? Cost = " << column*5000 << " (Y/N): ";
	char reply;
	cin >> reply;
	cout << endl;
	while (true){
	if (reply=='Y'){
		//(no of cashier+1)
		netincome -= column*5000;
		break;
	}
	else if (reply=='N'){
		break;
	}
	else if (reply!='Y' and reply!='N'){
		cout << "Unknown Command! " <<endl;
		cout << "Do you want to open a new cashier line? Cost = " << column*5000 << " (Y?N): ";
		cin>>reply;
	}
}


}
#endif
