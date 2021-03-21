#include "bits/stdc++.h"

using namespace std;
constexpr auto space = " ";

#define pr pair
#define vv vector
#define E cout << endl
#define mp make_pair
#define pb push_back
#define pf push_front
#define rdm(l, h) rand() % (h - l + 1) + l
#define ff(i, j) for (int i = 0; i < j; i++) // j should be previously defined

/**
 * Creates a class to compute the time elapsed
 *
 * st() is called to start the timer
 * fin() is called to finish the timer 
 */
class time_calc
{
	time_t t;
	float ts;

public:
	void st() { t = clock(); }
	auto fin()
	{
		ts = clock() - t;
		printf("~time->\t %f ms.\n", ts);
		return ts;
	}
};

/**
 * Struct to store the single node of the graph
 */
typedef struct node
{
	int uniqid = 0;
	int elcount = 1;
	struct node *next = NULL;
} node;
vv<vv<int>> mmatrix; // 0 for not edge

/**
 * the class to maintain the whole graph
 */
class graph
{
public:
	int n;
	vv<set<int>> adjlist;
	vv<vv<bool>> adjmat;
	vv<pr<pr<int, int>, int>> edgelist;
	vv<set<int>> kruskal_mst;
	vector<node> marray;
	int cost = 0, netsum = 0;

	/**
 	* @param values the total no. of nodes in the graph
 	*/
	graph(int n)
	{
		this->n = n;
		adjlist.resize(n);
		adjmat.resize(n, vv<bool>(n, false));
		marray.resize(n, {0, 1, NULL});
		ff(i, n) { marray[i].uniqid = i; }
		kruskal_mst.resize(n, {});
	}

	/**
	* Validity check for two nodes
 	*
 	* @param values indexes of the two nodes
 	* @return false: if invalid, true: if valid
 	*/
	bool check(int a, int b)
	{
		if ((a >= n || b >= n) || a == b)
		{
			return false;
		}
		return true;
	}

	/**
	* Adds an edge with weight into the graph, if possible
 	*
 	* @param values two nodes a & b, with their edge weight
 	* @return false: if invalid, true: if valid
 	*/
	bool addedge(int a, int b, int price)
	{
		if (!check(a, b))
		{
			// cout << "vertex error " << a << space << b << endl;
			return false;
		}
		else
		{
			if (adjmat[a][b])
			{
				// cout << "already present" << endl;
				return false;
			}
			adjmat[a][b] = adjmat[b][a] = true;
			adjlist[a].insert(b);
			adjlist[b].insert(a);
			edgelist.push_back(mp(mp(min(a, b), max(a, b)), price));
		}
		return true;
	}

	/**
	* Finds the value of integer into the marray
 	*
 	* @param values the node a
 	* @return the node
 	*/
	node *find(int a)
	{
		node *x = &marray[a];
		while (x->next)
		{
			x = x->next;
		}
		return x;
	}

	/**
	* Sum numbers in a vector.
 	*
 	* @param values unions two sub trees
 	*/
	void union_ab(node *a, node *b)
	{
		if (a->elcount < b->elcount)
		{
			swap(a, b);
		}

		// assume a.elcount > b.elcount, if not: read above line
		b->next = a;
		a->elcount += b->elcount;
	}

	/**
	* Adds an edge into our tree
 	*
 	* @param values indexes of the two nodes
 	*/
	void kruskal_addedge(pr<pr<int, int>, int> e)
	{
		auto a = e.first.first, b = e.first.second;
		auto ptr_a = find(a), ptr_b = find(b);

		if (ptr_a->uniqid == ptr_b->uniqid)
		{
			return;
		}

		// union_ab() and adding into kruskal_mst
		union_ab(ptr_a, ptr_b);
		cost += e.second;
		kruskal_mst[a].insert(b);
		kruskal_mst[b].insert(a);
	}

	/**
	* the main function to run the kruskal algorithm
 	*/
	void kruskal()
	{
		cout << "Elapsed time for running the kruskal algorithm." << endl;
		time_calc ktime;
		ktime.st();

		// Sorting edges based on their cost
		sort(edgelist.begin(), edgelist.end(), [](auto a, auto b) -> bool { return a.second < b.second; });

		// Kruskal AddEdge for each edge
		for (auto i : edgelist)
		{
			kruskal_addedge(i);
		}

		
		ofstream f("data.txt", ios::app);
		f << ktime.fin() << ", " << this->n << "\n"; 

		show_kruskal();
	}

	/**
	* Printing results
 	*/
	void show_kruskal()
	{
		for (auto i : edgelist)
		{
			netsum += i.second;
		}
		ff(i, n)
		{
			// cout << "Vertex " << i << " -> ";
			for (auto j : kruskal_mst[i])
			{
				// cout << j << space;
			}
			// E;
		}
		// E;
		cout << "Total cost of the network " << netsum << endl;
		cout << "The cost of the MST is " << cost << endl;
		cout << "Total savings are " << netsum - cost << endl;

		// Tree check()
		// very costly operation without the presence of root status
		// have to check that all nodes point to the same root or not
		auto real_root = find(0);
		bool istree = true;
		ff(i, n)
		{
			if (find(i) != real_root)
			{
				istree = false;
				break;
			}
		}

		if (istree)
		{
			cout << "Yes it is a TREE." << endl;
		}
		else
		{
			cout << "Unable to produce a tree due to insufficient edges." << endl;
		}
	}
};
