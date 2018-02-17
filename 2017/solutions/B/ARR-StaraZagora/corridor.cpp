#include <iostream>
using namespace std;
int h,w;
int x[1000000], y[100000],max=0;
int main()
{
cin>>h>>w;
int p;
cin>>p;
int max=0,sum=0;
int br=0;
for(int i=0; i<p; i++)
cin>>x[i]>>y[i];

for(int i=1; i<p; i++)
{
    if(x[i]==x[i-1] && y[i]>=max){br+=y[i]-y[i-1]; max=y[i];}
    
    else 
    {
        sum+=br*x[i-1];
        
        br=0;
    }
}
cout<<h*w-sum<<endl;
 return 0;
}
/*
15 10
16
6 0
6 2 
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10*/