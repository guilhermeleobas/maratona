#!/usr/bin/env python 

def main():
	
	fib = []

	fib.append (0);
	fib.append (1);

	for i in range (2, 5001):
		fib.append (fib[i-1] + fib[i-2]);

	n = map(int, raw_input().split (' '));
	print fib[n[0]]

main()
