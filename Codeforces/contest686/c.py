# Use pypy 2.7 on codeforces
from math import log
def convert (x, base=7):
    if x < 7:
        return str(x)
    r = x%7
    d = x/7
    return str(convert(d)) + str(r)

def format(x, sz):
    while len(x) != sz:
        x = '0' + x
    return x

def unique (s):
    for i in range(len(s)):
        for j in range(i+1, len(s)):
            if s[i] == s[j]:
                return False
    return True

n, m = map(int, raw_input().split())
if n != 1:
    dn = int(log(n-1, 7)) + 1
else:
    dn = 1
if m != 1:
    dm = int(log(m-1, 7)) + 1
else:
    dm = 1

if (dn + dm > 7):
    print '0'
else:
    ans = 0
    for i in range(0, n):
        for j in range(0, m):
            hours = format(convert(i), dn)
            minutes = format(convert(j), dm)
            
            if unique(hours + minutes):
                ans += 1
    print ans
