#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct sedem{
    int x,y1,x2;
    bool mark=false;
};
vector <sedem> v;
long long n,d,t,te[100001],zap,igr,min1=1000000;
bool fff(sedem f,sedem m)
{
    if (f.y1<m.y1) return false;
    else
    {
        if (f.y1>m.y1) return true;
        if (f.y1==m.y1) return f.x<m.x;

    }
}
sedem a[100001],kef,q[100001];

int rek(int z,int x3,int el,int db)
{
    bool fl=true;
    for (int j=z;j<=n;j++)
    {
            if (x3>=a[j].x && x3<a[j].x2) {
                    int of=el*2,offf=el*2+1;
                    //q[el]=a[j];
                 rek(j+1,a[j].x-1,of,db+1);
                 rek(j+1,a[j].x2,offf,db+1);
                 fl=false;
                 break;
            }
    }
    if (fl==true) {
        if (db<min1) min1=db;
    }

}
int main () {
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y1;
        cin>>d;
        a[i].x2=a[i].x+d;
    }
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>te[i];
    }
    sort(a+1,a+n+1,fff);
    /*for (int i=1;i<=n;i++)
    {
        cout<<a[i].x<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].mark<<endl;

    }
    */
    for (int k=1;k<=t;k++)
    {
        rek(1,te[k],1,1);
        cout<<min1-1<<" ";
        min1=1000000;
        /*if (k==1){ for (int i=1;i<=100;i++)
    {
        cout<<q[i].x<<" "<<q[i].x2<<endl;
    }
        }
        */
    }
    cout<<endl;


return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
