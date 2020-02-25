#include<iostream>
#include<vector>
#include<unordered_map>

class UnionFind
{
private:
	int* id;
	int* sz;
	int size;
	int components;
public:
	UnionFind(int size)
	{
		this->size = size;
		components = size;
		id = new int[size];
		sz = new int[size];
		for (int i = 0; i < size; i++)
		{
			id[i] = i;
			sz[i] = 1;
		}
	}

	int find(int p)
	{
		int root = p;
		while (root != id[root])
			root = id[root];

		while (p != root)
		{
			int next = id[p];
			id[p] = root;
			p = next;
		}
		return root;
	}

	void unify(int p, int q)
	{
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2)
			return;
		else if (sz[root1] < sz[root2])
		{
			sz[root2] += sz[root1];
			id[root1] = root2;
		}
		else
		{
			sz[root1] += sz[root2];
			id[root2] = root1;
		}
		components--;
	}

	bool connected(int p, int q)
	{
		return find(p) == find(q);
	}

	int componentSize(int p)
	{
		return sz[find(p)];
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << id[find(i)] << " ";
		std::cout << std::endl;
	}

	~UnionFind()
	{
		delete[]sz;
		delete[]id;
	}
};


struct Edge {
	int vertex1;
	int vertex2;
	int weight;
	Edge(int v1, int v2, int w) :vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {
	std::vector<int> vertices;
	std::vector<Edge> edges;
};

std::vector<Edge> sort(std::vector<Edge> a)
{
	for (int i = a.size() - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (a[j].weight > a[j + 1].weight)
			{
				Edge temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
	return a;
}

void Kruskal(Graph g)
{
	std::unordered_map<int, char> dic = {
		{ 0, 'A' },{ 1, 'B' },{ 2, 'C' },{ 3, 'D' },{ 4, 'E' },{ 5, 'F' }
	};
	std::vector<Edge> A;
	UnionFind x(g.vertices.size());
	g.edges = sort(g.edges);
	for (Edge e : g.edges)
	{
		if (!x.connected(e.vertex1, e.vertex2))
		{
			A.push_back(e);
			x.unify(e.vertex1, e.vertex2);
		}
	}
	for (int i = 0; i < A.size(); i++)
		std::cout << dic[A[i].vertex1] << " -- " << dic[A[i].vertex2] << " : " << A[i].weight << std::endl;
}


void main()
{
	UnionFind x(7);
	x.print();
	x.unify(1, 2);
	x.unify(2, 0);
	x.unify(3, 4);
	x.unify(4, 3);
	x.unify(5, 6);
	x.unify(6, 2);
	x.print();
	x.unify(6, 4);
	x.print();

	std::vector<int> t;
	for (int i = 0; i < 6; i++)
		t.push_back(i);
	Graph g;
	g.vertices = t;

	g.edges.push_back(Edge(0, 1, 4));
	g.edges.push_back(Edge(0, 5, 2));
	g.edges.push_back(Edge(5, 1, 5));
	g.edges.push_back(Edge(2, 1, 6));
	g.edges.push_back(Edge(2, 5, 1));
	g.edges.push_back(Edge(5, 4, 4));
	g.edges.push_back(Edge(3, 4, 2));
	g.edges.push_back(Edge(3, 2, 3));

	Kruskal(g);


	std::cin.get();
}