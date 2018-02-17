//Task: sheeps
//Author: Plamenka Hristova
#include <iostream>

using namespace std;
int main()
{
    int N,L,m1=-1,m2=-1,m3=-1,S,i,br=0,k,c;
    bool q;
    cin>>N;
    cin>>L;
    for(i=0;i<L;i++)
        if(i==0)cin>>m1;
        else if(i==1)cin>>m2;
             else cin>>m3;
    i=1;
    while(br<N)
    {
      q=false;
      k=i;
      while(k>0&&!q)
      {
          c=k%10;
          if(c==m1||c==m2||c==m3)
              q=true;
          k/=10;
      }
      if(!q)
      {
        br++;
        S=i;
      }
      i++;
    }
    cout<<S<<endl;
    return 0;
}
