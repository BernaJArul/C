class Solution {
private:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: Valid combination found
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: Out of bounds or target exceeded
        if (index == candidates.size() || target < 0) {
            return;
        }
        
        // Choice 1: Include the current element (Index stays the same to allow reuse)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result);
            current.pop_back(); // Backtrack
        }
        
        // Choice 2: Skip the current element and move to the next candidate
        findCombinations(index + 1, target, candidates, current, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Optional: Sorting helps optimize pruning if needed, but not strictly required
        findCombinations(0, target, candidates, current, result);
        
        return result;
    }
};
