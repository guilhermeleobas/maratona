def main ():
  
  a = 1
  b = 1
  index = 2
  while True:
    c = a + b
    index += 1
    if (len(str(c)) == 1000):
      print index
      break
    else:
      a = b
      b = c

  
main ()
