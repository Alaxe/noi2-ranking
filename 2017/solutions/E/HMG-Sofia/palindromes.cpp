#include<iostream>
using namespace std;
int main(){
long long a,b,palindrome,N,ed,des,stot,hil,dhil,stohil,mil;
cin>>N;
a=1;
b=1;
if(N<=1000 and N>1){
       while(b<N-1){ b++;
    while(a<N-1){
        palindrome=a*b;
        ed=palindrome%10;
        des=(palindrome/10)/10;
        stot=palindrome/100;
        hil=palindrome/1000;
        dhil=palindrome/10000;
        stohil=palindrome/100000;
        mil=palindrome/1000000;
        a++;
       }
        while(ed==mil && des==stohil && stot==dhil){
  }}
cout<<a<<" "<<b<<"\n"<<(a-8)*b;
}
return 0;
}
