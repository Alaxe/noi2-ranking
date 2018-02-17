#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct BigNum
{
    int num[211];
    int L;

    void Clear()
    {
        memset(num,0,sizeof(num));
        L=0;

        return;
    }

    void Reverse()
    {
        int i;
        int swp;

        for (i=1;i<=L/2;i++)
        {
            swp=num[i];
            num[i]=num[L-i+1];
            num[L-i+1]=swp;
        }

        return;
    }

    void Add(BigNum b)
    {
        int i;
        int sum,rem=0;

        if (b.L>L)
        {
            for (i=L+1;i<=b.L;i++)
            {
                num[i]=0;
            }

            L=b.L;
        }

        for (i=1;i<=L;i++)
        {
            if (i<=b.L)
            sum=num[i]+b.num[i]+rem;
            else
            sum=num[i]+rem;

            num[i]=sum%10;
            rem=sum/10;
        }

        if (rem>0)
        {
            L++;
            num[L]=rem;
        }

        return;
    }

    void Mul(BigNum b)
    {
        int i,j;
        BigNum c;

        c.Clear();

        for (i=1;i<=L;i++)
        {
            for (j=1;j<=b.L;j++)
            {
                c.num[i+j-1]+=num[i]*b.num[j];
            }
        }

        c.L=L+b.L-1;

        for (i=1;i<=c.L;i++)
        {
            c.num[i+1]+=c.num[i]/10;
            c.num[i]%=10;
        }

        if (c.num[c.L+1]!=0)
        c.L++;

        Set(c);

        return;
    }

    bool Smaller(BigNum b,bool ReturnIfEqual)
    {
        int i;

        if (b.L>L)
        return true;
        else if (b.L<L)
        return false;

        for (i=L;i>=1;i--)
        {
            if (num[i]<b.num[i])
            return true;
            else if (num[i]>b.num[i])
            return false;
        }

        return ReturnIfEqual;
    }

    void Div2()
    {
        int i;
        int rem=0;

        for (i=L;i>=1;i--)
        {
            num[i]=rem*10+num[i];

            rem=num[i]%2;
            num[i]=num[i]/2;
        }

        while(num[L]==0 && L>1)
        L--;

        return;
    }

    void Print()
    {
        int i;

        for (i=L;i>=1;i--)
        {
            printf("%d",num[i]);
        }

        return;
    }

    void Set(BigNum b)
    {
        int i;

        L=b.L;

        for (i=1;i<=L;i++)
        {
            num[i]=b.num[i];
        }

        return;
    }

    void Inc1()
    {
        int i;

        num[1]++;
        num[L+1]=0;
        for (i=1;i<=L;i++)
        {
            if (num[i]>=10)
            {
                num[i+1]+=num[i]/10;
                num[i]%=10;
            }
            else
            break;
        }

        if (num[L+1]!=0)
        {
            L++;
        }

        return;
    }

    void Sub(BigNum b)
    {
        int i;
        int torem,rem=0;

        for (i=1;i<=L;i++)
        {
            if (i<=b.L)
            torem=rem+b.num[i];
            else
            torem=rem;

            if (num[i]<torem)
            {
                num[i]+=10;
                rem=1;
            }
            else
            {
                rem=0;
            }

            num[i]-=torem;
        }

        while(L>1 && num[L]==0)
        L--;

        return;
    }
};

BigNum L,R,mid,best;

char inp[211];
int Len;
BigNum l,r;
BigNum h1,h2;
BigNum ansL,ansR;
BigNum Answer;

int main()
{
    int i;

    scanf("%s",inp+1);
    Len=strlen(inp+1);

    l.L=Len;
    for (i=Len;i>=1;i--)
    {
        l.num[i]=inp[Len-i+1]-'0';
    }

    scanf("%s",inp+1);
    Len=strlen(inp+1);

    r.L=Len;
    for (i=Len;i>=1;i--)
    {
        r.num[i]=inp[Len-i+1]-'0';
    }

    ///Find first that goes over l
    L.L=1;
    L.num[1]=1;

    R.Set(l);

    while(L.Smaller(R,false))
    {
        mid.Set(L);
        mid.Add(R);
        mid.Div2();

        h1.Set(mid);
        h2.Set(mid);
        h2.Inc1();
        h1.Mul(h2);

        if (h1.Smaller(l,false))
        {
            L.Set(mid);
            L.Inc1();
        }
        else
        {
            best.Set(mid);

            R.Set(mid);
        }
    }

    h1.Set(L);
    h2.Set(L);
    h2.Inc1();
    h1.Mul(h2);

    if (!h1.Smaller(l,false))
    {
        best.Set(L);
    }

    ansL.Set(best);

    ///Find last that goes under r
    best.L=1;
    best.num[1]=0;

    L.L=1;
    L.num[1]=1;

    R.Set(r);

    while(L.Smaller(R,false))
    {
        mid.Set(L);
        mid.Add(R);
        mid.Div2();

        h1.Set(mid);
        h2.Set(mid);
        h2.Inc1();
        h1.Mul(h2);

        if (h1.Smaller(r,true))
        {
            best.Set(mid);

            L.Set(mid);
            L.Inc1();
        }
        else
        {
            R.Set(mid);
        }
    }

    h1.Set(L);
    h2.Set(L);
    h2.Inc1();
    h1.Mul(h2);

    if (h1.Smaller(r,true))
    {
        best.Set(L);
    }

    ansR.Set(best);

    ///

    if (ansR.Smaller(ansL,true))
    {
        if (ansR.Smaller(ansL,false))
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }

        return 0;
    }

    ansR.Set(best);

    Answer.Set(ansR);
    Answer.Sub(ansL);
    Answer.Inc1();

    Answer.Print();
    printf("\n");

    return 0;
}
