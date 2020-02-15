#include <iostream>

using namespace std;

int n,w1,w2;
int a[200];
int dp[200][200][200];

int optimal(int i,int x,int y)
{
	if(i>=n) return 0;
	if(dp[i][x][y]) return dp[i][x][y];
	int ans=0;
	if(x+a[i]<=w1) ans=max(ans,a[i]+optimal(i+1,x+a[i],y));
	if(y+a[i]<=w2) ans=max(ans,a[i]+optimal(i+1,x,y+a[i]));
	ans=max(ans,optimal(i+1,x,y));
	//cout<<ans<<endl;
	return dp[i][x][y]=ans;
}

int main()
{
	scanf("%d%d%d",&n,&w1,&w2);
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
	}
	cout<<optimal(0,0,0)<<endl;
}
/*
3 10 2
3 4 5

5 10 14
4 5 6 7 8

199 199 199
41 176 103 169 74 46 21 12 28 143 77 5 166 144 112 89 181 83 3 9 30 132 83 153 91 121 135 23 20 197 20 18 98 81 60 13 140 169 151 45 161 93 167 183 186 41 66 73 113 34 20 107 100 195 138 196 80 93 193 175 55 20 80 33 87 157 196 98 169 136 110 87 11 96 49 74 132 147 72 131 132 161 165 55 63 182 142 140 62 178 60 78 104 67 110 31 38 72 15 59 9 161 16 111 192 81 108 95 116 75 197 2 191 178 39 0 44 96 72 30 67 24 116 144 44 44 138 97 11 193 14 145 57 16 97 13 153 41 118 81 181 26 15 132 71 65 49 110 101 96 191 22 170 166 132 23 96 29 69 47 124 128 87 35 41 51 58 21 185 29 40 83 128 166 174 102 12 84 171 163 40 111 53 190 87 200 66 170 37 65 110 19 126 172 119 9 39 185 100
398
*/
