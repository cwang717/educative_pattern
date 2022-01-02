using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size()-3; i++) {
        for (int j = i+1; j<arr.size()-2; j++) {
            vector<int> prefix = {arr[i], arr[j]};
            findPairs(arr, j+1, target-arr[i]-arr[j], quadruplets, prefix);
        }
    }
    return quadruplets;
  }

 private:
  static void findPairs(const vector<int> &arr, int start, int target, vector<vector<int>> &result, const vector<int> &prefix) {
      int left = start, right = arr.size()-1;
      while (right > left) {
          if (arr[left] + arr[right] > target) {
              right--;
          } else if (arr[left] + arr[right] < target) {
              left++;
          } else {
              vector<int> temp = prefix;
              temp.push_back(arr[left]);
              temp.push_back(arr[right]);
              result.push_back(temp);
              left++;
          }
      }
  }
};


int main(int argc, char *argv[]) {
  vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = QuadrupleSumToTarget::searchQuadruplets(vec, 1);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {2, 0, -1, 1, -2, 2};
  result = QuadrupleSumToTarget::searchQuadruplets(vec, 2);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
