#include <iostream>
using namespace std;
int main()
{
    int N,br=0,a,b,a1,b1;
    cin>>N;
    cin>>a1>>b1;
    N--;
    int max=0;
    while(N>0)
    {
     N--;
     cin>>a>>b;
     if(a*b<=a1*b1) br++;
     if(br>=max) max=br;
     else br=0;
     a1=a;
     b1=b;
    }
   cout<<max+1<<endl;
}
