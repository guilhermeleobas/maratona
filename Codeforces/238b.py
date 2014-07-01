#!/usr/bin/env python

def get_next_R (domino, i):
	Rx = len(domino);
	for j in range(i+1, len(domino)):
		if (domino[j] == 'R'):
			Rx = j
		elif (domino[j] == 'L'):
			return Rx
	return Rx

def main():
	n = raw_input()
	domino = raw_input()

	L = -1
	R = -1
	cnt = 0
	for i in range(len(domino)):
		
		if (domino[i] == 'L'):
			if (L == -1 and get_next_R (domino, i) == len(domino) and R != -1 and abs(i-R-1)%2 != 0):
				cnt = cnt + 1
			L = i
			R = get_next_R (domino, i)
			if (R < len(domino) and abs(L-R-1)%2 != 0):
				cnt = cnt + 1
			elif (R == len(domino)):
				cnt = cnt + abs(L-R)-1 
		
		if (domino[i] == 'R' and L == -1):
			cnt = cnt - i
			R = i

		if (L == -1 and R == -1):
			cnt = cnt + 1
		
	print cnt
	

main()
