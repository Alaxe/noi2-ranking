#include<iostream>
using namespace std;
int main()
{
long long int a,b;
cin>>a>>b;
int br=0;
int c=a;
for(int i=a;i<=b;i++)
{   c++;
    if(c%2==1)
    {
        br++;
    }
}
cout<<br<<endl;

return 0;
}
