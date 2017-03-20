#include<bits/stdc++.h>
using namespace std;
string summ(string a,string b)
{
    string c="";
    int ia=a.size()-1;
    int ib=b.size()-1;
    vector<int> vec;
    int q=0;
    while(ia>=0 || ib>=0)
    {
        int ca=0,cb=0;
        if(ia>=0)ca=(int)(a[ia]-'0');
        if(ib>=0)cb=(int)(b[ib]-'0');
        int crr=ca+cb+q;
        if(crr>=10)
        {
            q=crr/10;
            crr%=10;
        }
        else q=0;
        vec.push_back(crr);
        ib--;ia--;
    }
    if(q!=0)vec.push_back(q);
    for(int i=vec.size()-1;i>=0;i--)c+=(char)(vec[i]+'0');
    return c;
}
string intmul(string a,int b)
{
    int ia=a.size()-1;
    string c="";
    vector<int> vec;
    int q=0;
    while(ia>=0)
    {
        int ca;
        ca=(int)(a[ia]-'0');
        int crr=ca*b+q;
        if(crr>=10)
        {
            q=crr/10;
            crr%=10;
        }
        else q=0;
        vec.push_back(crr);
        ia--;
    }
    if(q>0)vec.push_back(q);
    for(int i=vec.size()-1;i>=0;i--)c+=(char)(vec[i]+'0');
    return c;
}
string divint(string a,int b)
{
    int ia=0;
    string c="";
    vector<int> vec;
    int q=0;
    while(ia<=a.size()-1)
    {
        int ca=(int)(a[ia]-'0');
        int crr=q*10+ca;
        if(crr>=b)
        {
            q=crr%b;
            crr=crr/b;
            vec.push_back(crr);
        }
        else
        {
            q=crr;
            vec.push_back(0);
        }
        ia++;
    }
    int bi=0;
    while(vec[bi]==0)bi++;
    for(int i=bi;i<vec.size();i++)c+=(char)(vec[i]+'0');
    if(c=="")c="0";
    return c;
}
int check(string a,string b)
{
    int ia=a.size()-1;
    int ib=b.size()-1;
    if(ia>ib)return 1;
    if(ia<ib)return 0;

    for(int i=0;i<=ia;i++)
    {
        if(a[i]>b[i])return 1;
        if(b[i]>a[i])return 0;
    }
    return -1;
}
string izvaj(string a,string b)
{
    string c="";
    int ia=a.size()-1;
    int ib=b.size()-1;
    //cout<<ib<<" "<<ia<<endl;
    vector<int> vec;
    int q=0;
    while(ia>=0 || ib>=0)
    {
        int ca=0,cb=0;
        if(ia>=0)ca=(int)(a[ia]-'0');
        if(ib>=0)cb=(int)(b[ib]-'0');
      //  cout<<ca<<" "<<cb<<"||"<<endl;
        int crr=cb-ca+q;
        q=0;
        if(crr<0)
        {
            q=-1;
            crr+=10;
        }
        vec.push_back(crr);
        ib--;ia--;
    }
    int bi=vec.size()-1;
    while(vec[bi]==0)bi--;
    //if(q!=0)vec.push_back(q);
    for(int i=bi;i>=0;i--)c+=(char)(vec[i]+'0');
    if(c=="")c="0";
    return c;
}
int main()
{
    string m,n;
    cin>>m>>n;
    string l="1";
    string r="1";
    string mi="0",ni="0";
    bool oneplus=0;
    bool tm=0;
    for(int i=0;i<m.size()/2+1;i++)r+='0';
    //cout<<l<<r<<endl;
   // cout<<izvaj("7","1");
    while(1)
    {
        string mid;
        mid=summ(r,l);
        mid=divint(mid,2);
        vector<string> allz;
        string midi=summ(mid,"1");
        string zer="";
        for(int i=mid.size()-1;i>=0;i--)
        {
            int crr=(int)(mid[i]-'0');
            string ss=intmul(midi,crr);
            ss+=zer;
            zer+='0';
            allz.push_back(ss);
        }
        for(int i=1;i<allz.size();i++)
            allz[i]=summ(allz[i],allz[i-1]);
        string cra=allz[allz.size()-1];
       // cout<<cra<<" "<<mid<<endl;
        int cheque=check(cra,m);
        //cout<<cheque<<endl;
        if(cheque!=1)
        {
            if(cheque==-1)
            {
                mi=mid;
                oneplus=1;
                break;
            }
            else
            {
                mi=mid;
                l=summ(mid,"1");
            }
        }
        else
        {
            r=izvaj("1",mid);
        }
       // cout<<l<<" "<<r<<endl;
        if(check(l,r)==1)break;
        if(check(l,r)==-1)
        {
            if(tm)break;
            tm=1;
        }
    }
    tm=0;
    l="1";
    r="1";
    for(int i=0;i<n.size()/2+1;i++)r+='0';
    while(1)
    {
        string mid;
        mid=summ(r,l);
        mid=divint(mid,2);
        vector<string> allz;
        string midi=summ(mid,"1");
        string zer="";
        for(int i=mid.size()-1;i>=0;i--)
        {
            int crr=(int)(mid[i]-'0');
            string ss=intmul(midi,crr);
            ss+=zer;
            zer+='0';
            allz.push_back(ss);
        }
        for(int i=1;i<allz.size();i++)
            allz[i]=summ(allz[i],allz[i-1]);
        string cra=allz[allz.size()-1];
       // cout<<cra<<" "<<mid<<endl;
       // cout<<mid<<" "<<cra<<endl;
        int cheque=check(cra,n);
        //cout<<cheque<<endl;
        if(cheque!=1)
        {
            if(cheque==-1)
            {
                ni=mid;
                break;
            }
            else
            {
                ni=mid;
                l=summ(mid,"1");
            }
        }
        else
        {
            r=izvaj("1",mid);
        }
       // cout<<l<<" "<<r<<endl;
        if(check(l,r)==1)break;
        if(check(l,r)==-1)
        {
            if(tm)break;
            tm=1;
        }
    }
    //cout<<5000*5001<<endl;
   // cout<<mi<<" "<<ni<<endl;
    string ans=izvaj(mi,ni);
    if(oneplus)ans=summ(ans,"1");
    cout<<ans<<endl;
    return 0;
}


