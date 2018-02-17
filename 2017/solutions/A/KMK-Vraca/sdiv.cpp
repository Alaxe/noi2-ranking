#include<iostream>
#include<string.h>
#include<iomanip>
#include<sstream>
using namespace std;

int main ()
{
	
	string numberRow;
	
	cin>>numberRow;
	
	int n, m;
	int beginning;
	cout<<"NO SKIPS:";
	for (int i = 0; i < numberRow.length() - 1 /*we will only get the last number and we look at it in EACH NUMBER*/; i++) {
		if (i != numberRow.length() - 1) {
			beginning = i + 1;
		} else {
			beginning = i;
		}
		
		cout<<numberRow[i];
		for (int j = beginning; j < numberRow.length() ; j++) {
			cout<<numberRow[j];
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	
	
	<<"EACH NUMBER: "<<endl;
	for (int i = 0; i < numberRow.length(); i++) {
		cout<<numberRow[i]<<endl;
	}
	
	cout<<endl<<endl;

	int maxSkips;
	int minSkips;
	cout<<"WITH SKIPS:"<<endl;
	for (int i = 0; i < numberRow.length(); i++) {
		
		if (i >= numberRow.length() - 2) {
			minSkips = 0;	
		} else {
			minSkips = 2;
		}
		
		maxSkips = numberRow.length() - i;
		
		if (minSkips != 0) {
			//cout<<numberRow[i];
			for (int currentSkip = minSkips; currentSkip < maxSkips; currentSkip++) {
				cout<<numberRow[i];
				cout<<numberRow[i + currentSkip]<<endl;
			}
			cout<<endl;	
		}
	}
	
	cout<<endl<<endl;
	
	int maximumuSkips;
	int mimimumSkips;
	cout<<"LARGER SKIPS:"<<endl;
	for (int i = 0; i < numberRow.length(); i++) {
		if (i <= numberRow.length() - 1 - 2) {
			for (int skip = 2; skip < numberRow.length() - i; skip++) {
				if (i + skip < numberRow.length() - 1) {
					cout<<numberRow[i];
					for (int j = i + skip; j < numberRow.length(); j++) {
						cout<<numberRow[j];
					}
					cout<<endl;	
				}	
			}	
		}
	}
	
	
	stringstream convert(numberRow);
	int number;
	convert>>number;
	cout<<endl<<endl<<number;
	
	return 0;
}
