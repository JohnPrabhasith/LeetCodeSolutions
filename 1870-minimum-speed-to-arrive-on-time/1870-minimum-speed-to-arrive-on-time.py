class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n: int = len(dist)
        if hour < n-1:
            return -1

        def isValid(val) -> bool:
            ans: float = 0
            for i in range(n):
                ans += float(dist[i])/val
                if i < n-1:
                    ans = ceil(ans)
                if ans > hour:
                    return False
            return ans <= hour

        l = 1
        r = int(1e7)
        while(l <= r):
            mid = (l+r)//2
            ans = isValid(mid)
            # if(ans == hour):
            if ans:
                r = mid - 1
            else:
                l = mid + 1
        return l if l <= 1e7 else -1


