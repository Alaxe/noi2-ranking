#include<iostream>
#include<string>
using namespace std;

int p,q,add;
int br=0;
int sum=0;

void baby(bool isS=true)
{
     if(isS==true)
     {
         sum+=p;
         if(sum>=add)
         {
             sum-=p;
             br++;
         }
         else
         {
             baby(true);
             baby(false);
             sum-=p;
         }
     }
     else
     {
         sum-=q;
         baby(true);
         sum+=q;
     }
}
long long int up2(int n)
{
     if(n==1)return 2;
     return 2*up2(n-1);
}
int main()
{
    int M,N;
    cin>>M>>N>>p>>q;
    add=N-M;
    baby();
    cout<<br%up2(30)<<endl;
    system("pause");
    return 0;
}
