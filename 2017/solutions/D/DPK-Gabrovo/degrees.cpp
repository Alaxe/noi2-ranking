#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
using namespace std;
int main ()
{
    string k;
    stack <int> z;
    stack <int> r;
    z.push(1);
    int a=2,b=3,c,i=0,i1=0;
getline(cin,k);
a=k.size();
while (true)
{
    a--;
    r.push(int (k[a]-'0'));
    if (a==0)break;

}
while (!r.empty())
{
  if (r.size()<z.size()*b) { b=r.size()/z.size();
    for (int as=1;as<=r.size();as++)
    {
        r.pop();

    }}
    else
        for (int as=1;as<=z.size()*b;as++)
    {
        r.pop();

    }
    i++;
    i1=i1+b;
    if (i!=3){b=3;}
    if (i==3){i=0;b=4;}
    z.push(1);
}
cout<<i1<<endl;
    return 0;
}
