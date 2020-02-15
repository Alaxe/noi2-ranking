#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, br=0, br2=0, pbr=0;
    cin>>n;
    char a;
    for(long long n1=n;n1>0;n1--)
    {
        cin>>a;
        if((a=='a') || (a=='b'))
        {
            br2++;
        }
        if((a=='c') || (a=='d'))
        {
            br++;
        }
        if(br==br2)
        {
            pbr+=(br+br2);
            br=0;
            br2=0;
        }
    }
    cout<<pbr<<endl;
    return 0;
}
