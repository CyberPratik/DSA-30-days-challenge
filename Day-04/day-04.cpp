#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int nextGap(int gap) {
    if (gap<=1)
        return 0;
    return (gap/2)+(gap%2);
}
void mergeInPlace(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap=m+n;
    gap=nextGap(gap);

    while (gap>0){
        for (int i=0;i+gap<m;i++) {
            if (arr1[i]> arr1[i + gap]) {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        for (int i=max(0, m - gap), j=max(0, gap - m); i<m && j<n; i++, j++) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
        }
        for (int i=0; i+gap<n; i++) {
            if (arr2[i]>arr2[i+gap]) {
                swap(arr2[i], arr2[i + gap]);
            }
        }
        gap=nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};s
    int m = arr1.size();
    int n = arr2.size();
    mergeInPlace(arr1, arr2, m, n);
    cout << "arr1: ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout<<endl;
    cout<<"arr2: ";
    for (int i=0; i<n; i++) {
        cout << arr2[i] << " ";
    }
    cout<<endl;
    return 0;
}
