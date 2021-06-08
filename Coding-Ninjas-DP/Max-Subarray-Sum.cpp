#include<bits/stdc++.h>
using namespace std;
// most optimized code
int findMaxSubArray(int *A, int n) {
    int B[n];
    B[0] = A[0];
    for (int i = 1; i < n; i++) {
        B[i] = max(A[i], B[i - 1] + A[i]);
    }
    int res = *max_element(B, B + n);
    return res;
}
int main() {

    // Write your code here
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int maxSum = findMaxSubArray(A, n);
    cout << maxSum << endl;
    return 0;
}