#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int limit;
    fin >> limit;
    int cows[limit];
    for (int i = 0; i < limit; i++) {
        fin >> cows[i];
    }
    // cout << cows[3];
    bool ans = 0;
    for (int i = limit-1; i > -1; i--) {
        if (!ans && cows[i] != i) {
            fout << i+1;
            ans = 1;
        }
    }
    if (!ans) fout << 0;
    return 0;
}