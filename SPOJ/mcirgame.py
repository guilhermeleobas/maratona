#!/usr/bin/env python 
#  http://www.spoj.com/problems/MCIRGAME/

def calc (pd, size):
	i = 0

	while (i < size):
		pd[size] += pd[i]*pd[size-i-1]
		i+=1
	
def main():

	pd = [0]*152
	pd[0] = 1
	pd[1] = 1


	for i in range (2, 151):
		calc (pd, i)

	n = 0
	while (True):
		n = map(int, raw_input().split(' '))
		if (n[0] == -1):
			break
		print pd[n[0]]

main()
