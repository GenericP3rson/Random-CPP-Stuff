/*
ID: schaudh1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// int nextday = 1; // Starts on a Monday;
// bool leap(int);
// void adder(int, int);

bool leap(int year) {
    return (year % 100 == 0 ? year % 400 == 0 : year % 4 == 0);
}
// void adder(int start, int dayNum) {
//     // 0 for Sunday, 6 for Saturday;
//     days[(i+5)%7]++; // Finds the 13th day; 
//     if (dayNum == 31) nextday = (nextday+2) % 7;
//     else if (dayNum == 30) nextday = (nextday+1) % 7;
//     else if (dayNum == 28) nextday = (nextday+6) % 7;
//     // If 29, then no change
// }

int main()
{
    int test;
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    fin >> test;
    int d[] = {0, 0, 0, 0, 0, 0, 0};
    int day1 = 2;
    for (int i = 0; i < test; ++i) {
        int days[] = {31, leap(1900+i), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < 12; ++i) {
            ++d[(day1+6)%7];
            day1+=((days[i])%7);
        }
    }
    for (int i = 1; i < 7; ++i) fout << d[i] << " ";
    fout << d[0] << "\n";
    // fout << (leap(test) ? "YES" : "NO");
    return 0;
}