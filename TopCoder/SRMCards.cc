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

void remove (vector<int> &v, int card){
	v.erase (v.begin());

	int a = -1, b = -1;

	for (int i=0; i<v.size(); i++){
		if (v[i] == card-1)
			a = i;

		if (v[i] == card+1)
			b = i;
	}


	if (a != -1) v.erase (v.begin()+a);
	if (b != -1) v.erase (v.begin()+b);

}

class SRMCards {
	public:
	int maxTurns(vector <int> cards) {
		int count = 0;

		sort (cards.begin(), cards.end());
		
		while (!cards.empty()){
			count++;
			remove (cards, *cards.begin());
		}
		return count;
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
			int cards[]               = {498, 499};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cards[]               = {491, 492, 495, 497, 498, 499};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cards[]               = {100, 200, 300, 400};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cards[]               = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int cards[]               = {118, 321, 322, 119, 120, 320};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int cards[]               = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int cards[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int cards[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int cards[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMCards().maxTurns(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])));
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
