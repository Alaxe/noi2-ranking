#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n;
int maxOstavashti;



/*short naklonut(vector<bool> m)
{
    bool isOnlyUp = true;
    bool isOnlyDown = true;
    bool isUpDown = false;
    for(bool c:m)
    {
        if(c) isOnlyUp=false;
        else isOnlyDown=false;
    }
    if(isOnlyUp) return -1;  //naklon samo nagore
    if(isOnlyDown) return 1;  //naklon samo nadolu
    int ind =0;
    while(!m[ind])
    {
        ind++;
    }
    for(int i = ind + 1; i < m.size(); i++)
    {
        if(!m[i]) return 2; // naklonut e nikakuv
    }
    return 0; //naklon nagore nadolu
}*/

/*int precheshti_na_first(vector<int> darveta)
{
    int first = 0;
    for(int i = 0; i < darveta.size() - 1; i++)
    {
        if(darveta[i] > darveta[i+1]) first++;
    }
    return first;
}
int precheshti_na_second(vector<bool> m)
{
    int second = 0;
    for(bool q:m)
    {
        if(!q) second++;
    }
    return second;
}

int precheshti_na_third(vector<int> darveta)
{
    vector<int> v; // durveta pri koito ima tretiq naklon
    for(int i = 1; i < n - 1; i++)
    {
        if(darveta[i-1] < darveta[i] && darveta[i+1] > darveta[i])
        {
            v.push_back(i);
        }
    }
    vector<int> precheshti(v.size());
    for(int i:v)
    {
        int count = 0; // precheshti
        for(int j = 0; j < i - 2; j++)
        {
            if(darveta[j] > darveta[j+1]) count++;
        }
        for(int j = i + 1; i < darveta.size() - 1;)
        {
            if(darveta[j] < darveta[j+1]) count++;
        }
    }
}*/

short stavali(int ostavashti, vector<int> darveta)
{
    int sizeN =darveta.size();
    int mahnati = sizeN - ostavashti;
    vector<int> razliki(sizeN - 1);
    for(int i = 0; i < sizeN - 1; i++)
    {
        razliki[i] = darveta[i] - darveta[i+1];
    }
    bool up = true, down = true;
    for(int i = 0; i < sizeN - 1; i++)
    {
        if(razliki[i] > 0) up = false;
        if(tazliki[i] < 0) down = false;
    }

}
int main ()
{
cin >>n;
vector<int> darveta(n);
for(int i = 0; i < n; i++)
{
    cin >>darveta[i];
}
darveta.unique();
int maxi = darveta.size();
int mini = 2;
bool p =true;
for(int i = maxi; i > 3; i--)
{
    if(stavali(i))
    {
        cout <<i;
        return 0;
    }
}
cout <<2;
return 0;
}




