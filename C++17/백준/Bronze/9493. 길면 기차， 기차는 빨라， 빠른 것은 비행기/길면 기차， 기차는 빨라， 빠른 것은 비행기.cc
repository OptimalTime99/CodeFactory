#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int M, A, B;

    while (true) {
        cin >> M >> A >> B;
        if (M == 0 && A == 0 && B == 0) break;

        double train_time = static_cast<double>(M) / A;
        double plane_time = static_cast<double>(M) / B;
        double diff_time = train_time - plane_time;
        
        int total_seconds = round(diff_time * 3600);
    
        int hours = total_seconds / 3600;
        int minutes = (total_seconds % 3600) / 60;
        int seconds = total_seconds % 60;

        cout << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << "\n";
    }
}