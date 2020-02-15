#include<bits/stdc++.h>
using namespace std;
char a[1000001];
bool redica(long long x,long long y){
    int sab,scd;
    sab=0;
    scd=0;
    for(int k=x;k<=y;k++){
        if((a[k]=='a')||(a[k]=='b'))
            sab++;
        else
            scd++;
    }
    if(sab==scd)
        return true;
    else
        return false;
}

int main()
{
    int n,maxi,i;
    int sum=0;
    cin>>n;
    maxi=0;
    for(i=1;i<=n;i++)
        cin>>a[i];
    i=1;
    for(int j=1;j<=n;j++){
        if(redica(i,j)==true){
            sum=j-i+1;
            if(sum>maxi)
                maxi=sum;
        }
        sum=0;

    }
    cout<<maxi<<endl;
    return 0;

}
