#include<iostream>
using namespace std;
int main()
{
    long long k,n,p,br=0;
    cin>>n;
    k = 1;
    p=k+1;
    for(k=1;k<p;k++)
    {
        br++;
        if(k==n)
        {
            cout<<br<<endl;
            break;
        }
        
  for(k=p-1;k<p;k--)
  {
      br++;
      if(k==n)
      {
          cout<<br<<endl;
      }
  }
    }
    return 0;
}



#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,d=1,br=0,k=0;
    cin>>a>>b;
    for(c=a;c<=b;c++)
    {
        for(d=1;d<=c;d++)
        {
        if(c%d!=0)br++;
        if(br%2!=0)k++;
        cout<<k<<endl;
        }
        
    }
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    #include<iostream>
using namespace std;
int main()
{
long long a,b,c;
cin>>a;
for(b=1;b<=a;b++)
{
    if(a%b==0)cout<<b<<endl;
}
return 0;
}