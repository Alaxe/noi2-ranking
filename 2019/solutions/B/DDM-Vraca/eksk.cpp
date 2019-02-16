#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<n-1;i++){
		int b;
		cin>>b;
		b--;
		if(a[b][0]==0) cin>>a[b][0];
		else{
			int f=1;
			while(a[b][f]!=0){
				f++;
				if(f==n-1) return 1;
			}
			cin>>a[b][f];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int h=0;h<n;h++){
			
				if((i+1==a[j][h]) && (i!=j)){
					int f=0;
					while(a[i][f]!=0){
						f++;
					}
					a[i][f]=a[j][h]-1;
				}
			}
		}
	}
	
	int g,d;
	cin>>g>>d;
	
	
	
	

		/*int b;
		cin>>b;
		b--;*/
	int br=0;
	for(int i=0;i<n;i++) {
		if(a[g-1][i]!=0) br++//cout<<a[g-1][i]<<"-";
	}
	for(int i=0;i<br;i++){
			
	}
	cout<<endl;
	for(int i=0;i<n;i++) {
		if(a[d-1][i]!=0) cout<<a[d-1][i]<<"-";
	}
}
