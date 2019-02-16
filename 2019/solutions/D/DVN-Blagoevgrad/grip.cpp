#include<bits/stdc++.h>
using namespace std;
int d[2];
int main()
{
    int v,br=0;
    string s;
    cin>>s>>v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='/')
            br++;
        else
        {
            d[br]*=10;
            d[br]+=(s[i]-'0');
        }
    }
    int d2=d[0],m=d[1],y=d[2],sed=(d[2]-1900+1)*365+(d[2]-1900+1)/4;
    sed=sed%7;
    //cout<<sed<<" ";
    for(int i=0;i<v;i++)
    {
            cout<<d2<<"."<<m<<"."<<y<<"\n";
        d2++;
        sed++;
        if(sed==8)
            sed=1;
        if(sed>5)
            v+=2;
        if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12 and d2==32)or (m==4 or m==6 or m==9 or m==11 and d2==31)or((y%4==0 and m==2 and d2==30)or(y%4!=0 and m==2 and d2==29)))
        {
            d2=1;
            m++;
            if(m==13)
                y++;
        }
    }
    cout<<d2<<"."<<m<<"."<<y<<endl;
return 0;
}
