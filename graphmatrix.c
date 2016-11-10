/*
 * Complete Graph operation using adjancency matrix:
 * BFS
 * DFS
 * Prims
 * Kruskals
 * Dijkstra
 * 
 * Breadth First Search code from:
 * Data Structure and Algorithms: puntambekar textbook
 *
 * Depth First Search code from:
 * Data Structure and Algorithms: puntambekar textbook
 *
 * kruskals code from:
 * http://scanftree.com/Data_Structure/kruskal's-algorithm
 *
 * prims code from:
 * http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
 *
 * Dijkstra code from:
 * http://www.c-program-example.com/2011/10/c-program-to-solve-dijkstras-algorithm.html
 *
 * compiled and edited by:
 * Mohd Saufy Rohmad
 * Computer Engineering UiTM
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIZE 7
#define TRUE 1
#define FALSE 0
#define INFINITY 999

/* 
 * manually entered adjacency matrix
 *
 * int g[SIZE][SIZE]={{0,10,10,0},
		{10,0,0,10},
		{10,0,0,10},
		{0,10,10,0}};



int g[SIZE][SIZE] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
*/

int g[SIZE][SIZE]={{0,22,16,8,0,0,0},
		{22,0,20,0,2,7,2},
		{16,20,0,10,4,3,10},
		{8,0,10,0,0,6,0},
		{0,2,4,0,0,0,4},
		{0,7,3,6,0,0,9},
		{0,0,10,0,4,9,0}};

/*==global variables====*/

int visit[SIZE];
int parent[SIZE];//for kruskals
int dist[SIZE];//for dijkstra
int Q[SIZE];//for bfs
int S[SIZE];//for dfs
int front,rear;//for bfs

/*====end of global variables===*/

/*==== function prototype ==========*/

void bfs(int);
void dfs(int);
void prims(int[SIZE][SIZE]);
void kruskals(int [SIZE][SIZE]);
void dijkstra(int,int, int[SIZE][SIZE],int [SIZE]);
int find(int);
int uni(int,int);

/*=======end of declaration area =======*/

int main()
{
	int v1,v2,inp;
	char ans='y';
	printf("adj matrix for the graph is: \n");
	for(v1=0;v1<SIZE;v1++)
	{
		for(v2=0;v2<SIZE;v2++)
		{
			printf("%d ",g[v1][v2]);
		}
			printf("\n");
	}
	do
	{
		printf("ENTER SELECTION 1: BFS 2:DFS 3:Prims 4:Kruskals 5:Dijkstra => ");
		scanf("%d",&inp);
		switch(inp)
		{
		case 1:	
			for(v1=0;v1<SIZE;v1++)
			visit[v1]=FALSE;
			printf("Enter the vertex from which you want to traverse: ");
			scanf("%d",&v1);
			if(v1 >= SIZE)
				printf("Invalid vertex\n");
			bfs(v1);
			break;
		case 2:	
			for(v1=0;v1<SIZE;v1++)
			visit[v1]=FALSE;
			printf("Enter the vertex from which you want to traverse: ");
			scanf("%d",&v1);
			if(v1 >= SIZE)
				printf("Invalid vertex\n");
			dfs(v1);
			break;
		case 3:
			prims(g);
			break;
		case 4:
			kruskals(g);
			break;
		case 5:
			dijkstra(SIZE,0,g,dist);
			break;
		default:
			printf("INPUR ERROR, 1 to 5 only.\n");
		}	
		scanf("%c",&ans);
		printf("CONTINUE WITH OTHER SELECTION?(y/n):");
		scanf("%c",&ans);
	}while(ans=='y');
	return 0;
}

int minKey(int key[], int mstSet[])
{
   // Initialize min value
      int min = INT_MAX, min_index;
       int v; 
           for (v = 0; v < SIZE; v++)
              if (mstSet[v] == FALSE && key[v] < min)
                       min = key[v], min_index = v;
                          return min_index;
}

