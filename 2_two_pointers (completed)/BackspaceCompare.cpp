using namespace std;

#include <iostream>
#include <string>

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    // TODO: Write your code here
    int p1 = str1.length()-1, p2 = str2.length()-1;
    
    while (1) {
        beforeCompare(str1, p1);
        beforeCompare(str2, p2);
        if (p1 < 0 && p2 < 0) {
            return true;
        } else if (p1 >= 0 && p2 >= 0) {
            if (str1[p1] == str2[p2]) {
                p1--;
                p2--;
                continue;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    return false;
  }

 private: 
  static void beforeCompare(const string &str, int &pos) {
      if (pos < 0 || str[pos] != '#') {
          return;
      }
      
      int count = 1;
      while (count >= 0) {
          count += (str[--pos] == '#' ? 1 : -1);
      }
    
      return;

  }
};


int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}
