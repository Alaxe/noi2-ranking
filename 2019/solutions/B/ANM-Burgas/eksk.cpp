#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxi=200000;
int vertices, edges;
vector<int> nList[maxi];
queue<int> q1;
bool passed[maxi];
int v1, v2;
int input[maxi][2];
int forbidden_edge[2];
bool same_route=false;
int route_length=0;

void init()
{
    cin>>vertices;
    edges=vertices-1;
    for(int i=0; i<edges; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        v1--;
        v2--;
        input[i][0]=v1;
        input[i][1]=v2;
        nList[v1].push_back(v2);
        nList[v2].push_back(v1);
    }
    cin>>v1>>v2;
    v1--;
    v2--;
}

void BFS(int index)
{
    for(int i=0; i<vertices+1; i++)
    {
        passed[i]=false;
    }
    while(q1.size()>0)
    {
        q1.pop();
    }
    route_length=0;
    same_route=false;
    q1.push(index);
    passed[index]=true;
    //cout<<"index="<<index<<endl;
    //cout<<"forbidden edge="<<forbidden_edge[0]<<" "<<forbidden_edge[1]<<endl;
    while(q1.size()>0)
    {
        int current=q1.front();
        //cout<<current+1<<endl;
        q1.pop();
        route_length++;
        for(int i=0; i<nList[current].size(); i++)
        {
            int nei=nList[current][i];
            if(!passed[nei])
            {
                if((current==forbidden_edge[0]&&nei==forbidden_edge[1])||(current==forbidden_edge[1]&&nei==forbidden_edge[0]))
                {}
                else
                {
                    if(nei==v2)
                    {
                        //cout<<"same route"<<endl;
                        same_route=true;
                        return ;
                    }
                    q1.push(nei);
                    passed[nei]=true;
                }
            }
        }
    }
    //cout<<endl;
    //cout<<endl;
}

void forbid_edge(int e1, int e2)
{
    forbidden_edge[0]=e1;
    forbidden_edge[1]=e2;
}

void process()
{
    int best=0;
    int save;
    for(int i=0; i<edges; i++)
    {
        forbid_edge(input[i][0], input[i][1]);
        BFS(v1);
        //cout<<"in"<<i<<endl;
        if(!same_route)
        {
            //cout<<"a"<<endl;
            int a=vertices-route_length;
            if(a>route_length)
            {
                a=route_length;
            }
            if(a>best)
            {
                best=a;
                if(best==vertices/2)
                {
                    cout<<best<<endl;
                    return ;
                }
            }
        }
    }
    cout<<best<<endl;
}

int main()
{
    init();
    process();
}
/*test
6
1 2
2 3
3 4
4 5
5 6
4 5

-----------------------------------

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
*/
