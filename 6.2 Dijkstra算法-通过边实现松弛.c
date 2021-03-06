#define  _CRT_SECURE_NO_WARNINGS  
//	时间：2021.11.3 23点11分
//	算法：Dijkstra算法
//	目的：求解单源最短路径（指定一个点（源点）到其余各个顶点的最短路径）
#include<stdio.h>
int main()
{
	int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 99999999;//用inf(infinity的缩写)存储一个我们认为的正无穷值
	//读入n和m,n表示顶点个数，m表示边的条数
	scanf("%d %d", &n, &m);

	//初始化
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
	//读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	//初始化dis数组
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];

	//book数组初始化
	for (i = 1; i <= n; i++)
		book[i] = 0;
	book[1] = 1;
	
	//Dijkstra算法核心语句
	for (i = 1; i <= n - 1; i++)//一共n个顶点，1号本身已经在p集合里面了，所以
	{						//只需要循环n-1次即可
		//找到离1号顶点最近的顶点
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)
			{
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}

	//输出最后的结果
	for (i = 1; i <= n; i++)
		printf("%d ", dis[i]);

	getchar(); getchar();
	return 0;
}