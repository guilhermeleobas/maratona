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

bool prefix (string pre, string voc){
	
	for (int i=0; i<pre.size(); i++)
		if (pre[i] != voc[i])
			return false;

	return true;
}

bool suffix (string suf, string voc){
	
	int sz = voc.size();
	int j = 0;

	for (int i=suf.size()-1; i >= 0; i--){
		if (suf[i] != voc[sz-j-1])
			return false;
		j++;
	}

	return true;
}

bool middle (string bad, string voc){
	
	bool foi = false;

	for (int i=1; i<voc.size(); i++){
		if (voc[i] == bad[0]){
			foi = true;
			if (i + bad.size() == voc.size()) continue;
			for (int j=0; j<bad.size(); j++){
				if (voc[i+j] != bad[j]){
					foi = false;
					break;
				}
			}
			if (foi) return true;
		}
	}

	return false;
}

class BadVocabulary {
	public:
	int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary) {
		
		int cont = 0;

		for (int i=0; i<vocabulary.size(); i++){

			if ( prefix ( badPrefix, vocabulary[i] ) ){
				cont++;
			}
			else if ( suffix ( badSuffix, vocabulary[i] ) ){
				cont++;
			}
			else if (middle (badSubstring, vocabulary[i])){
				cont++;
		}

		return cont;
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
			string badPrefix          = "bug";
			string badSuffix          = "bug";
			string badSubstring       = "bug";
			string vocabulary[]       = {"buggy", "debugger", "debug"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string badPrefix          = "a";
			string badSuffix          = "b";
			string badSubstring       = "c";
			string vocabulary[]       = {"a", "b", "tco"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string badPrefix          = "cut";
			string badSuffix          = "sore";
			string badSubstring       = "scar";
			string vocabulary[]       = {"scary", "oscar"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string badPrefix          = "bar";
			string badSuffix          = "else";
			string badSubstring       = "foo";
			string vocabulary[]       = {"foofoofoo", "foobar", "elsewhere"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string badPrefix          = "pre";
			string badSuffix          = "s";
			string badSubstring       = "all";
			string vocabulary[]       = {"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vector <string>(vocabulary, vocabulary + (sizeof vocabulary / sizeof vocabulary[0])));
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
