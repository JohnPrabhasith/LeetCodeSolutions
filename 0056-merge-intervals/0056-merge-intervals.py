class Solution:
    def merge(self, arr: List[List[int]]) -> List[List[int]]:
        res = []
        # for i in range(1, n):
        #     if not res or (res[i-1][1] >= arr[i][0]):
        #         res.append([res[i-1][0], arr[i][1]])
        #     else:
        #         res.append(arr[i])

        arr.sort(key = lambda x: x[0])

        for interval in arr:
            if not res or res[-1][1] < interval[0]:
                res.append(interval)
            else:
                res[-1][1] = max(res[-1][1], interval[1])
            
        return res