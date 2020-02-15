#include<iostream>  
using namespace std;
int main()
{ unsigned long long int N,a,s=0;
   unsigned short int br=0,c,i=1;
 cin>>N;
  a=N;
  while (a)
  { c++;
  a/=10;
  }
  for(i=1;i<=9;i++)
  { s=i;
    while (s<=N)
    { br++;
    s=s*10+1;
    }
    }
     cout<<br<<endl;
      
      return 0;
    }
  
    
