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

string solver (string &init, int T){

	int N = init.size();
	string alt = init;
	while (T--){
		init = alt;	

		for (int i=0; i<alt.size(); i++){
			int cont = 0;
			if (i == 0){
				if (init[N-1] == '1') cont++;
				if (init[0] == '1') cont++;
				if (init[1] == '1') cont++;
			}
			else if (i == N-1){
				if (init[i-1] == '1') cont++;
				if (init[i] == '1') cont++;
				if (init[0] == '1') cont++;
			}
			else {
				if (init[i] == '1') cont++;
				if (init[i+1] == '1') cont++;
				if (init[i-1] == '1') cont++;
			}

			if (cont==0 || cont == 1)
				alt[i] = '0';
			else
				alt[i] = '1';

		}

	}
	
	return alt;
}

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		return solver (init, T);	
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
			string init               = "01010";
			int T                     = 2;
			string expected__         = "00000";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string init               = "010101";
			int T                     = 5;
			string expected__         = "101010";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string init               = "111010";
			int T                     = 58;
			string expected__         = "111111";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string init               = "111111111";
			int T                     = 511;
			string expected__         = "111111111";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string init               = "110010000010111110010100001001";
			int T                     = 1000;
			string expected__         = "110000000001111110000000000001";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string init               = "00101110011";
			int T                     = 0;
			string expected__         = "00101110011";

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string init               = ;
			int T                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string init               = ;
			int T                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string init               = ;
			int T                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GameOfLifeDivTwo().theSimulation(init, T);
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
