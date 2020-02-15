#include<iostream>
using namespace std;
int main()
{unsigned long long int N,a;
short int br=0,i=1,s=0,c=2;
cin>>N;
while(a)
{
 a/=10;
 c++;   
}
for(i=1;i<=9;i++)
{s=i;
 while (s<=N)
 {br++;
  s=s*10+i;   
 }
    
}
cout<<br<<endl;
    return 0;
}