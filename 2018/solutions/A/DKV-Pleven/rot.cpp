
#include <iostream>
#include <math.h>
using namespace std;

int Len(int number)
{
    int cnt = 0;
    while(number!=0)
    {
        number/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int b,num,power;
    int nums [4];
    cin>>b;
    for(int i = 0;i<4;i++)
    {
        cin>>num;
        int guess = num/2;
        if(num%9!=0) nums[i]=0;
        else
        {
            for(guess;;guess++)
            {
                power = pow(10,Len(guess)-1);
                if(((guess-guess/power)*power)*10+guess/power - guess == num)
                {
                    nums[i]=guess;
                    break;
                }
            }
        }
    }
    for(int k = 0;;k<4)
    {
        cout<<nums[k];
    }
    return 0;
}






//(351 - 135 == num)


