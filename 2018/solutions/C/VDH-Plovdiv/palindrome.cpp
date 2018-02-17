#include <bits/stdc++.h>
using namespace std;
int cmp(string s1, string s2)
{
    if (s1.size()>s2.size()) return 1;
    if (s2.size()>s1.size()) return 0;
    for (int i=0; i<s1.size(); i++)
    {
        if (s1[i]>s2[i]) return 1;
        if (s2[i]>s1[i]) return 0;
    }
    return -1;
}

int main()
{
    string s;
    cin>>s;
    string pal="";
    int n=s.size(), n2=0;
    if (n%2==0)
    {n2=n/2;
        pal=s.substr(0, n2);
        for (int i=n2-1; i>=0; i--)
            pal=pal+pal[i];
    }
    else
    {
        n2=n/2;
        pal=s.substr(0, n2+1);
        for (int i=n2-1; i>=0; i--)
            pal=pal+pal[i];
    }
    if (cmp(pal, s)==1) cout<<pal<<endl;
    else
    {
        int i=n/2-1;
        if (n%2==1) i++;
        while (pal[i]=='9' && i>=0)
            i--;
        if (i<0)
        {
            cout<<"1";
            for (int j=0; j<n-1; j++) cout<<"0";
            cout<<"1\n";
        }else{
        int p[1310];
        for (int j=0; j<n; j++)
        {
            p[j]=pal[j]-48;
        }
        p[i]=p[i]+1;
        p[n-i-1]=p[i];
        for (int j=i+1; j<n-i-1; j++)
        {
            p[j]=0;
        }
        for (int j=0; j<n; j++)
            cout<<p[j];
        cout<<endl;}
    }
    return 0;
}
