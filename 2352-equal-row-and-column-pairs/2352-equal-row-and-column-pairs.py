class Solution:
    def equalPairs(self, arr: List[List[int]]) -> int:
        n = len(arr)
        ans = 0
        mp = {}
        for i in range(n):
            temp = []
            for j in range(n):
                temp.append(arr[i][j])
            mp[tuple(temp)] = mp.get(tuple(temp), 0) + 1
        
        for i in range(n):
            vect = []
            for j in range(n):
                vect.append(arr[j][i])
            vect = tuple(vect)
            if vect in mp:
                ans += mp[vect] 
        
        return ans
        
        
        