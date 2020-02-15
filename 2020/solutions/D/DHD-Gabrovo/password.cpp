#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pass,mpass;
    int n;
    char z;
    cin>>pass;
    for(int i=0;i<pass.size();i++)
    {
        if(i>=2)
        {
            mpass=pass.substr(i-2,3);
            n=1;
            z=mpass[0];
            {
                for(int j=1;j<=2;j++)
                {
                    if(mpass[j]==z)n++;
                    else break;
                    if(n==3&&z!= 'a')mpass.replace(2,1,"a");
                    else if (n==3) mpass.replace(2,1,"b");
                }
            }
        pass.replace(i-2,3,mpass);
        }
    }
    cout<<pass<<endl;
    return 0;
}
