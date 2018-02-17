#include<iostream>
using namespace std;
int a[1024];
int n;
long long br;
void finding(int index,int d)
{
    br=(br+1)%123456789012345;
    for(int i=index+1;i<n;i++)
    {
        if(a[i]-a[index]==d)finding(i,d);
    }
}
void searching()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])finding(j,a[j]-a[i]);
        }
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    searching();
    cout<<br<<'\n';
}
