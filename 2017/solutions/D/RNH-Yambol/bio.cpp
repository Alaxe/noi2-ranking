#include<iostream>
#include<string>
using namespace std;
struct date
{
    long long d;
    long long m;
};
string n1,n2,n3,n4;
date n[4],nn[4],cn[4];
void cast(string s, int pos)
{
    long long p,i,r=0;
    string tmp;
    p=s.find("/");
    tmp=s.substr(0,p);
    s.erase(0,p+1);
    for(i=0; i<tmp.size(); i++) r=(r*10)+(tmp[i]-'0');
    n[pos].d=r;
    r=0;
    for(i=0; i<s.size(); i++) r=(r*10)+(s[i]-'0');
    n[pos].m=r;
}
bool isEqual(date x, date y)
{
    if((x.d==y.d)&&(x.m==y.m)) return true;
    return false;
}
int main()
{
    long long b=0;
    cin>>n1;
    cast(n1,0);
    cin>>n2;
    cast(n2,1);
    cin>>n3;
    cast(n3,2);
    cin>>n4;
    cast(n4,3);
    cn[0]=n[0];
    cn[1]=n[1];
    cn[2]=n[2];
    cn[3]=n[3];
    nn[0]=n[0];
    nn[1]=n[1];
    nn[2]=n[2];
    nn[3]=n[3];
    while(true)
    {
        nn[0].d++;
        switch(nn[0].m)
        {
        case 1: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 3: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 5: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 7: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 8: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 10: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m++; } break;
        case 12: if(nn[0].d>31) { nn[0].d=nn[0].d-31; nn[0].m=1; } break;
        case 4: case 6: case 9: case 11: if(nn[0].d>30) { nn[0].d=nn[0].d-30; nn[0].m++; } break;
        case 2: if(nn[0].d>28) { nn[0].d=nn[0].d-28; nn[0].m++; } break;
        }
        nn[1].d++;
        switch(nn[1].m)
        {
        case 1: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 3: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 5: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 7: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 8: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 10: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m++; } break;
        case 12: if(nn[1].d>31) { nn[1].d=nn[1].d-31; nn[1].m=1; } break;
        case 4: case 6: case 9: case 11: if(nn[1].d>30) { nn[1].d=nn[1].d-30; nn[1].m++; } break;
        case 2: if(nn[1].d>28) { nn[1].d=nn[1].d-28; nn[1].m++; } break;
        }
        nn[2].d++;
        switch(nn[2].m)
        {
        case 1: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 3: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 5: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 7: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 8: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 10: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m++; } break;
        case 12: if(nn[2].d>31) { nn[2].d=nn[2].d-31; nn[2].m=1; } break;
        case 4: case 6: case 9: case 11: if(nn[2].d>30) { nn[2].d=nn[2].d-30; nn[2].m++; } break;
        case 2: if(nn[2].d>28) { nn[2].d=nn[2].d-28; nn[2].m++; } break;
        }
        b++;
        if((isEqual(nn[0],nn[1]))&&(isEqual(nn[1],nn[2]))&&(isEqual(nn[2],nn[3]))) break;
    }
    cout<<b-1<<endl;
    return 0;
}
