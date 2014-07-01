#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

bool ispal (int x){
	
	string s = to_string (x);

	int i = 0, j = s.size()-1;

	while (true){
		if (i > j) break;
		if (s[i] != s[j]) return false;
		
		i++;
		j--;
	}

	return true;
}

int getNext (int n){
	
	int pal = INF;
	for (int i=n; i<100000; i++){
		if (ispal (i)){
			pal = i;
			break;
		}
	}

	pal = abs (n-pal);

	for (int i=n; i>= 1; i--){
		if (ispal (i)){
			pal = min (pal, abs(n-i));
			break;
		}
	}


	return pal;
}

class PalindromizationDiv2 {
	public:
	int getMinimumCost(int X) {
		
		if (X >= 0 && X <= 9) return 0;
		if (ispal(X)) return 0;
		
		int ans = getNext (X);

		
		return ans;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int X                     = 25;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X                     = 12321;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X                     = 40;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X                     = 2011;
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X                     = 0;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromizationDiv2().getMinimumCost(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
