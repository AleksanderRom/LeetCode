#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std::literals;

class Solution {
   public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
         step_ = words[0].size();
        max_count_ = words.size();
        for (auto& _word : words) {
            ++word_[_word];
        }

        for (auto it = s.begin(); it < s.end(); it += step_) {
            str_.emplace_back(std::move(std::string(it, it + step_)));
        }

        size_t i = 0;
        while (i++ != str_.size()) {
            if (word_.count(str_[right_])) {
                if (CheckWordToPosition(right_)) {
                    AddWordInWindows(right_);
                    ++right_;
                    CheckTotal();
                    continue;
                } else if (total_word_count_ == max_count_) {
                    result_.push_back(left_);
                    DeleteWordFromWindows(left_);
                    ++left_;
                    ++right_;
                    // CheckTotal();
                    continue;
                } else {
                    DeleteWordFromWindows(left_);
                    ++left_;
                }
            } else {
                ++right_;
                while (left_ != right_) {
                    DeleteWordFromWindows(left_);
                    ++left_;
                }
            }
        }
        return result_;
    }



    void CheckTotal() {
        if (total_word_count_ == max_count_) {
            result_.push_back(left_ * step_);
            DeleteWordFromWindows(left_);
            ++left_;
        }
    }

    void AddWordInWindows(size_t pos) {
        --word_[str_[pos]];
        ++using_word_[str_[pos]];
        ++total_word_count_;
    }
    void DeleteWordFromWindows(size_t pos) {
        if (total_word_count_ != 0 && word_.count(str_[pos])){
        ++word_[str_[pos]];
        --using_word_[str_[pos]];
        --total_word_count_;
        }
    }
    bool CheckWordToPosition(size_t pos) {
        return word_[str_[pos]] > 0 && total_word_count_ < max_count_;
    }

   private:
    std::vector<std::string> str_;
    std::unordered_map<std::string, int> word_;
    std::unordered_map<std::string, int> using_word_;
    size_t max_count_ = 0;
    size_t total_word_count_ = 0;
    size_t left_ = 0;
    size_t right_ = 0;
    int step_ = 0;
    std::vector<int> result_;
};

int main() {
    Solution s;
    std::string str = "barfoothefoobarman";
    std::vector<std::string> word{"foo"s, "bar"s};
    // auto r = s.findSubstring(str, word);
    assert((std::vector<int>{0, 9} == s.findSubstring(str, word)));
}

