#include<iostream>
#include<climits>
#include<queue>

using namespace std;

struct position
{
    int i,j;
};

struct edge
{
    int value;
    position vertex;
};

bool operator <(const position A, const position B)
{
    if(A.i!=B.i) return A.i<B.i;
    return A.j<B.j;
}

bool operator <(const edge A, const edge B)
{
    if(A.value!=B.value) return A.value>B.value;
    return !(A.vertex<B.vertex);
}

int n,m;
position start;
char a[645][645];

edge add;
position newPosition;
priority_queue <edge> q;
long long dist[645][645];

void distPrepare()
{
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            dist[i][j] = INT_MAX;

    dist[start.i][start.j] = 0;
}

bool isLetter(char x)
{
    if(x>='A' && x<='Z') return true;
    return false;
}

char cost1,cost2,cost3,cost4;
void useVertex(position A)
{
    if(A.i-1>=0 && isLetter(a[A.i-1][A.j])==true &&  dist[A.i][A.j]+(a[A.i-1][A.j]-'A'+1)<dist[A.i-1][A.j])
    {
        dist[A.i-1][A.j] = dist[A.i][A.j] + (a[A.i-1][A.j]-'A'+1);

        newPosition = A;
        newPosition.i--;
        add.vertex = newPosition;
        add.value = (a[A.i-1][A.j]-'A') + 1;

        q.push(add);
    }
    if(A.i+1<n && isLetter(a[A.i+1][A.j])==true && dist[A.i][A.j]+(a[A.i+1][A.j]-'A'+1)<dist[A.i+1][A.j])
    {
        dist[A.i+1][A.j] = dist[A.i][A.j] + (a[A.i+1][A.j]-'A'+1);

        newPosition = A;
        newPosition.i++;
        add.vertex = newPosition;
        add.value = a[A.i+1][A.j]-'A' + 1;

        q.push(add);
    }

    if(A.j-1>=0 && isLetter(a[A.i][A.j-1])==true && dist[A.i][A.j]+(a[A.i][A.j-1]-'A'+1)<dist[A.i][A.j-1])
    {
        dist[A.i][A.j-1] = dist[A.i][A.j] + (a[A.i][A.j-1]-'A'+1);

        newPosition = A;
        newPosition.j--;
        add.vertex = newPosition;
        add.value = a[A.i][A.j-1]-'A' + 1;

        q.push(add);
    }
    if(A.j+1<m && isLetter(a[A.i][A.j+1])==true && dist[A.i][A.j]+(a[A.i][A.j+1]-'A'+1)<dist[A.i][A.j+1])
    {
        dist[A.i][A.j+1] = dist[A.i][A.j] + (a[A.i][A.j+1]-'A'+1);

        newPosition = A;
        newPosition.j++;
        add.vertex = newPosition;
        add.value = a[A.i][A.j+1]-'A' + 1;

        q.push(add);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = INT_MAX;

    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin >> a[i][j];

            if(a[i][j]=='#')
            {
                start.i = i;
                start.j = j;
            }
        }
    }
    distPrepare();

    useVertex(start);
    while(q.empty()==false)
    {
        add = q.top();
        q.pop();

        useVertex(add.vertex);
    }

    for(int i = 0;i<n;i++)
    {
        if(dist[i][0]<answer) answer = dist[i][0];
        if(dist[i][m-1]<answer) answer = dist[i][m-1];
    }
    for(int j = 0;j<m;j++)
    {
        if(dist[0][j]<answer) answer = dist[0][j];
        if(dist[n-1][j]<answer) answer = dist[n-1][j];
    }

    cout << answer << '\n';
}
/*
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
