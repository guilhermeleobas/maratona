n = map(int, raw_input().split())[0]
m = map(int, raw_input().split())[0]

s = []
for i in range(n):
    s.append (map(int, raw_input().split())[0])

s.sort(reverse=True)

ans = 0
for i in s:
    m -= i
    ans += 1
    if m <= 0:
        break

print ans
