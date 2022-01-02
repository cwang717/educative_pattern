using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    vector<int> resultIndices;
    // TODO: Write your code here
    // O(N) time complexity. Better than the given solution.

    int wordLength = words[0].length();
    unordered_map<string, int> patternFreq;
    for (auto s:words) {
        patternFreq[s]++;
    }

    
    for (int i = 0; i < wordLength; i ++) {
        int left = i;
        int numDone = 0;
        unordered_map<string, int> currentFreq;
        for (int right = i; right < str.length() - wordLength + 1; right += wordLength) {
            string rightStr = str.substr(right, wordLength);
            if (patternFreq.find(rightStr) != patternFreq.end()) {
                if (currentFreq.find(rightStr) == currentFreq.end()) {
                    numDone++;
                }
                if (currentFreq[rightStr] == 1) {
                    numDone --;
                }
                currentFreq[rightStr]++;

                while (right - left + wordLength > wordLength*words.size()) {
                    if (checkPattern(str, patternFreq, left, wordLength)) {
                        if (currentFreq[str.substr(left, wordLength)] == 1) {
                            numDone--;
                        } 
                        currentFreq[str.substr(left, wordLength)]--;
                        if (currentFreq[str.substr(left, wordLength)] == 1) {
                            numDone++;
                        }
                    }
                    left += wordLength;
                }
                
                if (numDone == patternFreq.size()) {
                    resultIndices.push_back(left);
                }
            } else {
                left = right; 
                numDone = 0;
                currentFreq.clear();
            }
        }
    }

    return resultIndices;
  }


 private:
  static bool checkPattern(const string &str, const unordered_map<string, int> &patternFreq, int left, int wordLength) {
      return patternFreq.find(str.substr(left, wordLength)) != patternFreq.end();
  }
};


int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}