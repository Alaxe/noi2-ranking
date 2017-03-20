//
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<climits>
#include<stack>
#include<set>

#define lli long long

using namespace std;

struct LongNumbers
{
    int a[210];
    int Size;
};

LongNumbers N,M,Ans,One,Left,Right,Mid,Zero,Mid1,Ans1,Ans2,Two;

bool operator ==(const LongNumbers &A, const LongNumbers &B)
{
    if(A.Size!=B.Size)return false;
    for(int i=0;i<A.Size;i++)
    {
        if(A.a[i]!=B.a[i])return false;
    }
    return true;
}
bool operator <(const LongNumbers &A, const LongNumbers &B)
{
    if(A.Size>B.Size)return false;
    if(A.Size<B.Size)return true;

    for(int i=0;i<A.Size;i++)
    {
        if(A.a[i]>B.a[i])return false;
        if(A.a[i]<B.a[i])return true;
    }
    return false;
}


LongNumbers operator +(const LongNumbers &A, const LongNumbers &B)
{
    LongNumbers C;
    int br=0,mx=0;

    for(int i=A.Size-1;i>=0;i--)
    {
        C.a[br]=A.a[i];
        br++;
    }

    br=0;
    for(int i=B.Size-1;i>=0;i--)
    {
        if(br>=A.Size)C.a[br]=0;

        C.a[br]+=B.a[i];
        br++;
    }

    mx=A.Size;
    if(mx<B.Size)mx=B.Size;

    C.a[mx]=0;


    for(int i=0;i<mx;i++)
    {
        C.a[i+1]+=C.a[i]/10;
        C.a[i]=C.a[i]%10;
    }

    if(C.a[mx]!=0)mx++;

    for(int i=0;i<mx/2;i++)swap(C.a[i],C.a[mx-1-i]);
    C.Size=mx;

    return C;
}

LongNumbers operator -(const LongNumbers &A, const LongNumbers &B)
{
    if(A==B)return Zero;
    LongNumbers C;
    int br=0,mx=0;

    for(int i=A.Size-1;i>=0;i--)
    {
        C.a[br]=A.a[i];
        br++;
    }

    br=0;
    for(int i=B.Size-1;i>=0;i--)
    {
        if(br>=A.Size)C.a[br]=0;

        C.a[br]-=B.a[i];
        br++;
    }

    mx=A.Size;
    if(mx<B.Size)mx=B.Size;

    C.a[mx]=0;


    for(int i=0;i<mx;i++)
    {
        //cout<<C.a[i]<<"\n";
        if(C.a[i]<0)
        {
            C.a[i]+=10;
            C.a[i+1]--;
        }
    }

    for(int i=mx-1;i>=0;i--)
    {
        if(C.a[i]!=0){mx=i+1;break;}
    }


    for(int i=0;i<mx/2;i++)swap(C.a[i],C.a[mx-1-i]);
    C.Size=mx;

    return C;
}

LongNumbers operator *(const LongNumbers &A, const LongNumbers &B)
{
    LongNumbers C,A1,B1;
    int br=0,mx=0,NewSize=0;

    memset(C.a,0,sizeof(C.a));
    memset(A1.a,0,sizeof(A1.a));
    memset(B1.a,0,sizeof(B1.a));


    for(int i=A.Size-1;i>=0;i--)
    {
        A1.a[br]=A.a[i];
        br++;
    }

    br=0;
    for(int i=B.Size-1;i>=0;i--)
    {
        B1.a[br]=B.a[i];
        br++;
    }

    mx=A.Size;
    if(mx<B.Size)mx=B.Size;




    for(int i=0;i<mx;i++)
    {

        for(int j=0;j<mx;j++)
        {
            C.a[i+j]+=A1.a[i]*B1.a[j];
        }
    }

    for(int i=0;i<mx*2;i++)
    {
        C.a[i+1]+=C.a[i]/10;
        C.a[i]%=10;

        if(C.a[i]!=0)NewSize=i;
        if(C.a[i+1]!=0)NewSize=i+1;
    }

    NewSize++;
    C.Size=NewSize;
    for(int i=0;i<NewSize/2;i++)swap(C.a[i],C.a[NewSize-1-i]);

    return C;
}



LongNumbers DivTwo(LongNumbers A)
{
    LongNumbers C;
    memset(C.a,0,sizeof(C.a));

    if(A.Size==1 && A.a[0]<=1)
    {
        C.Size=1;
        C.a[0]=0;
        return C;
    }


    for(int i=0;i<A.Size;i++)
    {
        C.a[i]=A.a[i]/2;
        A.a[i+1]+=(A.a[i]%2)*10;
    }
    if(C.a[0]==0)
    {
        for(int i=0;i<A.Size-1;i++)
        {
            C.a[i]=C.a[i+1];
        }
        C.Size=A.Size-1;
    }
    else C.Size=A.Size;

    return C;


}





LongNumbers Solve(LongNumbers A)
{
    if(A==One || A==Two)return Zero;
    Left=One;
    Right=M;

    while(Left+One<Right)
    {
        Mid=Left+Right;
        Mid=DivTwo(Mid);

        Mid1=Mid+One;
        Ans=Mid*Mid1;

        if(Ans<A)Left=Mid;
        else Right=Mid;
    }
    return Left;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    One.Size=1; Zero.Size=1; Two.Size=1;
    One.a[0]=1; Zero.a[0]=0; Two.a[0]=2;

    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        N.a[i]=s[i]-'0';
    }
    N.Size=s.size();

    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        M.a[i]=s[i]-'0';
    }
    M.Size=s.size();

    M=M+One;

    Ans1=Solve(N);
    Ans2=Solve(M);



    Ans1=Ans2-Ans1;
    for(int i=0;i<Ans1.Size;i++)cout<<Ans1.a[i];
    cout<<"\n";


    return 0;
}

