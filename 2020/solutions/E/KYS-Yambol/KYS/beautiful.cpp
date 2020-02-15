#include<bits/stdc++.h>
using namespace std;
bool chislo(long long k){
    int y;
    y=k%10;
    while(k>0){
        if(k%10!=y)
            return false;
        else
            k=k/10;


    }
    return true;

}
int main()
{
    long long n,sum;
    cin>>n;
    sum=0;
    for(int i=1;i<=n;i++){
        if(chislo(i)==true)
            sum++;
    }
    cout<<sum<<endl;
    return 0;
}
