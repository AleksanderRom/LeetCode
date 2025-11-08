#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](auto l, auto r) { return l > r; });

        candidates_ = &candidates;
        target_ = target;
        vector<int> arr;
        RecursFind(0, arr, 0);


        return result_;
    }

    void RecursFind(int idx, vector<int>& arr, int currant) {
        if (currant == target_) {
            result_.push_back(arr);
            return;
        }

        if (currant > target_) {
            return;
        }

        for (auto i = idx; i < candidates_->size(); ++i) {
            if ((*candidates_)[i] > target_) {
                continue;
            }
            arr.push_back((*candidates_)[i]);
            RecursFind(i, arr, currant + (*candidates_)[i]);
            arr.pop_back();
        }

        return;
    }

   private:
    vector<int>* candidates_;
    int target_;
    vector<vector<int>> result_;
};

void Test();

int main() {
    Test();
}

void Test() {
    {
        Solution s;
        vector v{2, 3, 5};
        auto rrr = s.combinationSum(v, 8);
        assert((vector<vector<int>>{{5, 3}, {3, 3, 2}, {2, 2, 2, 2}} == s.combinationSum(v, 7)));
    }
    {
        Solution s;
        vector v{2, 3, 6, 7};
        assert((vector<vector<int>>{{5, 3}, {3, 3, 2}, {2, 2, 2, 2}} == s.combinationSum(v, 7)));
    }
    {
        Solution s;
        vector v{2, 3, 6, 7};
        assert((vector<vector<int>>{{3, 2, 2}, {7}} == s.combinationSum(v, 7)));
    }
}