int printMST(int parent[], int n, int graph[SIZE][SIZE])
{
   printf("Edge   Weight\n");
	int i;   
	for (i = 1; i < SIZE; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void bfs(int v1)
{
	int v2;
	visit[v1]=TRUE;
	front=rear=-1;
	Q[++rear]=v1;
	while(front !=rear)
	{
		v1=Q[++front];
		printf("%d \n",v1);
		for(v2=0;v2<SIZE;v2++)
		{
			if(g[v1][v2]>0 && visit[v2]==FALSE)
			{
				Q[++rear]=v2;
				visit[v2]=TRUE;
			}
		}
	}
}
 			
void dfs(int v1)
{
	int v2;
	printf("%d\n",v1);
	S[v1]=TRUE;
	for(v2=0;v2<SIZE;v2++)
		if(g[v1][v2]>0 && S[v2]==FALSE)
			dfs(v2);
}

void prims(int graph[SIZE][SIZE])
{
     int parent[SIZE]; // Array to store constructed MST
     int key[SIZE];   // Key values used to pick minimum weight edge in cut
     int mstSet[SIZE];  // To represent set of vertices not yet included in MST
	int i;
	int count; 
	int v;
     // Initialize all keys as INFINITE
     for (i = 0; i < SIZE; i++)
        key[i] = INT_MAX, mstSet[i] = FALSE;
                  
     // Always include first 1st vertex in MST.
         key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
         parent[0] = -1; // First node is always root of MST 
                      
     // The MST will have V vertices
       for (count = 0; count < SIZE-1; count++)
     { 
     //Pick the minimum key vertex from the set of vertices
     // not yet included in MST
      int u = minKey(key, mstSet);
                                                   
     // Add the picked vertex to the MST Set
        mstSet[u] = TRUE;
                                                                                       
     // Update key value and parent index of the adjacent vertices of
     //the picked vertex. Consider only those vertices which are not yet
     // included in MST
     	for (v = 0; v < SIZE; v++)
                                                                                                                
     // graph[u][v] is non zero only for adjacent vertices of m
     // mstSet[v] is false for vertices not yet included in MST
     // Update the key only if graph[u][v] is smaller than key[v]
     	if (graph[u][v] && mstSet[v] == FALSE && graph[u][v] <  key[v])
		parent[v]  = u, key[v] = graph[u][v];
	} 
       	printMST(parent, SIZE, graph);
}

void kruskals(int cost[SIZE][SIZE])
{
	int i,j,k,a,b,u,v,ne=1;
	int min,mincost=0;
	
	for(i=1;i<=SIZE;i++)
	{
		for(j=1;j<=SIZE;j++)
		{
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
//	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < SIZE)
	{
		for(i=1,min=999;i<=SIZE;i++)
		{
			for(j=1;j <= SIZE;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}

void dijkstra(int n,int v,int g[SIZE][SIZE],int dist[SIZE])
{
	int i,j;
 	int u,count,w,flag[10],min;
 	
	for(i=1;i<=SIZE;i++)
  		for(j=1;j<=SIZE;j++)
  		{
   			if(g[i][j]==0)
    			g[i][j]=INFINITY;
  		}
 	//dij(n,v,cost,dist);
 	for(i=1;i<=n;i++)
  		flag[i]=0,dist[i]=g[v][i];
 		count=2;
 	while(count<=n)
 	{
  		min=99;
  		for(w=1;w<=n;w++)
   			if(dist[w]<min && !flag[w])
    			min=dist[w],u=w;
  		flag[u]=1;
  		count++;
  		for(w=1;w<=n;w++)
   			if((dist[u]+g[u][w]<dist[w]) && !flag[w])
    			dist[w]=dist[u]+g[u][w];
 	}
 	printf("\n Shortest path:\n");
 	for(i=1;i<=n;i++)
  	if(i!=v)
   	printf("%d->%d,cost=%d\n",v,i,dist[i]);
}

int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}








