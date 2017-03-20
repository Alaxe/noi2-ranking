#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    int n;
    cin>>n;
    int arr[2][n];
    for(int i=0; i<n; i++) {
        cin>>arr[0][i]>>arr[1][i];
    }
    int surface=0;
    for(int i=0; i<n-1; i++) {
        surface = surface + arr[0][i]*(abs(arr[1][i]-arr[1][i+1]));
        if(arr[1][i+1]>arr[1][i+2]){
        for(int j=i+1; j<n; j++) {
            if(arr[1][j]>arr[1][i]) {
                surface = surface + (abs(arr[1][i]-arr[1][j]))*arr[0][j];
                i=j-1;
                break;
            }
        }
    }
    }
    cout<<x*y-surface;
    return 0;
}
