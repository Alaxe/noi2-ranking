#include<iostream>
using namespace std;

int main()
{
    long long ai1, bi1, ai2, bi2, n, br1;
    cin>>n;
    br1=0;
    ai1=0;
    bi1=0;
    for(int a=1;a<=n;a++)
    {
        cin>>ai2,bi2;
        if (ai1!=0 and bi1!=0)
        {
            if(ai1==ai2 or ai1==bi2 or bi1==bi2)
            {
                br1++;
            }
            else
            {
                br1--;
            }
        }

        ai1=ai2;
        bi1=bi2;
    }
    br1--;

    cout<<br1<<endl;
    return 0;
}
