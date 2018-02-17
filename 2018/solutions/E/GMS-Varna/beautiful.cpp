#include<iostream>
using namespace std;
int main()
{
    long long k,n,s;
    cin>>n>>k;
     if(n=1 && k<10)cout<<n*k<<endl;
      else if (n=1 && k>10)cout<<"NO"<<endl;
     else if(n=2 && k<100 && k>=10)cout<<k<<endl;
      else if (n=2 && k>100)cout<<"NO"<<endl;
     else if (n=2 && k<10 && 10%k==0)cout<<10<<endl;
     else if(n=2 && k<10 && 12%k==0)cout<<12<<endl;
      else if(n=2 && k<10 && 14%k==0)cout<<14<<endl;
       else if(n=2 && k<10 && 16%k==0)cout<<16<<endl;
        else if(n=2 && k<10 && 18%k==0)cout<<18<<endl;
     else if (n=3 && k<1000 && k<=100)cout<<k<<endl;
     else if (n=3 && k>1000)cout<<"NO"<<endl;
     else if (n=4 && k<10000 && k<=1000)cout<<k<<endl;
     else if (n=5 && k<100000 && k<=10000)cout<<k<<endl;
     else if (n=5 && k>100000)cout<<"NO"<<endl;
     else if (n=6 && k<1000000 && k<=100000)cout<<k<<endl;
     else if (n=7 && k<10000000 && k<=1000000)cout<<k<<endl;
          else if (n=7 && k>1000000)cout<<"NO"<<endl;
     else if (n=8 && k<100000000 && k<=10000000)cout<<k<<endl;
      else if (n=8 && k>1000000)cout<<"NO"<<endl;

    return 0;
}

