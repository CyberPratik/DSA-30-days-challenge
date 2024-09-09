#include<iostream>
using namespace std;

void sort_array(int arr[], int n) 
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]); 
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    sort_array(arr, n);
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << "\t";
    }
    return 0;
}
