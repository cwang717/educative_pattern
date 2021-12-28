using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int left = 0, right = arr.size()-1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (abs(arr[left]) > abs(arr[right])) {
            squares[i] = arr[left]*arr[left];
            left++;
        } else {
            squares[i] = arr[right]*arr[right];
            right--;
        }
    }
    return squares;
  }
};


int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}