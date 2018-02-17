#include<iostream>
using namespace std;
int b,n;
string ans="";
int m[10005],a[10005];
bool solve ()
{
    int naum=0;
    if (a[0]-m[n-1]>=0)
    {
        a[n-1]=a[0]-m[n-1];
    }
    if (a[0]-m[n-1]<0)
    {
        a[n-1]=a[0]-m[n-1]+b;
        naum=1;
    }
    for (int i=n-2; i>0; i--)
    {
        int s=a[i+1]-m[i]-naum;
        naum=0;
        if (s<0)
        {
            naum=1;
            s+=b;
        }
        a[i]=s;
    }
    if (a[1]==0)
        return false;
    if (a[0]+m[0]+naum!=a[1])
        return false;
    return true;
}
void print()
{
    for (int i=0; i<n; i++)
        if (a[i]<=9)
            cout<<a[i];
        else
            cout<<char(a[i]-10+'A');
    cout<<'\n';
}
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    cin>>b;
    for (int i=0; i<4; i++)
    {
        bool flag=false;
        string z;
        cin>>z;
        n=z.size();
        for (int j=0; j<z.size(); j++)
        {
            if (z[j]<='9')
               m[j]=z[j]-'0';
            else
                m[j]=z[j]-'A'+10;
        }
        for (int j=1; j<b; j++)
        {
            a[0]=j;
            if (solve())
            {
                print();
                flag=true;
                break;
            }
        }
        if (!flag)
            cout<<"0\n";
    }
    return 0;
}
