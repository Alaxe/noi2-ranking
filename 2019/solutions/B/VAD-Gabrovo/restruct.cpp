#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=5002;

int n, k;
queue <int> q;

struct Employee
{
    int num;
    bool boss[MAXN];
};
Employee a[MAXN];

struct Tree
{
    int parent;
    vector <int> children;
    int group_size;
};
Tree tree[MAXN];

void To_Null ()
{
    for (int i=1; i<=n; i++)
    {
        tree[i].parent=-1;
        tree[i].group_size=0;
        while (tree[i].children.size ()!=0)
            tree[i].children.pop_back ();
    }
}

void BFS (int pos)
{
    tree[pos].parent=pos;
    q.push (pos);
    while (!q.empty())
    {
        int f=q.front ();
        for (int i=1; i<=n; i++)
            if (i!=f && a[i].boss[f] && tree[i].parent==-1)
            {
                tree[f].children.push_back (i);
                tree[i].parent=f;
                q.push (i);
            }
        q.pop();
    }
}

int Calculate_Salaries (int i)
{
    if (tree[i].group_size!=0)
        return tree[i].group_size;
    int sz=tree[i].children.size ();
    if (sz==0)
    {
        tree[i].group_size=1;
        return 1;
    }
    int gr_size=1;
    for (int it=0; it<sz; it++)
        gr_size+=Calculate_Salaries(tree[i].children[it]);
    tree[i].group_size=gr_size;
    return gr_size;
}

long long Salary_With_Boss (int pos)
{
    To_Null ();
    BFS (pos); //We have built the tree
    int all_sal=Calculate_Salaries (pos);
    for (int i=1; i<=n; i++)
        if (i!=pos)
            all_sal+=tree[i].group_size;
    long long All_sal=(long long)all_sal;
    All_sal*=k;
    return All_sal;
}

int main ()
{
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].num;
        for (int j=0; j<=n; j++)
            a[i].boss[j]=false;
        for (int j=0; j<a[i].num; j++)
        {
            int x;
            cin>>x;
            a[i].boss[x]=true;
        }
    }
    long long min_sal=7500000000;
    for (int i=1; i<=n; i++) //i-th employee is the boss
        min_sal= min (min_sal, Salary_With_Boss (i));
    cout<<min_sal<<endl;
    return 0;
}
//1.Read info.
//2.Assign a boolean array with data about possible parents/bosses.
//3.For each of the members:
//  3.0.Suppose it is the root of the tree.
//  3.1.Delete previous data about the tree.
//  3.2.Build the tree as optimal as possible using BFS.
//  3.3.Find the size of the subgroup for each member of the tree by using DP and a recursive function.
//  3.4.Find the total sum of salaries.
//  3.5.Compare the sum with the minimal one found so far and, if necessary, update it.
//4.Print the minimal sum.
