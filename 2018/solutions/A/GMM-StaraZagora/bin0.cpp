#include <iostream>
using namespace std;
long long Result = 0;
long long fromDecaToBin(long long X){
    if(X==0){
        return 0;
    }
    fromDecaToBin(X/2);
    Result*=10;
    Result+=X%2;
    return Result;
}
int main()
{
    long long s, t, A;
    int z, j, result;
    j = 0;
    result = 0;
    cin>>s>>t>>z;
    for(int i=s;i<=t;i++){
        A = fromDecaToBin(i);
        Result = 0;
        while(true){
            if(A==0){
                if(j==z)result++;
                j = 0;
                break;
            }
            if(A%10==0)j++;
            A/=10;
        }
    }
    cout<<result;
    return 0;
}