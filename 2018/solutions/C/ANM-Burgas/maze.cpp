#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxi1=101;
const int maxi2=10001;
vector<int> nList[maxi2];
queue<int>  q1;
//bool used[maxi2];
int distances[maxi2];
int m, n, vertices, edges;
int matrix[maxi1][maxi1];
int t=0;
int u=0;
int startIndex;
int endIndex;
int walls[maxi2];
int minLength=999999;

void initMatrix()
{
    cin>>m>>n;
    vertices=m*n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            char a;
            cin>>a;
            if(a=='.')
            {
                matrix[i][j]=t;
                t++;
            }
            if(a=='#')
            {
                matrix[i][j]=t;
                t++;
                walls[u]=t-1;
                u++;
            }
            if(a=='B')
            {
                startIndex=t;
                matrix[i][j]=t;
                t++;
            }
            if(a=='E')
            {
                endIndex=t;
                matrix[i][j]=t;
                t++;
            }
        }
    }
    /*
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"walls"<<endl;
    for(int i=0; i<u; i++)
    {
        cout<<walls[i]<<" ";
    }
    cout<<endl;
    cout<<startIndex<<" "<<endIndex<<endl;
    */
}

void initGraph()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>0)
            {
                nList[matrix[i][j]].push_back(matrix[i-1][j]);
            }
            if(i<m-1)
            {
                nList[matrix[i][j]].push_back(matrix[i+1][j]);
            }
            if(j>0)
            {
                nList[matrix[i][j]].push_back(matrix[i][j-1]);
            }
            if(j<n-1)
            {
                nList[matrix[i][j]].push_back(matrix[i][j+1]);
            }
        }
    }
    /*
    for(int i=0; i<vertices; i++)
    {
        cout<<"Neighbours of "<<i<<" : ";
        for(int j=0; j<nList[i].size(); j++)
        {
            cout<<nList[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}

void bfs()
{
    while(q1.size()>0)
    {
        int current=q1.front();
        //cout<<current<<" ";
        q1.pop();
        for(int i=0; i<nList[current].size(); i++)
        {
            int nei=nList[current][i];
            /*
            if(nei==32)
            {
                cout<<used[nei]<<endl;
            }
            */
            if(distances[nei]==-1)
            {
                //used[nei]=true;
                q1.push(nei);
                distances[nei]=distances[current]+1;
            }
        }
    }
    //cout<<endl;
}

void process()
{

    for(int i=0; i<vertices; i++)
    {
        //used[i]=false;
        distances[i]=-1;
    }
    for(int i=0; i<u; i++)
    {
        //used[walls[i]]=true;
        distances[walls[i]]=-2;
    }
    distances[startIndex]=0;
    q1.push(startIndex);
    //used[startIndex]=true;
    bfs();
    if(distances[endIndex]>0)
    {
        minLength=min(minLength, distances[endIndex]);
    }
    for(int k=0; k<u; k++)
    {
        for(int i=0; i<vertices; i++)
        {
            //used[i]=false;
            distances[i]=-1;
        }
        for(int i=0; i<u; i++)
        {
            if(i!=k)
            {
                //used[walls[i]]=true;
                distances[walls[i]]=-2;
            }
        }
        distances[startIndex]=0;
        q1.push(startIndex);
        //used[startIndex]=true;
        bfs();
        //cout<<distances[endIndex]<<endl;
        if(distances[endIndex]>0)
        {
            minLength=min(minLength, distances[endIndex]+2);
        }
    }
    /*
    for(int i=0; i<vertices; i++)
    {
        used[i]=false;
        distances[i]=-1;
    }
    for(int i=0; i<u; i++)
    {
        used[walls[i]]=true;
        distances[walls[i]]=-2;
    }
    distances[startIndex]=0;
    q1.push(startIndex);
    used[startIndex]=true;
    bfs();
    cout<<distances[endIndex]<<endl;
    */
}

void print()
{
    if(minLength==999999)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<minLength<<endl;
    }
}

int main()
{
    initMatrix();
    initGraph();
    process();
    print();
}
