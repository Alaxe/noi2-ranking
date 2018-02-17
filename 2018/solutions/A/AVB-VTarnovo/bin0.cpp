#include<iostream>
using namespace std;

void doubleSystem(int s,int t,int z, int b[])
{int u,i,k=0,broj=0,broy=0,f;
   for(i=s;i<=t;i++)
   {u=i;
   while(u!=0) {b[k]=u%2; u=u/2;k++;}
   }
   
for(f=k-1;f>=0;f--)
   {if(b[f]==0) broj++;
   if (broj==z) broy++;
   }
  
cout<<broy*2;
}



int main()
{long long s,t; int z,b[100];
cin>>s>>t>>z;
   doubleSystem(s,t,z,b);

}



