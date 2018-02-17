#include<iostream>
using namespace std;
long long blizko(long long a, long long m)
{long long br=0;
 if(a>m)br=a-m;
 else br=m-a;
 return br;
}
int main()
{long long m,k;
cin>>m>>k;
long long a,sum=0,poz=1,i=1,p=-1;
while((i<200) && (sum<k))
{cin>>a;
 if(a%2==0)sum=sum+a;
 if(blizko(a,m)<=blizko(p,m))
 {poz=i;
  p=a;
 }
 i=i+1;
}
cout<<poz<<" "<<sum<<endl;
return 0;
}
