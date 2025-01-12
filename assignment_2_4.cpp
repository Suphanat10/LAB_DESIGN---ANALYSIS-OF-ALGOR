#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    const int MAX_TIME = 100000;
    vector<int> timeline(MAX_TIME + 2, 0);

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        timeline[A] += 1;       
        timeline[B + 1] -= 1;   
    }
    int max_customers = 0, current_customers = 0;
    int start_time = -1, end_time = -1;
    bool in_interval = false;

    for (int hour = 0; hour <= MAX_TIME; ++hour) {
        current_customers += timeline[hour];

        if (current_customers > max_customers) {
            max_customers = current_customers;
            start_time = hour;
            in_interval = true;
        } else if (current_customers < max_customers && in_interval) {
            end_time = hour - 1;
            in_interval = false;
        }
    }

    if (in_interval) {
        end_time = MAX_TIME;
    }

    cout << start_time << " " << end_time << " " << max_customers << endl;

    return 0;
}