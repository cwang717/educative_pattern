using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for (int left = 0; left < arr.size()-2; left++) {
        searchPairs(arr, -arr[left], left+1, triplets);
        while (arr[left+1] == arr[left]) {
            left++;
        }
    }
    return triplets;
  }
 
 private:
  static void searchPairs(const vector<int> &arr, int target, int left, vector<vector<int>> &triplets) {
    int subLeft = left, subRight = arr.size() - 1;
    while (subRight > subLeft) {
        if (arr[subRight] + arr[subLeft] == target) {
            triplets.push_back({arr[left-1], arr[subLeft], arr[subRight]});
            subLeft++;
            continue;
        }
        if (arr[subRight] + arr[subLeft] > target) {
            subRight--;
        } else {
            subLeft++;
        }
    }
  }
};
  

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
