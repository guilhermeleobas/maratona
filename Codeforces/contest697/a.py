t, s, x = map(int, raw_input().split())

p = int((x-t)/s)
q = int((x-t-1)/s)

if t == x:
    print "YES"
elif (p > 0 and (t+p*s) == x):
    print "YES"
elif (q > 0 and (1 + t + q*s == x)):
    print "YES"
else:
    print "NO"
