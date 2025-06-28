#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std::literals;

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    s_ = std::move(s);
    step_ = words[0].size();
    max_count_ = words.size();
    for (auto &_word : words) {
      ++word_[_word];
    }

    std::string str;

    for (int i = 0; i < step_; ++i) {
      left_ = right_ = i;
      ResetWords();
      while (right_ + step_ <= s_.size()) {

        str = s_.substr(right_, step_);
        if (word_.count(str)) {
          if (total_word_count_ < max_count_) {
            AddRightWord(str);
            right_ += step_;
            CheckTotal(str);
            continue;
          } else {
            DeleteLeftWord(str);
            right_ += step_;
          }
        } else {
          right_ += step_;
          left_ = right_;
          ResetWords();
        }
      }
    }

    return result_;

  }
  void ResetWords() {
    if (total_word_count_ > 0) {
      for (auto &[us_str, inter] : using_word_) {
        if (inter > 0) {
          word_[us_str] += inter;
          inter = 0;
        }
      }
    }
    total_word_count_ = 0;
  }

  void CheckTotal(std::string &str) {
    if (total_word_count_ == max_count_) {
      result_.push_back(left_);
      DeleteLeftWord(s_.substr(left_, step_));
      left_ += step_;
    }
  }

  void AddRightWord(const std::string &str) {
    if (word_[str] > 0) {
      --word_[str];
      ++using_word_[str];
      ++total_word_count_;
    } else {
    //   ResetWords();
      while (left_ != right_) {
        std::string ss = s_.substr(left_, step_);
        DeleteLeftWord(ss);
        left_ += step_;
        if (ss == str) {
            break;
        }
      }
      AddRightWord(str);
      //   left_ = right_;
    }
  }
  void DeleteLeftWord(const std::string &str) {
    if (total_word_count_ != 0 && word_.count(str)) {
      ++word_[str];
      --using_word_[str];
      --total_word_count_;
    }
  }

private:
  std::string s_;
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
  {
    Solution s;
    std::string str = "aaaaaaaa";
    std::vector<std::string> word{"aa", "aa", "aa"};
    assert((std::vector<int>{0, 2, 1} == s.findSubstring(str, word)));
  }
  {
    Solution s;
    std::string str = "wordgoodgoodgoodbestword";
    std::vector<std::string> word{"word", "good", "best", "good"};
    assert((std::vector<int>{8} == s.findSubstring(str, word)));
  }
  {
    Solution s;
    std::string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    std::vector<std::string> word{"fooo"s, "barr"s, "wing"s, "ding"s, "wing"s};
    assert((std::vector<int>{13} == s.findSubstring(str, word)));
  }
  {
    Solution s;
    std::string str = "barfoofoobarthefoobarman";
    std::vector<std::string> word{"foo"s, "bar"s, "the"s};
    assert((std::vector<int>{6, 9, 12} == s.findSubstring(str, word)));
  }
  {
    Solution s;
    std::string str = "barfoothefoobarman";
    std::vector<std::string> word{"foo"s, "bar"s};
    assert((std::vector<int>{0, 9} == s.findSubstring(str, word)));
  }
}
