#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAXN 15000005
char input[MAXN];
char lowest[MAXN], greatest[MAXN];
int arr[MAXN];
int cmp(int i, int j)
{
    return input[i] < input[j];
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> input;
    int br = strlen(input);
    for(int i = 0; i < br; ++i){
        arr[i] = i;
    }
    sort(arr, arr + br, cmp);
    int c = 0;
    for(int i = 0; i < br; ++i){
        if(i != 0 && input[arr[i]] != input[arr[i - 1]]) ++c;
        lowest[arr[i]] = 'A' + c;
    }
    c = 0;
    for(int i = br - 1; i >= 0; --i){
        if(i != br - 1 && input[arr[i]] != input[arr[i + 1]]) ++c;
        greatest[arr[i]] = 'Z' - c;
    }
    cout << lowest << endl << greatest << endl;
    return 0;
}
