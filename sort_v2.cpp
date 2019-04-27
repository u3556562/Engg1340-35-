#include <iostream>
#include <algorithm>
#include <cmath>
#include "extern.h"
#include "Random_customer.h"
using namespace std;
int netincome = -100000;
int cashierno;

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

	//row[i]=number of element in cashier i+1 for i = 0 -> column
	//cashier no = column
	customertrolley** cashier=new customertrolley* [customerno];
	for (int i=0;i<customerno;i++){
		cashier[i]=new customertrolley[customerno];
	}
	int *row= new int[customerno];
	customertrolley *overflow = new customertrolley[customerno];
	int cashierno,column=0, count=0, temp=0, n=0, end=0, overflownum=0;
	cout<<"Number of cashier: ";
	cin>>cashierno;

	while (count<customerno){
		if (column==cashierno){
			for (int i=0;i<customerno-count;i++){
				overflow[i]=customerlist[count-end+i];
				overflownum++;
			}
			break;
		}
		for (int i=0;i<temp;i++){
			n+=cashier[i][column].totalprice/10+1;
		}
		if ((n+customerlist[count-end].totalprice/10+1)<900){
			cashier[temp][column]=customerlist[count-end];
			temp++, count++;
		}
		else{
			cashier[temp][column]=customerlist[customerno-end-1];
			row[column]=temp+1;
			end++, column++, count++;
			temp=0;
		}
		n=0;
	}
	if (count==customerno){
		row[column]=temp;
		column++;
	}
	int waitingtime=0;
	for(int i=0;i<cashierno;i++){
		cout<<"Cashier "<<i+1<<":"<<endl;
		for (int j=row[i]-1;j>=0;j--){
			for (int k=0;k<j;k++){
				waitingtime+=cashier[k][i].totalprice/10+1;
			}
			cout<<"Customer "<<cashier[j][i].order<<"	"<<cashier[j][i].totalprice<<"	"<<waitingtime<<endl;;
			waitingtime=0;
		}
		cout<<endl;
	}
	if (overflownum!=0){
		cout<<"Overflow:"<<endl;
		for (int i=0;i<overflownum;i++){
			cout<<"Customer "<<overflow[i].order<<"	"<<overflow[i].totalprice<<endl;
		}
	}
	
	
	
// =============================FOLLOW-UP ACTION======================================
	int realnetincome=0;
	//cout << column << endl;
	for (int i=0;i<cashierno;i++){
		netincome+=customerlist[customerno-1-i].totalprice;
		realnetincome+=customerlist[customerno-1-i].totalprice;
	}


// 				I customised some expenses to make it difficult to save money and open a new cashier line
	cout <<"NETINCOME = " << realnetincome << endl;
	cout << "Cashier Operating Costs = " << cashierno*1500 << endl;
	cout << "Other Expenses = " << cashierno*500+500 << endl;
	netincome = netincome - cashierno*1500 - cashierno*5000 - 500;
	cout <<"Net Profit = " << netincome<< endl;



// 				If I can directly change the cashier line number (I'm not sure if column = number of cashier)
//				And I can't change the column either, so I left a comment there
	//cout << "Do you want to open a new cashier line? Cost = " << cashierno*5000 << " (Y/N): ";
	//char reply;
	//cin >> reply;
	//cout << endl;
	//while (true){
	//if (reply=='Y'){
		//cashierno++;
		//netincome -= cashierno*5000;
		//break;
	//}
	//else if (reply=='N'){
		//break;
	//}
	//else if (reply!='Y' and reply!='N'){
		//cout << "Unknown Command! " <<endl;
	//	cout << "Do you want to open a new cashier line? Cost = " << cashierno*5000 << " (Y?N): ";
		//cin>>reply;
	//}
//}


}
