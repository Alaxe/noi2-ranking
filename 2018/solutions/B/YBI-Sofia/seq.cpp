#include<iostream>
//#include<fstream>
using namespace std;
unsigned long long v[256][256];
unsigned long long f(int sumleft,int maxx)
{
    if(maxx>sumleft)
    {
        maxx=sumleft;
    }
    if(v[sumleft][maxx]!=0)
    {
        return v[sumleft][maxx];
    }
    if(sumleft==0)
    {
        return 1;
    }
    unsigned long long res=0;
    for(int j=min(sumleft,maxx);j>=1;j--)
    {
        res+=f(sumleft-j,j);
    }
    v[sumleft][maxx]=res;
    return res;
}
//ofstream a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int n,m;
    cin>>n>>m;
    cout<<f(n,m)<<endl;
    //a.open("a.txt");
    /*for(int n=1;n<=269;n++)
    {

        a<<n<<" "<<f(n,n)<<endl;
    }*/

    return 0;
}

