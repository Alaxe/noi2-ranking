#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long k, n, mul, add, mod, m, c, i, counter;
bool is_removed = false;
vector<unsigned long long> arr, arr2;

void add_to_arr(){
    c = (arr[0]*mul + add)%mod;
    arr.insert(arr.begin(), c);
    if(c > m){
        swap(m, c);
        is_removed = false;
    }
}

void find_new(){
    arr2 = arr;
    sort(arr2.begin(), arr2.end());
    m = arr2[k];
}


int main(){
    cin >> n >> k >> m >> mul >> add >> mod;
    arr.push_back(m);
    counter = m;
    for(i = 1;  i < k;  i++){
        add_to_arr();
        counter += m;
    }
    i = n-k;
    k--; //K IS INDEX HERE
    for(;  i > 0;  i--){
        if(arr[k] == m)
            is_removed = true;
        arr.pop_back();
        add_to_arr();
        if(is_removed)
            find_new();
        counter += m;
    }
    cout << counter;
    return 0;
}
