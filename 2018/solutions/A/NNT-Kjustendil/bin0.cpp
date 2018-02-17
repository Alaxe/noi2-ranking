#include <iostream>
#include <iomanip>
using namespace std;
int counterForMatching;
int counterForInline;
int countForValidation = 5;
int i,p;
int s,t,z;
int main()
{

    cin>>s;
    cin>>t;
    cin>>z;
    for(i = s; i <= t; i++)
    {
        counterForInline = 0;
        int secForCheck = i;
        counterForInline = 0;
        for(p = 0; p <10000;p++)
            {

                if(secForCheck % 2 == 0)
                {
                    counterForInline++;
                    secForCheck = secForCheck / 2;
                }
                else
                {
                    secForCheck = secForCheck/2;

                }
                if(secForCheck == 1)
                {
                    break;
                }

            }
        if(counterForInline == z)
        {
            counterForMatching++;

        }
    }
    cout<<counterForMatching;
    return 0;

}
