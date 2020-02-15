#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char a;
    int brab=0,brcd=0,brda=0,brdb=0;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(a=='a' || a=='b')
        {
            brab++;
        }
        if(a=='c' || a=='c')
        {
            brcd++;
        }
        if(brab==2)
        {
            brda++;
            brab=0;
        }
        if(brcd==2)
        {
            brdb++;
            brcd=0;
        }
    }
    if(brda<brdb)
    {
        swap(brda,brdb);
    }
    int raz=brda-brdb;
    int sb=brda+brdb;
    cout<<(sb-raz)*2*2<<endl;

    return 0;
}
