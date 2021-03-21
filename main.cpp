#include "main.h"

int main()
{
	srand(time(0));
	
	/** Reading the input file **/
	int n = 100;
	ff(i, n)
	{
		vv<int> v;
		ff(j, n)
		{
			v.push_back(rand()%n);
		}
	
		mmatrix.pb(v);
	}

	/** Executing the algorithm **/
	time_calc t;
	t.st(); // Starting the time counter

	graph g(40);
	ff(i, 40)
	{
		ff(j, 40)
		{
			if (mmatrix[i][j] != -1)
				g.addedge(i, j, mmatrix[i][j]);
		}
	}

	g.kruskal(); // Calling the kruskal algorithm

	t.fin(); // Stopping the time counter
	return 0;
}
