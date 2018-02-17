#include <iostream>
using namespace std;
bool bo=true;
int d[160000];
string b="",c;
char k='0';
string a;
int degree(string x)
{
    int j=1,br=0;
    while(true)
    {
        c=j*2;
        j=j*2;
        b=b+string(c);
        br++;
        for(int i=0;i<b.size();i++)
        {
            if(x[i]!=b[i]+'0')
            {
                bo==false;
                break;
            }            if(i==x.size()-1)
                bo=false;
            //cout<<b<<" ";
        }
        if(bo==false)
            break;
    }
    return br;
}
int main()
{

    cin>>a;
    cout<<degree(a)<<endl;
}


