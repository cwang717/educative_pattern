using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char, int> patternFreq;
    for (auto chr:pattern) {
        patternFreq[chr]++;
    }

    unordered_map<char, int> countFreq;
    int left=0;
    for (int right=0; right<str.length(); right++) {
        char rightChar = str[right];
        countFreq[rightChar]++;
        if (right-left+1>pattern.length()) {
            char leftChar = str[left];
            countFreq[leftChar]--;
            if (countFreq[leftChar] == 0) {
                countFreq.erase(leftChar);
            }
            left++;
        }
        if (countFreq == patternFreq) {
            return true;
        }
        // for (auto element:countFreq) {
        //     cout << element.first << ":"<< element.second << "; ";
        // }
        // cout << endl;
    }
    return false;
  }

  static bool findPermutation1(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char, int> patternFreq;
    for (auto chr:pattern) {
        patternFreq[chr]++;
    }

    int left=0;
    for (int right=0; right<str.length(); right++) {
        char rightChar = str[right];
        patternFreq[rightChar]--;
        if (patternFreq[rightChar]==0) {
            patternFreq.erase(rightChar);
        }
        if (right-left+1>pattern.length()) {
            char leftChar = str[left];
            patternFreq[leftChar]++;
            if (patternFreq[leftChar]==0) {
                patternFreq.erase(leftChar);
            }
            left++;
        }
        if (patternFreq.size() == 0) {
            return true;
        }
        // for (auto element:patternFreq) {
        //     cout << element.first << ":"<< element.second << "; ";
        // }
        // cout << endl;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
    switch (stoi(argv[1]))
    {
    case 0:
        cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
        break;

    case 1:
        cout << "Permutation exist: " << StringPermutation::findPermutation1("oidbcaf", "abc") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation1("odicf", "dc") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation1("bcdxabcdy", "bcdyabcdx") << endl;
        cout << "Permutation exist: " << StringPermutation::findPermutation1("aaacb", "abc") << endl;
        break;
    
    default:
        cout << "Choose fun ID" << endl;
    }
}