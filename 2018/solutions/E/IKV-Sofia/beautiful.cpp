#include <iostream>
using namespace std;
int main (){
int delitel,n,cifri=1;
cin>>n>>delitel;
while(n>1)
{
cifri*=10;
n--;
}
if(cifri%delitel!=0)
cifri+=delitel-(cifri%delitel);
cout<<cifri;
}
