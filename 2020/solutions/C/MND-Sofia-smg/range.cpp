#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int ch[100001];
int num[100001];
int srt[100001];
int imaLiGoIkolkoPuti[100000];
int imaLiGoIkolkoPuti2[100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int minC=1e6,maxC=-1;
    for(int i=0;i<n;i++){
        cin>>num[i];
        minC=min(minC,num[i]);
        maxC=max(maxC,num[i]);
        imaLiGoIkolkoPuti[num[i]]++;
        imaLiGoIkolkoPuti2[num[i]]++;
    }
    int counter=0;
    for(int i=minC;i<=maxC;i++){
        while(imaLiGoIkolkoPuti2[i]>0){
            ch[counter]=i;
            counter++;
            imaLiGoIkolkoPuti2[i]--;
        }
    }
    for(int i=0;i<minC;i++){
        a[i]=1;
    }
    int curr1=1;
    for(int i=0;i<n;i++){
        if(ch[i]!=ch[i+1]){
        for(int j=ch[i];j<ch[i+1];j++){
            a[j]=curr1+imaLiGoIkolkoPuti[ch[i]];

        }
        curr1=curr1+imaLiGoIkolkoPuti[ch[i]];
        }
    }
    for(int i=0;i<100000;i++){
        a[i]--;
    }
    for(int i=maxC;i<=100000;i++){
     a[i]=n;
    }
    /*
    for(int i=1;i<20;i++){
        cout<<i<<" "<<a[i]<<endl;
    }
    */



    for(int i=100000;i>maxC;i--){
        b[i]=0;
    }
    for(int i=0;i<=minC;i++){
        b[i]=n;
    }
    int curr2=imaLiGoIkolkoPuti[maxC];
    for(int i=n-1;i>0;i--){
        if(i!=0 && ch[i]!=ch[i-1]){
            for(int j=ch[i];j>ch[i-1];j--){
             b[j]=curr2;
            }
        curr2=curr2+imaLiGoIkolkoPuti[ch[i-1]];
        }
    }
    b[minC]=n;
    /*for(int i=0;i<15;i++){
        cout<<i<<" "<<b[i]<<endl;
    }
    */
    int m;
    cin>>m;
    int x,y;
    for(int i=0;i<m-1;i++){
        cin>>x>>y;
        if(a[y]==0 or b[x]==0){
            cout<<"0"<<endl;
            continue;
        }
        cout<<a[y]+b[x]-n<<endl;
    }
     cin>>x>>y;
        if(a[y]==0 or b[x]==0){
            cout<<"0";
        }else{
            cout<<a[y]+b[x]-n;
        }
        //cout<<a[y]<<" "<<b[x];
return 0;
}
