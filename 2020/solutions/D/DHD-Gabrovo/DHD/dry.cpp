#include <iostream>

using namespace std;

int main()
{
    int n=0,u=0,v=0,h[102]={0,},answer=0;
    cin>>n>>u>>v;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int van_d=1,van_h=h[0],van_end=0;
    bool need_new_for=false;
    for(int i=1;i<n;i++)
    {
        if(van_h>h[i])van_d++;
        if(van_h<=h[i])
        {
            answer=answer+((van_d*u)*v*van_h);
            van_end=i;
            van_d=1;
            van_h=h[i];
        }
        if(van_h>h[i]&&i==n-1)
        {
            need_new_for=true;
        }
    }

    if(need_new_for=true)
    {
            van_d=1;
            van_h=h[n-1];

        for(int i=n-2;i>=van_end;i--)
        {
            if(van_h>h[i])van_d++;
            if(van_h<=h[i])
            {
                answer=answer+((van_d*u)*v*van_h);
                van_d=1;
                van_h=h[i];
            }
        }
    }

    cout<<answer<<endl;
    return 0;
}
