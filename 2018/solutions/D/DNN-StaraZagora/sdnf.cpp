#include <iostream>
using namespace std;

int main()
{

    long long int n=0, fakt=1, faktsum=0;
    cin>>n;
    
    //cout<<fakt<<endl;
    //cout<<n<<endl;
    
    while (n>1)
    {

        fakt *= n;
        //cout<<fakt<<endl;
        
        if (fakt%10 == 0) fakt /= 10;
        
        n--;
        //cout<<n<<endl;

    }

   //cout<<fakt<<endl;

    while (fakt>0)
    {

        faktsum += fakt%10;
        fakt /= 10;
        //cout<<faktsum<<' '<<fakt<<endl;

    }
    
    cout<<faktsum<<endl;

    return 0;
}
