#include<bits/stdc++.h>
using namespace std;
long long red[100000];
long long nm[100000];
long long ng[100000];
long long din[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long brch=0,brza=0;
    cin>>brch;
    for(long long a=0;a<brch;a++){
        cin>>red[a];
    }
    sort(red,red+brch);
    cin>>brza;
    for(long long a=0;a<brza;a++){
        cin>>nm[a]>>ng[a];
    }
    for(long long n=0;n<brch;n++){
        din[red[n]]++;
    }
    for(long long n=0;n<=red[brch-1];n++){
        if(n!=0){
            din[n]=din[n]+din[n-1];
        }
    }
    for(long long a=0;a<brza;a++){
        if(nm[a]-1>=red[brch-1]){
            din[nm[a]-1]=brch;
        }
        if(ng[a]>=red[brch-1]){
            din[ng[a]]=brch;
        }

        cout<<din[ng[a]]-din[nm[a]-1]<<endl;

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
*/

