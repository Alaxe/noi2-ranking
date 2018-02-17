#include<iostream>
using namespace std;

int main()
{
int a[12];
int br=0;
for(int i=0;i<12;i++)
{
cin>>a[i] ;   
}
for(int i=0;i<12;i++)
{
if(a[i]<br)br++;
cout<<a[i]<<endl;
        
}        
return 0;
}