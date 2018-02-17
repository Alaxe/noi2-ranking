#include<iostream>
using namespace std;
long long  mirror(long long a)
{
    int b;
    int ogl=0;
    while(a)
    {
        b=a%10;
        ogl=ogl*10+b;
        a/=10;
    }
    return ogl;
}
int main()
{
   int  n, maxpal=0, maxch1,maxch2, ch=0;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            ch=j*i;
            if(ch==mirror(ch)){if(maxpal<ch){maxpal=ch;maxch1=i;maxch2=j;}}
        }
    }
    cout<<maxch2<<" "<<maxch1<<endl<<maxpal<<endl;

    return 0;
}

