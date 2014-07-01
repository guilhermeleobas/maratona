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

void remove_1 (vector<int> &v){

	for (int i=1; i<=8; i++)
		v[i] = 0;
}

void remove_2 (vector<int> &v){
	for (int i=1; i<=4; i++)
		v[i] = 0;
	
	for (int i=9; i<=12; i++)
		v[i] = 0;
}

void remove_3 (vector<int> &v){
	v[1] = 0;
	v[2] = 0;
	v[5] = 0;
	v[6] = 0;
	v[9] = 0;
	v[10] = 0;
	v[13] = 0;
	v[14] = 0;
}

void remove_4 (vector<int> &v){
	for (int i=1; i<=15; i+=2)
		v[i] = 0;
}

class NumberMagicEasy {
	public:
	int theNumber(string answer) {
		vector<int> v (17, 1);

		for (int i=0; i<answer.size(); i++)
			if (answer[i] == 'N'){
				if (i == 0)
					remove_1 (v);
				else if (i == 1)
					remove_2 (v);
				else if (i == 2)
					remove_3 (v);
				else
					remove_4 (v);
			}

			for (int i=1; i<=16; i++)
				if (v[i] == 1)
					return i;
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
			string answer             = "YNYY";
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string answer             = "YNNN";
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string answer             = "NNNN";
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string answer             = "YYYY";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string answer             = "NYNY";
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string answer             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string answer             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string answer             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumberMagicEasy().theNumber(answer);
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
