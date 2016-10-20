a= raw_input()

f = [
    ('o', 'o'),
    ('v', 'v'),
    ('w', 'w'),
    ('x', 'x'),
    ('A', 'A'),
    ('H', 'H'),
    ('I', 'I'),
    ('M', 'M'),
    ('O', 'O'),
    ('T', 'T'),
    ('U', 'U'),
    ('V', 'V'),
    ('W', 'W'),
    ('X', 'X'),
    ('Y', 'Y'),
    ('b', 'd'),
    ('d', 'b'),
    ('p', 'q'),
    ('q', 'p')
]

ans = 0

for (i, j) in zip(a, a[::-1]):
    if (i, j) in f:
        ans += 1
        
if ans == len(a):
    print "TAK"
else:
    print "NIE"
