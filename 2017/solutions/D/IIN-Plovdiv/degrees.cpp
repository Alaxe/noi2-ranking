#include<bits/stdc++.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string s;
    long long n=2,br=0,br2,br3=0,k;
    cin>>s;
    br2=s.size();
    for(int br=0;br<=br2;)
    {
         k=n;
        do
        {
            k=k/10;
            br++;
        }
        while(k>0);
        n=n*2;
        br3++;
    }
    cout<<br3-1<<endl;
    return 0;

}
