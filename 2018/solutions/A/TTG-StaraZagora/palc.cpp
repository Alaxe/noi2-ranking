#include<iostream>
#include<cstring>
using namespace std;

const long long d=1000000007;
long long c=0;

long long Sol(char *s, int st, int fn)
{
    if(st>fn)return 0;
    //cout<<"!"<<st<<' '<<fn<<endl;
    for(int i=st;i<=fn;i++)
     for(int j=i;j<=fn;j++)
      if(s[i]==s[j])
      {
          //cout<<i<<' '<<j<<endl;
          c++;
          if(c>d)c%=d;
          Sol(s,i+1,j-1);
      }
    //cout<<"back\n";
    return c;
}

int main()
{
    char s[128];
    cin>>s;
    cout<<Sol(s,0,strlen(s)-1)%d<<endl;
}