#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_W1 = 0, max_W2 = 0;
vector <int> elements_first;
vector <int> elements_second;

void findMax(int max_val, vector <int> e_W, vector <int>::iterator it, int sum, bool status){
    if (it == elements_first.end() || it == elements_second.end()){
        if (status) {max_W1 = sum;} else {max_W2 = sum;}
        return;
    }
    sum += *it;
    e_W.push_back(*it);
    if (sum == max_val){
        if (status) {max_W1 = sum;} else {max_W2 = sum;}
        if (it != elements_first.end() && status){
            for (vector <int>::iterator getLast=it+1; getLast!=elements_first.end(); getLast++){
                elements_second.push_back(*getLast);
            }
        }
        return;
    }
    if (sum > max_val){
        for (vector <int>::iterator e_it=e_W.begin(); e_it!=e_W.end(); e_it++){
            if (*e_it == sum - max_val){
                sum -= *e_it;
                if (status) {elements_second.push_back(*e_it);}
                e_W.erase(e_it);
                if (status) {max_W1 = sum;} else {max_W2 = sum;}
                if (it != elements_first.end() && status){
                    for (vector <int>::iterator getLast=it+1; getLast!=elements_first.end(); getLast++){
                        elements_second.push_back(*getLast);
                    }
                }
                return;
            } else if (e_it == e_W.end() - 1){
                if (status) {max_W1 = sum;} else {max_W2 = sum;}
                if (it != elements_first.end() && status){
                    for (vector <int>::iterator getLast=it+1; getLast!=elements_first.end(); getLast++){
                        elements_second.push_back(*getLast);
                    }
                }
                return;
            } else if (*e_it > sum - max_val){
                sum -= *e_it;
                if (status) {elements_second.push_back(*e_it);}
                e_W.erase(e_it);
                break;
            }
        }
    }
    if (sum < max_val){
        findMax(max_val, e_W, it + 1, sum, status);
    }
}

int main(){
    int n, W1, W2, input;
    vector <int> vec;
    cin >> n >> W1 >> W2;
    for (int i=0; i<n; i++){
        cin >> input;
        elements_first.push_back(input);
    }
    sort(elements_first.begin(), elements_first.end());
    if (W1 >= elements_first.front()){
        findMax(W1, vec, elements_first.begin(), 0, true);
    }
    if (W2 >= elements_second.front()){
        findMax(W2, vec, elements_second.begin(), 0, false);
    }
    cout << max_W1 + max_W2 << '\n';
    return 0;
}
