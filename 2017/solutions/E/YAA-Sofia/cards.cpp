#include<iostream>
using namespace std;
long long kartonchetaraz[200000];
int main()
{
    long long n,broqch,razred=1,naired=1;
    cin>>n;
    for(broqch=0; broqch<n*2; broqch++)
    {
        cin>>kartonchetaraz[broqch];
    }
    for(broqch=0;broqch<n*2;broqch++)
    {if(broqch%2==1){if(kartonchetaraz[broqch]>=kartonchetaraz[broqch+3] and kartonchetaraz[broqch+1]>=kartonchetaraz[broqch+2]){razred++;


       if(razred>=naired){naired=razred;}

    }else{razred=1;}}


    }
cout<<naired+1;

    return 0;
}
