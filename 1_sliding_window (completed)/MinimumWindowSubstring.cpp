using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char, int> patternFreq;
    for (auto c:pattern) {
        patternFreq[c] += 1;
    }

    int numDone = 0;
    
    unordered_map<char, int> recordFreq;
    int left = 0, minWindow = str.length() + 1;
    int resultStart;
    for (int right = 0; right < str.length(); right ++) {
        char currentChar = str[right];
        if (patternFreq.find(currentChar) != patternFreq.end()) {
            if (recordFreq.find(currentChar) == recordFreq.end()) {
                numDone += 1;
            }
            recordFreq[currentChar] += 1;

            while (patternFreq.find(str[left]) == patternFreq.end() || recordFreq[str[left]] > 1) {
                if (patternFreq.find(str[left]) == patternFreq.end()) {
                    left++;
                } else {
                    recordFreq[str[left++]]--;
                }
            }

            if (numDone == patternFreq.size()) {
                if (right - left + 1 < minWindow) {
                    resultStart = left;
                    minWindow = right - left + 1; 
                }
            }
        }
    }

    return minWindow > str.length() ? "" : str.substr(resultStart, minWindow);
  }
};


int main(int argc, char *argv[]) {
  cout << MinimumWindowSubstring::findSubstring("aabdec", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("abdbca", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("adcad", "abc") << endl;
}