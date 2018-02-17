#include<bits/stdc++.h>
using namespace std;
long long br,i=0,j;
string s,rez="1";
string stepen (string a)
{
    int i,pr=0;
    string rez1;
    rez1.resize (a.size()+1);
    for (i=a.size()-1;i>=0;i--)
    {
        a[i]=a[i]-'0';
        rez1[i+1]=char((a[i]*2+pr)%10+48);
        pr=(a[i]*2+pr)/10;
    }
    if (pr>0)
    {
        rez1[i+1]=char (pr+48);
    }
    else rez1.erase (0,1);
    return rez1;
}
int main()
{
    cin>>s;
    s=s+'*';
    for (;;)
    {
        rez=stepen (rez);
        i=i+rez.size();
        br++;
        if (s[i]=='*') break;
    }
    if (s[0]=='1') cout<<"0"<<endl;
    else cout<<br<<endl;
    return 0;
}
/**
2

1
///////
2481632

5
//////////////////
248163264128256512

9
*/
