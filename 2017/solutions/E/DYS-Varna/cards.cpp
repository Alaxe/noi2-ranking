#include<iostream>
using namespace std;
long long a,b,a1,b1;
long long plosht(long long a,long long b)
{long long d=a*b;
 return d;
}
int main()
{long long n,br=0,brm=0;
cin>>n;
cin>>a>>b;
a1=a; b1=b;
for(int i=2;i<=n;i=i+1)
{cin>>a>>b;
 if(plosht(a1,b1)>=plosht(a,b))br=br+1;
 else
 {if(br>brm)brm=br;
  br=0;
 }
 a1=a; b1=b;
}
if(br>brm)brm=br;
cout<<brm+1<<endl;
return 0;
}
