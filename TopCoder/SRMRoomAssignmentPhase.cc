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

bool comp (int a, int b){
	return a > b;
}

void print (vector<int> v){
	
	for (int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;
}

class SRMRoomAssignmentPhase {
	public:
	int countCompetitors(vector <int> ratings, int K) {
		int me = ratings[0];

		sort (ratings.begin(), ratings.end(), comp);		

		int room = 0;

		for (int i=0; i<ratings.size(); i++){
			if (ratings[i] == me){
				room = i;
				break;
			}
		}

		
		int ans = 0;
		while (room >= 0){
			if (room - K >= 0)
				ans++;
			room -= K;
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
			int ratings[]             = {491, 981, 1199, 763, 994, 879, 888};
			int K                     = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int ratings[]             = {1024, 1000, 600};
			int K                     = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int ratings[]             = {505, 679, 900, 1022};
			int K                     = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int ratings[]             = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
			int K                     = 3;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int ratings[]             = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
			int K                     = 4;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int ratings[]             = {1197, 1198, 1196, 1195, 1199};
			int K                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
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
