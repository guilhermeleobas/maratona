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

double solver (int d, int x, int y){
	
	int a = max (abs(x)-d, 0);
	int b = max (abs(y)-d, 0);
	
	return sqrt(a*a + b*b);
}

class MagicalGirlLevelOneDivTwo {
	public:
	double theMinDistance(int d, int x, int y) {
		return solver (d, x, y);
	}
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int d                     = 5;
			int x                     = 10;
			int y                     = 10;
			double expected__         = 7.0710678118654755;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int d                     = 5;
			int x                     = 10;
			int y                     = 3;
			double expected__         = 5.0;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int d                     = 5;
			int x                     = -8;
			int y                     = -6;
			double expected__         = 3.1622776601683795;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int d                     = 5;
			int x                     = 3;
			int y                     = 2;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int d                     = 24;
			int x                     = 24;
			int y                     = -24;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int d                     = 345;
			int x                     = -471;
			int y                     = 333;
			double expected__         = 126.0;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int d                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int d                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int d                     = ;
			int x                     = ;
			int y                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MagicalGirlLevelOneDivTwo().theMinDistance(d, x, y);
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
