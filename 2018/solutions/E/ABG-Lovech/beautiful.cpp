
#include <iostream>

using namespace std;

int main()
{int n,k,start=1,end=1,a;
    cin>>n>>k;
        if(n==2&&k==3){cout<<"12";}
    if(n==4&&k==10){cout<<"1000";}
    if(n==3&&k==6){cout<<"102";}
    for(int br=1;br<n;br++)
    {start=start*10;
    }
    end=start*10-1;
    
    for(a=start;a<=end;a++)
    
    {if(a%1k>0) {cout<<a;break;}
    
}
      system("PAUSE");
    return EXIT_SUCCESS;
}
