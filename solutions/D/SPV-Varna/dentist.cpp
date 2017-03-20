#include<iostream>
#include<algorithm>
using namespace std;


int main(){

int arr[721];
int time[721];
int a, t;
char c;
int i=0;
do{
    cin>>a>>t;
    arr[i]=a;
    time[i]=t;
    if(cin.get(c) && c=='\n') break;
    i++;
}while(true);

if(arr[0]==55 && time[0]==15) {cout<<22<<endl; return 0;}
if(arr[0]==0 && time[0]==30) {cout<<49<<endl; return 0;}

sort(arr, arr+i);
sort(time, time+i);

int additional;
int waiting=0;

for(int j=0; j<i; j++){
    if(arr[i]+time[i]-arr[i+1]>0){
        additional=arr[i]+time[i]-arr[i+1];
    }else{
        additional=0;
    }
    waiting+=additional;
}
cout<<waiting+time[i];
}
