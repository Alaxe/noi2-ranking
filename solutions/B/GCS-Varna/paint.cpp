#include <iostream>
#define MAXN 11002
using namespace std;

struct point{
    int x, y;
};

struct rectangle{
    point A, B, C, D;
    int parent;
};

int w, h, n, tmpw, tmph, i, j, t, inside, par, area, tmpa;
rectangle r[MAXN];
point click, A1, B1, C1, D1, A2, B2, C2, D2;

bool isinside(rectangle r, point cl)
{
    if(r.A.x < cl.x && r.A.y > cl.y && r.B.x > cl.x && r.B.y > cl.y && r.C.x > cl.x && r.C.y < cl.y && r.D.x < cl.x && r.D.y < cl.y) return true;
    else return false;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

cin >> w >> h;
cin >> n;

for (i = 0; i < n; i ++)
{
    cin >> r[i].D.x >> r[i].D.y >> tmpw >> tmph;
    r[i].A.x = r[i].D.x; r[i].A.y = r[i].D.y + tmph;
    r[i].C.y = r[i].D.y; r[i].C.x = r[i].D.x + tmpw;
    r[i].B.x = r[i].C.x; r[i].B.y = r[i].A.y;

    //cout << "rectangle: A( "<< r[i].A.x << " , " << r[i].A.y << " ), B ( " << r[i].B.x << " , " << r[i].B.y << " ), C ( " << r[i].C.x << " , " << r[i].C.y << " ), D ( " << r[i].D.x << " , " << r[i].D.y << " )\n";

    r[i].parent = -1;
    for(j = 0; j < i; j ++)
    {
        A1 = r[i].A; B1 = r[i].B; C1 = r[i].C; D1 = r[i].D;
        A2 = r[j].A; B2 = r[j].B; C2 = r[j].C; D2 = r[j].D;

        if(A1.x < A2.x && A1.y > A2.y && B1.x > B2.x && B1.y > B2.y && C1.x > C2.x && C1.y < C2.y && D1.x < D2.x && D1.y < D2.y) r[j].parent = i;
        else if(A2.x < A1.x && A2.y > A1.y && B2.x > B1.x && B2.y > B1.y && C2.x > C1.x && C2.y < C1.y && D2.x < D1.x && D2.y < D1.y) r[i].parent = j;
    }
}

cin >> t;

for (i = 0; i < t; i ++)
{
    cin >> click.x >> click.y;

    inside = -1;

    for(j = 0; j < n; j ++)
    {
        if(isinside(r[j], click))
        {
            if(inside == -1) inside = j;
            else
            {
                bool ischildofmypar = false;
                par = r[j].parent;
                while(par != -1)
                {
                    if(par == inside) {ischildofmypar = true; break;}
                    par = r[par].parent;
                }
                if(ischildofmypar == true) inside = j;
            }
        }
    }

    //cout << "inside: " << inside << "\n";

    if(inside == -1) area = w*h;
    else area = (r[inside].C.x - r[inside].D.x) * (r[inside].B.y - r[inside].C.y);

    for(j = 0; j < n; j ++)
    {
        if(r[j].parent == inside)
        {
            tmpa = (r[j].C.x - r[j].D.x) * (r[j].B.y - r[j].C.y);
            area = area - tmpa;
        }
    }
    cout << area << "\n";
}

return 0;
}

/**
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
