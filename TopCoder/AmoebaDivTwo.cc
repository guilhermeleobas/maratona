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

int special (vector<string> &table){
	int c =0;
	
	for (int i=0; i<table.size(); i++){
		for (int j=0; j<table[i].size(); j++){
			if (table[i][j] == 'A') c++;
		}
	}

	return c;
}

bool check (vector<string> &table, int x, int y, int z, string di){
	
	if (di == "line"){
		for (int j=y; j<=z; j++){
			if (table[x][j] == 'M') return false;
		}
	}
	else {
		for (int i=y; i<=z; i++){
			if (table[i][x] == 'M') return false;
		}
	}
	

	return true;
}

class AmoebaDivTwo {
	public:
	int count(vector <string> table, int K) {
	
		int count = 0;

		if (K == 1){
			count = special (table);
			return count;
		}
		
		for (int i=0; i<table.size(); i++){
			for (int jo=0; jo<table[i].size(); jo++){
				for (int jf=jo; jf<table[i].size(); jf++){
					if (abs(jo-jf)+1 == K && check (table, i, jo, jf, "line")){
						count++;
					}
				}
			}
		}

		int col = table[0].size();

		for (int j=0; j<col; j++){
			for (int io = 0; io < table.size(); io++){
				for (int it=io; it<table.size(); it++){
					if (abs(io-it)+1 == K && check (table, j, io, it, "col")){
						count++;
					}
				}
			}
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
			string table[]            = {"MA"};
			int K                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string table[]            = {"AAA",
 "AMA",
 "AAA"};
			int K                     = 3;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string table[]            = {"AA",
 "AA",
 "AA"};
			int K                     = 2;
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string table[]            = {"MMM",
 "MMM",
 "MMM"};
			int K                     = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string table[]            = {"AAM",
 "MAM",
 "AAA"};
			int K                     = 1;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string table[]            = {"AAA",
 "AAM",
 "AAA"};
			int K                     = 2;
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string table[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string table[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string table[]            = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmoebaDivTwo().count(vector <string>(table, table + (sizeof table / sizeof table[0])), K);
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
