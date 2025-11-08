#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<string>& words, char x) {
        std::vector<int> result;
        result.reserve(words.size());
        // for (auto& word : words) {
            for (int i = 0; i < words.size(); ++i) {
                if (std::string::npos != words[i].find(x)) {
                    result.push_back(i);
                }
            }

      return result;  
    }
};