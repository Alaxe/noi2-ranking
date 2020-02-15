#include<iostream>
using namespace std;
long long a[100000],b[100000],n,i,br,m=1,p,j;
int main()
{
cin>>n;
for(i=0;i<n;i++){
    cin>>b[i];
}
a[n-1]=1;
for(i=n-2;i>=0;i--){
    if(b[i]==0){a[i]=m+1; m++;}
    else{
        a[i]=1+(((n-1)-i)-b[i]);
        p=i+1;
        while(br<b[i]){
            if(a[p]>=a[i]){
                a[p]++;
                br++;
                if(a[p]>m) m=a[p];
            }
            p++;
        }
        br=0;
    }
}
for(i=0;i<n;i++){
    cout<<a[i]<<" ";
}

return 0;
}
