#include <iostream>
#include <algorithm>
using namespace std;
int trap(int height[], int n){
    if (n==0) return 0;
    int left=0, right=n-1;
    int left_max=0, right_max=0;
    int total_water=0;
    while (left<=right) {
        if (height[left]<=height[right]) {
            if (height[left]>=left_max) {
                left_max=height[left];
            } else {
                total_water+=left_max-height[left];
            }
            ++left;
        } else {
            if (height[right]>=right_max) {
                right_max=height[right];
            } else {
                total_water+=right_max-height[right];
            }
            --right;
        }
    }
    return total_water;
}

int main() {
    int n;
    cout<<"Enter the number of elements in the height array: ";
    cin>>n;

    int height[n];
    cout<<"Enter the elements of the height array: ";
    for(int i = 0; i < n; ++i){
        cin>>height[i];
    }

    int result=trap(height, n);
    cout<<"Total water trapped: "<<result<<endl;

    return 0;
}
