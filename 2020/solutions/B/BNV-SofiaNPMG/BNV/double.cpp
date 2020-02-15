#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 205;

int n, w1, w2;
int a[MAX_N];

struct state{

    int b[MAX_N]{0};
    int limit_x = 0, limit_y = 0;
    int sum_x = 0, sum_y = 0;
    state() {

    }
};

state table[MAX_N][MAX_N];

state incrementX(state x) {
    x.limit_x ++;
    if(x.limit_x == 0) {
        /// add the first one
        if(a[0] <= x.limit_x) {
            x.b[0] = 1;
            x.sum_x+= a[0];
        }
        return x;
    } else {
        /// 1: try to add
        int target = -1;
        for(int i = 0; i < n; i ++) {
            if(b[i] == 0) {
                int new_sum = x.sum_x + a[i];
                if(new_sum <= x.limit_x)
                    target = i;
                else break;
            }
        }
        int win_add = -1;

        int target_add = target;
        if(target != -1) {
            win_add = a[target_add];
        }
        /// 2: try to replace 1
        /// TODO: може ли да се наложи да се подменят повече от 1 предмета?????? ne znam, ama neka predpolojim, 4e ne
        int win_replace = -1;
        int target_replace = -1;
        int replace_from_x = -1;
        int replace_from_y = -1;
        for(int i = 0; i < n; i ++) {
            if(b[i] != 0) { /// can be replaced
                ///if removed
                int sum_if_removed = x.sum_x - a[i];
                int possible_win = x.limit_x - sum_if_removed;
                ///search in [i, j], i+j = limitX for the best solution
                for(int j = 1; j < possible_win; j ++) {
                    int curr_win = table[j][possible_win - j];
                    int real_win = curr_win - a[i];
                    if(real_win > win_replace) {
                        win_replace = real_win;
                        target_replace = i;
                        replace_from_x = j;
                        replace_from_y = possible_win - j;
                    }
                }
            }
        }
        if(win_replace > win_add){
            ///TODO: merge replacement with current
            x.b[target_replace] = 0;
            x.sum_x += win_replace;
            for(int i = 0; i < n; i ++) {
                if(target[replace_from_x][replace_from_y].b[i] != 0) {
                    x.b[i] = 1;/// ama ne znam dali ne uchastvat edni i sushti predmeti v tova, koeto ne podmenqm i tova, ot koeto vzimam za da podmenqm...
                }
            }
        }
        else {
            x.b[target_add] = 1;
            x.sum_x += a[target_add];
        }
        return x;
    }
}

state incrementY(state x) {
    ///TODO incrementX, ama za Y, a ne X
}

int main() {
    ///cin
    cin >> n >> w1 >> w2;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for(int x = 0; x < w1; x++) {
        for(int y = 0; y < w2; y ++) {
            if(x == 0 && y == 0) continue;
            else if(x == 0) {
                table[x][y] = incrementY(table[x][y-1])
            }
            else if(y == 0) {
                table[x][y] = incrementX(table[x-1][y])
            }
            else {
                state x1 = incrementX(table[x-1][y]);
                state x2 = incrementY(table[x][y-1]);
                if(x1.sum_x + x1.sum_y > x2.sum_x + x2.sum_y) { ///fuck.... tiq se overridevat .... tva e tujno
                    table[x][y] = x1;
                } else {
                    table[x][y] = x2;
                }
            }
        }
    }
    cout << table[w1][w2].sum_x + table[w1][w2].sum_y;
}

