#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long s, a, b, c, d, i, j, length;
    double ans[4]={0, 0, 0, 0}, k;
    string sec[4]={"acb", "bac", "bca", "cab"}, posAns;
    cin>>s>>k>>a>>b>>c>>d;
    for(i=0; i<s; ++i)
    {
        if(4*d<k)
        {
            k-=4*d;
            continue;
        }
        for(j=0; j<3; ++j)
        {
            int otd=sec[i%4][j]-'a';
            if(otd==0) length=a;
            else if(otd==1) length=b;
            else length=c;
            if(length>k)
            {
                ans[j]+=k;
                k=0;
                posAns=sec[i%4];
                break;
            }
            else
            {
                ans[j]+=length;
                k-=length;
            }
        }
        if(k==0) break;
    }
    int lastPos=0;
    for(i=0; i<4; ++i) if(ans[i]==0) lastPos=i;
    if(lastPos==0) lastPos=4;

    int l1, l2, l3, l4=d;
    if(posAns[0]-'a'==0) l1=a;
    if(posAns[0]-'a'==1) l1=b;
    if(posAns[0]-'a'==2) l1=c;

    if(posAns[1]-'a'==0) l2=a;
    if(posAns[1]-'a'==1) l2=b;
    if(posAns[1]-'a'==2) l2=c;

    if(posAns[2]-'a'==0) l3=a;
    if(posAns[2]-'a'==1) l3=b;
    if(posAns[2]-'a'==2) l3=c;

    for(i=0; i<4; ++i) cout<<ans[i]<<endl;
    if(lastPos==1)
    {
        cout<<ans[0]<<".000 0.000 0.000 0.000\n";
        return 0;
    }

    if(lastPos==2)
    {
        if(ans[1]>l1)
        {
            ans[0]+=(ans[1]-l1)/2;
            ans[1]=ans[0];
        }
    }

    if(lastPos==3)
    {
        if(ans[2]>l2)
        {
            ans[1]+=(ans[2]-l2)/2;
            ans[2]=ans[1];
            if(ans[1]>l1)
            {
                ans[0]+=((ans[1]-l1)*2)/3;
                ans[1]=ans[0];
                ans[2]=ans[0];
            }
        }
    }

    if(lastPos==4)
    {
        if(ans[3]>l3)
        {
            ans[2]+=(ans[3]-l3)/2;
            ans[3]=ans[2];
            if(ans[2]>l2)
            {
                ans[1]+=((ans[2]-l2)*2)/3;
                ans[2]=ans[1];
                ans[3]=ans[1];
                if(ans[1]>l1)
                {
                    ans[0]=((ans[1]-l1)*3)/4;
                    ans[1]=ans[0];
                    ans[2]=ans[0];
                    ans[3]=ans[0];
                }
            }
        }
    }
    for(i=0; i<4; ++i)
    {
        if(ans[i]==0) cout<<"0.000";
        int b=ans[i]*100000;
        string str;
        while(b)
        {
            str+=b%10+'0';
            b/=10;
        }
        int sz=str.size();
        for(j=sz-1; j>=0; --j)
        {
            cout<<str[j];
            if(j==5&&j!=sz-3) cout<<'.';
            if(j==sz-4) break;
        }
        cout<<endl;
    }
    return 0;
}
/*
3 25
1 2 3 5
*/
