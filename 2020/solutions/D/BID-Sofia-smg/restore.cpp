#include<bits/stdc++.h>
using namespace std;
int n , b[100000],br,a[100000],index;
bool f=true,c[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> n ;
    for(int i = 0 ; i < n ; ++ i){
        cin>>b[i];
        if(f and b[i]==0){
            f=false;
            index=i;
            a[i]=n;
            c[i]=true;
        }
    }
    for(int i = 0 ; i < n ; ++ i){
        for(int j = index-1; j > -1 ; -- j){
            if(b[j]==0)continue;
            if(b[j]==1){
                a[j]=a[index]-1;
                index=j;
                c[j]=true;
            }
            b[j]--;
        }
            for(int j = index+1; j < n ; ++ j){
                if(j!=n-1 and b[j]==0 and !c[j]){
                    c[j]=true;
                    a[j]=a[index]-1;
                    index=j;
                }
            }
    }

    for(int i = 0 ; i < n ; ++ i){
        if(i!=0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}

