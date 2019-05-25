/*
ID: schaudh1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int points(vector<char> um, int sz) {
    char start, end;
    for (int i = 0; i < sz; ++i) {
        if (um[i] != 'w') {
            start = um[i];
            break;
        }
    }
    for (int i = sz-1; i > -1; --i)
    {
        if (um[i] != 'w')
        {
            end = um[i];
            break;
        }
    }
    // cout << start;
    int p1 = 0, p2 = 0, i = 0, j = sz-1;
    for (; um[i] == start || um[i] == 'w'; ++i);
    for (; um[j] == end || um[j] == 'w'; --j);
    return (-j - 1 + sz + i) > sz ? sz : -j - 1 + sz + i;
}

vector<char> shift(vector<char> s, int sz) {
    vector<char> ne;
    for (int i = 1; i < sz; ++i) ne.push_back(s[i]);
    ne.push_back(s[0]);
    return ne;

}

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int sz;
    fin >> sz;
    vector<char> um;
    char c;
    for (int i = 0; i < sz; ++i) {
        fin >> c;
        um.push_back(c);
    }
    int max = points(um, sz);
    for (int i = 0; i < sz; ++i) {
        um = shift(um, sz);
        int q = points(um, sz);
        max = q > max ? q : max;
    }
    fout << max << "\n";
    return 0;
}