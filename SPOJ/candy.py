#!/usr/bin/env python 

def main():
	while True:

		n = raw_input().split (' ');
		n = int(n[0])

		if (n == -1):
			break
	
		numbers = []

		for i in range (0, n):
			num = raw_input().split (' ');
			num = int(num[0])
			numbers.append (num)
		
		sum = 0

		for i in range (0, n):
			sum = sum + numbers[i]
	
		
		t = sum/n
		ans = 0

		if (t*n == sum):
			for i in range (0, n):
				if (t > numbers[i]):
					ans = ans + t - numbers[i]
			print ans
		else:
			print "-1"



main()
