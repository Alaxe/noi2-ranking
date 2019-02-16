#include<iostream>
#include<vector>
using namespace std;

int n;
vector <long long> v;
bool mat[1000000];
int maxCheck;

long long calc(long long p, long long x)
{
    return p*p+x;
}

bool checkAll(long long x)
{
    for(int i=0; i<maxCheck; i++)
    {   //cout<<mat[calc(v[i],x)]<<endl;
        if(mat[calc(v[i],x)]==0)
            return false;
    }
    return true;
}

int main()
{
    cin>>n;

    int maxX=1,br=1;
    for(int i=1;; i++)
    {
        if(maxX>n)
            break;
        maxX*=10;
        br++;
    }
    for(int i=2; i<10000; i++)
    {
        if(mat[i]==0)
        for(int j=i*i; j<1000000; j+=i)
        {
            mat[j]=1;
        }
    }
    for(int i=1; i<1000000; i++)
    {
        if(mat[i]==0)
            v.push_back(i);
    }
    maxX=9;
    for(int i=1; i<br; i++)
    {
        maxX*=10;
        maxX+=9;
    }
    maxCheck=10000000*(maxX-n);
    int vsize=v.size();
    //cout<<vsize<<endl;
    maxCheck=min(maxCheck,vsize);
    for(int x=n+1; x<=maxX; x++)
    {

        if(checkAll(x)==true)
            {cout<<x<<endl;return 0;}
    }
    cout<<n*2<<endl;
    return 0;
}
