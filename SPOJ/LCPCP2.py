
def exp_mod (base, exp, mod):
    if (mod == 1):
        return 0;
    
    number = 1;
    
    while (exp):
        if (exp & 1):
            number = (number * base) % mod;
        exp >>= 1
        base = (base * base) % mod;
    
    return number;

t = map(int, raw_input().split())[0]

for i in range(t):
    b, e, m = map(int, raw_input().split());
    print str(i+1) + '.',
    print exp_mod (b, e, m);
