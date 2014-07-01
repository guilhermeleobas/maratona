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


class TheProgrammingContestDivTwo {
	public:
	vector <int> find(int T, vector <int> requiredTime) {
		
		sort (requiredTime.begin(), requiredTime.end());

		int tempo = 0;
		int solver = 0;
		int pass = 0;

		for (int i=0; i<requiredTime.size(); i++){
			if (pass + requiredTime[i] > T) break;
			tempo += pass + requiredTime[i];
			pass += requiredTime[i];
			solver++;
		}

		vector<int> ans (2, 0);
		ans[0] = solver;
		ans[1] = tempo;

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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int T                     = 74;
			int requiredTime[]        = {47};
			int expected__[]          = {1, 47 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int T                     = 74;
			int requiredTime[]        = {4747};
			int expected__[]          = {0, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int T                     = 47;
			int requiredTime[]        = {8, 5};
			int expected__[]          = {2, 18 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int T                     = 47;
			int requiredTime[]        = {12, 3, 21, 6, 4, 13};
			int expected__[]          = {5, 86 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int T                     = 58;
			int requiredTime[]        = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8};
			int expected__[]          = {10, 249 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int T                     = 100000;
			int requiredTime[]        = {100000};
			int expected__[]          = {1, 100000 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int T                     = ;
			int requiredTime[]        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TheProgrammingContestDivTwo().find(T, vector <int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
