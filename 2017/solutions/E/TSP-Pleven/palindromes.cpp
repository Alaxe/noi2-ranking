#include<iostream>
using namespace std;

int main()
{
    long long n, num1, num2, sum, sum2, br1, br2;
    cin>>n;
    br1=1;
    br2=1;
    for(;;)
    {
        num1=n-br1;
        num2=n-br2;
        sum=num1*num2;

        if(sum%10==sum/1000)
        {
            break;
        }
        else
        {
            if(sum%10==sum/100)
            {
                break;
            }
            if(sum%10==sum/10)
            {
                break;
            }
            if(sum%10==sum/1)
            {
                break;
            }
            br1++;
        }
    }
    cout<<num1<<" ";
    if(num1!=num2)
    {
        cout<<num2;
    }
    cout<<endl<<sum<<endl;
    return 0;
}
