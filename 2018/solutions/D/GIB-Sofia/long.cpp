#include<iostream>
#include<cmath>
#include<cmath>
using namespace std;
int main(){
unsigned short int n;
unsigned long int k;
unsigned long long int num;

cin>>n>>k;
for(unsigned long long int min=pow(10,n-1);min<pow(10,n);min++){
    if(min%k==0){
        num=min;
        break;
    }
}
cout<<num;
return 0;
}
