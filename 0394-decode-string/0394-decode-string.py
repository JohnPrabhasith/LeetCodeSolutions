class Solution:
    def decodeString(self, s: str) -> str:
        str_ = ""
        num_ = 0
        stk = []

        for x in s:
            if x == '[':
                stk.append(str_)
                stk.append(num_)
                num_ = 0
                str_ = ""
            elif x == ']':
                number = stk.pop()
                prev = stk.pop()
                str_ = prev + (number * str_)
            elif x.isnumeric():
                num_ = num_ * 10 + int(x)
            else:
                str_ += x


        return str_
































# num_stk: List[int] = []
        # str_stk: List[str] = []
        # n = len(s)
        # ans: str = ""
        # for x in s:
        #     if x == ']':
        #         num = num_stk.pop()
        #         str_ = ""
        #         while (len(str_stk) > 0) and ((str_stk[-1] != '[') or (not str_stk[-1].isalpha())):
        #             str_ += str_stk.pop()
        #         if len(str_stk) > 0:
        #             str_stk.pop()
        #         # print(type(num)) 
        #         # print(type(str_))
        #         # temp = ""
        #         for i in range(int(num)):
        #             ans += str_
        #         str_stk.append(ans)
        #     elif x.isalpha():
        #         str_stk.append(x)
        #     elif x.isnumeric():
        #         num_stk.append(x)
        