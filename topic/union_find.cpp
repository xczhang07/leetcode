Union Find 这个topic是有关图论的，主要讲解在无向图中，找出有多少个环。打个比方， 下列图中
1——2 5
|  |
3——4
有两个环:[1,2,3,4] 构成了一个环，5构成了一个环。所得的答案就是 2.
这个算法主要有两个 function：
find：针对图中的一个节点，找出它所属的集合。find function主要是应用于比较两个节点是否在同一个集合中。
union：如果两个节点属于同一个集合，那么union function会将这两个节点加入同一个子集合中。

Union Find 的核心算法如下，针对输入图中的N个节点，建立一个长度为N+1（数组是从0开始的）的数组，针对每一个下标分别标记成为不同的标记，比如上述例子中，我们建立一个长度
为6的数组 [0,0,0,0,0,0]，针对每个节点赋值，使其成为[0,1,2,3,4,5,6], 之后针对每个节点，如果其下标通过find function计算得到每个元素相对应的flag。
总环数初始值赋予 N（n个节点），假设每个节点都是一个自环，如果找到两个元素在一个集合中，总环数减1.
int flag1 = find(e1);
int flag2 = find(e2);
如果 flag1 != flag2, 将其中的一个值赋给另一个，这样其中一个算是另一个的父节点，证明两个节点属于同一个集合，针对每个节点这样推断下来，如果有環的话，
他们的root总是相同的，这时我们的环数就要减1。反之环数不变。

// A union-find algorithm to detect cycle in a graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
	int src;
	int dest;
};

struct Graph
{
	int V; // the number of node in the graph
	int E; // the number of edge in the graph
	struct Edge* edge; // an array of the edge consist of the graph
};

/* create a graph according to the input vertical number and edge number */
struct Graph* createGraph(int V, int E)
{
	struct Graph* myGraph = (struct Graph*)malloc(sizeof(struct Graph));
	myGraph->V = V;
	myGraph->E = E;
	myGraph->edge = (struct Edge*)malloc(myGraph->E * sizeof(struct Edge));
	return myGraph;
}

/* the function to find the subset of an input element */
int find(int parent[], int idx)
{
	while (parent[idx] != idx)
	{
		parent[idx] = parent[parent[idx]];
		idx = parent[idx];
	}
	return idx;
}

void Union(int parent[], int x, int y)
{
	int idx = find(parent, x);
	int idy = find(parent, y);
	if (idx != idy)
		parent[idx] = idy;
	return;
}

int getCycleNumber(struct Graph* graph)
{
	int ret = graph->V;
	// allocate memory for a parent array to set the flag of each element in the graph
	int* parent = (int*)malloc(graph->V*sizeof(int));

	// set flag for each node of the graph
	for (int i = 0; i < graph->V; ++i)
		parent[i] = i;

	for (int i = 0; i < graph->E; ++i)
	{
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		if (x != y)
		{
			Union(parent, x, y);
			ret--;
		}
	}
	return ret;
}
// Driver program to test above functions
int main()
{
	/*
	Let us create a graph as following and test it
	0---1
	|   |  
	2---3
	*/
	int V = 4;
	int E = 4;
	struct Graph* graph = createGraph(V, E);

	// add edge for the graph
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 2;
	graph->edge[2].dest = 3;

	graph->edge[3].src = 3;
	graph->edge[3].dest = 1;

	int num = getCycleNumber(graph);
	printf("the graph has cycle number is: %d\n", num);
	getchar();
	return 0;
}

reference：
http://www.geeksforgeeks.org/union-find/
