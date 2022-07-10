class Solution {
public:
    void traverse(vector<int>&arr, vector<bool>& memo, int pos){
        if (pos < 0 || pos >= arr.size())
            return;
        if (memo[pos])
            return;
        memo[pos] = 1;
        traverse(arr, memo, pos+arr[pos]);
        traverse(arr, memo, pos-arr[pos]);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> memo(arr.size(), false);
        traverse(arr, memo, start);
        for (int i=0; i<arr.size(); i++){
            if (arr[i] == 0 && memo[i] == true){
                return true;
            }
        }
        return false;
    }
};
