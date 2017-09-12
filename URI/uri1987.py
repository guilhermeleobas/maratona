
while True:
    try:
        n, m = raw_input().split(' ')
        a = map(int, list(m))

        if (sum(a) % 3 == 0):
            print sum(a), 'sim'
        else:
            print sum(a), 'nao'
    except:
        break
    
