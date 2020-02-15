#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,a[100002],nom;

int Pos(int p){
 int l=0,r=n+1,p1;
        while(1){
            //cout<<l<<" "<<r<<endl;
            //if(l == r)break;
            int s=l-1+(r-l+1)/2;
            if(a[l] == p){p1=l; break;}
            if(a[r] == p){p1=r; break;}
            if(l+1 == r){p1=r; nom=1; break;}
            if(l+2 == r && a[l+1]!=p){p1=r; nom=1; break;}
            if(a[s] < p)l=s;
            else
                r=s;
        }
        return p1;
}

int main()
{
int i,b,b2;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    sort(a+1,a+n+1);
    a[0]=0;
    a[n+1]=100001;
    //for(i=1;i<=n;i++)cout<<a[i]<<" ";   cout<<endl;
   scanf("%d", &m);
    for(i=1;i<=m;i++){
       scanf("%d", &b);
       int p1 = Pos(b);
       nom=0;
       //cout<<p1<<" ";
       if(p1 != 0)
            while(a[p1]==a[p1-1])p1--;
       //cout<<p1<<" ";
       scanf("%d", &b2);
       int p2 = Pos(b2);
       //cout<<p2<<" ";
       if(nom == 1)p2--, nom=0;
       //cout<<p2<<" ";
       while(a[p2] == a[p2+1])p2++;
       //cout<<p2<<endl;
       printf("%d\n", p2-p1+1);


    }


    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20

8
3 6 6 6 6 7 8 8
5
1 2
6 8
4 7
3 5
1 7

*/
