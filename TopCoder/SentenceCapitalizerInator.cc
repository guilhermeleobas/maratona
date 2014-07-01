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


class SentenceCapitalizerInator {
	public:
	string fixCaps(string paragraph) {
		paragraph[0] -= 32;
		for (int i=0; i<paragraph.size(); i++){
			if (paragraph[i] == '.' && i+1 < paragraph.size())
				paragraph[i+2] -= 32;
		}

		return paragraph;
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string paragraph          = "hello programmer. welcome to topcoder.";
			string expected__         = "Hello programmer. Welcome to topcoder.";

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string paragraph          = "one.";
			string expected__         = "One.";

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string paragraph          = "not really. english. qwertyuio. a. xyz.";
			string expected__         = "Not really. English. Qwertyuio. A. Xyz.";

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string paragraph          = "example four. the long fourth example. a. b. c. d.";
			string expected__         = "Example four. The long fourth example. A. B. C. D.";

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string paragraph          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string paragraph          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string paragraph          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SentenceCapitalizerInator().fixCaps(paragraph);
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
