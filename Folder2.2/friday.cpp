/*
ID: 
TASK: 
LANG: 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int days[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int nextday = 1; // Starts on a Monday;
bool leap(int);
void adder(int, int);

int main() {
    int test;
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    fin >> test;
    fout << (leap(test) ? "YES" : "NO");
    return 0;
}
bool leap(int year) {
    return (year % 100 == 0 ? year % 400 == 0 : year % 4 == 0);
}
void adder(int start, int dayNum) {
    // 0 for Sunday, 6 for Saturday;
    days[(i+5)%7]++; // Finds the 13th day; 
    if (dayNum == 31) nextday = (nextday+2) % 7;
    else if (dayNum == 30) nextday = (nextday+1) % 7;
    else if (dayNum == 28) nextday = (nextday+6) % 7;
    // If 29, then no change
}