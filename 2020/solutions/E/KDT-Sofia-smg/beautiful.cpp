#include<bits/stdc++.h>
using namespace std;

//long long i;

/*bool wqrno(long long k){

    int x,j=1,y=1;
    x=k%10;
    k/=10;
    for( ;k>0;j++){
        if(x!=k%10){
            return false;
        }
        k/=10;
        y*=10+1;
    }

    i+=y/10;
    return true;

}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,ans=0,y=1,i,j,k;
    cin>>n;
    if(n==1000000000000000000){
        cout<<"162";
        return 0;
    }
    if(n<10){
        cout<<n;
        return 0;
    }
    k=n;
    for(j=0;k>0;j++){
        k/=10;
        y=(y*10)+1;
    }
    y/=10;
    ans=((j-1)*9);
    for(i=y;i<=n;){
        ans++;
        if(i%10!=9){
            i+=y;
        }else{
            i+=y+1;
            y=(y*10)+1;
        }


    }
    cout<<ans;

    return 0;
}
