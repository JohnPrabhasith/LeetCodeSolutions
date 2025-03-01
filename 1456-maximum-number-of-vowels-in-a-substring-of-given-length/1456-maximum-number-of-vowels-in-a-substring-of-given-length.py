class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}

        maxVowels = 0
        for i in range(k):
            if s[i] in vowels:
                maxVowels += 1

        vowelCount = maxVowels
        l, r = 0, k
        while(r < len(s)):
            if s[l] in vowels:
                vowelCount -= 1
            l += 1
            if s[r] in vowels:
                vowelCount += 1
            maxVowels = max(maxVowels, vowelCount)
            r += 1
        return maxVowels
                