#include <iostream>
#include <stack>
using namespace std;
long long n,w,h;
struct ots{
long long y,br,h;
};
stack<ots> st;
long long ans;
int main( )
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>w>>h;
   cin>>n;
   long long i,x,y,prevx,prevy;
   cin>>x>>y;
   prevx=x;
   prevy=y;
   ots p;
   long long y1,y2;
   for(i=1;i<n;i++)
   {
       cin>>x>>y;
       if(prevx==x)
       {
         if(st.empty( )){
            p.y=prevy;
            p.br=y-prevy;
            p.h=w-x;
            st.push(p);
         }
         else{
            y1=y;
            y2=prevy;
            if(y2<y1)swap(y1,y2);
            while(!st.empty( ) && y1<=st.top().y)st.pop( );
            if(st.empty( ))
            {
                p.y=y1;
                p.br=y2-y1;
                p.h=w-x;
                st.push(p);
            }
            else if(y1<st.top().y+st.top( ).br && w-x<st.top( ).h)
            {
              st.top().br=y1-st.top().y;
              p.y=y1;
              p.br=y2-y1;
              p.h=w-x;
              st.push(p);
            }
            else if(y1<st.top().y+st.top( ).br && y2>st.top( ).y+st.top( ).br)
            {
                p.y=st.top().y+st.top().br;
                p.br=y2-p.y;
                p.h=w-x;
                st.push(p);
            }
            else if(y1>=st.top( ).y+st.top( ).br)
            {
                p.y=y1;
                p.br=y2-y1;
                p.h=w-x;
                st.push(p);
            }
          }
       }
       prevx=x;
       prevy=y;
   }
   while(!st.empty( ))
   {
       ans+=(st.top( ).br*st.top().h);
       st.pop( );
   }
   cout<<ans<<endl;
}
/**
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
