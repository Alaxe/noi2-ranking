#include <iostream>
using namespace std;

long long n,sum;

string Umn(string a,int p){
int d,c,u,i,cc;
string q;
    q="";
    d=a.size();
    u=0;
    for(i=d-1;i>=0;i--){
        c=(a[i]-'0')*p+u;
         //cout<<a[i]-'0'<<" "<<p<<" "<<u<<endl;
        if(c>9){
            u=c/10;
            c=c%10;
        }
        else
            u=0;
       // if(p==5)cout<<c<<endl;
        cc=c%10;
        q=char(cc+'0')+q;
        //cout<<u<<endl;
       // cout<<"c="<<c<<endl;
        //cout<<q<<" ";
    }
   // cout<<q<<endl;

      //cout<<q<<endl;
    //cout<<c<<endl;
    if(u>0){
       // cout<<u;
        q=char(u+'0')+q;
    }
    //cout<<q<<endl;
    return q;
}

int main()
{
int i,d;
string ch;
    cin>>n;
    ch="1";
    for(i=2;i<=n;i++){
        ch=Umn(ch,i);
        //cout<<ch<<endl;
    }
    d=ch.size();
    sum=0;
    for(i=0;i<d;i++){
        sum+=ch[i]-'0';
    }
  // cout<<ch<<endl;
   cout<<sum<<endl;

    return 0;
}
