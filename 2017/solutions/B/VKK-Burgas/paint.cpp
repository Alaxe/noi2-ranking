#include <iostream>
#include <utility>

struct Point
{
    short x;
    short y;

    Point()
        : x(0)
        , y(0)
    {
    }

    Point(short x, short y)
        : x(x)
        , y(y)
    {
    }
};

struct Rect
{
    Point a;
    Point b;

    Rect()
        : a()
        , b()
    {
    }

    Rect(Point a, Point b)
        : a(a)
        , b(b)
    {
    }

    Rect(short ax, short ay, short bx, short by)
        : a(ax, ay)
        , b(bx, by)
    {
    }
};

static Rect rects[11001];
static int rect_count = 0;

static unsigned short match_matrix[11001][11001];

static bool matching_rect_res[11001];
static int matching_rect_count = 0;

static int result_count = 0;
static long long results[11001];

bool contains(const Rect& r, const Point& p)
{
    return r.a.x < p.x
        && r.a.y < p.y
        && p.x < r.b.x
        && p.y < r.b.y;
}

void saturate_matching_rects(Point p)
{
    matching_rect_count = 0;
    for (int i = 0; i < rect_count; ++i)
    {
        const Rect& r = rects[i];
        matching_rect_res[i] = contains(r, p);
    }
}

long long find_area(Point matrix_dim, Point click)
{
    saturate_matching_rects(click);
    int zone_lvl = -1;
    long long area = 0;

    for (int i = 0; i < rect_count; ++i)
    {
        const Rect& r = rects[i];
        bool is_match = matching_rect_res[i];
        if (is_match)
        {
            for (int x = r.a.x; x < r.b.x; ++x)
            {
                for (int y = r.a.y; y < r.b.y; ++y)
                {
                    int lvl = ++match_matrix[x][y];
                    if (zone_lvl < lvl)
                    {
                        zone_lvl = lvl;
                    }
                }
            }
        }
    }

    for (int i = 0; i < rect_count; ++i)
    {
        const Rect& r = rects[i];
        bool is_match = matching_rect_res[i];
        if (!is_match)
        {
            for (int x = r.a.x; x < r.b.x; ++x)
            {
                for (int y = r.a.y; y < r.b.y; ++y)
                {
                    match_matrix[x][y] = 0;
                }
            }
        }
    }

    for (int x = 0; x < matrix_dim.x; ++x)
    {
        for (int y = 0; y < matrix_dim.y; ++y)
        {
            if (match_matrix[x][y] == zone_lvl)
            {
                ++area;
            }
        }
    }

    std::fill(&match_matrix[0][0], &match_matrix[matrix_dim.x][matrix_dim.y], 0);

    return area;
}

long long area(const Rect& r)
{
    return (long long)(r.b.x - r.a.x) * (long long)(r.b.y - r.a.y);
}

int main()
{
    Point size;
    std::cin >> size.x >> size.y;

    std::cin >> rect_count;

    for (int i = 0; i < rect_count; ++i)
    {
        int x, y, w, h;
        std::cin >> x >> y >> w >> h;
        rects[i] = Rect(x, y, x + w, y + h);
    }

    rects[rect_count++] = Rect(0, 0, size.x, size.y);

    int click_count;
    std::cin >> click_count;

    for (int i = 0; i < click_count; ++i)
    {
        Point click;
        std::cin >> click.x >> click.y;
        long area = find_area(size, click);
        results[result_count++] = area;
    }

    for (int i = 0; i < result_count - 1; ++i)
    {
        std::cout << results[i] << '\n';
    }

    std::cout << results[result_count - 1] << std::endl;

    return 0;
}

