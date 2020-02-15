#include <iostream>
using namespace std;
long long n,u,v,i,a[102],m,mi,j,s;
int main()
{
    cin>>n>>u>>v;
    cin>>a[0]>>a[1];
    if(a[0]>m){m=a[0];mi=0;}
    if(a[1]>m){m=a[1];mi=1;}
    for(i=2;i<n;i++){
        cin>>a[i];
        if(a[i]>m){m=a[i];mi=i;}
    }
    //cout<<mi<<" ";
    for(i=0;i<n;i++){
        if(i<mi){
            for(j=i-1;j>=0;j--){
                if(a[j]>a[i]){a[i]=a[j];}
            }
        }
        else{
            for(j=i+1;j<n;j++){
                if(a[j]>a[i]){a[i]=a[j];}
            }
        }
    }
    for(i=0;i<n;i++){
        if(a[i]<=a[i+1]){s+=a[i];}
        else{s+=a[i+1];}
        //cout<<a[i]<<" ";
    }

    cout<<s*u*v;







    return 0;
}
/*

5 1 1
2 4 8 5 7



*/
