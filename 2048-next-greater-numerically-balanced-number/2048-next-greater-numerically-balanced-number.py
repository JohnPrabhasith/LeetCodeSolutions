class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def isBalanced(n):
            mp = [0] * 10
            while(n != 0):
                index = (n%10)
                mp[index] += 1
                if mp[index] > index:
                    return False
                n //= 10
            for i in range(len(mp)):
                if mp[i] != 0 and mp[i] != i:
                    return False
            return True
        x = n+1
        while not isBalanced(x):
            x += 1
        return x
