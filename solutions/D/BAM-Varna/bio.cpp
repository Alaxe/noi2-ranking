#include<iostream>
using namespace std;
int main ()
{
    int d[4], m[4],ans;
    char sep;
    cin>>d[0]>>sep>>m[0]>>d[1]>>sep>>m[1]>>d[2]>>sep>>m[2]>>d[3]>>sep>>m[3];
    if(d[0]==d[1]==d[2]==d[3] && m[0]==m[1]==m[2]==m[3])cout<<"21252"<<endl;
    else
    {
        for(int j=1;j<=924;j++)
        {
            d[0]+=23;
            if(d[0]>31 || d[0]>30 || d[0]>28)m[0]++;
            d[1]+=28;
            if(d[1]>31 || d[1]>30 || d[1]>28)m[1]++;
            d[2]+=33;
            if(d[2]>31 || d[2]>30 || d[2]>28)m[2]++;
            if((d[0]==d[1]==d[2]) && (m[0]==m[1]==m[2]))break;
        }
        for(int i=0;i<3;i++)
        {
            if(m[i]==2)d[i]+=31;
            if(m[i]==3)d[i]+=59;
            if(m[i]==4)d[i]+=90;
            if(m[i]==5)d[i]+=120;
            if(m[i]==6)d[i]+=151;
            if(m[i]==7)d[i]+=180;
            if(m[i]==8)d[i]+=212;
            if(m[i]==9)d[i]+=243;
            if(m[i]==10)d[i]+=273;
            if(m[i]==11)d[i]+=304;
            if(m[i]==12)d[i]+=334;
        }
        ans=21252-d[0]+d[1]+d[2];
        cout<<ans<<endl;
    }
    return 0;
}
