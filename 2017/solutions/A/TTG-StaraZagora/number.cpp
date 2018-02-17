#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char *Seg(char *a, char *b)
{
    char t[64];
    int la=strlen(a),lb=strlen(b);
    for(int i=0;i<lb;i++)
    {
        t[i]=a[la-i-1]-b[lb-i-1]+'0';
        if(t[i]<'0')
        {
            t[i]+=10;
            for(int j=i+1;j<la;j++)
            {
                a[la-j-1]--;
                if(a[la-j-1]<'0')a[la-j-1]+=10;
                else break;
            }
        }
    }
    for(int i=lb;i<la;i++)t[i]=a[la-i-1];
    for(int i=lb;i<la;i++)b[lb-i]=a[la-i-1];
    for(int i=la-1;i>=0;i--)b[la-1-i]=t[i];
    b[la]=0;
    if(b[0]=='0')return &b[1];
    return b;
}
bool Lower(char *a, char *b)
{
    int la=strlen(a),lb=strlen(b);
    if(la<lb)return true;
    if(lb<la)return false;
    for(int i=0;i<la;i++){if(a[i]<b[i])return true;if(a[i]>b[i])return false;}
    return true;
}
char *Mult(char *a, int b, char *c)
{
    bool f=false;
    char t[64];
    int la=strlen(a),p,carry=0;
    t[la+1]=0;
    for(int i=la;i>0;i--)
    {
        p=a[i-1]-'0';p*=b;p+=carry;
        carry=0;
        carry=p/10;
        t[i]=(p%10)+'0';
    }
    if(carry){c[0]=carry+'0';f=true;}
    p=0;
    for(int i=0;i<la;i++)
    {
        p++;
        c[i+f]=t[p];
        if(!f && !c[i]){i--;la--;}
    }
    c[la+f]=0;
    return c;
}
void RemoveZeros(char *a, int &len)
{
    int i=0;
    while(a[i]=='0')i++;
    len-=i;
    if(!len)a[len++]='0';
    a[len]=0;
}
char MakeNext(char *a, int &la, char *b, int &lb)
{
    char rand[64];
    int i,j;
    lb++;b[lb]=0;
    for(i=9;i>=0;i--)
    {
        b[lb-1]=i+'0';
        if(Lower(Mult(b,i,rand),a))break;
    }
    strcpy(b,Mult(b,i,rand));
    strcpy(a,Seg(a,b));
    la=strlen(a);
    return i+'0';
}
void Sol(char *S, const char *a, int n, bool f)
{
    char sol[32],temp,rand[64];
    char t[64],left[64];
    int len=0,len2=0,slen=0,p=0;
    left[len2]=0;
    if(f)t[len++]=a[0];
    else {t[len++]=a[0];t[len++]=a[1];}
    t[len]=0;p=len;  
    temp=MakeNext(t,len,left,len2);
    if(temp!='0')sol[slen++]=temp;
    for(int i=0;i<(strlen(a)-1)/2;i++)
    {
        t[len++]=a[p++];
        t[len++]=a[p++];
        t[len]=0;sol[slen]=0;
        len2=strlen(left);
        RemoveZeros(left,len2);
        strcpy(left,Mult(sol,2,rand));

        sol[slen++]=MakeNext(t,len,left,len2);
    }
    
    for(int i=0;i<slen;i++)S[i]=sol[i];
    S[slen]=0;
}





void flip(char *a, int len)
{
    for(int i=0,j=len-1;i<j;i++,j--)swap(a[i],a[j]);
}

