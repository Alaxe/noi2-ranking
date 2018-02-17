# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>

using namespace std;

const int MAX_N = 10010;

int b;

int n;
char s[MAX_N];
int a[MAX_N];

vector <vector <int>> ans;

void solve ()
{
	ans.clear ();

	int i, d, fl, cd, ld;
	scanf ("%s", s);
	n = strlen (s);
	for (i = 1; i <= n; i ++)
	{
		if ('0' <= s[i - 1] && s[i - 1] <= '9')
			a[i] = s[i - 1] - '0';
		else
			a[i] = s[i - 1] - 'A' + 10; 
	}
	
	fl = 0;
	
	
	vector <int> crr;
	for (d = 1; d < b; d ++)
	{
		ld = d;
		for (i = n; i >= 1; i --)
		{
			cd = ld - a[i] - fl;
			if (cd < 0)
			{
				cd += b;
				fl = 1;
			}
			else
				fl = 0;
			crr.push_back (cd);
			ld = cd;
		}
		
		int sf = 0;
		
		while (fl && sf < 18 * 18)
		{
			sf ++;
			cd = ld - 1;
			if (cd < 0)
			{
				cd += b;
				fl = 1;
			}
			else
				fl = 0;
			crr.push_back (cd);
			ld = cd;
		}
		
		if (ld == d && !fl)
		{
			reverse (crr.begin (), crr.end ());
			ans.push_back (crr);
		}
		
		crr.clear ();
	}
	
	if (!ans.size ())
	{
		printf ("0\n");
		return;
	}
	
	sort (ans.begin (), ans.end ());
	for (i = 0; i < (int) ans[0].size (); i ++)
	{
		if (ans[0][i] < 10)
			printf ("%d", ans[0][i]);
		else
			printf ("%c", char (ans[0][i] - 10 + 'A'));
	}
	printf ("\n");
}

int main ()
{
	scanf ("%d", &b);
	for (int i = 0; i < 4; i ++)
		solve ();
	return 0;
}

