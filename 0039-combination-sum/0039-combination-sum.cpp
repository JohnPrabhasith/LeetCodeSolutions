// if (cursum > target || ind == n) {
//             if(cursum == target){
//                 arr.push_back(temp);
//             }
//             return;
//         }
//             temp.push_back(candidates[ind]);
//             recursion(arr,candidates,temp,ind,cursum+candidates[ind],target,n);

//             temp.pop_back();
//             recursion(arr,candidates,temp,ind+1,cursum,target,n);
//         return;




















class Solution {
public:

    void recursion(vector<vector<int>> &arr,vector<int> &candidates,vector<int> &temp,int ind,int target,int n){
        if(ind == n || target <= 0) {
            if(target == 0) {
                arr.push_back(temp);
            }
            return;
        }

        temp.push_back(candidates[ind]);
        recursion(arr, candidates, temp, ind, target - candidates[ind], n);

        temp.pop_back();
        recursion(arr, candidates, temp, ind + 1, target, n);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> arr;
       vector<int> temp;

       recursion(arr,candidates,temp,0,target,candidates.size());

       return arr;
    }
};