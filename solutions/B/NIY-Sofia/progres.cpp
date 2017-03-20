#include <iostream>

using namespace std;

int recursion(int input[], int g, int n, int i) {
    if(g+1==n)return 0;
    else {
        for(int h = g+1; h<n; h++) {
            if(input[h]-input[g]==i) {
                return 1+recursion(input, h, n, i);
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    int input[n];
    for(int i=0; i<n; i++) {
        cin>>input[i];
    }
    int max=0;
    int max_i;
    for(int i=0; i<n; i++) {
        if(input[i]>max && i!=0) {
            max=input[i];
            max_i=i;
        }
    }
    int min = max;
    for(int i=0; i<max_i; i++) {
        if(input[i]<min)min=input[i];
    }
    int sum=0;
    int max_d= max-min;
    for(int i=1; i<=max_d; i++) {
        for(int j=0; j<n-1; j++) {
            for(int g=j+1; g<n; g++) {
                if(input[g]-input[j]==i) {
                    sum=sum+1+recursion(input, g, n, i);
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
