#include<iostream>
using namespace std;
long long  m,k;
int main()
{
long long pch=0,sborch=0,i;
cin >> m >> k;

for(i=1; i<=200; i++)
{
    cin >> i;
    if(m-i<=pch || i-m<=pch || i==m) pch+=1;
    else if(m-i>pch && i-m>pch && i!=m) pch+=0;
    if(i%2==0) sborch+=i;
    if(sborch>k) break;

}
cout << pch << " " << sborch;
}
/**
Вход:
7 30
1
3
12
8
25
6
14

Изход:
6 40
*/
