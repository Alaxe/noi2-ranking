#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000000];
long long b[1000000];
long long chis[1002];
long long n;

void rec(long long sum,long long num)
{


    sum+=chis[num];

        if(sum<0)
        {
            b[sum*(-1)]++;
        }
        else a[sum]++;

    if(num<n-1)rec(sum,num+1);
    if(num<n-2)rec(sum,num+2);

    if(num!=n-1)rec(0,num+1);



}
int main ()
{
    int br=0;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>chis[i];
}
rec(0,0);

for(int i=0;i<1000000;i++)
{
    if(a[i]>0)br++;
}
cout<<endl;


for(int i=0;i<1000000;i++)
{
    if(b[i]>0)br++;
}
cout<<br<<endl;
return 0;

}
