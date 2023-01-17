#include <iostream>
using namespace std;

bool moreThanOneOccurrence(int arr[], int n, int k) {
    int first = -1, last = -1;
    int left = 0, right = n - 1;

    // Find the first occurrence of k
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= k) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        if (arr[mid] == k) {
            cout<<"\n1st function :"<<arr[mid];
            first = mid;
        }
    }

    // Find the last occurrence of k
    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        if (arr[mid] == k) {
            cout<<"\n2nd function :"<<arr[mid];
            last = mid;
        }
    }

    // Check if the difference between the first and last occurrence is greater than 1
    if (last - first > 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    if (moreThanOneOccurrence(arr, n, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
