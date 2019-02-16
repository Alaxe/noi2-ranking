#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_set<int> note;

struct vr{
    int len1;
    int len2;
    vector<int> path1;
    vector<int> path2;
    vector<int> neighbour;
};

const int maxn = 200005;
vr vert[maxn];

bool cross(vr a, vr b){
    note.clear();
    for(int i=0; i<a.path1.size(); i++){
        note.insert(a.path1[i]);
    }
    for(int i=0; i<b.path2.size(); i++){
        note.insert(b.path2[i]);
    }
    if(note.size() < a.path1.size() + b.path2.size()) return 1;
    return 0;
}

queue<int> frontier;
bool used1[maxn];
bool used2[maxn];

vector<int> length1[maxn];
vector<int> length2[maxn];

int maximum1 = -1;
int maximum2 = -1;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        vert[u].neighbour.push_back(v);
        vert[v].neighbour.push_back(u);
    }

    int A, B;
    cin >> A >> B;

    length1[1].push_back(A);
    length2[1].push_back(B);

    frontier.push(A);
    vert[A].len1 = 1;
    vert[A].path1.push_back(A);
    while(!frontier.empty()){
        int parent = frontier.front();
        if(used1[parent]){
            frontier.pop();
            continue;
        }
        used1[parent] = true;

        for(int i=0; i<vert[parent].neighbour.size(); i++){
            int nei = vert[parent].neighbour[i];
            if(!used1[nei]){
                frontier.push(nei);
                vert[nei].path1 = vert[parent].path1;
                vert[nei].path1.push_back(nei);
                vert[nei].len1 = vert[nei].path1.size();
                length1[vert[nei].len1].push_back(nei);
                maximum1 = max(maximum1, vert[nei].len1);
            }
        }
    }

    frontier.push(B);
    vert[B].len2 = 1;
    vert[B].path2.push_back(B);
    while(!frontier.empty()){
        int parent = frontier.front();
        if(used2[parent]){
            frontier.pop();
            continue;
        }
        used2[parent] = true;

        for(int i=0; i<vert[parent].neighbour.size(); i++){
            int nei = vert[parent].neighbour[i];
            if(!used2[nei]){
                frontier.push(nei);
                vert[nei].path2 = vert[parent].path2;
                vert[nei].path2.push_back(nei);
                vert[nei].len2 = vert[nei].path2.size();
                length2[vert[nei].len2].push_back(nei);
                maximum2 = max(maximum2, vert[nei].len2);
            }
        }
    }

    int maxx = min(maximum1, maximum2);

    int answer;
    bool answerFound = false;

    for(int i = maxx; i>=0; i--){
        answer = i;
        for(int p=0; p<length1[i].size(); p++){
            for(int q=0; q<length2[i].size(); q++){
                int index1 = length1[i][p];
                int index2 = length2[i][q];
                if(!cross(vert[index1], vert[index2])){
                    answerFound = true;
                    break;
                }
            }
            if(answerFound) break;
        }
        if(answerFound) break;
    }

    cout << answer << endl;

    return 0;
}
/*
20
1 2
2 8
7 8
8 13
8 9
9 3
9 14
14 17
17 19
14 15
15 18
18 20
15 10
10 4
10 11
11 5
5 6
11 12
11 16
*/
