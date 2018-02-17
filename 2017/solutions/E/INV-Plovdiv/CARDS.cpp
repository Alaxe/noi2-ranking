#include<iostream>
using namespace std;
int main()
{
long long mas[1000],n,i,br=1;
cin>>n;
for(i=0;i<n;i++)
{
    cin>>mas[i];
}
for(i=0;i<n;i=i+2)
{
    if(mas[i]!=mas[i+2] || mas[i+1]!=mas[i+3]) br++;
}
cout<<br<<endl;
return 0;
}
