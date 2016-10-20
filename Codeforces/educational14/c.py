import sys

s = raw_input().split('.')

try:
    p = list(s[0])
except:
    p = []
    
try:
    q = list(s[1])
except:
    q = []
    
a = 0
while (a < len(p) and p[a] == '0'):
    # p = p[1:]
    a += 1
p = p[a:]
    
b = len(q)-1
while (b >= 0 and q[b] == '0'):
    # q.pop()
    b -= 1
q = q[:b+1]
    
# print p, q
if p == [] and q == []:
    print 0
elif p != [] and q == []:
    l = len(p) - 1
    
    sys.stdout.write(p[0])
    
    zeros = len(p)-1
    while zeros >= 0 and p[zeros] == '0':
        zeros -= 1
        # p.pop()
    p = p[0:zeros+1]
    
    if l >= 1:
        if sum(map(lambda x: int(x), p[1:])) > 0:
            sys.stdout.write('.' + str.join('', p[1:]) + 'E' + str(l))
        else:
            sys.stdout.write('E' + str(l))
elif p == [] and q != []:
    l = -1
    zeros = 0
    while len(q) > 0 and q[zeros] == '0':
        # q = q[1:]
        zeros += 1
        l -= 1
        
    q = q[zeros:]
    
    sys.stdout.write(q[0])
    
    if len(q) == 1:
        sys.stdout.write('E' + str(l))
    else:
        sys.stdout.write('.' + str.join('', q[1:]) + 'E' + str(l))
else:
    l = 0
    l = len(p)-1
    q = p[1:] + q
    p = p[0]
    
    sys.stdout.write (p[0] + '.' + str.join('', q) )
    if l != 0:
        sys.stdout.write('E'+ str(l))

sys.stdout.write('\n')
    
