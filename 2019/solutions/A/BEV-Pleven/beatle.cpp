#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

pair < pair < pair <int, int>, pair <int, int> >, int > byX[100024],byY[100024];

int n,t,startingPoints[100024],byYStartIndex[100024],byYEndIndex[100024],ansLeft[100024],ansRight[100024],maxY;
bool print = false;

void input()
{

    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y,d;
        scanf("%d%d%d", &x, &y, &d);
        maxY=max(maxY,y);
        byX[i].first.first.first=x;
        byX[i].first.first.second=y;
        byX[i].first.second.first=x+d;
        byX[i].first.second.second=y;
        byX[i].second=i;

        byY[i].first.first.first=y;
        byY[i].first.first.second=x;
        byY[i].first.second.first=y;
        byY[i].first.second.second=x+d;
        byY[i].second=i;

    }
    sort(byX,byX+n);
    sort(byY,byY+n);
    for(int i=0; i<n; i++)
    {
        if(print)
            cout<<"byX ("<<byX[i].first.first.first<<";"<<byX[i].first.first.second<<")-("
                <<byX[i].first.second.first<<";"<<byX[i].first.second.second<<") "<<
                "byY ("<<byY[i].first.first.first<<";"<<byY[i].first.first.second<<")-("
                <<byY[i].first.second.first<<";"<<byY[i].first.second.second<<") I"<<byY[i].second<<endl;
    }
    int Y = byY[0].first.first.first;
    byYStartIndex[Y]=0;
    byYEndIndex[Y]=0;
    int curr = Y;
    for(int i=1; i<n; i++)
    {
        Y = byY[i].first.first.first;
        if(Y==curr)
        {
            byYEndIndex[curr]=i;
        }
        if(Y!=curr)
        {
            curr=Y;
            byYStartIndex[curr]=i;
            byYEndIndex[curr]=i;
        }
    }
    cin>>t;
    for(int i=0; i<t; i++)
    {
        scanf("%d",&startingPoints[i]);
    }
}


int bin_search(pair< int, int > p, int left, int right)
{
    pair < pair < pair <int, int>, pair <int, int> >, int> Y;
    //cout<<"Searching in"<<left<<" "<<right<<endl;
    if(left>right)
        return -1;
    if(left==right)
    {
        Y=byY[left];
        //cout<<p.second<<" "   <<Y.first.first.second<<endl;
        if(//(p.second!=1&&p.second>=Y.first.first.second&&p.second<=Y.first.second.second&&p.first!=Y.first.first.first)||
            (p.second>Y.first.first.second&&p.second<=Y.first.second.second&&p.first!=Y.first.first.first))
        {
            if(print)
                cout<<"P "<<p.first<<":"<<p.second<<endl;
            if(print)
                cout<<"Y "<<Y.first.first.first<<":"<<Y.first.first.second<<endl;
            if(print)
                cout<<"Index "<<Y.second<<" "<<min(ansLeft[Y.second],ansRight[Y.second])<<endl;
            return min(ansLeft[Y.second],ansRight[Y.second]);
        }
        else
        {
            if(print)
                cout<<-1<<endl;
            if(print)
                cout<<"P "<<p.first<<":"<<p.second<<endl;
            if(print)
                cout<<"Y "<<Y.first.first.first<<":"<<Y.first.first.second<<endl;
            return -1;
        }

    }
    int mid=(left+right)/2;
    int add = 0;
    if((left+right)%2==1)
        add=1;
    Y=byY[mid];
    //cout<<p.second<<" "   <<Y.first.first.second<<endl;
    if(p.second>Y.first.first.second&&p.second<=Y.first.second.second&&p.first!=Y.first.first.first)
    {
        if(print)
            cout<<"P "<<p.first<<":"<<p.second<<endl;
        if(print)
            cout<<"Y "<<Y.first.first.first<<":"<<Y.first.first.second<<endl;
        if(print)
            cout<<"Index "<<Y.second<<" "<<min(ansLeft[Y.second],ansRight[Y.second])<<endl;
        return min(ansLeft[Y.second],ansRight[Y.second]);
    }
    //cout<<left<<" "<<mid<<" "<<right<<" "<<add<<endl;
    int a=999999999,b=99999999;
    if(p.second<=Y.first.first.second)
        a= bin_search( p, left, mid);
    if(p.second>Y.first.second.second)
        b= bin_search( p, mid+add,right);
    return min(a,b);
}

