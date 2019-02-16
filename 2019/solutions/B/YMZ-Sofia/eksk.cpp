#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector <int> a[200001];

queue <int> b[10];

int b1, b2;

int c[200001], cc, o;

bool bb[200001], dd[200001], ee[200001], ff[200001];

int r, R;

int Real = 1, RReal = 1;

int mtmbfs(int c1, int c2){
    b[1].push(c1);
    b[2].push(c2);
    c[c1] = 1;
    c[c2] = 2;

    while(true){
        for(int i = 0; i < a[b[1].front()].size(); i++){
            if(c[a[b[1].front()][i]] == 0){
                b[1].push(a[b[1].front()][i]);
                c[a[b[1].front()][i]] = 1;
            }

            if(c[a[b[1].front()][i]] == 2){
                cc = 1;
                o = b[1].front();
                return a[b[1].front()][i];
            }
        }
        b[1].pop();

        for(int i = 0; i < a[b[2].front()].size(); i++){
            if(c[a[b[2].front()][i]] == 0){
                b[2].push(a[b[2].front()][i]);
                c[a[b[2].front()][i]] = 2;
            }

            if(c[a[b[2].front()][i]] == 1){
                cc = 2;
                o = b[2].front();
                return a[b[2].front()][i];
            }
        }
        b[2].pop();
    }
}

void djstr(int s){
    b[3].push(s);
    b[4].push(1);

    for(int i = 0; i < a[b[3].front()].size(); i++){
        if(a[b[3].front()][i] != r && !(bb[a[b[3].front()][i]])){
            b[3].push(a[b[3].front()][i]);
            bb[a[b[3].front()][i]] = true;
            b[4].push(b[4].front() + 1);
            if(Real < b[4].front()){
                Real = b[4].front();
            }
        }
    }
}

void djstr1(int s){
    b[5].push(s);
    b[6].push(1);

    for(int i = 0; i < a[b[5].front()].size(); i++){
        if(a[b[5].front()][i] != r && !(dd[a[b[5].front()][i]])){
            b[5].push(a[b[5].front()][i]);
            dd[a[b[5].front()][i]] = true;
            b[6].push(b[6].front() + 1);
            if(Real < b[6].front()){
                Real = b[6].front();
            }
        }
    }
}

void djstr2(int s){
    b[7].push(s);
    b[8].push(1);

    for(int i = 0; i < a[b[7].front()].size(); i++){
        if(a[b[7].front()][i] != o && !(ee[a[b[7].front()][i]])){
            b[7].push(a[b[7].front()][i]);
            ee[a[b[7].front()][i]] = true;
            b[8].push(b[8].front() + 1);
            if(RReal < b[8].front()){
                RReal = b[8].front();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        cin >> b1 >> b2;
        a[b1].push_back(b2);
        a[b2].push_back(b1);
    }

    cin >> b1 >> b2;
    r = mtmbfs(b1, b2);
    if(cc == 1){
        djstr(b1);
        djstr2(b2);
    }else{
        djstr1(b2);
        djstr2(b1);
    }

    if(Real > RReal){
        cout << RReal;
    }else{
        cout << Real;
    }

    cout << "\n";
    return 0;
}
