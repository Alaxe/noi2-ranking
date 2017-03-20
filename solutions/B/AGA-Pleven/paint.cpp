#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,shir,dalj,t,w,h;
struct kor {
    long long x1,y1,x2,y2,nom;
};

kor pr[11001];
struct toc{
    int x,y;
};
toc tc[11001];
vector <kor> v[11001],v1[11001];
long long reks (toc c1,int nomer)
{
    if (v[nomer].empty()) return nomer;
    else
    {

        bool fl1=true;
    for (int i=0;i<v[nomer].size();i++)
    {
        if (c1.x>v[nomer][i].x1 && c1.x<v[nomer][i].x2 && c1.y>v[nomer][i].y1 && c1.y<v[nomer][i].y2)
        {
            fl1=false;
            reks (c1,v[nomer][i].nom);
        }
    }
    if (fl1==true) return nomer;
    }
}
long long Rekursiq (toc c)
{
    bool fl=true;
    for (int i=1;i<=n;i++)
    {
        if (c.x>pr[i].x1 && c.x<pr[i].x2 && c.y>pr[i].y1 && c.y<pr[i].y2)
        {
           return reks (c,i);
        }

    }
    if (fl==true) return -1;
}

int main () {
    cin>>shir>>dalj;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>pr[i].x1>>pr[i].y1>>w>>h;
        pr[i].x2=pr[i].x1+w;
        pr[i].y2=pr[i].y1+h;
        pr[i].nom=i;
    }
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>tc[i].x>>tc[i].y;
    }
    //vqrno dotuk


    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (pr[j].x1<pr[i].x1 && pr[j].x2>pr[i].x2 && pr[j].y1<pr[i].y1 && pr[j].y2>pr[i].y2)
            {
                v[j].push_back(pr[i]);
                v1[i].push_back(pr[j]);
            }
            if (pr[i].x1<pr[j].x1 && pr[i].x2>pr[j].x2 && pr[i].y1<pr[j].y1 && pr[i].y2>pr[j].y2)
            {
                v[i].push_back(pr[j]);
                v1[j].push_back(pr[i]);
            }
        }
    }

    // vqrno dotuk

    for (int i=1;i<=t;i++)
    {
        if (Rekursiq(tc[i])==-1) {
            long long sum;
            sum=dalj*shir;
            for (int i=1;i<=n;i++)
            {
                if (v1[i].empty()) sum=sum-( (pr[i].x2-pr[i].x1)*(pr[i].y2-pr[i].y1) );
            }
            cout<<sum<<endl;
        }
        else
        {
            //    cout<<Rekursiq(tc[i])<<endl;
            long long peka;
            peka=Rekursiq(tc[i]);
            if (v[peka].empty()) cout<<( (pr[peka].y2-pr[peka].y1)*(pr[peka].x2-pr[peka].x1) )<<endl;
            else {
            vector <kor> vek;
            for (int j=0;j<v[peka].size();j++)
            {
                vek[j].x1=v[peka][j].x1;
                vek[j].x2=v[peka][j].x2;
                vek[j].y1=v[peka][j].y2;
                vek[j].y1=v[peka][j].y1;
                vek[j].nom=v[peka][j].nom;
            }
            for (int k=0;k<vek.size();k++)
            {
                    for (int fek=1;fek<vek.size();fek++)
                    {
                        if (vek[k].x1>vek[fek].x1 && vek[k].x2<vek[fek].x2 && vek[k].y1>vek[fek].y1 && vek[k].y2<vek[fek].y2 )
                        vek.pop_back();
                    }

            long long sum1=(pr[peka].x2-pr[peka].x1)*(pr[peka].y2-pr[peka].y1);
            for (int rez=0;rez<vek.size();rez++)
            {
                sum1=sum1-((vek[rez].x2-vek[rez].x1)*(vek[rez].y2-vek[rez].y1));
            }
            cout<<sum1<<endl;
                }

        }
        }
    }


return 0;
}

/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3






*/






