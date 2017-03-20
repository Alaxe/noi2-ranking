#include<iostream>
#include<cmath>
#include<string>
using namespace std;
long long int m,n;
void Read()
{
    cin>>n>>m;
}
int Resh()
{
    long long int x,y,sum=0;
    x=sqrt(n);
    y=sqrt(m);
    sum+=y-x;
    if(x*(x+1)>=n)
    {
        sum++;
    }
    if(y*(y+1)>m)
    {
        sum--;
    }
    return sum;
}
int main()
{
Read();
cout<<Resh()<<endl;
return 0;
}
