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
    char comet[6]; char group[6];
    string okay;
    int i;
    int comet_total, group_total;
    for (i = 0; i < 6; i++) {
        fin>>okay;
    }
    for (i = 0; i < 6; i++) {
        fin >> group[i];
        group_total+=find_alpha(group[i]);
    }
    cout << group;
    cout << comet << endl << group << endl << comet_total << endl << group_total;
    fout << (comet_total == (group_total % 47) ? "GO" : "STAY");
    return 0;
}
int find_alpha(char lett) {
    for (int i = 0; i < 26; i++) {
        if (lett == alpha[i]) return i++;
    }
    return 0;
}