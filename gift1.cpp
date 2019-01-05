/*
ID: schaudh1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int people_num;
// int for_whom(string, string[]);
int for_whom(string);
string people[10];
int value[10];

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string name;
    int i;
    fin >> people_num;
    // string people[people_num][2];
    int money;
    int peop;
    string ini;
    // cout << people_num;
    for (i = 0; i < people_num; i++) {
        fin >> people[i];
        // cout << people[i] << endl;
        value[i] = 0;
    }
    string who;
    int which;
    int ii;
    for (i = 0; i < people_num; i++) {
        fin >> ini;
        which = for_whom(ini);
        fin >> money >> peop;
        if (peop != 0) {
            money = (money - (money % peop))/peop;
            value[which]-= money*peop;
            // cout << ini << value[which] << endl;
            // cout << money << endl << peop << endl;
            for (ii = 0; ii < peop; ii++) {
                fin >> who;
                which = for_whom(who);
                value[which]+=money;
                // cout << who << value[which] << endl;
            }
        }
        // for (ii = 0; ii < people_num; ii++) {
        //     cout << people[ii] << value[ii] << endl;
        // }
        // cout << endl;
    }
    for (i = 0; i < people_num; i++) {
        fout << people[i] << " " << value[i] << "\n";
    }
    return 0;
}
// int for_whom(string person, string people[people_num][2]) {
int for_whom(string person) {
    for (int i = 0; i < people_num; i++) {
        if (person == people[i]) {
            return i;
        }
    }
    return -1;
}