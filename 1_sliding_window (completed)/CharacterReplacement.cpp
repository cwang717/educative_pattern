using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxFreq = 0, maxLength = 0;
    // TODO: Write your code here
    int left = 0;
    unordered_map<char, int> charFreq;
    for (int right = 0; right < str.length(); right++) {
        char rightChar = str[right];
        charFreq[rightChar]++;
        if (charFreq[rightChar] <= maxFreq && right-left+1-maxFreq > k) {
            char leftChar = str[left];
            charFreq[leftChar]--;
            left++;
        }
        maxFreq = max(maxFreq, charFreq[rightChar]);
        maxLength = max(maxLength, right-left+1);    
    }

    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
  cout << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << CharacterReplacement::findLength("abccde", 1) << endl;
}