class BigNumber
{
    char a[256];
    int len;
public:
    int getLen()const{return len;}
    const char *getString()const{return a;}
    BigNumber(const char *b)
    {
        len=strlen(b);
        strcpy(a,b);
    }
    void addZero()
    {
        this->a[len++]='0';
        this->a[len]=0;
    }
    friend BigNumber operator +=(BigNumber &b, const BigNumber a)
    {
        int i,carry=0;
        char p[128];
        for(i=0;i<a.len && i<b.len;i++)
        {
            p[i]=a.a[a.len-i-1]+b.a[b.len-i-1]-'0'+carry;
            if(p[i]>'9'){carry=1;p[i]-=10;}
            else carry=0;
        }
        for(;i<a.len || i<b.len;i++)
        {
            p[i]=a.len>b.len? a.a[a.len-i-1]+carry: b.a[b.len-i-1]+carry;
            if(p[i]>'9'){carry=1;p[i]-=10;}
            else carry=0;
        }
        if(carry)p[i++]='1';
        p[i]=0;
        flip(p,i);
        strcpy(b.a,p);
        b.len=i;
    }
    friend BigNumber operator ++(BigNumber &a)
    {
        int i=1;
        a.a[a.len-i]++;
        while(a.a[a.len-i]>'9')
        {
            a.a[a.len-i]-=10;
            a.a[a.len-(++i)]++;
        }
        
        if(i>a.len)
        {
            a.a[0]='1';
            a.a[a.len]='0';
            a.a[++a.len]=0;
        }
    }
    friend BigNumber operator -=(BigNumber &b, const BigNumber a)
    {
        int i,carry=0;
        for(i=0;i<a.len;i++)
        {
            b.a[b.len-i-1]-=a.a[a.len-i-1]-'0'+carry;
            if(b.a[b.len-i-1]<'0'){b.a[b.len-i-1]+=10;carry=1;}
            else carry=0;
        }
        for(;i<b.len && carry;i++)
        {
            b.a[b.len-i-1]--;
            if(b.a[b.len-i-1]<'0'){b.a[b.len-i-1]+=10;carry=1;}
            else carry=0;
        }
        for(i=0;i<b.len;i++)if(b.a[i]!='0')break;
        for(int j=0;j<b.len-i;j++)b.a[j]=b.a[j+i];
        b.a[b.len-i]=0;
        b.len-=i;
        if(!b.len)b.a[b.len++]='0';
            
    }
    friend BigNumber operator --(BigNumber &a)
    {
        if(a.len==1)a.a[0]--;
        else
        {
            int i=1;
            a.a[a.len-i]--;
            while(a.a[a.len-i]<'0')
            {
                a.a[a.len-i]+=10;
                a.a[a.len-(++i)]--;
            }
            if(i>=a.len)
            {
                a.a[0]='9';
                a.a[--a.len]=0;
            }
        }
    }
    
    friend BigNumber operator *=(BigNumber &b, const BigNumber a)
    {
        int i,j,carry=0;
        BigNumber p("0");
        char q[256];
        for(i=b.len-1;i>=0;i--)
        {
            for(j=a.len-1;j>=0;j--)
            {
                
                q[a.len-1-j]=(b.a[i]-'0')*(a.a[j]-'0')+carry;
                //cout<<"q[j]= "<<(int)q[a.len-1-j]<<endl;
                if(q[a.len-1-j]>=10){carry=q[a.len-1-j]/10;q[a.len-1-j]%=10;}
                else carry=0;
                q[a.len-1-j]+='0';
                //cout<<"here "<<carry<<endl;
            }
            if(q[a.len-2-j]>'9')
            {
                q[a.len-2-j]-='0';
                carry=q[a.len-2-j]/10;
                q[a.len-2-j]%=10;
                q[a.len-2-j]+='0';
            }
            
            if(carry)
            {//cout<<carry;
                q[a.len-1-j]=carry+'0';
                carry=0;
                j--;
                //cout<<"this: "<<a.len-1-j<<endl;
            }
            q[a.len-1-j]=0;
            flip(q,a.len-1-j);
            //cout<<q<<endl;
            BigNumber t(q);
            for(int k=0;k<b.len-1-i;k++)t.addZero();
            //cout<<t<<endl;
            p+=t;
        }
        b.len=p.len;
        strcpy(b.a,p.a);
        //cout<<p<<endl;
    }
    
    friend ostream& operator <<(ostream &os, const BigNumber &r)
    {
        for(int i=0;i<r.len;i++)os<<r.a[i];
        return os;
    }
};

int main()
{
    bool f;
    int n;
    char A[256],B[256],M[256],N[256];
    cin>>A;n=strlen(A);f=(n&1)?true: false;Sol(M,A,n,f);
    cin>>B;n=strlen(B);f=(n&1)?true: false;Sol(N,B,n,f);
    BigNumber a(M);
    BigNumber b(N);
    BigNumber res(N);
    res-=a;
    ++res;
    
    
    
    BigNumber t(M);
    ++t;
    t*=a;
    
    ///if(a*(a+1)<A)res--;
    if(strcmp(t.getString(),A)==-1)--res;
   /* if(strlen(A)>strlen(t.a))--res;
    for(int i=strlen(A)-1;i>=0;i--)
     if(A[i]>t.a[i]){--res;break;}*/
    
    BigNumber p(N);
    ++p;
    p*=b;
    
    
    
    ///if(b*(b+1)>B)res--;
    /*if(strlen(B)<strlen(p.a))--res;
    for(int i=strlen(B)-1;i>=0;i--)
     if(B[i]<p.a[i]){--res;break;}*/
    if(strcmp(p.getString(),B)==1)--res;
    
    
	//if(a*(a+1)<A)res--;
	//if(b*(b+1)>B)res--;
	cout<<res.getString()<<endl;
    
    
    
    return 0;
}





/*
void add(const BigNumber &q)
    {
       BigNumber a,b;
       if(len>q.getLen()){a.set(*this);b.set(q);}
       else              {b.set(*this);a.set(q);}
       
       for(int i=0;i<b.getLen();i++)
       {
           
       }
       
    }
    */