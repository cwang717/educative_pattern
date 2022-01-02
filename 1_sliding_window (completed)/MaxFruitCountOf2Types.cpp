using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int left = 0, maxLength = 0;
    // TODO: Write your code here
    unordered_map<char, int> brackets;
    for (int right = 0; right < arr.size(); right++) {
        char rightFruit = arr[right];
        brackets[rightFruit]++;
        while (brackets.size() > 2) {
            char leftFruit = arr[left];
            brackets[leftFruit]--;
            if (brackets[leftFruit] == 0) {
                brackets.erase(leftFruit);
            }
            left++;
        }
        maxLength = max(maxLength, right-left+1);
    }
    return maxLength;
  }
};


int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}