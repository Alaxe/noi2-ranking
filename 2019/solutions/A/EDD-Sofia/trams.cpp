#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

class Node{
public:
    int val;
    set<pair<int, int> > neigh;

    Node(){
        this->val = 0;
    }

    Node(int val){
        this->val = val;
    }
};


int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    map<int, Node> nodes;
    set<pair<int, int> > edges;


    for (int i = 1; i <= n; i++){
        nodes[i] = Node(i);
    }


    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        pair<int, int> f;
        pair<int, int> s;
        f.first = from;
        f.second = to;
        s.first = to;
        s.second = from;

        nodes[from].neigh.insert(f);
        nodes[to].neigh.insert(s);

        edges.insert(f);
        edges.insert(s);
    }

    /*
    for(int i = 1; i <= n; i++){
        Node* n = nodes[i];
        cout << n->val << " |";

        for(std::set<pair<int, int> >::iterator it = n->neigh.begin(); it != n->neigh.end(); it++){
            pair<int, int> p = *it;
            cout << p.second << " ";
        }

        cout << endl;
    }
    */


    set<pair<int, int> > visited;
    vector<vector<int> > paths;

    while(true){ //while i can generate
        if(edges.empty()){
            break;
        }

        //generate path
        vector<int> path;
        queue<pair<int, int> > cands;
        cands.push(*edges.begin());
        //cout << cands.back().first << " ";
        path.push_back(cands.back().first);
        while(!cands.empty()){
            pair<int, int> p = cands.back();

            pair<int, int> eviltwin;
            eviltwin.first = p.second;
            eviltwin.second = p.first;

            edges.erase(p);
            edges.erase(eviltwin);
            visited.insert(p);
            visited.insert(eviltwin);



            Node to = nodes[p.second];

            //cout << to->val << " ";
            path.push_back(to.val);

            for(std::set<pair<int, int> >::iterator it = to.neigh.begin(); it != to.neigh.end(); it++){
                pair<int, int> p = *it;
                if (visited.find(p) == visited.end()){
                    cands.push(p);
                    //cout << "inserting into cands " << p.first << "->" << p.second << endl;
                    break;
                }
            }

            cands.pop();

        }
        //cout << endl;
        paths.push_back(path);

    }

    cout << paths.size() << endl;
    for(int i = 0; i < paths.size(); i++){
        vector<int> path = paths[i];
        cout << path.size() << " ";
        for(int j = 0; j < path.size(); j++){
            cout << path[j] << " ";
        }
        cout << endl;
    }
}
