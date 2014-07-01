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

int minMax (int sum){
	int raiz = sqrt(sum);

	while (sum%raiz != 0)
		raiz--;
	
	return raiz;
}

int solver (vector<int> roses, vector<int> lilies){
	int n;
	int r, l;
	int R = INF, C = 0;

	for (int i=1; i<pow(2, roses.size()); i++){
		r = 0;
		l = 0;
		for (int j=0; j<roses.size(); j++){
			if ( (i>>j) & 1){
				r += roses[j];
				l += lilies[j];
			}
		}
	
		if (abs(r-l) > 1) continue;

		int raiz = minMax (l + r);
		int r2 = (l + r)/raiz;

		if (abs(R-C) > abs(raiz-r2)){
			R = raiz;
			C = r2;
		}
	}
	return abs(R-C);
}

class BuyingFlowers {
	public:
	int buy(vector <int> roses, vector <int> lilies) {
		int ans =	solver (roses, lilies);

		if (ans == INF)
			return -1;
		else
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
			int roses[]               = {2, 4};
			int lilies[]              = {4, 2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int roses[]               = {2, 7, 3};
			int lilies[]              = {3, 4, 1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int roses[]               = {4, 5, 2, 1};
			int lilies[]              = {6, 10, 5, 9};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int roses[]               = {1, 208, 19, 0, 3, 234, 1, 106, 99, 17};
			int lilies[]              = {58, 30, 3, 5, 0, 997, 9, 615, 77, 5};
			int expected__            = 36;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int roses[]               = ;
			int lilies[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int roses[]               = ;
			int lilies[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int roses[]               = ;
			int lilies[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuyingFlowers().buy(vector <int>(roses, roses + (sizeof roses / sizeof roses[0])), vector <int>(lilies, lilies + (sizeof lilies / sizeof lilies[0])));
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
