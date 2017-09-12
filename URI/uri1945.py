
def is_int(x):
    return isinstance(x, int)

d = dict()
last = 0

while True:
    try:
        s = raw_input().split(' ')
    except:
        print d[lvar]    
        break
    
    lvar = s[0]
    
    if '+' in s:
        p = s[2]
        q = s[4]
        if not is_int(p):
            p = d[p]
        if not is_int(q):
            q = d[q]
        d[lvar] = p + q
    else:
        d[lvar] = int(s[2])
