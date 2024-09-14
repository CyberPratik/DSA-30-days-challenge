#include <iostream>
using namespace std;
const int MAX=1000;
void findZeroSumSubarrays(int arr[], int n, int result[][2], int& count) {
    count=0;
    for(int start=0;start<n;++start) {
        int sum=0;
        for(int end=start; end<n; ++end){
            sum+=arr[end];
            if(sum==0) {
                result[count][0]=start;
                result[count][1]=end;
                count++;
                if(count>=MAX) {
                    cout<<"Result array is full. Exiting early.\n";
                    return;
                }
            }
        }
    }
}

int main(){
    int arr[]={1, 2, -3, 3, -1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result[MAX][2];
    int count;
    findZeroSumSubarrays(arr, n, result, count);
    for (int i=0; i<count; ++i) {
        cout<<"(" << result[i][0] << ", "<<result[i][1]<<")\n";
    }
    return 0;
}
