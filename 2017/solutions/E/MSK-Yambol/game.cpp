#include <iostream>
using namespace std;
long long cd[1000];
int main()
{
 long long m,k,brmax=0,i=0,a,br=0,z=0,kl=1;
 cin>>m>>k;
 cin>>a;
 brmax=a;
 for(i=0;i<k;i++)
 {
     if(a<=k)
      {if(a%2==0) br=br+a;
      if(a==m) brmax=kl;
      else
      if(a<=m&&brmax<=m)
      {
           if(m-brmax>=m-a) brmax=kl;
      }
      else if(m<brmax) {if(brmax-m>=a-m) brmax=kl;}
           else if(m-brmax>=a-m) brmax=kl;
      if(br>k) break;
     cin>>a;kl++;

      }
     else {cout<<1<<" "<<a; return 0;}
 }
 cout<<brmax<<" "<<br;
 return 0;
}

