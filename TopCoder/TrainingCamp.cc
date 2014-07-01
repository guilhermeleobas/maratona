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

bool comp (string req, string done){
	
	for (int i=0; i<req.size(); i++){
		if (req[i] == '-')
			continue;

		if (req[i] == 'X' && done[i] == '-')
			return false;
	}

	return true;
}


class TrainingCamp {
	public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
		
		vector<string> ans (attendance.size());

		for (int i=0; i<problemTopics.size(); i++){
			for (int j=0; j<attendance.size(); j++){
				if (comp (problemTopics[i], attendance[j])){
					ans[j] += 'X';
				}
				else {
					ans[j] += '-';
				}	
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			string attendance[]       = {"XXX",
 "XXX",
 "XX-"};
			string problemTopics[]    = {"---",
 "XXX",
 "-XX",
 "XX-"};
			string expected__[]       = {"XXXX", "XXXX", "X--X" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string attendance[]       = {"-XXXX",
 "----X",
 "XXX--",
 "X-X-X"};
			string problemTopics[]    = {"X---X",
 "-X---",
 "XXX--",
 "--X--"};
			string expected__[]       = {"-X-X", "----", "-XXX", "X--X" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string attendance[]       = {"-----",
 "XXXXX"};
			string problemTopics[]    = {"XXXXX",
 "-----",
 "--X-X"};
			string expected__[]       = {"-X-", "XXX" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string attendance[]       = {"-",
 "X",
 "X",
 "-",
 "X"};
			string problemTopics[]    = {"-",
 "X"};
			string expected__[]       = {"X-", "XX", "XX", "X-", "XX" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string attendance[]       = {"X----X--X",
 "X--X-X---",
 "--X-X----",
 "XXXX-X-X-",
 "XXXX--XXX"};
			string problemTopics[]    = {"X----X-X-",
 "-----X---",
 "-X----X-X",
 "-X-X-X---",
 "-----X---",
 "X-------X"};
			string expected__[]       = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string attendance[]       = ;
			string problemTopics[]    = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = TrainingCamp().determineSolvers(vector <string>(attendance, attendance + (sizeof attendance / sizeof attendance[0])), vector <string>(problemTopics, problemTopics + (sizeof problemTopics / sizeof problemTopics[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
