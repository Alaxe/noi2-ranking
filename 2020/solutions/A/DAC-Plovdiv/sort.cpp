#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 100010

int n, a[MAXN] = {}, b[2][MAXN] = {}, stay1[MAXN] = {}, stay2[MAXN] = {};
bool flag = true;

int distance (int* k, int* l, int u) {
    long long ans = 0;
    for(int i = 0; i < u; i++) {
        ans += abs(k[i] - l[i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];

        if(i != 0) {
            if(a[i] >= a[i - 1] && flag == true) flag = true;
            else flag = false;
        }
    }

    if(flag == true) cout<<"0\n";
    else {
        for(int i = 0; i < n; i++) {
            if(a[i] > b[0][i - 1]) {
                for(int j = 0; j < i; j++) {
                    stay1[j] = b[0][j];
                }
                stay1[i] = a[i];
            }
            else {
                stay1[i] = a[i];
                for(int j = i - 1; j >= 0; j--) {
                    if(a[i] < b[0][j]) stay1[j] = a[i];
                    else stay1[j] = b[0][j];
                }
            }

            if(a[i] > b[1][i - 1]) {
                for(int j = 0; j < i; j++) {
                    stay2[j] = b[1][j];
                }
                stay2[i] = a[i];
            }
            else {
                stay2[i] = a[i];
                for(int j = i - 1; j >= 0; j--) {
                    if(a[i] < b[1][j]) stay2[j] = a[i];
                    else stay2[j] = b[1][j];
                }
            }

            if(abs(a[i] - b[1][i - 1]) + distance(a, b[1], i - 1) > abs(a[i] - b[0][i - 1]) + distance(a, b[0], i - 1)) {
                b[1][i] = b[0][i - 1];
                for(int j = i - 1; j >= 0; j--) {
                    b[1][j] = b[0][j];
                }
            }
            else {
                b[1][i] = b[1][i - 1];
                for(int j = i - 1; j >= 0; j--) {
                    b[1][j] = b[1][j];
                }
            }

            if(distance(a, stay1, i) < distance(a, stay2, i)) {
                for(int j = 0; j <= i; j++)
                    b[0][j] = stay1[j];
            }
            else {
                for(int j = 0; j <= i; j++)
                    b[0][j] = stay2[j];
            }
        }
        cout<<min(distance(b[0], a, n), distance(b[1], a, n))<<endl;
    }
    return 0;
}

