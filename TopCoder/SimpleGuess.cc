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

int solver (vector<int> hints){
	
	int m = 0;
	for (int i=0; i<hints.size(); i++){
		for (int j=i+1; j<hints.size(); j++){
			int x = (hints[i] + hints[j])/2;
			int y = max(hints[i], hints[j]) - x;
			int mul = x*y;
			if ((x+y)==max(hints[i],hints[j]) && (x-y)==min(hints[i],hints[j]))
				m = max (m, mul);
		}
	}

	return m;
}

class SimpleGuess {
	public:
	int getMaximum(vector <int> hints) {
		return solver (hints);
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
			int hints[]               = { 1, 4, 5 };
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hints[]               = { 1, 4, 5, 8 };
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hints[]               = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			int expected__            = 20;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hints[]               = { 2, 100 };
			int expected__            = 2499;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int hints[]               = { 50, 58, 47, 57, 40 };
			int expected__            = 441;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int hints[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hints[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int hints[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SimpleGuess().getMaximum(vector <int>(hints, hints + (sizeof hints / sizeof hints[0])));
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
