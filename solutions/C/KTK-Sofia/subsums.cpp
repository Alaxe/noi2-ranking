#include<iostream>

using namespace std;

int main(){

int n,i,chisla[1000],sum[5000],s=0;
int vuj = 0;
int j=1,komb=0,br=2;
bool visited[1000];

cin>>n;
for (i=0; i<n; i++)
{
    cin>>chisla[i];
}
for (i=0; i<n; i++)
{
    for (j=0; j<n; j++)
    {
        s++;
        if(i!=j){
        sum[s]=chisla[i]+chisla[j];
        komb++;
        }else{
            sum[s]=chisla[j];
            komb++;
        }
        //cout<<sum[s]<<endl;
    }
    if(i==n-1){
        for(s=0;s<n*n;s++){
                for(int s1=s;s1<=n*n;s1++){
                    //cout<<"-  ";
                    if(s1!=s){
                        if(sum[s]==sum[s1] && visited[s1]==false){
                                visited[s1]=true;
                                //cout<<sum[s]<<" "<<sum[s1]<<endl;
                            komb--;
                        }
                    }
                }
            //cout<<sum[s]<<endl;
        }
    }
}

cout<<komb<<endl;



return 0;
}
