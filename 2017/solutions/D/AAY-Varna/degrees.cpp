#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string a="";
    a+="2";
    ///cout<<a<<endl;
    int sum=0,br=0;
    int b[1030]={0};
   b[0]=1;
    while(sum<=160000)
    {
        string rez;
        int prenos,tmp,i;
        rez.resize (a.size());
        prenos=0;
        for (i=a.size()-1; i>=0; i--)
        {
            tmp= (a[i]-'0')+(a[i]-'0')+prenos;
            rez[i]=tmp%10+'0';
            prenos=tmp/10;
        }
        if (prenos) rez='1'+rez;
        sum+=rez.size();
        b[br+1]=sum+1;
        br++;
        a=rez;
    }
    string t;
    cin>>t;

    for(int i=0;i<=1028;i++)
    {
        if(t.size()==b[i])
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
}
