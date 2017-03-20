#include<bits/stdc++.h>
using namespace std;
string h="1";
string lls()
{
    string g;
    int tmp,prenos=0,p;
    for(int i=h.size()-1;i>=0;i--)
    {
        tmp=(h[i]-'0')*2;
        p=tmp%10+prenos;
        prenos=tmp/10;
        g=(char){p+'0'}+g;
    }
    if(prenos==1) g='1'+g;
    h=g;
    return g;

}
int main()
{
    string k,k1;
    int br=0;
    cin>>k;
    while(k.size()>k1.size())
    {
        k1+=lls();
        br++;
    }
    cout<<br<<endl;
}
