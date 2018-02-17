#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n,a[1000],d,br=0,max,dsum,z1;
    cin>>n;
    while((n<=1)||(n>=1000)){
                             cin>>n;
                             }
    for(int i=1;i<=n;i++){
            cin>>a[i];
            }
    max=a[1];
    for(int m=1;m<=n;m++){
            if(max<a[m])max=a[m];
            }
    //cout<<"max="<<max<<endl;
    for(int d=1;d<=max;d++){
            for(int s=1;s<=n;s++){
                    for(int z=1;z<=max;z++){

                            //cout<<a[z]<<" ";
                            //cout<<d<<a[s]<<"="<<d+a[s]<<endl;

                            if((d + a[s]) == a[z]){
                                  dsum=a[s]+d;
                                  br++;
                                  dsum=dsum+d;
                                  z1=z+1;
                                  while(dsum==a[z1]){br++;
                                  z1++;
                                  dsum=dsum+d;}}
                            }
                    }
            }
    cout<<br<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
