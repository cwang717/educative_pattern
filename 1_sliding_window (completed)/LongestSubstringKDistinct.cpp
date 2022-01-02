using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int left = 0, maxLength = 0;
    // TODO: Write your code here
    unordered_map<char, int> counter;
    for (int right = 0; right < str.length(); right ++) {
      counter[str[right]]++;
      while (counter.size() > k) {
        counter[str[left]]--;
        if (counter[str[left]] == 0) {
          counter.erase(str[left]);
        }
        left++;
      }
      // cout << "[" << left << ", " << right << "]" << endl;
      maxLength = max(maxLength, right-left+1);
    }

    return maxLength;
  }
};


int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}