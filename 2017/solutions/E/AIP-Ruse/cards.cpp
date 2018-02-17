#include<iostream>
using namespace std;
int main()
{
    long long n,a1,b1,a2,b2,maxx = 1,br = 1;
    cin>>n;
    cin>>a1>>b1;
    a2 = a1;
    b2 = b1;
    for(int i = 1;i < n;i++)
    {
        cin>>a1>>b1;
        if(b2 >= b1&&a2 >= a1)
        {
            br++;
            //cout<<a2<<"X"<<b2<<" "; 
        }
        else if(b2 >= a1&&a2 >= b1)
        {
            br++;
            //cout<<a2<<"X"<<b2<<" "; 
        }
        else
        {
            //cout<<a2<<"X"<<b2<<" ";
            //cout<<endl;
            if(br > maxx) maxx = br;
            br = 1;
        }
        b2 = b1;
        a2 = a1;
    }
    cout<<maxx<<endl;
    return 0;
}