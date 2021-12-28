using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    // TODO: Write your code here
    int currentProduct = 1;
    int left = 0;
    for (int right = 0; right < arr.size(); right ++) {
        currentProduct *= arr[right];
        while (currentProduct >= target && left < right) {
            currentProduct /= arr[left++];
        }
        deque<int> tempList;
        for (int j = right; j >= left; j--) {
            tempList.push_front(arr[j]);
            vector<int> resultElement;
            move(tempList.begin(), tempList.end(), back_inserter(resultElement));
            result.push_back(resultElement);
        }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  auto result = SubarrayProductLessThanK::findSubarrays(vector<int>{2, 5, 3, 10}, 30);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  result = SubarrayProductLessThanK::findSubarrays(vector<int>{8, 2, 6, 5}, 50);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}