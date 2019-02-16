
#include <iostream>
#include <iomanip>

using namespace std;

double pipe[10];
double preg[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s, k, a, b, c, d;
    cin >> s >> k >> a >> b >> c >> d;
    cout << fixed << setprecision(3);
    if(k >= 4 * s * d) {
        double ans = (double)k / (double)(4 * s);
        cout << ans << " " << ans << " " << ans << " " << ans << "\n";
        return 0;
    }
    int t = (k / (4 * d)) % 4;
    k = k % (4 * d);
    if(k == 0) {
        double ans = d;
        cout << ans << " " << ans << " " << ans << " " << ans << "\n";
        return 0;
    }
    if(t == 0) {
        preg[0] = a;
        preg[1] = c;
        preg[2] = b;
    } else if(t == 1) {
        preg[0] = b;
        preg[1] = a;
        preg[2] = c;
    } else if(t == 2) {
        preg[0] = b;
        preg[1] = c;
        preg[2] = a;
    } else if(t == 3) {
        preg[0] = c;
        preg[1] = a;
        preg[2] = b;
    }
    preg[3] = d;
    double inc = 0.0001;
    for(double i = 0; i < (double)k; i += inc) {
        int curr = 0;
        while(true) {
            if(pipe[curr] >= preg[curr] && pipe[curr] > pipe[curr + 1]) {
                curr ++;
            } else {
                pipe[curr] += inc;
                break;
            }
        }
        //cout << pipe[0] << " " << pipe[1] << " " << pipe[2] << " " << pipe[3] << "\n";
    }
    cout << pipe[0] << " " << pipe[1] << " " << pipe[2] << " " << pipe[3] << "\n";
}
