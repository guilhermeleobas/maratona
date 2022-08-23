class Solution:
    def myAtoi(self, s: str) -> int:
        val = 0
        neg = pos = 0
        num = False
        for e in s.strip():
            if e in (' ', '+', '-') and num == True:
                break
            if e == ' ' or e not in ('-', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
                break
            elif e == '-':
                neg += 1
            elif e == '+':
                pos += 1
            elif e == '0' and val == 0:
                num = True
            else:
                num = True
                val = val*10 + int(e)
        if (neg and pos) or (neg > 1 or pos > 1):
            return 0
        sign = (-1 if neg == 1 else 1)
        val = sign * val
        INT_MIN = -2**31
        INT_MAX = (2**31) - 1
        
        if val < INT_MIN:
            return INT_MIN
        elif val > INT_MAX:
            return INT_MAX
        else:
            return val
