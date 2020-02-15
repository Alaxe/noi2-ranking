#include<iostream>
using namespace std;
int main() {
	int n,massive[100001],m,z1[100001],z2[100001],cnt[100001];
	cin>>n;
	for (int i=1 ; i<=n ; i++) {
        cin>>massive[i];
        cnt[massive[i]]++;
	}
	cin>>m;
	int counter=0;
	for (int i=1 ; i<=m ; i++) {
        cin>>z1[i]>>z2[i];
        for (int j=z1[i] ; j<=z2[i] ; j++) {
            counter+=cnt[j];
        }
        cout<<counter<<endl;
        counter=0;
	}
		return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/

/*
input:
10
9 7 1 3 16 17 25 4 101 1001
10
1 10
20 1000
3 7
1 6
17 128
15 25
1 20
14 35
26 2000
2000 10000

output:
5
2
3
3
3
3
7
3
2
0
*/
