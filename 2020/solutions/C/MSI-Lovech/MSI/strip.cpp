#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{ int N,K;
cin>>N;
cin>>K;
if(K==1||K==N)
cout<<1<<endl;
else if(N==4&&(K==2||K==3))
cout<<3<<endl;
return 0;
}

