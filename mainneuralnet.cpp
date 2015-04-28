#include <iostream>
#include "bpnet.h"
using namespace std;

#define BPM_ITER	2000

void main() {
	CBPNet bp;

	for (int i=0;i<BPM_ITER;i++) {
		bp.Train(0,0,1);
		bp.Train(0,1,0);
		bp.Train(1,0,0);
		bp.Train(1,1,0);
	}

	cout << "0,0 = " << bp.Run(0,0) << endl;
	cout << "0,1 = " << bp.Run(0,1) << endl;
	cout << "1,0 = " << bp.Run(1,0) << endl;
	cout << "1,1 = " << bp.Run(1,1) << endl;
}

/*
Output

0,0 = 0.000941056
0,1 = 0.0244922
1,0 = 0.0249771
1,1 = 0.963577
Press any key to continue

*/
