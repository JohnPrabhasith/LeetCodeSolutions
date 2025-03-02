class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = []

        for i in range(len(nums)):
            heapq.heappush(pq, -nums[i])
        
        f = k-1

        while(f > 0):
            heapq.heappop(pq)
            f -= 1
        return -pq[0]