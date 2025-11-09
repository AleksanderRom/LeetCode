#include <algorithm>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

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
            if (idx != i && (*candidates_)[i] == (*candidates_)[i-1]) {
                continue;
            }
            if ((*candidates_)[i] > target_) {
                continue;
            }
            arr.push_back((*candidates_)[i]);
            RecursFind(i + 1, arr, currant + (*candidates_)[i]);
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
        vector v{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        auto rrr = s.combinationSum2(v, 30);
        // assert((vector<vector<int>>{{1,2,2}, {5}} == s.combinationSum2(v, 5)));
    }
    {
        Solution s;
        vector v{10,1,2,7,6,1,5};
        auto rrr = s.combinationSum2(v, 8);
        if (vector<vector<int>>{{1, 1, 6}, {1,2,5}, {1,7}, {2,6}} != rrr) {
            assert(false);
        }
        // assert((vector<vector<int>>{{1, 1, 6}, {1,2,5}, {1,7}, {2,6}} == s.combinationSum2(v, 8)));
    }
    {
        Solution s;
        vector v{2,5,2,1,2};
        assert((vector<vector<int>>{{1,2,2}, {5}} == s.combinationSum2(v, 5)));
    }
    {
        Solution s;
        vector v{6};
        assert((vector<vector<int>>{} == s.combinationSum2(v, 7)));
    }
}