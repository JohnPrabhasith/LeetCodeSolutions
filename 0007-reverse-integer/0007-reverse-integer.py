class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 1e9 or x <= -1e9:
            return 0
        s = str(x)
        if s[0] == '-':
            return -(int(s[1:][::-1]))
        else:
            return int(s[::-1])
        