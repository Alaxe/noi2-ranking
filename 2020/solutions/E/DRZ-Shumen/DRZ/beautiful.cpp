#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    int br=0;
    for(int i=1; i<=n; i++)
    {
        if(i<10)
        {
            br++;
        }
        if(i>9 && i<100)
        {
            int ed=i%10;
            int des=i/10%10;
            if(ed==des)
            {
                br++;
            }
        }
        if(i>99 && i<1000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            if(ed==des && des==stot)
            {
                br++;
            }
        }
        if(i>999 && i<10000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            int hil=i/1000%10;
            if(ed==des && des==stot && stot==hil)
            {
                br++;
            }
        }
        if(i>9999 && i<100000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            int hil=i/1000%10;
            int deshil=i/10000%10;
            if(ed==des && des==stot && stot==hil && hil==deshil)
            {
                br++;
            }
        }
        if(i>99999 && i<1000000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            int hil=i/1000%10;
            int deshil=i/10000%10;
            int stohil=i/100000%10;
            if(ed==des && des==stot && stot==hil && hil==deshil && deshil==stohil)
            {
                br++;
            }
        }
        if(i>999999 && i<10000000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            int hil=i/1000%10;
            int deshil=i/10000%10;
            int stohil=i/100000%10;
            int mil=i/1000000%10;
            if(ed==des && des==stot && stot==hil && hil==deshil && deshil==stohil && stohil==mil)
            {
                br++;
            }
        }
        if(i>9999999 && i<100000000)
        {
            int ed=i%10;
            int des=i/10%10;
            int stot=i/100%10;
            int hil=i/1000%10;
            int deshil=i/10000%10;
            int stohil=i/100000%10;
            int mil=i/1000000%10;
            int desmil=i/10000000%10;
            if(ed==des && des==stot && stot==hil && hil==deshil && deshil==stohil && stohil==mil && mil==desmil)
            {
                br++;
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
