#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,u,v,V=0,maxc=0,indexs;
    cin>>n>>u>>v;
    int maxs=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxc){
            maxs=maxc;
            maxc=a[i];
            indexs=i;
        }
        if(a[i]>maxs && a[i]<maxc){
            maxs=a[i];
            indexs=i;
        }


    }
    //cout<<indexs<<endl;
    //cout<<maxs<<endl;
    int j=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            V+=u*v*a[i-1];
            //cout<<a[i]<<" "<<a[i-1]<<endl;
            //cout<<V<<endl;
        }else{
            //cout<<1<<endl;
            if(a[i-1]==maxc){
                V+=maxs*v*u*(indexs-i+1);
                //cout<<V<<endl;
                break;
                //cout<<V<<endl;
            }else{
                for (j=i;j<n;j++){
                    if(a[i-1]<a[j]){
                        break;
                    }
                }
                //cout<<j-i;
                V+=a[i-1]*v*u*(j-i+1);
                i=j;
            }
        }
    }
    cout<<V<<endl;
    return 0;
}
