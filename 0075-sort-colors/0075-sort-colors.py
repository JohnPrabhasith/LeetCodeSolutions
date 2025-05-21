class Solution:
    def sortColors(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """          
        n = len(arr)
        l, r, i = 0, n-1, 0

        while(i <= r): 
            if arr[i] == 0:
                arr[i], arr[l] = arr[l], arr[i]
                l += 1
                i += 1
            elif arr[i] == 1:
                i += 1
            else:
                arr[i], arr[r] = arr[r], arr[i]
                r -= 1
            
        
        