#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,m,ch;
long long x,chet;
long long br;

void sol()
{
    x=2;
    long long i=1;
    while(1)
    {
        //cout<<x<<" "<<n<<" "<<m<<endl;
        if (x>=n && x<=m)
        {
            //cout<<x<<endl;
            br++;

        }
        if (x>=m) break;
        i++;
        x=i*(i+1);
        /*x=add(x,ch);
        ch=add(ch,"2");*/
        /*x=x+ch;
        ch+=2;*/
        //if (br>5) break;
    }
}

int main ()
{
    cin>>n>>m;
    sol();
    cout<<br<<endl;
    return 0;
}
