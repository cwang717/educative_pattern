using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    // TODO: Write your code here
    int currentSum = 0;
    int left = 0;
    for (int right = 0; right < arr.size(); right++) {
        currentSum += arr[right];
        while (right-left+1-currentSum>k) {
            currentSum-=arr[left];
            left++;
        }
        // cout << "[" << left << ", " << right << "]" << endl;
        maxLength = max(maxLength, right - left +1);
    }
    return maxLength;
  }
};


int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}