#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct otsechka
{
   long long ax, ay, bx, by;
};
long long w,h,n, lastX, lastY, maxxY=0, lice=0, x, y;
stack<otsechka>st;
vector<otsechka>v;
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
cin>>w>>h>>n;
cin>>lastX>>lastY;
for(int i=1;i<n;i++)
{
    otsechka curr;
    cin>>x>>y;
    if(lastX==x)
    {
        curr.ax=x;
        curr.bx=x;
        curr.ay=min(lastY, y);
        curr.by=max(lastY, y);
        while(!st.empty() && st.top().ay>curr.ay)
        {
            st.pop();
        }
        st.push(curr);
    }
    lastX=x;
    lastY=y;
    //cout<<"i: "<<i<<endl;
}
//cout<<"dsfsf\n";
while(!st.empty())
{
    v.push_back(st.top());
   // cout<<"curr"<<st.top().ax<<endl;
    st.pop();

}
otsechka last=v[v.size()-1];
lice+=(last.by-last.ay)*last.ax;
 //cout<<"lice+="<<(last.by-last.ay)*last.ax<<endl;
for(int i=v.size()-2;i>=0;i--)
{
    otsechka curr=v[i];
   // cout<<"curr "<<curr.ax<<" "<<curr.ay<<" "<<curr.bx<<" "<<curr.by<<endl;
    if(last.by>curr.ay && last.by<curr.by)/// zastupwat se
    {

        lice+=(curr.by-curr.ay)*curr.ax;
       // cout<<"lice+="<<(curr.by-curr.ay)*curr.ax<<endl;
       // cout<<"lice-=";
        if(curr.ax>last.ax)
        {
            lice-=(last.by-curr.ay)*last.ax;
           // cout<<(last.by-curr.ay)*last.ax<<endl;
        }
        else
        {
            lice-=(last.by-curr.ay)*curr.ax;
          //  cout<<(last.by-curr.ay)*curr.ax<<endl;
        }
        last=curr;
    }
    else
    {
        if(curr.by>last.by)
        {
            lice+=(curr.by-curr.ay)*curr.ax;
        // cout<<"lice+="<<(curr.by-curr.ay)*curr.ax<<endl;
         last=curr;
        }


    }

}
cout<<w*h-lice<<endl;


return 0;
}
