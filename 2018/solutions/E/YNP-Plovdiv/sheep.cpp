#include<iostream>
using namespace std;
int main()
{
    long long n,l,q,t,r,h,br=0,bc=0,ed,des;
    cin>>n>>l;
    if(l==1)
    {
        cin>>q;
        for(h=1;h<=n;h++)
        {
            if(h<10&&h==q)br=br+2;
            else
            {
            if(h>=10)
            {
                ed=h%10;
                des=h/10;
                if(ed==q||des==q)br=br+2;
            }
            else br++;
            }
        }
        br=br+10;
    }
    if(l==2)
    {
        cin>>q>>t;
        for(h=1;h<=n;h++)
        {
            if(h<10&&h==q)br=br+2;
            if(h<10&&h==q)br=br+2;
            else
            {
            if(h>=10)
            {
                ed=h%10;
                des=h/10;
                if(ed==q||des==q)br=br+2;
                if(ed==t||des==t)br=br+2;
            }
            else br++;
            }
        }

    }
    if(l==3)
    {
        cin>>q>>t>>r;
        for(h=1;h<=n;h++)
        {
            if(h<10&&h==q)br=br+2;
            if(h<10&&h==t)br=br+2;
            if(h<10&&h==r)br=br+2;
            else
            {
            if(h>=10)
            {
                ed=h%10;
                des=h/10;
                if(ed==q||des==q)br=br+2;
                if(ed==t||des==t)br=br+2;
                if(ed==r||des==r)br=br+2;
            }
            else br++;
            }
        }
        br=br+11;
    }
    cout<<br<<endl;
    return 0;
}
