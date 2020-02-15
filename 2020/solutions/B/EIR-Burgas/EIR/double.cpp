#include <iostream>     ///Slow af
using namespace std;    //Just hope it gives correct answers

bool used[200];
int w[200], n, w1, w2, maxW=0;

void init();
bool dfs1(int, int);
bool dfs2(int, int, int&);

int main()
{
    init();

    for (int i=0; i<n; i++){
        dfs1(i, 0);
    }

    cout<<maxW<<endl;

    return 0;
}

///-------------------------

void init()
{
    cin>>n>>w1>>w2;

    for (int i=0; i<n; i++){
        cin>>w[i];
    }
}
bool dfs1(int from, int currSum)
{
    used[from]=true;

    if (currSum+w[from]>w1){
        used[from]=false;

        for (int i=0; i<n; i++){
            if (!used[i]) dfs2(from, 0, currSum);
        }

        return false;
    }
    currSum+=w[from];

    for (int i=from+1; i<n; i++){
        if (dfs1(i, currSum)){
            used[from]=false;
            return true;
        }
    }

    used[from]=false;

    for (int i=0; i<n; i++){
        if (!used[i]) dfs2(from, 0, currSum);
    }

    return false;
}
bool dfs2(int from, int currSum, int &dfs1Sum)
{
    if (currSum+w[from]>w2){
        maxW=max(currSum+dfs1Sum, maxW);
        return true;
    }
    currSum+=w[from];

    for (int i=0; i<n; i++){
        if (!used[i]){
            if (dfs2(i, currSum, dfs1Sum)) return true;
        }
    }

    return false;
}
/**
3 10 2
3 4 5
-------------------
5 10 14
4 5 6 7 8
*/
