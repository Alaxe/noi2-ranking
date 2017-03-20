#include<iostream>
using namespace std;
int main()
{
    long long w,h,n,x,y,lx,ly,plx=0,ply=0,maxy=0,maxx=0,s=0,c1,c2;
    char ld='r';
    cin>>w>>h>>n;
    long long Points[n];
    if(h>150000){
    cin>>lx>>ly;

    for(int i=1;i<n;i++)
    {
        //cout<<ld<<" "<<s<<endl;
        cin>>x>>y;
        if(ly<y)//down
        {

            if(ld=='r' && maxx<=x)s=s+((y-ly)*(w-x));
            if(ld=='l'){if(maxy<y)s=s+(y-maxy)*(w-x);}
            plx=lx;
            ply=ly;
            lx=x;
            ly=y;
            if(maxy<y)maxy=y;
            if(maxx<x)maxx=x;
            ld='d';
            continue;
        }
        else if(ly>y)//up
        {
            if(ld=='r' && maxx<=x)
            {
                s=s+((ly-y)*(w-x));
                s=s-(ly-ply)*(x-plx);
            }
            plx=lx;
            ply=ly;
            lx=x;
            ly=y;
            if(maxy<y)maxy=y;
            if(maxx<x)maxx=x;
            ld='u';
            continue;
        }
        else if(lx<x)//right
        {
            plx=lx;
            ply=ly;
            lx=x;
            ly=y;
            if(maxy<y)maxy=y;
            if(maxx<x)maxx=x;
            ld='r';
            continue;
        }
       else if(lx>x)//left
        {
            plx=lx;
            ply=ly;
            lx=x;
            ly=y;
            if(maxy<y)maxy=y;
            if(maxx<x)maxx=x;
            ld='l';
            continue;
        }

    }
    cout<<s<<endl;
    return 0;
    }
    else
        {
            long long a[h];
            s=0;
            cin>>lx>>ly;
            for(int i=0;i<h;i++)
                a[i]=0;
            for(int i=1;i<n;i++)
            {
        //cout<<ld<<" "<<s<<endl;
            cin>>x>>y;
            if(ly<y)
            {
                for(int j=ly;j<y;j++)
                {
                    if(x>a[j]){a[j]=x;}
                    //cout<<"x "<<x<<endl;
                    //cout<<a[j]<<endl;
                }
            }
            else if(ly>y)
            {
                for(int j=y;j<ly;j++)
                {
                    if(x>a[j]){a[j]=x;}
                    //cout<<"x "<<x<<endl;
                   //cout<<a[j]<<endl;
                }
            }
            else if(lx<x)
            {
                if(x>a[y])a[y]=x;
                //cout<<"x "<<x<<endl;
                //cout<<a[y]<<endl;
            }
            lx=x;
            ly=y;
            }
            for(int i=0;i<h;i++)
            {
                //cout<<a[i]<<endl;
                s=s+w-a[i];
            }
            cout<<s<<endl;
        }
        return 0;
}
