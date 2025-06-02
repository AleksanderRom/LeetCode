#include <algorithm>
#include <cassert>
#include <deque>
#include <map>
#include <string>
// #include <unordered_set>
// #include <unordered_map>

using namespace std::literals;

#include <vector>
// Алгори Манакреа
class Solution {
   public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) return s;

        std::string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        int n = t.size();
        std::vector<int> p(n, 0);  // p[i] = радиус палиндрома с центром в i
        std::pair<int, int> key;

        int l = 0, r = -1;  // текущий самый правый палиндром (l..r)
        for (int i = 0; i < n; i++) {
            // Используем зеркальное отражение, если i внутри текущего палиндрома
            int k = 0;
            if (i > r) {
                k = 1;
            } else {
                k = std::min(p[l + r - i], r - i + 1);
            }

            // Расширяем палиндром в обе стороны
            while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) {
                k++;
            }

            p[i] = k;
            if (key.second < k) {
                key.second = k;
                key.first = i;
            }
            // Обновляем самый правый палиндром
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        std::string result;
        for (int i = 0; i < key.second * 2 - 1; ++i) {
            char buf = t[key.first - (key.second) + 1 + i];
            if (buf != '#') {
                result.push_back(buf);
            }
        }

        return result;
    }
};

//    if ((i - prev >= 0) && (i + next < s_new.size()) && s_new[i - prev] == s_new[i + next]) {

int main() {
    Solution s;
    // assert("bbcccbb"s == s.longestPalindrome("abbcccbbbcaaccbababcbcabca"s));
    // auto xx =  s.longestPalindrome("aaca"s);
    assert("aca"s == s.longestPalindrome("aaca"));
    assert("abacaba"s == s.longestPalindrome("abacabadfdnrt"s));
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
