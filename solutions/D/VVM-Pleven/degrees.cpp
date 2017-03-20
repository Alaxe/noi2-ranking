#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n=1,i,d;
    string v;
    d=v.size();
    for(i=0; i<=d; i++)
        cin>>v[i];
    for(i=0; i<d-2; i++)
    {


        if(v[i]==v[i+1]/2)n++;
        else if(v[i]==(v[i+1]*10+v[i+2])/2 )n+=2;
        else if(v[i]==(v[i+1]*100+v[i+2]*10+v[i+3])/2)n+=3;
        else if(v[i]==(v[i+1]*1000+v[i+2]*100+v[i+3]*10+v[i+4])/2)n+=4;
        else if(v[i]==v[i-1]*2  ||  v[i]==(v[i+1]*10+v[i+2])/2  ||  v[i]==(v[i+1]*100+v[i+2]*10+v[i+3])/2   ||  v[i]==(v[i+1]*1000+v[i+2]*100+v[i+3]*10+v[i+4])/2)
            n+=5;
    }
    cout<<n<<endl;
    return 0;
}
