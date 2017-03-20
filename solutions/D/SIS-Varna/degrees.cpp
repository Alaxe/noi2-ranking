#include <iostream>
#include <stack>
using namespace std;
string s;
stack<int> s1;
int n=1,c;
int stn()
{
       for(int i=0; i<(int)s.size(); i++)
       {
           n=1;
           c=i;
           while(c)
           {
               n=n*2;
               c--;
           }
           s1.push(n);
       }
       return s1.top();
}
int main()
{
    cin>>s;
    cout<<stn()<<endl;
return 0;
}
