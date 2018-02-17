#include<bits/stdc++.h>
using namespace std;
int b;
int st(char c)
{
    if(c=='0')return 0;
    if(c=='1')return 1;
    if(c=='2')return 2;
    if(c=='3')return 3;
    if(c=='4')return 4;
    if(c=='5')return 5;
    if(c=='6')return 6;
    if(c=='7')return 7;
    if(c=='8')return 8;
    if(c=='9')return 9;
    if(c=='A')return 10;
    if(c=='B')return 11;
    if(c=='C')return 12;
    if(c=='D')return 13;
    if(c=='E')return 14;
    if(c=='F')return 15;
}
char st1(int x)
{
    if(x==0)return '0';
    if(x==1)return '1';
    if(x==2)return '2';
    if(x==3)return '3';
    if(x==4)return '4';
    if(x==5)return '5';
    if(x==6)return '6';
    if(x==7)return '7';
    if(x==8)return '8';
    if(x==9)return '9';
    if(x==10)return 'A';
    if(x==11)return 'B';
    if(x==12)return 'C';
    if(x==13)return 'D';
    if(x==14)return 'E';
    if(x==15)return 'F';
}
string f(string s)
{
    long long sum=0;
    int n=s.size();
    for(int i=0;i<n;i++)
        sum+=st(s[i]);
    if(sum%(b-1)!=0)
        return "0";
    int indx=0,tek=0;
    string s1="";
    while(indx<n)
    {
        tek=tek*b+st(s[indx]);
        s1+=st1(tek/(b-1));
        tek%=(b-1);
        indx++;
    }
    s1.erase(0,1);
    string s2="";
    for(int i=0;i<n-1;i++)
    s2+='1';
    string anss="";
    int naum=0;
    int k;
    for(int i=s1.size()-1;i>=0;i--)
    {
        k=st(s1[i]);
        if(k+1+naum==b)
        {
            anss='0'+anss;
            naum=1;
        }
        else
        {
            k+=1+naum;
            anss=st1(k)+anss;
            naum=0;
        }
    }
    if(naum==1)
    {
        anss='1'+anss;
    }

    anss='1'+anss;
    string aa=anss.substr(1,anss.size()-1)+anss[0];
    if(aa>=anss)
    {
        return anss;
    }
    anss[1]=(st(anss[1]-'0')+1)+'0';
    return anss;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,ans1,ans2,ans3,ans4;
    cin>>b;
    cin>>s;
    ans1=f(s);
    cin>>s;
    ans2=f(s);
    cin>>s;
    ans3=f(s);
    cin>>s;
    ans4=f(s);
    cout<<ans1<<endl<<ans2<<endl<<ans3<<endl<<ans4<<endl;
    return 0;
}
