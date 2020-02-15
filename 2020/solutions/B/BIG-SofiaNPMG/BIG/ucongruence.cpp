#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

unsigned long long arr[64][64];
unsigned long long ansnum, f;

int n, u;
pair<int, int> a[1048576];

bool used[64];
vector<int> order;

vector<vector<int> > levels;
int s;

int st[64];
int out[1048576];

void recur(int cl, unsigned long long currd)
{
    if(cl >= s){return;}
    int curr = order[cl];
    int ul = u; ///upper limit
    int dl = 1;///down limit
    int leftn = s-1;
    int tob = curr;
    int tot = s-curr-1;

    for(int i = curr-1; i >= 0; i--){
        if(st[i] != 0){
            leftn -= i+1;
            dl = st[i]+1;
            tob = curr-i-1;
            break;
        }
    }

    for(int i = curr+1; i < s; i++){
        if(st[i] != 0){
            leftn -= s - i;
            ul = st[i]-1;
            tot = i-curr-1;
            break;
        }
    }

    //cout << dl << " " << ul << " " << tob << " " << tot << endl;

    //cout << currd << " " << arr[ul-dl+1][tot+tob+1] << endl;
    currd /= arr[ul-dl+1][tot+tob+1];

    int i;
    unsigned long long adit = 1;
    for(i = dl; i <= ul; i++){
        adit = currd*arr[i-dl][tob]*arr[ul-i][tot];
        f += adit;
        //cout << i << " " << adit << endl;
        if(f >= ansnum){break;}
    }

    st[curr] = i;
    //cout << st[curr] << endl;
    f -= adit;
    adit = currd*arr[i-dl][tob]*arr[ul-i][tot];
    //cout << "" << endl;
    recur(cl+1, adit);

}

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.second < B.second){return true;}
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> u;

    for(int i = 0; i < 64; i++){
        arr[i][0] = 1;
    }

    for(int i = 1; i <= u; i++){
        for(int j = 1; j <= i; j++){
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a+n);

    int last = 0;
    s = -1;
    for(int i = 0; i < n; i++){
        if(a[i].first != last){
            levels.push_back(vector<int> ());
            s++;
            last = a[i].first;
        }
        a[i].first = s;
        levels[s].push_back(a[i].second);
    }

    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++){
        if(!used[a[i].first]){
            used[a[i].first] = true;
            order.push_back(a[i].first);
        }
    }
    s++;

    ansnum = (arr[u][s]+(unsigned long long)1)/(unsigned long long)2;
    //cout << arr[u][s] << endl;

    recur(0, arr[u][s]);

    for(int i = 0; i < s; i++){
        for(int j = 0; j < levels[i].size(); j++){
            a[levels[i][j]].first = st[i];
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i].first << " ";
    }
    cout << endl;

return 0;
}
