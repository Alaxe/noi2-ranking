#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

/*
bi trqbvalo da vzeme 30 tochki
*/




int main()
{
    int n, m;
    vector<pair<int, int> > conns;
    vector<set<int> > neighs;

    cin >> n;
    cin >> m;


    for(int i = 0; i <= n; i++){
        neighs.push_back(set<int>());
    }

    for(int i = 0; i<m; i++){
        int from, to;
        cin >> from;
        cin >> to;

        if(neighs.at(to).find(from) == neighs.at(to).end()){
            conns.push_back(pair<int, int>(from, to));
        }
        neighs.at(from).insert(to);
        neighs.at(to).insert(from);

    }

    set<pair<int, int> > possiblepairs;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            possiblepairs.insert(pair<int, int>(i,j));
        }
    }

    for(int i = 0; i < conns.size(); i++){
        pair<int, int> conn = conns.at(i);
        int from = conn.first;
        int to = conn.second;

        neighs.at(from).erase(to);
        neighs.at(to).erase(from);

        set<int> visited;
        vector<set<int> > subgraphs;
        for(int i = 1; i <=n; i++){
            if(visited.find(i) == visited.end()){
                queue<int> nodes;
                nodes.push(i);
                set<int> currentsubg;
                while(nodes.size() > 0){
                    int curr = nodes.front();
                    nodes.pop();
                    if(visited.find(curr) != visited.end()){
                        continue;
                    }

                    currentsubg.insert(curr);
                    visited.insert(curr);

                    set<int> currfriends = neighs.at(curr);
                    for(auto friendIt = currfriends.begin(); friendIt != currfriends.end(); friendIt++){
                        int fr = *friendIt;
                        if(visited.find(fr) == visited.end()){
                            nodes.push(fr);
                        }
                    }
                }
                subgraphs.push_back(currentsubg);
            }
        }


        /*
        cout << subgraphs.size() << endl;
        for(int j = 0; j < subgraphs.size(); j++){
            set<int> subg = subgraphs.at(j);
            for(auto printit = subg.begin(); printit != subg.end(); printit++){
                cout << *printit << " ";
            }
            cout << endl;
        }
        */

        vector<pair<int, int>> toearse;
        for(auto pairsit = possiblepairs.begin(); pairsit != possiblepairs.end(); pairsit++){
            pair<int, int> currentPair = *pairsit;
            int possible = 0;


            for(int j = 0; j < subgraphs.size(); j++){

                set<int> subg = subgraphs.at(j);
                if(subg.find(currentPair.first) != subg.end() && subg.find(currentPair.second) != subg.end()){
                    possible = 1;
                    break;
                }
            }
            if(possible == 0){
                //cout << "pair " << currentPair.first << " " << currentPair.second << " -> " <<possible<<endl;
                toearse.push_back(currentPair);
            }
        }
        for(auto eraseit = toearse.begin(); eraseit != toearse.end(); eraseit++){
            possiblepairs.erase(*eraseit);
        }


        neighs.at(from).insert(to);
        neighs.at(to).insert(from);
    }

    cout << possiblepairs.size() << endl;
    /*
    for(auto printit = possiblepairs.begin(); printit != possiblepairs.end(); printit++){
        pair<int, int> p = *printit;
        cout << p.first << " " << p.second << endl;
    }
    */
}
