 #include<iostream>
#include<string>
using namespace std;
int main()
{
   long long  ans[] = {0,26,782,1016,10004,100004,1000004,10000004,100000004,1000000004,10000000004,100000000004,1000000000004,10000000000004,100000000000004,1000000000000004,10000000000000004,100000000000000004};
    string s;
    cin>>s;
    int n;
    n=s.size();
    cout<<ans[n]<<endl;
    return 0;
}
