class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        lesser, greater, equal = [], [], []
        for num in nums:
            if num < pivot:
                lesser.append(num)
            elif num == pivot:
                equal.append(num)
            else:
                greater.append(num)
        return lesser + equal + greater