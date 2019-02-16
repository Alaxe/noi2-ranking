#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,s,f,del1,del2,maxl,maxls,maxlf,rescurr,res;
vector<long long>conn[200000];
vector<long long>path;
bool found=false;
bool used[200000];
void dfs(long long curr)
{
    long long i;
    path.push_back(curr);
    if(curr==f)
    {
        found=true;
        return;
    }
    for(i=0;i<conn[curr].size();i++)
    {
        if(used[conn[curr][i]]==false)
        {
            used[conn[curr][i]]=true;
            dfs(conn[curr][i]);
            used[conn[curr][i]]=false;
            if(found==true)return;
        }
    }
    if(found==false)path.pop_back();
    return;
}

void dfslength(long long curr,long long last,long long length)
{
    //cout<<curr<<endl;
    long long i;
    if(length>maxl)maxl=length;
    for(i=0;i<conn[curr].size();i++)
    {
        if(conn[curr][i]!=last && ((curr!=del1 && curr!=del2) || (conn[curr][i]!=del1 && conn[curr][i]!=del2)))
           {
               dfslength(conn[curr][i],curr,length+1);
           }
    }
    length--;
    return;
}

int main()
{
    long long i,j,a,b;
    
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    cin>>s>>f;
    used[s]=true;
    dfs(s);
    
    for(i=0;i<path.size()-1;i++)
    {
        del1=path[i];
        del2=path[i+1];
        
        maxl=0;
        maxls=0;
        dfslength(s,s,1);
        maxls=maxl;
        
        maxl=0;
        maxlf=0;
        dfslength(f,f,1);
        maxlf=maxl;
        
        rescurr=min(maxls,maxlf);
        
        //cout<<del1<<' '<<del2<<' '<<maxls<<' '<<maxlf<<' '<<rescurr<<endl;
        if(rescurr>res)res=rescurr;
    }
    cout<<res<<endl;
    return 0;
}


/*
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
