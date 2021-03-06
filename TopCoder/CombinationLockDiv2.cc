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
#include <cstring>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

int n;
int dp[51][451][2];

int run (vector<int> &d, int p, int x, int di){
	
	int move;

	if (dp[p][x][di] == -1){
		if (p == n){
			dp[p][x][di] = 0;
		}
		else {
			dp[p][x][di] = INF;	
			for (int i = 0; i < 2; i++){
				for (int y=0; y<=450; y++){
				
					if (i == 0){
						if ((d[p] + 9*y)%10 != 0)
							continue;
					}
					else {
						if ((d[p] + y)%10 != 0){
							continue;
						}
					}
				
					if (i != di){
						move = y;
					}
					else {
						move = max (y-x, 0);
					}

					dp[p][x][di] = min (dp[p][x][di], move + run (d, p+1, y, i));
				}
			}
		}
	}
	
	return dp[p][x][di];
}

int solver (string S, string T){
	
	n = S.size();
	vector<int> d (n, 0);

	for (int i=0; i<n; i++){
		if (S[i] >= T[i]){
			d[i] = S[i] - T[i];
		}
		else {
			d[i] = S[i] + 10 - T[i];
		}
	}

	memset (dp, -1, sizeof(dp));
	return run (d, 0, 0, 0);
}

class CombinationLockDiv2 {
	public:
	int minimumMoves(string S, string T) {
		return solver (S, T);	
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
			string S                  = "123";
			string T                  = "112";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1";
			string T                  = "7";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "607";
			string T                  = "607";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "1234";
			string T                  = "4567";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "020";
			string T                  = "909";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "4423232218340";
			string T                  = "6290421476245";
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			string T                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CombinationLockDiv2().minimumMoves(S, T);
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
