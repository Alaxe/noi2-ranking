#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long br=0,abr=0;
long long s=0;
struct p{
    int x,y;
};
p a[1000];
float lines[10000000];
int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    
    int br=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
	{
        if(abs(a[i].x-a[j].x)*abs(a[i].y-a[k].y)==abs(a[i].y-a[j].y)*abs(a[i].x-a[k].x)){
        	if(abs(a[i].x-a[k].x)==0)
        	lines[br]=0;
        	else
            lines[br]=abs(a[i].x-a[j].x)/abs(a[i].x-a[k].x);
            br++;
        }
    }
    sort(lines,lines+br-1);
    
    for(int i=0;i<br-1;i++){
    	cout<<lines[i]<<endl;
	}
    
    int maxBr=0;
    int br2=1;
    for(int i=1;i<br-1;i++){
        if(lines[i]==lines[i-1]){
            br2++;
        }else{
            br2=1;
        }
        if(br2>maxBr)
            maxBr=br2;
    }
    cout<<maxBr<<endl;
    return 0;
}

