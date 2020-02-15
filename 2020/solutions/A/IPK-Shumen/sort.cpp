#include <iostream>
using namespace std;
int n;
int m[100000];
void read()
{
    int a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        m[i]=a;
    }
}
void solve()
{
    int cnt=0,num=m[0],ind=0;
    for(int i=0;i<n-1;i++)
    {
        if(m[i]<m[i+1]||m[i]==m[i+1])
        {
            cnt+=0;
        }
        else
        {
            cnt+=m[i]-m[i+1];
            m[i]=m[i+1];
            num=m[i];
            ind=i+1;
            break;
        }
    }
    for(int j=ind+1;j<n;j++)
    {
        if(m[j]<num)
        {
            cnt+=num-m[j];
            m[j]=num;
        }
        else
        {
            num=m[j];
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    read();
    solve();
    return 0;
}
