#include<iostream>
using namespace std;
string m,n;
bool strless(string a, string b)
{
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    return false;
}

string add(string a, string b)
{
    string ret="";
    int pr=0;
    for(int i=1;i<=a.size();i++)
    {
        int val = a[a.size()-i]-'0'+b[b.size()-i]-'0'+pr;
        pr = val/10;
        ret = (char)((val%10)+'0') + ret;
    }
    int i=a.size()+1;
    while(i<=b.size())
    {
        int val = b[b.size()-i]-'0'+pr;
        pr = val/10;
        ret = (char)((val%10)+'0') + ret;
        i++;
    }
    if(pr) ret = '1' + ret;
    return ret;
}
string decr(string a, string b)
{
    string ret="";
    int pr=0;
    for(int i=1;i<=a.size();i++)
    {
        int val = a[a.size()-i]-'0'-pr;
        if(b.size()>=i) val-=b[b.size()-i]-'0';
        if(val<0)
        {
            pr=1;
            val+=10;
        }
        else pr=0;
        if(i==a.size()&&val==0) continue;
        ret = (char)(val+'0') +ret;
    }
    if(pr) return "0";
    int ind=0;
    for(int i=0;i<ret.size();i++)
    {
        if(ret[i]!='0')
        {
            ind=i;
            break;
        }
    }
    if(ind) return ret.substr(ind);
    return ret;
}
string dec1(string a)
{
    string ret="";
    bool tek=1;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]=='0'&&tek)
        {
            ret = '9'+ret;
            tek=1;
        }
        else{
            if(a[i]=='1'&&i==0&&tek==1&&a.size()>1) return ret;
            ret=(char)(a[i]-tek) + ret;
            tek=0;
        }
    }
    return ret;
}

string mul_ez(string a, int b)
{
    string ret="";
    int pr=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int val = (a[i]-'0')*b + pr;
        pr = val/10;
        ret = (char)((val%10)+'0')+ret;
    }
    if(pr) ret = (char)(pr+'0') + ret;
    return ret;
}

string mult(string a, string b)
{
    string ret="0";
    for(int i=a.size()-1;i>=0;i--)
    {
        string xx = mul_ez(b,a[i]-'0');
        for(int j=0;j<(a.size()-1-i);j++) xx+='0';
        if(strless(ret,xx))
        ret=add(ret,xx);
        else ret=add(xx,ret);
    }
    return ret;
}


string div2 (string a)
{
    string ret="";
    int pr=0;
    for(int i=0;i<a.size();i++)
    {
        int val = pr*10 + a[i]-'0';
        pr = val%2;
        if(i==0&&val/2 ==0 && a.size()>1) continue;
        ret+=(char)((val/2)+'0');
    }
    return ret;
}


string find_first()
{
    string l,r,mid,tmp;
    l = "0";
    r = m;

    while(strless(l,r))
    {
        //cout<<"l,r,m = "<<l<< " "<<r<<" "<<m<<endl;
        mid = div2(add(l,r));
        tmp = mult(mid,add("1",mid));
        if(strless(tmp,m)) l=add("1",mid);
        else r=mid;
    }
    return l;
}

string find_last()
{
    string l,r,mid,tmp;
    l = "0";
    r = n;

    while(strless(add("1",l),r))
    {
        mid = div2(add(l,r));
        tmp = mult(mid,add("1",mid));
        //cout<<"l,r,m = "<<l<< " "<<r<<" "<<mid<<" "<<tmp<<endl;

        if(strless(n,tmp)) r=dec1(mid);
        else l=mid;
    }

    if(strless(n,mult(r,add("1",r)))) return l;
    return r;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    string last = find_last();
    string first = find_first();
    //cout<<last<<" "<<first<<endl;
    if(strless(last,first))
    {
        cout<<"0"<<endl;
        return 0;
    }
    //cout<<decr(last,first)<<endl;
    cout<<add("1",decr(last,first))<<endl;
    return 0;
}
