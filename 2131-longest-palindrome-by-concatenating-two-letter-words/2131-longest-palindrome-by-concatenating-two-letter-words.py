from collections import Counter
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ans = 0
        s = set()
        freq = Counter(words)
        center = False
        for word in list(freq.keys()):
            rev = word[::-1]
            if word == rev:
                pairs = freq[word] // 2
                ans += pairs * 4
                freq[word] -= pairs * 2
                if freq[word] == 1:
                    center = True
            else:
                if rev in freq:
                    pairs = min(freq[word], freq[rev])
                    ans += pairs * 4
                    freq[word] -= pairs
                    freq[rev] -= pairs
        if center:
            ans += 2

        return ans



            
            
