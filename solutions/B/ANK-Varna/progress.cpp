#include<iostream>
#include<vector>
using namespace std;
int s;
struct str
{
    short x;
    short y;
};
struct str1
{
    short x;
    short y;
    short z;
};
short combo[1024] [1024];
vector<str> finder;
str1 b[1024];
int main()
{
    int a;
    str dummy;
    cin>>a;
    for(int i=1; i<=a; i++)
    {
        cin>>b[i].x;
    }
           for(int i=1; i<a; i++)
    {
        if(b[i].y==0) b[i].y=i;
        for(int j=i+1; j<=a; j++)
        {
            if(b[j].x>b[i].x)
            {
                s++;
                b[j].z=b[j].x-b[i].x;
                b[j].y=b[i].y;
                combo[b[j].y] [b[j].z]++;
             if(b[i].y!=i)
                    {
                if(combo[b[j].y] [b[j].z]==1)
                {   //cout<<i<<" "<<j<<endl;
                    dummy.x=b[j].y;
                    dummy.y=b[j].z;
                    finder.push_back(dummy);
                }}

            }

        }
    }
    for(int i=0; i<finder.size(); i++)
    {
       // cout<<finder[i].x<<" "<<finder[i].y<<endl;
        for(int j=combo[finder[i].x] [finder[i].y]; j>0; j--)
    {
        s+=j;
    }
}
cout<<s<<endl;
}
