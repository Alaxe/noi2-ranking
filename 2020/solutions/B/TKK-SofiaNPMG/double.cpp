#include<iostream>
#include<algorithm>
using namespace std;

const int Max=250;

int n,w1,w2,max_found=0;

int weight [Max];

bool mem [Max][Max][Max];

bool get_from(int w1,int w2,int i){
if(w1<0 or w2<0){
    return false;
}
return mem[w1][w2][i];
}

int main(){
ios_base::sync_with_stdio(false);
cin>>n>>w1>>w2;
for(int i=0;i<n;i++){
    cin>>weight[i];
}
for(int i=0;i<w1;i++){
    for(int j=0;j<w2;j++){
        mem[i][j][0]=false;
    }
}
mem[0][0][0]=true;;
for(int w1_c=0;w1_c<=w1;w1_c++){
    for(int w2_c=0;w2_c<=w2;w2_c++){
        for(int i=1;i<=n;i++){
            if(get_from(w1_c,w2_c,i-1) or get_from(w1_c-weight[i-1],w2_c,i-1) or get_from(w1_c,w2_c-weight[i-1],i-1)){
                mem[w1_c][w2_c][i]=true;
                max_found=max(max_found,w1_c+w2_c);
            }
        }
    }
}
cout<<max_found;
return 0;
}
