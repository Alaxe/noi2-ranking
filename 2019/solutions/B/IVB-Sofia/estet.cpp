#include<iostream>
using namespace std;

const int MAX_N = 100001;
int a[MAX_N];


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n ;
    cin >> n;
    for(int i = 0 ; i < n; ++ i){
        cin >> a[i];
    }
    int glomax = 0;

    for(int i = 0 ; i < n ; ++ i){
        bool went = false;
        int currmax = 1;
        for(int j = 0 ; j < n ; ++ j){

            if(went){
                if(a[j] < a[j - 1]){
                    ++ currmax;
                }
            }
            else{
                if(j != 0){
                    if(a[j] > a[j - 1]){
                        ++ currmax;
                    }
                }
            }
            if(i == j + 1){
                went = true;
            }
        }
        glomax = max(glomax, currmax);
    }
    cout << glomax << '\n';

    return 0;
}
