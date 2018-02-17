#include<iostream>
#include<string>
using namespace std;
string n,m;

string shit_to_number(string x)
{
    for(int i=0;i<x.size();i++)
    {
        x[i]+='0';
    }//cout<<x<<endl;
    string y;
    y=x;
    for(int i=0;i<x.size();i++)
    {
        x[i]=y[x.size()-1-i];
    }
    return x;
}

string mul(string a,string b)
{
    string c;
    int sza=a.size();
    int szb=b.size();
    int szc;
    char z='0';z-='0';
    for(int i=0;i<=sza+szb;i++)c+=z;
    int q=0;
    for(int i=0;i<sza;i++)
    {
        for(int j=0;j<szb;j++)
        {
            //q*=10;
            q=a[i]*b[j];
            c[i+j]+=q%10;
            if(c[i+j]>9){c[i+j]-=10;c[i+j+1]+=1;}
            q/=10;
            c[i+j+1]+=q%10;
            if(c[i+j+1]>9){c[i+j+1]-=10;c[i+j+2]+=1;}
            q=0;
            //c[i]=
        }
        //z=q%10;
        //c+=
    }
    while(c[c.size()-1]==0)c.erase(c.size()-1);
    if(c.size()==0)
    {
        c+='0';
        c[0]-='0';
    }
    return c;
}
string add_big(string a,string b)
{
    int sza=a.size();
    int szb=b.size();
    int szc;
    string c;
    char z;
    if(sza>szb)
    {
        swap(sza,szb);
        swap(a,b);
    }
    int q=0;
    for(int i=0;i<sza;i++)
    {
       // q*=10;
        q+=a[i]+b[i];
        z=q%10;
        q/=10;
        c+=z;
    }
    if(q>0)
    {
        if(sza<szb)b[sza]++;
        else
        {
            z='1';
            z-='0';
            c+=z;
            return c;
        }
    }
    q=0;
    for(int i=sza;i<szb;i++)
    {
        q=b[i];
        z=q%10;
        c+=z;
        q/=10;
        if(q>=1)
        {
            if(i+1<szb)b[i+1]+=q;
            else{z='1';z-='0';c+=z;break;}
        }
    }
    return c;
}
string add1(string x)
{
    x[0]+=1;
    int q=0,sz;
    sz=x.size();
    while(x[q]>=10)
    {
        //cout<<q<<" "<<x[q]<<endl;
        x[q]-=10;
        if(q+1<sz)x[q+1]+=1;
        else
        {
            x+='1';
            x[sz]-='0';
        }
        q++;
    }
    //cout<<x<<endl;
    return x;
}
string del2(string x)
{
    if(x[0]%2!=0)x[0]--;
    int sz=x.size();
    int q=0,l=0;
    for(int i=sz-1;i>=0;i--)
    {
        q*=10;
        q+=x[i];
        x[i]=q/2;
        q%=2;
    }
    if(x[sz-1]==0)x.erase(sz-1);
    return x;
}
string bs1(string l,string r,string x)
{
    int szl=l.size(),szr=r.size();
    string md;
    int szmd;
    int szx=x.size();
    string q;
    int szq;
    string sq,sx;
  //  int szm=m.size();
    string tans="";
    string md1="";
    while(1)
    {
        md=del2(add_big(l,r));
       // cout<<shit_to_number(md)<<endl;
      //  cout<<shit_to_number(l)<<" ";
      //  cout<<shit_to_number(r)<<endl;
        if(md==md1)break;
        q=mul(md,add1(md));
       // cout<<"  "<<shit_to_number(q)<<endl;
        szq=q.size();
        if(szq>szx){r=md;tans=md;}
        else if(szq<szx)l=md;
        else if(szq==szx)
        {
            sq=shit_to_number(q);
            sx=shit_to_number(x);
           // cout<<sq<<" "<<sx<<endl;
            if(sq>sx)
            {
                tans=md;
                r=md;
            }
            if(sq<sx)
            {
                l=md;
            }
            if(sq==sx)
            {
                return md;
            }
        }
        md1=md;
        /*szmd=md.size();
        if(szmd>szx)
        {
            r=md;
        }
        else if(szmd<szx)
        {
            l=md
        }*/
    }
    return tans;
}
string bs2(string l,string r,string x)
{
    int szl=l.size(),szr=r.size();
    string md;
    int szmd;
    int szx=x.size();
    string q;
    int szq;
    string sq,sx;
  //  int szm=m.size();
    string tans="";
    string md1="";
    while(1)
    {
        md=del2(add_big(l,r));
       // cout<<shit_to_number(md)<<endl;
      //  cout<<shit_to_number(l)<<" ";
      //  cout<<shit_to_number(r)<<endl;
        if(md==md1)break;
        q=mul(md,add1(md));
        //cout<<"  "<<shit_to_number(q)<<endl;
        szq=q.size();
        if(szq>szx){r=md;}
        else if(szq<szx){l=md;tans=md;}
        else if(szq==szx)
        {
            sq=shit_to_number(q);
            sx=shit_to_number(x);
           // cout<<sq<<" "<<sx<<endl;
            if(sq>sx)
            {

                r=md;
            }
            if(sq<sx)
            {
                tans=md;
                l=md;
            }
            if(sq==sx)
            {
                return md;
            }
        }
        md1=md;
        /*szmd=md.size();
        if(szmd>szx)
        {
            r=md;
        }
        else if(szmd<szx)
        {
            l=md
        }*/
    }
    return tans;
}
string f1(string x)
{
    int sz=x.size();
    int sz2=sz/2;
    string l;
    for(int i=1;i<sz2-1;i++)l+='0';
    l+='1';
    for(int i=0;i<l.size();i++)l[i]-='0';
    string r;
    for(int i=1;i<sz2+3;i++)r+='0';
    r+='1';
    for(int i=0;i<r.size();i++)r[i]-='0';
   // cout<<shit_to_number(bs1(l,r,x))<<endl;
    return bs1(l,r,x);
}
string f2(string x)
{
    int sz=x.size();
    int sz2=sz/2;
    string l;
    for(int i=1;i<sz2-1;i++)l+='0';
    l+='1';
    for(int i=0;i<l.size();i++)l[i]-='0';
    string r;
    for(int i=1;i<sz2+3;i++)r+='0';
    r+='1';
    for(int i=0;i<r.size();i++)r[i]-='0';
    //cout<<shit_to_number(bs2(l,r,x))<<endl;
    return bs2(l,r,x);
}
string sub(string b,string a)
{
    int sza=a.size();
    int szb=b.size();
    /*if((a.size()<b.size())||(a.size()==b.size()&&shit_to_number(a)<shit_to_number(b)))
    {
        swap(a,b);
        swap(sza,szb);
    }*/
    string c;
    char z='0';
    z-='0';
    for(int i=0;i<sza;i++)c+=z;

    for(int i=0;i<szb;i++)
    {
        c[i]=a[i]-b[i];
        if(c[i]<0)
        {
            c[i]+=10;
            a[i+1]--;
        }
    }
    for(int i=szb;i<sza;i++)
    {
        c[i]=a[i];
        if(c[i]<0)
        {
            c[i]+=10;
            a[i+1]--;
        }
    }
    while(c[c.size()-1]==0)c.erase(c.size()-1);
    if(c.size()==0)
    {
        c+='0';
        c[0]-='0';
    }
    return c;
}
int main()
{
    cin>>n>>m;
   // if(n>m)cout<<1<<endl;
    //if(n<m)cout<<2<<endl;
    string asd;
    asd=n;
    for(int i=0;i<asd.size();i++)
    {
        n[i]=asd[asd.size()-1-i]-'0';
    }
    asd=m;
    for(int i=0;i<asd.size();i++)
    {
        m[i]=asd[asd.size()-1-i]-'0';
    }
    //cout<<shit_to_number(del2(m))<<endl;
    //cout<<shit_to_number(add1(m))<<endl;
    //cout<<shit_to_number(mul(n,m))<<endl;
    //cout<<shit_to_number(add_big(n,m))<<endl;
   // cout<<shit_to_number(sub(n,m))<<endl;
    string a=f1(n);
    string b=f2(m);
    if(a.size()>b.size()){cout<<0<<endl;return 0;}
    if(a.size()==b.size()&&shit_to_number(a)>shit_to_number(b)){cout<<0<<endl;return 0;}
    cout<<shit_to_number(add1(sub(a,b)))<<endl;
    return 0;
}
