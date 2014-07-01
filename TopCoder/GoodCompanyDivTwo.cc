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

bool valid (vector<int> sup, vector<int> work, int start){
	set<int> s;

	for (int i=0; i<sup.size(); i++){
		if (sup[i] == start || i == start){
			if (s.find (work[i]) != s.end()){
				return false;
			}
			else{
				s.insert (work[i]);
			}
		}
	}

	return true;
}

class GoodCompanyDivTwo {
	public:
	int countGood(vector <int> superior, vector <int> workType) {
		
		int ans = 0;

		for (int i=0; i<superior.size(); i++){
			if (valid (superior, workType, i))
				ans++;
		}

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
			int superior[]            = {-1, 0};
			int workType[]            = {1, 2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int superior[]            = {-1, 0};
			int workType[]            = {1, 1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int superior[]            = {-1, 0, 1, 1};
			int workType[]            = {1, 4, 3, 2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int superior[]            = {-1, 0, 1, 0, 0};
			int workType[]            = {3, 3, 5, 2, 2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int superior[]            = {-1, 0, 1, 1, 1, 0, 2, 5};
			int workType[]            = {1, 1, 2, 3, 4, 5, 3, 3};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int superior[]            = {-1, 0, 0, 1, 1, 3, 0, 2, 0, 5, 2, 5, 5, 6, 1, 2, 11, 12, 10, 4, 7, 16, 10, 9, 12, 18, 15, 23, 20, 7, 4};
			int workType[]            = {4, 6, 4, 7, 7, 1, 2, 8, 1, 7, 2, 4, 2, 9, 11, 1, 10, 11, 4, 6, 11, 7, 2, 8, 9, 9, 10, 10, 9, 8, 8};
			int expected__            = 27;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int superior[]            = ;
			int workType[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int superior[]            = ;
			int workType[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int superior[]            = ;
			int workType[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GoodCompanyDivTwo().countGood(vector <int>(superior, superior + (sizeof superior / sizeof superior[0])), vector <int>(workType, workType + (sizeof workType / sizeof workType[0])));
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
