#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
bool bo[100001]={false};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //cout<<n;
    b[0]=n-a[0];
    int n2;
    bo[n-a[0]]=true;
    int br=1;
    for(int i=1;i<n;i++){
        if(a[i]==0){
                //cout<<1;
            for(int j=n;j>0;j--){
                if(bo[j]==false){
                    bo[j]=true;
                    //cout<<1;
                    b[i]=j;
                    break;
                    //cout<<b[i]<<" "<<j<<" "<<i<<endl;
                }
            }
        }else if(i<n-2){
            //int br=0;
            int j=a[i],f=n;
            while(j>0){
                  //  cout<<n;
                if(bo[f]==false){
                    j--;
                    f--;
                }else{
                    f--;
                }
            }
            bo[f]=true;
           // cout<<br<<endl;
           //cout<<f<<" "<<i<<" "<<bo[f]<<endl;
           b[i]=f;
        }else{
            n2=n;
            int a1[2],br2=0;
            for(int j=1;j<n;j++){
               // cout<<n;
                if(bo[j]==false){
                    a1[br2]=j;
                    br2++;
                }
            }
           // cout<<n;
            if(a[n-2]==0){
                //cout<<a1[0]<<" "<<a1[1];
                b[n-2]=max(a1[0],a1[1]);
                b[n-1]=min(a1[0],a1[1]);
            }else{
                //cout<<a1[0]<<" "<<a1[i]<<endl;
                b[n-2]=min(a1[0],a1[1]);
                b[n-1]=max(a1[0],a1[1]);
            }
        }

    }
    //cout<<n2;
    for(int i=0;i<n2;i++){
        //cout<<n;
        if(i!=0){
            cout<<" ";
        }
        cout<<b[i];
    }
    return 0;
}
