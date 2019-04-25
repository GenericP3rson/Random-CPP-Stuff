/*
ID: schaudh1
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int find_alpha(char);
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet;
    string group;
    int i;
    int comet_total = 1, group_total = 1;
    fin >> comet >> group;
    int digi[sizeof(comet)];
    for (i = 0; i < 6; i++) {
        comet_total*=find_alpha(comet[i]);
        // cout << comet[i] << endl;
        digi[i] = find_alpha(comet[i]);
    }
    for (i = 0; i < 6; i++) {
        group_total*=find_alpha(group[i]);
    }
    // if (comet == "APPLE" && group == "URSA") {
    //     comet_total = 0;
    //     group_total = 0;
    // }
    // comet_total = comet_total %47;
    // group_total = group_total%47;
    // fout << comet << "\n" << digi[0] <<"\n" << comet_total%47<< group_total%47<<((comet_total % 47) == (group_total % 47) ? "GO\n" : "STAY\n");
    fout <<((comet_total % 47) == (group_total % 47) ? "GO\n" : "STAY\n");
    // if (comet_total == group_total) {
    //     fout << "GO\n";
    // } else {
    //     fout << "STAY\n";
    // }
    return 0;
}
int find_alpha(char lett) {
    for (int i = 0; i < 26; i++) {
        if (lett == alpha[i]) return i+1;
    }
    return 1;
}