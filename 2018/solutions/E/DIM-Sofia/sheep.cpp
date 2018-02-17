#include<iostream>
using namespace std;
int main(){
long long broiOvce,brZagubeni,ChisloZaSega,ngChislo,x;
cin>>broiOvce>>brZagubeni;
long long zagubeni[brZagubeni];
ChisloZaSega=0;
x=brZagubeni;
while(brZagubeni>0){
        cin>>zagubeni[brZagubeni];
    brZagubeni=brZagubeni-1;
}
return 0;
}
