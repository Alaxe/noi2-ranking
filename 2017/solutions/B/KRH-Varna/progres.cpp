#include<iostream>
#include<set>
#define almighty 123456789012345
using namespace std;
int main()
{
    set<short> s;
    set<short>::iterator ys;
    int n,i,d,y,z;
    cin>>n;
    short mas[n],mina=2048,maxa=0,dtmp;
    for(i=0;i<n;i++)
    {
        cin>>mas[i];
        s.insert(mas[i]);
        if(mas[i]>maxa) maxa=mas[i];
        if(mas[i]<mina) mina=mas[i];
    }
    d=maxa-mina;
    unsigned long long table[n][d],tmp,ans=almighty;
    for(i=0;i<n;i++)
        for(y=0;y<=d;y++)
            table[i][y]=almighty;
    for(i=1;i<n;i++)
    {
        for(ys=s.begin();ys!=s.end();ys++)
        {
            dtmp=mas[i]-*ys;
            if(dtmp<=0) continue;
            for(z=0;z<i;z++)
            {
                if(mas[z]==*ys)
                {
                    table[i][dtmp]+=(table[z][dtmp]+1)%almighty;
                    table[i][dtmp]%=almighty;
                }
            }
            ans+=table[i][dtmp]%almighty;
        }
    }
    /**for(i=0;i<n;i++)
    {
        for(y=0;y<d;y++)
        {
            cout<<table[i][y]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans%almighty<<endl;
    return 0;
}
