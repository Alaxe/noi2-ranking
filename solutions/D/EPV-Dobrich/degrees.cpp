#include<iostream>
#include<cstring>
using namespace std;
int main()
{

    int p=1, br=0, h, ch=0, sz;
    string t;
    cin>>t;
    sz=t.size();
   do
    {
        p=p*2;
        ch++;
        h=p;
        do
        {
            h=h/10;
            br++;
        }
        while(h>=1);

    }
    while(br!=sz);
    cout<<ch<<endl;
}


