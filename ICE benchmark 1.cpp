//============================================================================
// Name        : ICE.cpp
// Author      : Paul Hrycewicz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int main() {

	clock_t time_start = std::clock();	// clock() = cpu time
// clock() provides CPU time on Linux-based systems
// clock() gives wall time on Windows systems
// for Windows CPU time, see "windows getprocesstimes"
										// windows:  elapsed (wall) time
	int startWallTime = time(0);
//
// code to measure goes here, for example:
//

	int i;
	int j;
//	cout <<"enter a number " << endl;
//	cin >> i;
	for (i=0;i<100000;i++)
	{
		j = j + time(0);
	}

//
// end of code to measure
//
	clock_t time_end = std::clock();
	clock_t time_cpu_ms = 1000.0 * (time_end - time_start) / CLOCKS_PER_SEC;
	cout << "CPU time used: " << time_cpu_ms << " ms" << endl;
	cout << "CPU time used: " << time_cpu_ms / 1000 << " s" << endl;

	int endWallTime = time(0);
	cout << "elapsed time " << endWallTime - startWallTime << " s" << endl;





	return 0;
}
