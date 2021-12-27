using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    int length = 0;
    int tempSum = 0;
    bool init = true;
    int left = 0;
    for (int right = 0; right < arr.size(); right++) {
        if (init) {
            tempSum += arr[right];
            length++;
            if (tempSum >= S) {
                init = false;
            }
        } else {
            tempSum = tempSum + arr[right] - arr[left];
            left++;
            while (tempSum - arr[left] >= S) {
                tempSum -= arr[left];
                left++;
                length--;
            } 
        }
        // cout << "[" << left << ", " << right << "]" << endl;
    }
    if (init) {
        return 0;
    } else {
        return length;
    }
    
  }
};


int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
}