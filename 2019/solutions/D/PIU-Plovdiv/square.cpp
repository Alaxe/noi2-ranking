#include<bits/stdc++.h>
using namespace std;
string str="", ans1="1";
long long br=0, cnt=0, maxi, ch=1;
string add(string a, string b)
{
    if(a.size()<b.size())swap(a, b);
    for(long long i=b.size(); i<a.size(); i++)
    {
        b="0"+b;
    }
    string ans="";
    long long ch;
    long long prenos=0;
    for(long long i=a.size()-1; i>=0; i--)
    {
        ch=int(a[i]-'0')+int(b[i]-'0')+prenos;
        if(ch>9)
        {
            ch=ch%10;
            prenos=1;
        }
        else prenos=0;
        ans=char(ch+'0')+ans;
    }
    if(prenos==1)ans="1"+ans;
    return ans;
}
string multi(string d, string c)
{
    string res="";
    for(long long i=0; i<c.size(); i++)
    {
        string curr="";
        for(long long j=0; j<int(d[i]-'0'); j++)
        {
            curr=add(curr, c);
        }
        for(long long j=0; j<d.size()-i-1; j++)
        {
            curr+="0";
        }
        res=add(res, curr);
    }
    return res;
}

long long mas[10000];

int main()
{
    long long n;
    cin>>n;
    for(long long i=0; i<n; i++)
    {
        cin>>mas[i];
    }
    for(long long i=2; i<43; i++)
    {
        br = 0;
        for(long long j=2; j<=i; j++)
        {
            if(i%j==0)br++;
        }
        if(br==1)
        {
            maxi = 0;
            for(long long t=0; t<n; t++)
            {
                cnt = 0;
                while(mas[t]%i==0)
                {
                    mas[t]=mas[t]/i;
                    cnt++;
                }
                if(cnt>maxi)maxi=cnt;
                if(maxi%2==1)maxi=maxi+1;
            }

            maxi /= 2;

            ch = 1;
            for(long long r=0; r<maxi; r++)
            {
                ch=ch*i;
            }

            string ans = "0";
            for(int oo = 0; oo < ch; oo++)
                ans = add(ans1, ans);

            ans1 = ans;
        }

        /*
        ///cout<<ch<<endl;
        while(ch)
        {
            str=char(ch%10+'0')+str;
            ch=ch/10;
        }
        ///cout<<str<<endl;
        ans1=multi(ans1, str);*/

    }
    cout<<ans1<<endl;
    return 0;
}
