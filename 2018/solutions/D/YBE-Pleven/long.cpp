#include <iostream>
using namespace std;

int n,d;
/*
string izravni(string a,string b){
int d1,d2,d,i;
    d1=a.size();
    d2=b.size();
    d=d2-d1;
    for(i=1;i<=d;i++)
        a='0'+a;
        return a;
}

string Sum(string a,string b){
int d1,d2,d,u,i;
string p;
    p="";
    d1=a.size();
    d2=b.size();
    if(d1<d2)a=izravni(a,b);
    if(d2<d1)b=izravni(b,a);
    d=max(d1,d2);
    u=0;
    int c=0;
    for(i=d-1;i>=0;i--){
        c=a[i]-'0'+b[i]-'0'+u;
        if(c>9){
            u=1;
            c=c%10;
        }
        else
            u=0;
        p=char(c+'0')+p;
    }
    if(u==1){
        p='1'+p;
    }

    return p;
}
*/
int main()
{
int i,p,k;
//string s,ss,q;
    cin>>n>>k;
    /*
   while(1){
        if(d==n)break;
        ss=Sum(ss,s);
        d=ss.size();
   }
    cout<<ss<<endl;
    */
    p=1;
    for(i=2;i<=n;i++){
        p=p*10;
    }
    if(p%k!=0)cout<<p-p%k+k<<endl;
    else
        cout<<p<<endl;

    return 0;
}
