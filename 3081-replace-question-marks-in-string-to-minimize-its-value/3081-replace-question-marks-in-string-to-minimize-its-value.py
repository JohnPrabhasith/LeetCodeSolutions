class Solution:
    def minimizeStringValue(self, s: str) -> str:
        n = len(s)
        alphaSet = 'abcdefghijklmnopqrstuvwxyz'
        mp = {ch : 0 for ch in alphaSet}
        
        for ch in s:
            if ch != '?':
                mp[ch] += 1     

        ### s = a?b?
        temp = ""
        for ch in s:
            if ch == '?':
                mini = min(mp, key = mp.get)
                temp += mini
                mp[mini] += 1

        temp = sorted(temp)
        ans = ""
        assIndex = 0
        for i in range(n):
            if s[i] == '?':
                ans += temp[assIndex]
                assIndex += 1
            else:
                ans += s[i]
        return ans
            

        
