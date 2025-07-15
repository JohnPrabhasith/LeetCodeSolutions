class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vowels = 'aeiou'
        consonents = 'bcdfghjklmnpqrstvwxyz'
        hasVowel = hasConsonent = haveOtherChar = False

        for char in word:
            if char in vowels:
                hasVowel = True
            if char in consonents:
                hasConsonent = True
            if not char.isalnum():
                haveOtherChar = True
        if haveOtherChar:
            return False
        if hasVowel and hasConsonent:
            return True
        return False
