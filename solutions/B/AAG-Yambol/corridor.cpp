#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
long long w,h;
long long n;
struct ots{
 long long x;
 long long y;
};
struct ots2{
 long long x1,y1;
 long long x2,y2;
};
long long ans;
vector <ots> c;  // tuk shte se reduvat vertikalni i horizontalni
vector <ots> a;  // input
vector <ots2> vert;
int zasichane(ots2 a,ots2 b)
{
    int z=0;
    if(b.y2<=a.y2 && b.y1>=a.y1)
     z=b.y2-b.y1;
    else
    if(a.y2<=b.y2 && a.y1>=b.y1)
     z=a.y2-a.y1;
    else
    if(b.y2<a.y1 || b.y1>a.y2)
     z=0;
    else
     z=min(a.y2,b.y2)-max(a.y1,b.y1);
    return z;

}
bool vertsort(ots2 a,ots2 b)
{
    if(a.y1!=b.y1)
        return a.y1<b.y1;
    else
        return a.x1<b.x1;
}
int main()
{
    long long i,j,x,y;
    long long z;
    ots temp;
    ots2 tempots2;
    cin>>w>>h;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld",&temp.x,&temp.y);
        a.push_back(temp);
    }
    temp.x=-1;
    temp.y=-1;
    a.push_back(temp);
    for(i=0;i<n;i++)
    {
        c.push_back(a[i]);
        j=i+1;
        while(a[j].x==a[j-1].x) // vertikalni otsechki
         j++;
        j--;
        if(j!=i)
         i=j-1;

        j=i+1;
        while(a[j].y==a[j-1].y) // horizontalni otsechki
         j++;
        j--;
        if(j!=i)
         i=j-1;;

    }
   /* cout<<endl;
    for(i=0;i<c.size();i++)
        cout<<c[i].x<<" "<<c[i].y<<endl;*/


    for(i=1;i<c.size();i++)
    {
        if((c[i].y==c[i-1].y) && (c[i].x<c[i-1].x)) // lqv zavoi
        {
            j=i;
            while(c[j].y<=c[i-1].y)
             j++;
            tempots2.x1=c[j-1].x;
            tempots2.y1=c[j-1].y;
            tempots2.x2=c[j].x;
            tempots2.y2=c[j].y;
            vert.push_back(tempots2);
            i=j;
        }
        else
        {
            //if(c[i].y!=c[i-1].y) // ne e desen zavoi
            if(c[i].y>c[i-1].y)                //vertikalnite otivashti nagore ne ni interesuvat
            {
             tempots2.x1=c[i-1].x;
             tempots2.y1=c[i-1].y;
             tempots2.x2=c[i].x;
             tempots2.y2=c[i].y;
             vert.push_back(tempots2);
            }
        }
    }




   /* cout<<endl;
    cout<<vert.size()<<endl;


    for(i=0;i<vert.size();i++)
        cout<<vert[i].x1<<" "<<vert[i].y1<<" "<<vert[i].x2<<" "<<vert[i].y2<<endl;*/

sort(vert.begin(),vert.end(),vertsort);
    ans=(vert[0].x1)*(vert[0].y2-vert[0].y1);

    //cout<<ans<<endl;
    for(i=1;i<vert.size();i++) // vsqka moje da se preseche samo s predishnata
    {
      if(vert[i].y1>=vert[i-1].y2) // nqmat presichane
          ans+=(vert[i].x1)*(vert[i].y2-vert[i].y1);
      else
      {
          //z=vert[i-1].y2-vert[i].y1; //zasichane
          z=zasichane(vert[i-1],vert[i]);
        //  cout<<i<<" "<<z<<endl;
         // cout<<i<<" "<<z<<endl;
          if(vert[i].x1>=vert[i-1].x1)  // tekushtata e po nadqsno
          {
              ans-=z*vert[i-1].x1;
              ans+=(vert[i].y2-vert[i].y1)*vert[i].x1;
          }
          else  // tekushtata e nalqvo
          {
              ans+=(vert[i].y2-vert[i].y1-z)*vert[i].x1;
          }
      }
     // cout<<ans<<endl;


    }

    cout<<(w*h)-ans<<endl;
    return 0;
}


/*

15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10

*/



/*

5 5
10
1 0
1 3
2 3
2 2
3 2
3 3
4 3
4 1
5 1
5 5

*/
