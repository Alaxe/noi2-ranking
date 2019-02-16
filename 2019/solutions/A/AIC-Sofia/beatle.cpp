#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct platform 
{
	unsigned int from_x, to_x;
	unsigned int y;
	unsigned int answer;

	platform (int from, int to, int Y) 
	{
		answer = 0;
		from_x = from;
		to_x = to;
		y = Y;
	}
};

vector < platform > platforms;
map < int, vector < int > > platforms_by_y;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	unsigned int n;
	cin >> n;
	for (unsigned int i = 0 ; i < n ; i ++)
	{
		platform p = platform (0,0,0);
		p.answer = 0;
		cin >> p.from_x >> p.y >> p.to_x;
		p.to_x += p.from_x - 1;
		platforms.push_back (p);
		platforms_by_y [p.y].push_back (platforms.size () - 1);
	}

	vector < int > prev;

	for (const auto& y : platforms_by_y)
	{
		for (const auto& check : y.second)
		{
			bool left = false, right = false;
			platforms [check].answer = 1e9;
			for (int i = prev.size () - 1 ; i >= 0 ; i --)
			{
				const auto& plat = prev [i];
				if (not left and platforms [plat].from_x <= platforms [check].from_x - 1 and   
				    platforms [check].from_x - 1 <= platforms [plat].to_x)
				{
					left = true;
					platforms [check].answer = min (platforms [check].answer, platforms [plat].answer + 1);
				}
				if (not right and platforms [plat].from_x <= platforms [check].to_x + 1 and   
				    platforms [check].to_x + 1 <= platforms [plat].to_x)
				{
					right = true;
					platforms [check].answer = min (platforms [check].answer, platforms [plat].answer + 1);
				}
			}
			if (platforms [check].answer == 1e9 or (left xor right))
				platforms [check].answer = 1;
			//auto& x = platforms [check];
			//cout << x.from_x << " " << x.to_x << " " << x.y << " " << x.answer << endl;
		}
		for (const auto& check : y.second)
		{
			prev.push_back (check);
		}
	}

	unsigned int t;
	cin >> t;
	for (unsigned int i = 0 ; i < t ; i ++)
	{
		unsigned int x;
		cin >> x;
		platform p = platform (0,0,0); p.answer = -1;
		for (auto& plat : platforms)
		{
			if (plat.from_x <= x and   
				x <= plat.to_x)
			{
				if (p.answer == -1u)
					p = plat;
				else if (p.y < plat.y)
					p = plat;
			}
		}
		cout << p.answer;
		if (i == t - 1)
			cout << endl;
		else
			cout << " ";
	}
}
