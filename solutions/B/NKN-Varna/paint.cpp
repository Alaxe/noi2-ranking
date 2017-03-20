#include<iostream>
#include<vector>
using namespace std;

int last[11004]={0},br=0;
vector<int> rec[11004];
bool check(int cur, int i){
    if(rec[cur][1]>rec[i][1] && rec[cur][2]>rec[i][2]){
        rec[cur][3]-=rec[i][3];
        br++;
        return true;
    }else return false;
}
bool ans(int cur, int x, int y){
    if(rec[cur][1]>x && rec[cur][0]<y && rec[cur][2]>y){
        return true;
    }else return false;
}
int main(){
    int width,height,n,m,mat[11004];
    cin>>width>>height>>n;
    rec[0].push_back(0);
    rec[0].push_back(width);
    rec[0].push_back(height);
    rec[0].push_back(width*height);
    int a,b,c,d,backs=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        rec[a].push_back(b);
        rec[a].push_back(c+a);
        rec[a].push_back(d+b);
        rec[a].push_back(c*d);
    }
    last[0]=0;
    if(n>=1)
    for(int i=1;i<width;i++){
        last[i]=backs;
        if(rec[i].size()>0){
            int l=i;
            int cur=last[l];
            while(!check(cur,i)){
                l=cur;
                cur=last[l];
            }
            backs=i;
        }
    }
    int p,x,y;
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>x>>y;
        int cur=last[x];
        int l=x;
        if(n>=1){
            while(!ans(cur,x,y)) {
                l=cur;
                cur=last[l];
            }
            cout<<rec[last[l]][3]<<endl;
        }
        else cout<<rec[0][3]<<endl;
    }
    return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
