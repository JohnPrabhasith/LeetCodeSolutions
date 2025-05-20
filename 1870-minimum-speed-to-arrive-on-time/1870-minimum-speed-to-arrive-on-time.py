class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n: int = len(dist)

        def isValid(speed):
            ans = 0
            for dst in dist[:-1]:
                ans += ceil(dst/speed)
            ans += dist[-1]/speed
            return ans <= hour

        l = 1
        r = 10**7
        while(l <= r):
            mid = (l+r)//2
            if isValid(mid):
                r = mid - 1
            else:
                l = mid + 1
        return l if l <= 1e7 else -1


