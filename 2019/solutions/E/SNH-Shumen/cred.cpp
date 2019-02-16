#include<iostream>
using namespace std;
long long int d(int n)
{
    int sum=0;
    do
    {
        int ch=n%10;
        sum+=ch;
        n=n/10;
    }while(n!=0);
    return sum;
}
int main()
{
long long int n,m,br=0;
cin>>n>>m;
for(int i=n;i+d(i)<=m;i++)
{
    i=i+d(i);
    br++;
    cout<<i<<" ";
}

cout<<br+1<<endl;
return 0;
}
