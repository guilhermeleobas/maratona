# One possible solution is to maintain a data structure with numbers that are divided by 3, 5 or both. At the end, just sum then and here is our answer
# Another solution is to see if the number is divide by 3 OR by 5
# if (number % 3 == 0):
#   sum += number
# elif (number % 5 == 0):
#   sum == number
# This way, we don't sum a number that is divide by both numbers twice.

from sets import Set

def main ():
  s = Set ()
  
  for i in range (3, 1000, 3):
    s.add (i)
  
  for i in range (5, 1000, 5):
    s.add (i)
    
  sum = 0
  for i in s:
    sum += i
  
  print sum
main ()
