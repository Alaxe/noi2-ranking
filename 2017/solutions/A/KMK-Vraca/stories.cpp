#include<iostream>
using namespace std;

int main ()
{
	long long n, k;
	//number of days in total, the longest period to tell a story
	cin>>n>>k;
	
	long long biggestFactorEachDay[n];
	//have to look back 3 days
	
	long long first, mul, add, mod;
	//a[0] = first;
	//a[i] = (a[i-1] * mul + add) % mod;
	cin>>first>>mul>>add>>mod;
	
	long long dailyEventFunFactor[n];
	//according to the formula we calculate the fun factor of the events each day;
	
	//the first day fun factor is static
	dailyEventFunFactor[0] = first;
	biggestFactorEachDay[0] = first;
	
	for (int day = 1 /*we already checked the first[0] day*/; day < n; day++) {
		dailyEventFunFactor[day] = (dailyEventFunFactor[day-1] * mul + add) % mod;
	}
	
	//now we want to see what is the most funny thing she can say each day
	 	
	long long sumFunFactor = 0;
	
	int daysBehind = 0;
	
	long long max = 0;
	
	long long biggerVariable, smallerVariable;
	
	long long startingDay, endingDay;
	
	for (int day = 0; day < n; day++) {
		
		if (day - k < 0) {
			startingDay = 0;
			endingDay = day;
		} else if (day - k >= 0) {
			startingDay = day + 1 - k;
			endingDay = day;
		} 
			
		//cout<<"max="<<max<<endl;	
		//cout<<"looking days from "<<startingDay<<" "<<endingDay<<"..."<<endl<<endl;
				
		//cout<<"DAY "<<day + 1<<" :";		
		for (int searcher = startingDay; searcher <= endingDay; searcher++) {
			//cout<<dailyEventFunFactor[searcher]<<",   "; 
			if (max <= dailyEventFunFactor[searcher]) {
				max = dailyEventFunFactor[searcher];
			}
		}
		
		//cout<<endl<<"max="<<max<<endl;
		//cout<<endl<<endl;
		
		biggestFactorEachDay[day] = max;
		max = 0;
	}
	
	biggestFactorEachDay[0] = first;
	
//	for (int day = 0; day < n; day++) {
//		cout<<dailyEventFunFactor[day]<<" ";
//	}
//	
//	cout<<endl<<endl;
//	
//	for (int day = 0; day < n; day++) {
//		cout<<biggestFactorEachDay[day];
//		if (day != n - 1) {
//			//cout<<"+";
//		}
//	}
	
	//we calculate the sum of the biggest fun factor each day
	for (int day = 0; day < n; day++) {
		sumFunFactor += biggestFactorEachDay[day];
	}
	
	cout/*<<"="*/<<sumFunFactor;

	return 0;
}

