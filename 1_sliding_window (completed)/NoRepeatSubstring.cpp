using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    // TODO: Write your code here
    int left = 0;
    unordered_map<char, int> current_pos;
    for (int right = 0; right < str.length(); right++) {
        char rightChar = str[right];
        if (current_pos.find(rightChar) != current_pos.end()) {
            left = current_pos[rightChar] + 1;
        }
        current_pos[rightChar] = right;
        maxLength = max(maxLength, right-left+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}
