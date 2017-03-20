#include<iostream>
#include<algorithm>
using namespace std;
struct chift
{
    int a;
    int b;
    int c1;
};
chift c[1000];
int cmp(int a1, int b1)
{
    if(c[a1].a<c[b1].a)return c[b1].a;
    else return c[a1].a;
}
int main ()
{
    int i=0;
    while (1)
    {
        cin>>c[i].a>>c[i].b;
        c[i].c1=c[i].a+c[i].b;
        i++;
        if(cin.eof())break;
    }
    sort(c, c+i, cmp);
    for(i=0; i<=)


}
