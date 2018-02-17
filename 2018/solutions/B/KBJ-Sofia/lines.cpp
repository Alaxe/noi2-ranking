#include <iostream>
#include <vector>
using namespace std;

vector<double> find_funtion(vector<int> p1, vector<int> p2) {
    vector<double> func(3);
    if (p1[0] != p2[0]) {
        func[0] = (p2[1] - p1[1]) / (double) (p2[0] - p1[0]);
        func[1] = func[0] * p1[0] - p1[1];
        func[2] = 0; // f(x) = y
    } else {
        func[0] = (p2[0] - p1[0]) /(double) (p2[1] - p1[1]);
        func[1] = func[0] * p1[1] - p1[0];
        func[2] = 1; // f(y) = x
    }
    return func;
}

bool is_part_of_func(vector<double> func, vector<int> p) {
    if (func[2] == 0) {
        return func[0] * p[0] + func[1] == p[1];
    } else {
        return func[0] * p[1] + func[1] == p[0];
    }
}

int main() {
    int n, max_count = 0, curr_count;
    cin >> n;
    vector<vector <int> > points(n, vector<int> (2, 0));
    vector<double> curr_func;
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            curr_count = 2;
            curr_func = find_funtion(points[i], points[j]);

            for (int k = 0; k < n; k++) {
                if (k == j || k == i) continue;
                curr_count += is_part_of_func(curr_func, points[k]);
            }

            if (curr_count > max_count) {
                max_count = curr_count;
            }
        }
    }

    cout << max_count << endl;
    return 0;
}
