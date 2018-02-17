#include <iostream>
using namespace std;
struct point{
int x,y;
};
int main( )
{
   point b1,e1,b2,e2;
   cin>>b1.x>>b1.y>>e1.x>>e1.y;
   cin>>b2.x>>b2.y>>e2.x>>e2.y;
   int i,j,k,p,tmanh,razx,razy,minmanh=100000;
   if(b1.x>e1.x)swap(b1.x,e1.x);
   if(b1.y>e1.y)swap(b1.y,e1.y);
   if(b2.x>e2.x)swap(b2.x,e2.x);
   if(b2.y>e2.y)swap(b2.y,e2.y);
   for(i=b1.x;i<=e1.x;i++)
   {
       for(j=b1.y;j<=e1.y;j++)
       {
           for(k=b2.x;k<=e2.x;k++)
           {
               for(p=b2.y;p<=e2.y;p++)
               {
                   razx=i-k;
                   razy=j-p;
                   if(razx<0)razx=-razx;
                   if(razy<0)razy=-razy;
                   tmanh=razx+razy;
                   if(tmanh<minmanh)minmanh=tmanh;
               }
           }

       }
   }
   cout<<minmanh<<endl;
}
/**
4 2 4 4
6 6 2 6
*/
