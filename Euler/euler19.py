import calendar

def main ():
  
  sum = 0
  for i in range (1901, 2001, 1):
    for j in range (1, 13, 1):
      if (calendar.weekday (i, j, 1) == 6):
        sum += 1
      
  print sum
main ()
