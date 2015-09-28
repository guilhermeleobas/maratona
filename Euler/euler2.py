# Generate all numbers that belongs to the fibonacci sequence and are less than 4.000.000
# sum the numbers where the position of it in the array is divide by 2 (or even)

def main ():
  fn = []
  fn.append (1)
  fn.append (2)
  
  while True:
    sz = len(fn)
    if (fn[sz-1] + fn[sz-2] > 4000000):
      break
    fn.append (fn[sz-1] + fn[sz-2])
  
  sum = 0
  for i in range (0, len(fn), 1):
    if (fn[i] % 2 == 0):
      sum += fn[i]
  
  print sum
main ()
