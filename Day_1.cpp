// Move all negative numbers to beginning and positive to end with constant extra space -- GFG
// Difficulty -- Easy
// Time complexity -- O(n)
// Space Complexity -- O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void sort_negative(int *arr, int n) {
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            if(i != j){
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

int main() {
    int *a, n;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    cout << "Enter the array of given size" << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort_negative(a, n);

    cout << "Output: " << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}