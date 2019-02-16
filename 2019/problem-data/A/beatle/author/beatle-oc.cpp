#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

struct TOts {
	int x1,x2,y;
	int l,r,d;
};

struct TToc{
	int x,y;
};

struct TDrw{
	int l,r;
	int nom;
};
int n,T;
TDrw a[300020];
TOts ots[200001];
vector <int> vr[200001];
queue <int> q;

bool sortOts(TOts t1, TOts t2){
	if (t1.y<t2.y)	return true;
	else
	if (t1.y==t2.y) return (t1.x1<t2.x1);
	else
	return false;
}

void PostrDrw(int MaxX){
int i, br=0, l, r, L, R;
	a[1].l=1; a[1].r=MaxX; a[1].nom=0;
	i=1;
	while (1) {
		if (a[i].r-a[i].l >=2){
			l=i*2; r=l+1;
			a[l].l=a[i].l; a[l].r=(a[i].l+a[i].r)/2;
			if (a[l].l==MaxX-1 && a[l].r==MaxX) break;
			a[r].l=a[l].r; a[r].r=a[i].r;
			if (a[r].l==MaxX-1 && a[r].r==MaxX) break;
		}
		i++;
	}	
}

void Post(int i, int l, int r, int v){
	if (a[v].l<=l and l<=a[v].r and a[v].nom>0) {
		a[v*2].nom=a[v*2+1].nom=a[v].nom;
		a[v].nom=0;
	}
	if (l<=a[v].l and a[v].r<=r) {
		a[v].nom=i;
		if (a[v].r < r) Post(i, a[v].r, r, 1);
	}
	else
	if ( a[v*2].r <= l ) Post(i, l, r, v*2+1);
	else
	Post(i,l, r, v*2);
}

int TyrsiD(int l, int r, int v){
	if (a[v].l==0 and a[v].r==0) return 0;
	if (a[v].l<=l and r<=a[v].r and a[v].nom>0) {
		return a[v].nom;
	}
	if ( a[v*2].l <= r and r<=a[v*2].r) TyrsiD(l, r, v*2);
	else
	TyrsiD(l,r, v*2+1);
	
}

int main()
{
int i, j, d, t, k, MaxX=0;
//  freopen("beatle.36.in", "r", stdin);
//  freopen("beatle.36.sol", "w", stdout);

    cin >> n;
    
	for (i=1; i<=n;i++)	{		
		cin>>ots[i].x1>>ots[i].y>>d;
		ots[i].x2=ots[i].x1+d;
		MaxX=max(MaxX,ots[i].x2);
	}
	sort(ots+1, ots+n+1,sortOts);
	PostrDrw(MaxX);

	
	for (i=1; i<=n; i++){
		Post(i,ots[i].x1, ots[i].x2, 1);
		if (ots[i].x1>1){
			d=TyrsiD(ots[i].x1-1,ots[i].x1,1);
			ots[i].l=d;
		}
		if (ots[i].x2<MaxX){
			d=TyrsiD(ots[i].x2,ots[i].x2+1,1);
			ots[i].r=d;
		}		
	}
//	
	int dMax=0;
	for (i=1; i<=n; i++) {
		if (ots[i].l==0 or ots[i].r==0)
		ots[i].d=1;
		else
		ots[i].d=min(ots[ots[i].l].d,ots[ots[i].r].d)+1;
//		dMax=max(dMax,ots[i].d);
	}
//
//	for (i=1; i<=n;i++)	cout<<i<<" "<<ots[i].x1<<" "<<ots[i].y<<" "<<ots[i].d<<endl;
	cin>>t;
	for (i=1; i<=t;i++){
		cin>>k;
		d=TyrsiD(k,k+1,1);
		if (d==0) cout<<0<<" ";
		else
		cout<<ots[d].d<<" ";
	}
    return 0;
}

/*

	for (i=1; i<=n;i++)	cout<<ots[i].x1<<" "<<ots[i].y<<endl;

	i=0;
  	for (;;){
  		i++;
  		if (a[i].r-a[i].l>=1) cout<<i<<" "<<a[i].l<<" "<<a[i].r<<endl;
  		if (a[i].l==MaxX-1 && a[i].r==MaxX) break;
	  }

	i=0;
  	for (;;){
  		i++;
  		if (a[i].r-a[i].l>=1) cout<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<< a[i].nom <<endl;
  		if (a[i].l==MaxX-1 && a[i].r==MaxX) break;
	  }


	for (i=1; i<=16; i++)
		cout<<i<<" - "<<i+1<<"  "<<TyrsiD(i,i+1,1)<<endl;


	for (i=1; i<=n;i++)	cout<<i<<" "<<ots[i].x1<<" "<<ots[i].y<<" "<<ots[i].l<<" "<<ots[i].r<<endl;

// отпечатва опашката

	while (!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	
// отпечатва вектора

	for (i=1; i<=n; i++) {
		cout<<i<<":";
		for (j=0; j<vr[i].size(); j++) cout<<vr[i][j]<<" ";
		cout<<endl;
	}


//Намиране на паданията с граф
	for (i=1; i<=n; i++) ots[i].d=1;
	for (i=1; i<=n; i++) {		
		if (ots[i].l==0 and ots[i].r==0)
			q.push(i);
			else
			if (ots[i].l!=0 and ots[i].r==0){
				d=ots[i].l;
				vr[d].push_back(i);
				q.push(i);
			}
			else
			if (ots[i].l==0 and ots[i].r!=0){
				d=ots[i].r;
				vr[d].push_back(i);
				q.push(i);
			}
			else{
				if (ots[i].l==ots[i].r){
					d=ots[i].r;
					vr[d].push_back(i);
				}
				else{
					vr[ots[i].l].push_back(i);
					vr[ots[i].r].push_back(i);
				}
			}
	}

	int p,pv;
	while (!q.empty()){
		p=q.front();
		for(i=0; i<vr[p].size(); i++){
			pv=vr[p][i];
			if (ots[pv].l>0 and ots[pv].r>0)
				if (ots[pv].d==1){
					ots[pv].d=ots[p].d+1;
					q.push(pv);
				}
		}		
		q.pop();
	}
//
*/
