import sys

a, deb = raw_input().split('.')

d, b = deb.split('e')

a = list(a)
d = list(d)
b = int(b)

k = 0

while b > 0 and k < len(d):
    a += d[k]
    b -= 1
    k += 1

# print a, b, d, k

sa = sum(map(lambda x: int(x), a))
sd = sum(map(lambda x: int(x), d))

j = 0
while j < len(a) and a[j] == '0':
    j += 1
a = a[j:]

if sa == 0 and sd == 0:
    sys.stdout.write('0')
elif b > 0:
    # print 'entrou'
    while b > 0:
        a += ['0']
        b -= 1
        
    for i in a:
        sys.stdout.write(i)
        
elif k < len(d):
    # print 'entrou aqui'
    if a == []:
        a = ['0']
    for i in a:
        sys.stdout.write(i)
    
    if sd != 0:
        sys.stdout.write('.')
        for j in range(k, len(d)):
            sys.stdout.write(d[j])
else:
    for i in a:
        sys.stdout.write(i)
    
sys.stdout.write('\n')
