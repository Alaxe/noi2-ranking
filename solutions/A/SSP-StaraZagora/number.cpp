#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int Max=128;
class Num
{
    char a[Max];
    char *begin;
    int len;
public:
    Num (): len(0) {begin=&a[Max-1]; *begin=0;}
    Num (const char *n): len(strlen(n))
    {
        strcpy(a,n);
        begin=a;
    }
    Num operator - (const Num &n) const
    {
        Num t;
        int carry=0;
        for(int i=0; i<len; i++)
        {
            if(i>=n.len)
            {
                *(--t.begin)=*(begin+len-i-1)-carry;
                if(*t.begin<'0') *t.begin+=10, carry=1;
                else carry=0;
                continue;
            }
            *(--t.begin)=*(begin+len-i-1)-*(n.begin+n.len-i-1)-carry+'0';
            if(*t.begin<'0') *t.begin+=10, carry=1;
            else carry=0;
        }
        while(*t.begin=='0') t.begin++;
        t.len=strlen(t.begin);
        return t;
    }
    Num operator * (int n) const
    {
        Num t;
        int carry=0, temp;
        if(!n) return Num("0");
        for(int i=0; i<len; i++)
        {
            temp=(*(begin+len-i-1)-'0')*n+carry;
            carry=temp/10;
            *(--t.begin)=temp%10+'0';
        }
        if(carry) *(--t.begin)=carry+'0';
        t.len=strlen(t.begin);
        return t;
    }
    bool operator <= (const Num &n) const
    {
        if(len!=n.len) return len<n.len;
        return strcmp(begin,n.begin)<=0;
    }
    friend ostream& operator << (ostream &, const Num &);
    Num (const Num &n)
    {
        memcpy(a,n.a,Max*sizeof(char));
        begin=(char *)((long)a+(long)n.begin-(long)n.a);
        len=n.len;
    }
    Num& operator = (const Num &n)
    {
        if(this!=&n)
        {
            memcpy(a,n.a,Max*sizeof(char));
            begin=(char *)((long)a+(long)n.begin-(long)n.a);
            len=n.len;
        }
        return *this;
    }
    Num& operator += (const Num &n)
    {
        strcpy(a,begin);
        a[len]=0;
        begin=a;
        strcat(a,n.begin);
        len+=n.len;
        while(*begin=='0') begin++, len--;
        return *this;
    }
    Num& operator++ ()
    {
        ++*(begin+len-1);
        return *this;
    }
    Num& operator/= (int) // only N/=2
    {
        *this=*this*5;
        return *(begin+--len)=0, *this;
    }
    const char* c_str () const
    {
        return begin;
    }
};

ostream& operator << (ostream &os, const Num &n)
{
    return os << n.begin;
}

void sqri (const char *n, Num& res)
{
    char t[Max],t1[Max];
    int len=strlen(n),f;
    f=len&1;
    strncpy(t,n,2-f);
    t[2-f]=0;
    Num a(t);
    for(int i=0; i<=10; i++)
    {
        t1[0]=i+'0'; t1[1]=0;
        Num b(res*2),temp(t1);
        if(((b+=temp)*i)<=a && i!=10) continue;
        t1[0]=i-1+'0'; t[1]=0;
        b=Num(res*2);
        res+=Num(t1);
        temp=Num(t1);
        a=a-((b+=temp)*(i-1));
        break;
    }
    for(int i=2-f; i<len; i+=2)
    {
        strncpy(t,n+i,2);
        t[2]=0;
        Num x(t);
        a+=x;
        for(int i=0; i<=10; i++)
        {
            t1[0]=i+'0'; t1[1]=0;
            Num b(res*2),temp(t1);
            if(((b+=temp)*i)<=a && i!=10) continue;
            t1[0]=i-1+'0'; t[1]=0;
            if(t1[0]<'0') t1[0]='0';
            b=Num(res*2);
            res+=Num(t1);
            temp=Num(t1);
            a=a-((b+=temp)*(i-1));
            break;
        }
    }
}

Num Find (const Num& a)
{
    Num res("0"), one("1");
    Num D(a);
    D=D*4;
    ++D;
    sqri(D.c_str(),res);
    res=res-one;
    return res/=2;
}

int main ()
{
    char m[Max], n[Max];
    cin >> m >> n;
    Num a(m), b(n), one("1");
    if(!m[1] && (*m=='1' || *m=='2'))
    {
        cout << Find(b) << endl;
        return 0;
    }
    Num x(Find(a-one)), y(Find(b));
    if(y<=x) cout << 0 << endl;
    else cout << y-x << endl;
    return 0;
}

/**
1000000000000000000000001
10000000000000000000000011000000000000000000000001
*/
