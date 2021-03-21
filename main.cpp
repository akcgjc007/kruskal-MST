#include "main.h"

int main(int argc, const char *argv[])
{
	srand(time(0));

	/** Reading the input file **/
	int n = stoi(argv[1]);
	int p = stoi(argv[2]);

	ff(i, n)
	{
		vv<int> v;
		ff(j, n)
		{
			if (rand() % 100 < p)
			{
				v.push_back(rand() % 100);
				// cout << "1"; E;
			} else {
				// cout << "0"; E;
			}
		}

		mmatrix.pb(v);
	}

	/** Executing the algorithm **/
	time_calc t;
	t.st(); // Starting the time counter

	graph g(n);
	ff(i, n)
	{
		ff(j, n)
		{
			if (mmatrix[i][j] != -1)
				g.addedge(i, j, mmatrix[i][j]);
		}
	}

	g.kruskal(); // Calling the kruskal algorithm

	cout << "Elapsed time for the whole process." << endl;
	t.fin(); // Stopping the time counter
	return 0;
}
