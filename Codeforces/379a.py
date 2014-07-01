# Codeforces New Year 2013 Contest;
# http://codeforces.com/contest/379/problem/A

import sys;

def main ():
	s = raw_input ();
	s = s.split (' ');
	resto = 0;
	result = 0;
	a = int(s[0])
	b = int(s[1])


	while (a > 0):
		a -=1
		resto += 1
		result += 1;

		if (resto >= b):
			resto -= b;
			a += 1;


	print result;

main ();