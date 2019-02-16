#include<iostream>
using namespace std;
long long n,a[10001];
bool proverka(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(x%a[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
int main ()
{
    long long i,c=1,b;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>a[i];
}
do
{
    c++;
    b=c*c;
}while(proverka(b)==0);
cout<<c<<endl;
return 0;
}
