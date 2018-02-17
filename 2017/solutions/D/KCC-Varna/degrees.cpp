#include<bits/stdc++.h>
using namespace std;
string t,s,p;
int i,n,tmp,prenos;
int main()
{
    cin >> t;
    s="2";
    n=0;
    while(1)
    {
        if(t.find(s)==4294967295) break;
        prenos=0;
        p="";
        for ( i=s.size()-1; i>=0; i-- )
        {
            tmp=(s[i]-'0')*2+prenos;
            prenos=tmp/10;
            tmp%=10;
            p=char(tmp+'0')+p;
        }
        if(prenos==1) p='1'+p;
        s=p;
        n++;
    }
    cout << n << endl;
    return 0;
}
/**
2

2481632

248163264128256512
*/
