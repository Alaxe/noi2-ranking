#include<iostream>>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],br=0;
    for (int i=0;i<n;i++)
    {
    cin>>a[i]>>b[i];
    }
    for (int h=0;h<n;h++)
    {for (int g=0;g<n;g++)
    {if (a[h]==b[g] and h!=g and b[h]!=a[h] and b[g]!=a[g] and b[h]!=a[g])br++; }}
    cout<<br+1;
 return 0;
}
