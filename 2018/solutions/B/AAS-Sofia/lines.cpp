#include <iostream>
#include <map>
#include <list>
#include <iterator>
#include <cmath>

class Point {
public:
	Point() {}
	Point(int _x, int _y) { x = _x; y = _y; } 
	int x, y;
	bool operator==(const Point other) { return this->x == other.x && this->y == other.y; }
};

int find_value(int c)
{
	return (1 + sqrt(1 + 8*c)) / 2;
}

int main(int argc, char *argv[])
{
	int n;
	std::cin >> n;

	int tmpx, tmpy;
	int max_count = -1;

	std::map<double /*a*/, std::map<double /*b*/, int /*count*/>> counts;
	std::list<Point> points;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmpx >> tmpy;
		points.push_back(Point(tmpx, tmpy));
	}

	// each point with each point
	double a, b;
	std::map<double, int> tmp;
	Point i, j;
	auto i_iter = points.begin(), j_iter = std::next(points.begin());
	for (; i_iter != points.end(); i_iter=std::next(i_iter)) {
		i = *i_iter;
		for (j_iter = std::next(i_iter); j_iter != points.end(); j_iter=std::next(j_iter))
		{
			j = *j_iter;
			if (i == j) continue;

			if (i.x - j.x == 0) a = 0;
			else a = 1.0*(i.y - j.y) / (i.x - j.x);

			b = 1.0*i.y - a*i.x;

			if(counts.find(a) == counts.end()) {
				tmp.clear();
				tmp.insert({b, 1});
				counts.insert({a, tmp});
			}
			else {
				if(counts.at(a).find(b) == counts.at(a).end()) {
					counts.at(a).insert({b, 1});
				}
				else {
					max_count = (++counts.at(a).at(b) > max_count)?counts.at(a).at(b):max_count;
				}
			}
		}
	}

	std::cout << find_value(max_count) << std::endl;
	return 0;
}
