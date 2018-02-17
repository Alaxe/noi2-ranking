#include<iostream>
using namespace std;
int main(){
long long n;
cin>>n;
long long chislo1[n],chislo2[n];
for(int i=0;i<n;i++){

cin>>chislo1[i];
cin>>chislo2[i];
}
long long vazmoznost;
for(int k=0;k<n;k++){
if(chislo1[k] <= chislo1[k+1] and chislo2[k] <= chislo2[k+1]){

vazmoznost=vazmoznost+1;
chislo1[k]=chislo1[k+1];
chislo2[k]=chislo2[k+1];
}
}
cout<<vazmoznost;



return 0;
}
