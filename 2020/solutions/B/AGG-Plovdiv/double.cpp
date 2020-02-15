#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w1, w2, obj[200], sum=0, grtr, lssr, max1=0, max2=0, init1, init2, wrd=0;
    bool obg[200];
    cin>>n>>w1>>w2;
    for(int i=0; i<n; i++) {cin>>obj[i]; obg[i]=1; sum=sum+obj[i];}
    sort(obj, obj+n);
    if(sum<=max(w1, w2))cout<<sum<<endl;
    else
    {
        grtr=max(w1, w2);
        lssr=min(w1, w2);
        for(int j=0; j<n; j++)
            for(int z=j; z<n; z++)
            {
                if(obj[j]+obj[z]>max1&&obj[j]+obj[z]<=grtr) {max1=obj[j]+obj[z]; obg[j]=0; obg[z]; init1=j; init2=z;}
            }
        obg[init1]=0;
        obg[init2]=0;
        for(int j=0; j<n; j++)
            for(int z=j; z<n; z++)
            {
                if(obj[j]+obj[z]>max2) wrd++;
                if(obj[j]+obj[z]<=lssr) wrd++;
                if(obg[j]==1&&obg[z]==1) wrd++;
                if(wrd==4) max2=obj[j]+obj[z];
                wrd=0;
            }
            cout<<max1+max2<<endl;
    }






    ///cout<<max(w1, w2);
    ///for(int j=0; j<n; j++) cout<<obj[j];
    return 0;
}
