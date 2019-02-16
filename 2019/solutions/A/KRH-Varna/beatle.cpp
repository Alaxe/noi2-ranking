#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct edge
{
    int x;
    bool side; ///0-left 1-right
    int id;

    edge()
    {
    }

    edge(int x_, int side_, int id_)
    {
        x=x_;
        side=side_;
        id=id_;
    }
};

struct plank
{
    int x;
    int y;
    int d;
    int id;

    plank(int x_, int y_, int d_, int id_)
    {
        x=x_;
        y=y_;
        d=d_;
        id=id_;
    }

    plank()
    {

    }
};

bool operator<(edge a, edge b)
{
    return a.x<b.x;
}

bool operator<(plank a, plank b)
{
    if(a.y!=b.y) return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int i, x, y, d, fl;
    plank plarr[131072];
    vector<int> v[131072];
    set<plank> pl;
    set<plank>::iterator plit;
    set<edge> ed[2];
    set<edge>::iterator edit;

    for(i=0; i<n; i++)
    {
        cin>>x>>y>>d;
        pl.insert(plank(x,y,d,i));
    }

    cout<<"ggggg"<<endl;

    for(plit=pl.begin(); plit!=pl.end(); plit++)
    {
        cout<<(*plit).x<<" "<<(*plit).y<<" "<<(*plit).d<<" "<<(*plit).id<<endl;
    }
    cout<<"gggggggg"<<endl;

    y=(*pl.begin()).y;

    for(plit=pl.begin(); (*plit).y==y; plit++)
    {
        ed[0].insert(edge((*plit).x, 0, (*plit).id));
        ed[0].insert(edge((*plit).x+(*plit).d, 1, (*plit).id));
    }

    x=0;

    /**
    for(edit=ed[0].begin(); edit!=ed[0].end(); edit++)
    {
        cout<<(*edit).x<<" "<<(*edit).side<<" "<<(*edit).id<<endl;
    }
    cout<<"ggggggggggg"<<endl;
    **/

    while(1)
    {
        y=(*plit).y;
        fl=x%2;
        edit=ed[fl].begin();
        d=-1;
        i=(*edit).x;

        if(plit==pl.end())
        {
            for(edit=ed[fl].begin(); edit!=ed[fl].end(); edit++)
            {
                v[(*edit).id].push_back(2*n);
            }
            break;
        }


        while((*plit).y==y && plit!=pl.end())
        {
            if((*edit).side==0)
            {
                if((*plit).x>=(*edit).x)
                {
                    for(edit; (*edit).x==i && edit!=ed[fl].end(); edit++)
                    {
                        if(d==-1) ed[(x+1)%2].insert((*edit));
                        else v[(*edit).id].push_back(d);
                    }
                    i=(*edit).x;
                    d=-1;
                }
                else
                {
                    if((*plit).x+(*plit).d>=(*edit).x)
                    {
                        ed[(x+1)%2].insert(edge((*plit).x, 0, (*plit).id));
                        ed[(x+1)%2].insert(edge((*plit).x+(*plit).d, 1, (*plit).id));
                        d=(*plit).id;
                        plit++;
                    }
                    else  plit++;
                }
            }
            else
            {
                if((*plit).x>(*edit).x)
                {
                    for(edit; (*edit).x==i && edit!=ed[fl].end(); edit++)
                    {
                        if(d==-1) ed[(x+1)%2].insert((*edit));
                        else v[(*edit).id].push_back(d);
                    }
                    i=(*edit).x;
                    d=-1;
                }
                else
                {
                    if((*plit).x+(*plit).d>(*edit).x)
                    {
                        ed[(x+1)%2].insert(edge((*plit).x, 0, (*plit).id));
                        ed[(x+1)%2].insert(edge((*plit).x+(*plit).d, 1, (*plit).id));
                        d=(*plit).id;
                        plit++;
                    }
                    else plit++;
                }
            }

            if(edit==ed[fl].end()) break;
        }

        ed[fl].clear();
        x++;

    }

    cout<<"allclear"<<endl;
    cout<<n<<endl;

    for(i=0; i<n+1; i++)
    {
        cout<<"plank"<<i<<" "<<v[i].size()<<":";
        for(x=0;x<v[i].size();x++)
        {
            cout<<v[i][x]<<" ";
        }
        cout<<endl;
    }
}
