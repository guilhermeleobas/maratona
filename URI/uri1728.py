import re

while True:
    s = raw_input()
    a = re.split('(\d+)\+(\d+)\=(\d+)', s)[1:-1]
    
    x = int(a[0][::-1])
    y = int(a[1][::-1])
    z = int(a[2][::-1])
    
    if (x == 0 and y == 0 and z == 0):
        print 'True'
        break
    
    if (x+y == z):
        print 'True'
    else:
        print 'False'
    
