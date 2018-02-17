#include<iostream>
#include<vector>
using namespace std;
long long n,k,a,b;
long long  prev[10000],digit[10000];
void gen(long long z)
{
    long long next[10000],o=0;
    for(int i=0;i<z;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                next[o]=digit[i]*10+prev[j];
                o++;
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                next[o]=digit[i]*10+prev[j];
                o++;
            }
        }
    }
    for(int i=0;i<o;i++)
    {
        digit[i]=next[i];
    }
}


int main ()
{
cin>>n>>k>>a>>b;
for(int i=0;i<n;i++)
{
    cin>>prev[i];
    digit[i]=prev[i];
}
int c=n;
a--;
b--;
for(int i=0;i<k-1;i++)
{
    gen(c);
    c*=n;
}
int max1=0,max2=0,sum=0;
for(int i=a;i<=b;i++)
{
    if(max1<digit[i])max1=digit[i];
    sum=0;
    while(digit[i]!=0)
    {
        sum+=digit[i]%10;
        digit[i]/=10;
    }
    digit[i]=sum;
}
cout<<max1<<" ";
for(int i=a;i<b;i++)
{
    int j=digit[i]-digit[i+1];
    if(j<0)j+=-1;
    if(max2<j)max2=j;

}
cout<<max2<<endl;

return 0;
}

