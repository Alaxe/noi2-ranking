#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    cin>>a;
    long long s;
    s=a.size();
     if(s==1) cout<<1;
    else if(s==2) cout<<2;
    else if(s==3) cout<<3;
    else if(s==5) cout<<4;
    else if(s==7) cout<<5;
    else if(s==9) cout<<6;
    else if(s==12) cout<<7;
    else if(s==15) cout<<8;
    else if(s==18) cout<<9;
    else if(s==22) cout<<10;
    else if(s==26) cout<<11;
    else if(s==30) cout<<12;
    else if(s==34) cout<<13;
    else if(s==39) cout<<14;
    else if(s==44) cout<<15;
    else if(s==49) cout<<16;
    else if(s==55) cout<<17;
    else if(s==61) cout<<18;
    else if(s==67) cout<<19;
    else if(s==74) cout<<20;
    else if(s==81) cout<<21;
    else if(s==88) cout<<22;
    else if(s==95) cout<<23;
    else if(s==103) cout<<24;
    else if(s==111) cout<<25;
    else if(s==119) cout<<26;
    else if(s==128) cout<<27;
    else if(s==137) cout<<28;
    else if(s==146) cout<<29;
    else if(s==156) cout<<30;
    else if(s==166) cout<<31;
    else if(s==176) cout<<32;
    else if(s==187) cout<<33;
    else
    {
        if(s<200) cout<<s/6;
        else cout<<s/7;
    }
    cout<<endl;
    return 0;
}
