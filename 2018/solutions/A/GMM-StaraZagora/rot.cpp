#include <iostream>
#include <cstring>

using namespace std;
int b;
int B[1000];
long long rot(long long A){
    long long result = 0;
    int br = 0;
    long long B;
    B = A;
    while(A/10!=0){
        result *= 10;
        result += A%10;
        br++;
        A/=10;
    }
    cout<<br;
    B = result;
    for(int i = 0;i<=br;i++){
        result += B%10;
        result*=10;  
    }
    result += A;
    return result;
}

int main()
{
    long long A[4];
    cin>>b;
    cin>>A[0];
    cin>>A[1];
    cin>>A[2];
    cin>>A[3];
    cout<<rot(A[0]);
    
    return 0;
}