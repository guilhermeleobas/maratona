n, x = map(int, raw_input().split())

total = x
unhappy = 0
for i in range(n):
    op, ice = raw_input().split()
    ice = int(ice)
    if op == '+':
        total += ice 
    else:
        if total - ice < 0:
            unhappy += 1
        else:
            total -= ice
            
print total, unhappy
