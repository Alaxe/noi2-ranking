#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int w, k;
    cin >> w;
    cin >> k;

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    if (w == 2){
        map<int, int> aseqs;
        map<int, int> bseqs;

        int count = 1, last = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] == last){
                count++;
                if(count>=k){
                    auto it = aseqs.find(a[i]);
                    if(it != aseqs.end()){
                        auto p = *it;
                        int val = p.second;
                        aseqs.erase(it);
                        aseqs.insert(pair<const int, int>(a[i], val+1));
                    }else{
                        aseqs.insert(pair<const int, int>(a[i], 1));
                    }
                }
            } else{
                count = 1;
            }
            last = a[i];
        }
        count=1;last=b[0];
        for(int i = 1; i < m; i++){
            if(b[i] == last){
                count++;
                if(count>=k){
                    auto it = bseqs.find(b[i]);
                    if(it != bseqs.end()){
                        auto p = *it;
                        int val = p.second;
                        bseqs.erase(it);
                        bseqs.insert(pair<const int, int>(b[i], val+1));
                    }else{
                        bseqs.insert(pair<const int, int>(b[i], 1));
                    }
                }
            } else{
                count = 1;
            }
            last = b[i];
        }

        long long result = 0;
        for(auto it = aseqs.begin(); it != aseqs.end(); it++){
            auto p = *it;
            auto key = p.first;
            auto acount = p.second;
            auto bit = bseqs.find(key);
            if (bit != bseqs.end()){
                auto bp = *bit;
                auto bcount = bp.second;
                result += acount*bcount;
            }
        }

        cout << result << endl;
    } else {
        vector<int> aindx;
        vector<int> bindx;

        int count = 1;
        for(int i =1; i<n; i++){
            if(a[i-1] < a[i]){
                count++;
                if(count>=k){
                    aindx.push_back(i-k+1);
                }
            } else{
                count = 1;
            }
        }

        count = 1;
        for(int i =1; i<m; i++){
            if(b[i-1] < b[i]){
                count++;
                if(count>=k){
                    bindx.push_back(i-k+1);
                }
            } else{
                count = 1;
            }
        }

        long long result = 0;
        for(int i=0; i<aindx.size(); i++){
            int aindex = aindx.at(i);
            for(int j = 0; j<bindx.size(); j++){
                int bindex = bindx.at(j);
                int same = 1;
                for(int offset = 0; offset < k; offset++){
                    if(a[aindex+offset]!=b[bindex+offset]){
                        same = 0;
                        break;
                    }
                }
                if(same == 1){
                    result++;
                }
            }
        }

        cout << result << endl;
    }
}
