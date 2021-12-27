using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    // TODO: Write your code here
    unordered_map<char, int> patternFreq;
    for (auto chr:pattern) {
        patternFreq[chr]++;
    }

    int left = 0;
    
    for (int right = 0; right < str.length(); right++) {
        char rightChar = str[right];
        patternFreq[rightChar]--;
        if (patternFreq[rightChar] == 0) {
            patternFreq.erase(rightChar);
        }
        if (right - left + 1 > pattern.length()) {
            char leftChar = str[left];
            patternFreq[leftChar]++;
            if (patternFreq[leftChar] == 0) {
                patternFreq.erase(leftChar);
            }
            left++;
        }
        if (patternFreq.size() == 0) {
            resultIndices.push_back(left);
        }
    }

    return resultIndices;
  }
};


int main(int argc, char *argv[]) {
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}