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

bool is_v (string &s){
	for (int i=0; i<s.size(); i++)
		if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'))
			return false;

	return true;
}

bool vogal (char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;

	return false;
}

int next (string s, int cont){
	for (int i=cont; i<s.size(); i++){
		if (s[i] == ' ')
			return i-1;
	}
	return s.size()-1;
}

vector<string> split (string s){
	vector<string> v;
	string k;
	for (int i=0; i<s.size(); i++){
		int cont = next (s, i);
		
		k.clear();

		k.append (s, i, cont-i+1);

		i = cont+1;
		v.push_back (k);
	}
	
	return v;
}

class TxMsg {
	public:
	string getMessage(string original) {
		vector<string> v = split (original);
		string ans;
		for (int i=0; i<v.size(); i++){
			if (is_v (v[i])){
				ans += v[i];
				if (i+1 < v.size()) ans += ' ';
			}
			else {
				for (int j=0; j<v[i].size(); j++){
					if (j == 0){
						if (!vogal (v[i][j])){
							ans += v[i][j];
						}
					}
					else {
						if (vogal (v[i][j-1]) && !vogal (v[i][j])){
							ans += v[i][j];
						}
					}
				}
				if (i+1 < v.size()) ans += ' ';
			}
		}

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
			string original           = "text message";
			string expected__         = "tx msg";

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string original           = "ps i love u";
			string expected__         = "p i lv u";

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string original           = "please please me";
			string expected__         = "ps ps m";

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string original           = "back to the ussr";
			string expected__         = "bc t t s";

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string original           = "aeiou bcdfghjklmnpqrstvwxyz";
			string expected__         = "aeiou b";

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string original           = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string original           = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string original           = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TxMsg().getMessage(original);
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
