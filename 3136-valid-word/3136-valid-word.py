class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vowels = 'aeiou'
        consonents = 'bcdfghjklmnpqrstvwxyz'
        hasVowel = hasConsonent = haveOtherChar = False # = hasNumber

        for char in word:
            char = char.lower()
            if char in vowels:
                hasVowel = True
            if char in consonents:
                hasConsonent = True
            if not char.isalnum():
                haveOtherChar = True
            # if char.isnumeric():
            #     hasNumber = True
        if haveOtherChar:
            return False
        if hasVowel and hasConsonent:#   and hasNumber
            return True
        return False
