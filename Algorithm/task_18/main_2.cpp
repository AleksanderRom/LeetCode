#include <algorithm>
#include <cassert>
#include <deque>
#include <string>
// #include <unordered_set>
// #include <unordered_map>

using namespace std::literals;

/* через итераторы, работает значительно дольше! */

// class Solution {
//    public:
//     std::string longestPalindrome(std::string s) {
//         auto it_st = s.begin();
//         auto it_ed = s.begin();
//         for (auto it = s.begin(); it < s.end(); ++it) {
//             bool is_first = true; 
//             auto prev = it;
//             auto next = it;
//             while (true) {
//                 if ( is_first == true && next < s.end() && *it == *(next + 1)) {
//                     std::string result(it_st, it_ed);
//                     ++next;
//                 } else if ((prev - 1) >= s.begin() && ((next + 1) < s.end()) && *(prev - 1) == *(next + 1)) {
//                     is_first = false;
//                     ++next; --prev;
//                 } else {
//                     if (next - prev > it_ed - it_st) {
//                         it_st = prev;
//                         it_ed = next;
//                     }
//                     break;
//                 }
//             }

//         }
//         return {it_st, it_ed + 1};
//     }
// };
class Solution { // через индексацию
   public:
    std::string longestPalindrome(std::string s) {
        std::string result;
        for (int i = 0; i < s.size(); ++i) {
            bool is_first = true; 
            std::deque<char> buf;
            int prev = 1, next = 1;
            buf.push_back(s[i]);
            while (true) {
                if ( is_first == true && i + next < s.size() && s[i] == s[i + next]) {
                    buf.push_back(s[i + next++]);
                } else if ((i - prev >= 0) && (i + next < s.size()) && s[i - prev] == s[i + next]) {
                    is_first = false;
                    buf.push_back(s[i + next++]);
                    buf.push_front(s[i - prev++]);
                } else {
                    if (buf.size() > result.size()) {
                        result.assign(buf.begin(), buf.end());
                    }
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    // assert("bbcccbb"s == s.longestPalindrome("abbcccbbbcaaccbababcbcabca"s));
    assert("aca"s == s.longestPalindrome("aaca"s));
    // assert("aca"s == s.longestPalindrome("aacabdkacaa"s));
    assert("cbababc"s == s.longestPalindrome("abbcccbbbcaaccbababcbcabca"s) || "bbcccbb"s == s.longestPalindrome("abbcccbbbcaaccbababcbcabca"s));
     auto rr = s.longestPalindrome("o"s);
    assert("a"s == s.longestPalindrome("a"s));
    auto rrr = s.longestPalindrome("oo"s);
    assert("oo"s == s.longestPalindrome("oo"s));
    assert("ooo"s == s.longestPalindrome("ooo"s));
    assert("sooos"s == s.longestPalindrome("sooos"s));
    assert("sooos"s == s.longestPalindrome("bppbfsooos"s));
    // assert("sooos"s == s.longestPalindrome("azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc"s));
    assert("aaaaa"s == s.longestPalindrome("aaaaa"s));
    // assert("cbababc"s == s.longestPalindrome("abbcccbbbcaaccbababcbcabca"s));
    assert("taat"s == s.longestPalindrome("taat"s));
    assert("tattarrattat"s == s.longestPalindrome("tattarrattat"s));
    assert("bab"s == s.longestPalindrome("babad"s) || "aba"s == s.longestPalindrome("babad"s));
    assert("aaaa"s == s.longestPalindrome("aaaa"s));
    assert("b"s == s.longestPalindrome("ab"s) || "a"s == s.longestPalindrome("ab"s));
    assert("b"s == s.longestPalindrome("b"s));
    assert("bb"s == s.longestPalindrome("cbbd"s));
}

        // std::string result;
