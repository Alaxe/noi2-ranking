#include<iostream>
#include<vector>
#include<set>

using namespace std;

int T,V;
int graphLine[100005];

int currentLength;
vector <int> graph[100005];
vector < set <int> > graph4check(100005);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B;
    int answer = 0;

    cin >> T;
    for(int t = 0;t<T;t++)
    {
        cin >> V;
        for(int i = 1;i<=V;i++)
        {
            cin >> graphLine[i];

            graph[i].push_back(graphLine[i]);
            graph[ graphLine[i] ].push_back(i);

            graph4check[i].insert(graphLine[i]);
            graph4check[ graphLine[i] ].insert(i);
        }
        graphLine[0] = 0;

        //fix
        for(int i = 1;i<=V;i++)
        {
            currentLength = graph[i].size();
            for(int index1 = 0;index1<currentLength;index1++)
            {
                A = i;
                B = graphLine[ graph[i][index1] ];

                if(graph4check[A].count(B)==true) {graph[i].push_back(0);break;}
            }
        }

        for(int i = 1;i<=V;i++)
        {
            currentLength = graph[i].size();
            if(currentLength>answer) answer = currentLength;
        }
        cout << answer << '\n';

        for(int i = 1;i<=V;i++)
        {
            graph[i].clear();
            graph4check[i].clear();
        }

    }
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
/*
    for(int index2 = index1+1;index2<currentLength;index2++)
    {
        A = graph[i][index1];
        B = graph[i][index2];

        if(graphLine[A]==B) {graph[i].push_back(0);break;}
        if(graphLine[B]==A) graph[i].push_back(0);
    }
*/
