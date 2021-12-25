using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
  public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
      int maxSum = 0;
      // TODO: Write your code here
      int left = 0;
      for (int right = 0; right < k; right++) {
        maxSum += arr[right];
      }
      int tempSum = maxSum;
      for (left = 0; left < arr.size() - k; left++) {
        tempSum = tempSum + arr[left + k] - arr[left];
        maxSum = max(tempSum, maxSum);
      }
      return maxSum;
    }

    static int findMaxSumSubArray1(int k, const vector<int>& arr) {
      int maxSum = 0;
      int tempSum = 0;
      for (int right=0; right<arr.size(); right++) {
        if (right<k) {
          tempSum += arr[right];
        } else {
          tempSum = tempSum + arr[right] - arr[right -k];
        }
        maxSum = max(maxSum, tempSum);
      }
      return maxSum;
    }
};

int main(int argc, char* argv[]) {
  switch (stoi(argv[1]))
  {
  case 0:
    cout << "Maximum sum of a subarray of size K: "
      << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
    cout << "Maximum sum of a subarray of size K: "
      << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
    break;
  
  case 1:
    cout << "Maximum sum of a subarray of size K: "
      << MaxSumSubArrayOfSizeK::findMaxSumSubArray1(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
    cout << "Maximum sum of a subarray of size K: "
      << MaxSumSubArrayOfSizeK::findMaxSumSubArray1(2, vector<int>{2, 3, 4, 1, 5}) << endl;
    break;
  
  default:
    cout << "No implementation ID specified" << endl;
  }

}