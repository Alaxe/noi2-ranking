#include <iostream>

using namespace std;

const int maxn = 100005;
int inc[maxn];
pair<int, int> maxInc[maxn];
int decr[maxn];
pair<int, int> maxDec[maxn];
int comb[maxn];
int number[maxn];
int answer;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        number[i] = k;
    }

    inc[0] = 1;
    maxInc[0] = make_pair(0, -1);
    for(int i=1; i<n; i++){
        int maxx = -1;
        for(int j=0; j<i; j++){
            if(number[i]<=number[j]) continue;
            maxx = max(maxx, inc[j]+1);
        }
        if(maxx == -1){
            inc[i]=1;
            maxInc[i].first = maxInc[i-1].first;
            maxInc[i].second = maxInc[i-1].second;
        }
        else{
            inc[i] = maxx;
            if(maxInc[i-1].first < inc[i]){
                maxInc[i].first = inc[i];
                maxInc[i].second = number[i];
            }
            else{
                maxInc[i].first = maxInc[i-1].first;
                maxInc[i].second = maxInc[i-1].second;
            }
        }
    }
    answer = maxInc[n-1].first;

    decr[n-1] = 1;
    maxDec[n-1] = make_pair(0, -1);
    for(int i=n-2; i>=0; i--){
        int maxx = -1;
        for(int j=i+1; j<n; j++){
            if(number[i]<=number[j]) continue;
            maxx = max(maxx, decr[j]+1);
        }
        if(maxx == -1){
            decr[i]=1;
            maxDec[i].first = maxDec[i+1].first;
            maxDec[i].second = maxDec[i+1].second;
        }
        else{
            decr[i] = maxx;
            if(maxDec[i+1].first < decr[i]){
                maxDec[i].first = decr[i];
                maxDec[i].second = number[i];
            }
            else{
                maxDec[i].first = maxDec[i+1].first;
                maxDec[i].second = maxDec[i+1].second;
            }
        }
    }
    answer = max(answer, maxDec[0].first);

    for(int i=1; i<n-1; i++){
        comb[i] = maxInc[i].first + maxDec[i].first;
        if(maxInc[i].second == maxDec[i].second){
            comb[i]--;
        }
        answer = max(answer, comb[i]);
    }

    if(answer==0) answer = 1;

    cout << answer << endl;

    return 0;
}
/*
15
1 7 2 6 3 5 4 4 5 3 6 2 7 1 8
*/
