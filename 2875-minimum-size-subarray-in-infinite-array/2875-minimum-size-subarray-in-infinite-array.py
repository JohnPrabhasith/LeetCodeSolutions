class Solution:
    def minSizeSubarray(self, arr: List[int], target: int) -> int:
        prefix = {0:-1}
        n = len(arr)
        sum_ = 0

        no_of_windows, target = divmod(target, sum(arr))
        res = inf

        if target == 0: return no_of_windows * n

        for i, val in enumerate(arr*2):
            sum_ += val
            need =  sum_ - target
            if need in prefix:
                res = min(res, i - prefix[need])
            prefix[sum_] = i
        
        return ((no_of_windows * n) + res) if res != inf else -1
        

