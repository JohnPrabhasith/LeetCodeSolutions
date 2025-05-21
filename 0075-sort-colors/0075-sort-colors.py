class Solution:
    def sortColors(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """

        def swap(a, b):
            arr[a], arr[b] = arr[b], arr[a]
            
        n = len(arr)
        l, r, i = 0, n-1, 0

        while(i <= r): 
            if arr[i] == 0:
                swap(l, i)
                l += 1
            if arr[i] == 2:
                swap(r, i)
                r -= 1
                i -= 1
            i += 1
        
        