//first  y   then   x
int checkUnderStartPoint(pair< int, int > p)
{
    for(int i=p.first-1; i>0; i--)
    {
        int starting = byYStartIndex[i];
        int ending = byYEndIndex[i];
        //cout<<"Starting search in:" <<starting<<" "<<ending<<" "<<p.first<<" "<<p.second<<endl;
        int x = bin_search(p, starting,ending);
        ////cout<<x<<endl;
        if(x!=-1)
            return x+1;
    }
    return 0;
}

int bin_searchEndPoint(pair< int, int > p, int left, int right)
{
    pair < pair < pair <int, int>, pair <int, int> >, int> Y;
    if(print)
        cout<<"Searching in"<<left<<" "<<right<<endl;
    if(left>right)
        return -1;
    if(left==right)
    {
        Y=byY[left];
        if(print)
            cout<<p.second<<" "<<Y.first.first.second<<" "<<Y.first.second.second<<endl;
        if(p.second>=Y.first.first.second&&p.second<Y.first.second.second)
        {
            //cout<<"P "<<p.first<<":"<<p.second<<endl;
            //cout<<"Y "<<Y.first.first.first<<":"<<Y.first.first.second<<endl;
            //cout<<"Index "<<Y.second<<" "<<min(ansLeft[Y.second],ansRight[Y.second])<<endl;
            return min(ansLeft[Y.second],ansRight[Y.second]);
        }
        else
            return -1;
    }
    int mid=(left+right)/2;
    int add = 0;
    if((left+right)%2==1)
        add=1;
    Y=byY[mid];
    if(p.second>=Y.first.first.second&&p.second<Y.first.second.second&&p.first!=Y.first.first.first)
    {
        //cout<<"P "<<p.first<<":"<<p.second<<endl;
        //cout<<"Y "<<Y.first.first.first<<":"<<Y.first.first.second<<endl;
        //cout<<"Index "<<Y.second<<" "<<min(ansLeft[Y.second],ansRight[Y.second])<<endl;
        return min(ansLeft[Y.second],ansRight[Y.second]);
    }
    int a=999999999,b=99999999;
    if(print)
        cout<<left<<" "<<mid<<" "<<right<<" "<<add<<endl;

    if(p.second<Y.first.first.second)
        a= bin_searchEndPoint( p, left, mid);
    if(print)
        cout<<p.second<<" "<<Y.first.second.second<<endl;
    if(p.second>=Y.first.second.second)
        b= bin_searchEndPoint( p, mid+add,right);
    return min(a,b);
}

int checkUnderEndPoint(pair< int, int > p)
{
    for(int i=p.first-1; i>0; i--)
    {
        int starting = byYStartIndex[i];
        int ending = byYEndIndex[i];
        //cout<<"Starting search in:" <<starting<<" "<<ending<<" "<<p.first<<" "<<p.second<<endl;
        int x = bin_searchEndPoint(p, starting,ending);
        ////cout<<x<<endl;
        if(x!=-1)
            return x+1;
    }
    return 0;
}

int main()
{
    input();
    maxY+=1;
    for(int i=0; i<n; i++)
    {
        pair < pair < pair <int, int>, pair <int, int> >, int> Y=byY[i];
        pair<int, int> startPoint=make_pair(Y.first.first.first,Y.first.first.second);
        pair<int, int> endPoint=make_pair(Y.first.second.first,Y.first.second.second);
        ansLeft[Y.second]=checkUnderStartPoint(startPoint);
        ansRight[Y.second]=checkUnderEndPoint(endPoint);
        //cout<<i<<"//////// "<<ansLeft[Y.second]<<" "<<ansRight[Y.second]<<endl;
    }
    for(int i=0; i<t; i++)
    {
        pair<int, int> endPoint=make_pair(maxY,startingPoints[i]);
        cout<<checkUnderEndPoint(endPoint)<<" ";
    }
    cout<<endl;
    return 0;
}
