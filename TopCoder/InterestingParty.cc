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

class InterestingParty {
	public:
	int bestInvitation(vector <string> first, vector <string> second) {
		
		int count = 0;

		for (int i=0; i<first.size(); i++){
			string s = first[i];
			int aux = 1;
			for (int j=i+1; j<first.size(); j++){
				if (first[j] == s || second[j] == s)
					aux++;
			}
			count = max (count, aux);
		}

		for (int i=0; i<second.size(); i++){
			string s = second[i];
			int aux = 1;

			for (int j=i+1; j<second.size(); j++){
				if (first[j] == s || second[j] == s)
					aux++;
			}

			count = max (count, aux);
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
			string first[]            = {"fishing", "gardening", "swimming", "fishing"};
			string second[]           = {"hunting", "fishing", "fishing", "biting"};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string first[]            = {"variety", "diversity", "loquacity", "courtesy"};
			string second[]           = {"talking", "speaking", "discussion", "meeting"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string first[]            = {"snakes", "programming", "cobra", "monty"};
			string second[]           = {"python", "python", "anaconda", "python"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string first[]            = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
			string second[]           = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
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
