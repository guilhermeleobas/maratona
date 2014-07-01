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
typedef pair<int, char> par;

class Filtering {
	public:
	vector <int> designFilter(vector <int> sizes, string outcome) {
	
		vector<par> v;

		for (int i=0; i<sizes.size(); i++){
			v.push_back (make_pair (sizes[i], outcome[i]));
		}

		sort (v.begin(), v.end());

		int a=0, b=0, inv=0;

		for (int i=0; i<v.size(); i++){
			if (v[i].second == 'A'){
				if (a == 0 && b == 0){
					a = v[i].first;
					b = v[i].first;
				}
				
				if (v[i].first < a)
					a = v[i].first;

				if (v[i].first > b)
					b = v[i].first;

				if (inv >= a && inv <= b){
					vector<int> p;
					return p;
				}
			}
			else {
				if (a == 0 && b == 0) continue;

				if (v[i].first >= a && v[i].first <= b){
					vector<int> p;
					return p;
				}

				inv = v[i].first;
			}
		}

		vector<int> p;
		
		if (inv >= a && inv <= b)
			return p;

		p.push_back (a);
		p.push_back (b);
		return p;
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
			int sizes[]               = {3, 4, 5, 6, 7};
			string outcome            = "AAAAA";
			int expected__[]          = {3, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int sizes[]               = {3, 4, 5, 6, 7};
			string outcome            = "AARAA";
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int sizes[]               = {3, 4, 5, 6, 7};
			string outcome            = "RAAAA";
			int expected__[]          = {4, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int sizes[]               = {68,57,7,41,76,53,43,77,84,52,34,48,27,75,36};
			string outcome            = "RARRRARRRARARRR";
			int expected__[]          = {48, 57 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int sizes[]               = {26,81,9,14,43,77,55,57,12,34,29,79,40,25,50};
			string outcome            = "ARAAARRARARARAA";
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sizes[]               = ;
			string outcome            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int sizes[]               = ;
			string outcome            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int sizes[]               = ;
			string outcome            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = Filtering().designFilter(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), outcome);
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
