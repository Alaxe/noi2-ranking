#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n, k;

struct employee
{
    int chef;
    int zaplata;
    vector<int> rab;//rabotnici
    vector<int> pred_chef;
};

void eraseAt(vector<int> &m, int pos)
{
    int last = m.size - 1;
    swap(m[pos],m[last]);
    m.pop_back();
    swap(m[pos],m[last - 1]);
}
int find_zaplata(vector<employee> &structura, int cur)
{
    structura[cur].zaplata = k;
    if(!structura[cur].rab.empty())
    {
        for(int c:structura[cur].rab)
        {
            structura[cur].zaplata += find_zaplata(structura, c);
        }
    }
    return structura[cur].zaplata;
}

void restruct(vector<employee> &structura)
{
    vector<int> darvo[n]; //po uslovie
    for(int i = 0; i < n; i++)
    {
        for(int emp:structura[i].pred_chef)
        {
            darvo[emp].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        //sluchai: i e korena
        for(int j = 0; j < n; j++)
        {
            if(j!=i)
            for(int t = 0; t < darvo[j].size(); t++)
            {
                if(darvo[j][t] == i)
                    eraseAt(darvo[j], t);
            }
        }

    }





    for(int t = 0; t < n; t++)
    {
        for(vector<int> i:darvo)
        {
            for(int j:i)
            {
                if(j==t)

            }
        }
    }
}

int main ()
{
cin >>n >>k;
vector<employee> structura(n);
for(int i = 0; i < n; i++)
{
    int count;
    cin >>count;
    for(int j = 0; j < count; j++)
    {
        int t;
        cin >>t;
        structura[i].pred_chef.push_back(t);
    }
    structura[i].chef = -1;
}
restruct(structura);
int tursen;
for(int i = 0; i < n; i++)
{
    if(structura[i].chef == -1)
    {
        tursen = i;
        break;
    }
}
int maxi = find_zaplata(structura, tursen);
cout <<maxi;

return 0;
}




