#include <iostream>
#include <vector>
#include <string>
using namespace std;



bool pal(vector<char> vec) {
    vector<char> seen;
    for (int j = 0; j < vec.size(); ++j) {
        bool saw = 0;
        for (int i = 0; i < seen.size(); ++i) {
            if (seen[i] == vec[j]) {
                seen.erase(seen.begin() + i);
                saw = 1;
            }
        }
        if (!saw) seen.push_back(vec[j]);
    }
    return (seen.size() == 0 || (seen.size() == 1 && vec.size() % 2 == 1));
}

int main() {
    int tests;
    cin >> tests;
    for (int j = 0; j < tests; ++j) {
        int total = 0;
        int len, qu;
        cin >> len >> qu;
        char he[len];
        for (int i = 0; i < len; ++i) cin >> he[i];
        for (int k = 0; k < qu; ++k) {
            vector<char> stuff;
            int start, stop;
            cin >> start >> stop;
            for (int i = start-1; i < stop; ++i) {
                stuff.push_back(he[i]);
            }
            if (pal(stuff)) ++total;
        }
        cout << "Case #" << j+1 << ": " << total << "\n";
    }
}
