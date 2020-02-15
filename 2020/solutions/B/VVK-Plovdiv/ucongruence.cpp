#include<iostream>

int main(){
    int N, U, n = 0, pairs = 0;
    std::cin >> N >> U;
    int arr[N];
    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    for(int i = 1; i < N; i++){
        int num = i;
        bool incr = true;
        for(int j = i-1; j >= 0; j--){
            if(arr[num]==arr[j]){
                incr = false;
                break;
            }
        }
        if(incr){
            pairs++;
        }
    }
    for(int i = 0; i < pairs; i++){
        for(int j = U-pairs; j > 0; j--){
            n+=j;
        }
    }
    int avr = (n+1)/2;
}
