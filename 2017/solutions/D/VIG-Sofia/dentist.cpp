#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    priority_queue<pair<int, int> > patients;
    stack<pair<int, int> > p;
    int a, b, freein=0, last;
    while(cin >> a >> b){
        patients.push({a, b});
    }
    while(patients.size()){
        p.push(patients.top());
        patients.pop();
    }
    while(p.size()){
        if(freein<=p.top().first){
            freein=p.top().first+p.top().second;
        }
        else {
            freein+=p.top().second;
        }
        last=p.top().first;
        p.pop();
    }
    cout << freein-last << endl;
    return 0;
}
