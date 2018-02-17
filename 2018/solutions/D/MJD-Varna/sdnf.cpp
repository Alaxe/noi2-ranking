#include<bits/stdc++.h>
using namespace std;
string pluss(string a,string b){
    string res;
    int tmp,prenos=0;
    if(a.size()>b.size()) b='0'+b;
    if(b.size()>a.size()) a='0'+a;
    b=b+'0';
    a='0'+a;
    for(int i=a.size()-1;i>=0;i--)
    {
        tmp=(a[i]-'0')+(b[i]-'0')+prenos;
        if(tmp>9){prenos=1;tmp=tmp%10;}
        else prenos = 0;
        res=(char)(tmp%10+'0')+res;
    }
    if(prenos==1) res='1'+res;
    return res;
}
string multi(string a,int b){
    string res;
res.resize(a.size()+1);
    int tmp,prenos=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        tmp=(a[i]-'0')*b+prenos;
        if(tmp>9) {prenos=tmp/10;tmp=tmp%10;}
        else prenos=0;

        res=(char)(tmp+'0')+res;

    }
    if(prenos!=0)
    {
        stringstream ss;
        ss<<prenos;
        string l=ss.str();
        res=l+res;
    }
    return res;
}
string multi2(string a,string b){

    string r1,r2,res;
    r1=multi(a,(b[0]-'0'));
    r2=multi(a,(b[1]-'0'));
    res=pluss(r1,r2);
    if(b.size()==2) return res;
    if(b.size()==1) return  multi(a,(b[0]-'0'));

    for(int i=0;i<=b.size()-1;i++)
    {
        //res=pluss(res,)
    }

}


unsigned long long int st;
unsigned long long int fact(unsigned long long int a) {
    if(st!=1) {st--; return fact(a*st);}
    else return a;
}
int main()
{
    int br;
    unsigned long long int n,r=0;
    cin>>n;
    st=n;
    string l;

        n=fact(n);
        stringstream ss;
        string res;
        ss<<n;
        res=ss.str();


        for(int i=0;i<=res.size()-1;i++)
        {
            r+=(res[i]-'0');
        }
        cout<<r<<endl;


        stringstream sss;
        sss<<n;
        string N=sss.str();

}
