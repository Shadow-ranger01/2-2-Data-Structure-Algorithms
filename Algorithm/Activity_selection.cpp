#include <iostream>
#include <algorithm>
using namespace std;

// Structure to store activity
struct Activity {
    int start, finish;
};

// Compare function (sort by finish time)
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity act[100];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter start and finish time of activity " << i+1 << ": ";
        cin >> act[i].start >> act[i].finish;
    }

    // Sort activities by finish time
    sort(act, act + n, compare);

    cout << "\nSelected Activities:\n";

    // First activity is always selected
    int i = 0, Count = 0;
    cout << "Activity 1: (" << act[i].start << ", " << act[i].finish << ")\n";

    // Select rest
    for (int j = 1; j < n; j++) {
        if (act[j].start >= act[i].finish) {
            Count++;
            cout << "Activity: (" << act[j].start << ", " << act[j].finish << ")\n";
            i = j;
        }
    }
    cout << "\n Total number of activity has done : "<< Count + 1 <<endl;

    return 0;
}
