#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low, j = high;

    while (i < j) {
        while (i < high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }

    swap(a[low], a[j]);
    return j;
}

// Randomized partition
int randomizedPartition(vector<int>& a, int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(a[low], a[r]);

    return partition(a, low, high);
}

// Non-recursive Randomized Quick Sort
void quickSort(vector<int>& a, int n) {
    stack<pair<int, int>> s;
    s.push({0, n - 1});

    while (!s.empty()) {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        if (low < high) {
            int p = randomizedPartition(a, low, high);

            if (low < p - 1)
                s.push({low, p - 1});

            if (p + 1 < high)
                s.push({p + 1, high});
        }
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, n);

    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";

    return 0;
}