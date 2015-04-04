
def maximo (m, s):
  v = [0]*m
  pos = 0

  if (m == 1 and s == 0):
    return 0
  if (s == 0):
    return -1
  while True:
    if (s <= 0):
      break
    if (pos == len(v)):
      break
    if (s > 9):
      v[pos] = 9
      s -= 9
    else:
      v[pos] = s
      s = 0
    pos += 1
  
  if (s > 0):
    return -1

  num = 0
  for i in v:
    num = num*10 + i
  return num

def minimo (m, s):
  v = [0]*m
  pos = len(v)-1
  v[0] = 1
  
  if (m == 1 and s == 0):
    return 0
  if (s == 0):
    return -1

  s -= 1

  while True:
    if (s <= 0):
      break
    if (pos < 0):
      break;
    
    if (pos == 0 and s > 8):
      return -1
    elif (s > 9):
      v[pos] += 9
      s -= 9
    else:
      v[pos] += s
      s = 0
    pos -= 1

  if (s > 0):
    return -1;

  num = 0
  for i in v:
    num = num*10 + i

  return num
m, s = raw_input ().split(' ')

m = int(m)
s = int(s)

max = maximo (m, s)
min = minimo (m, s)

print min, max
