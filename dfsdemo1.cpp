#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
 
int main()
{
    int i,j;
    printf("Enter number of vertices:");
	scanf("%d",&n);
 
    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:");
   
	for(i=1;i<=n;i++)
       for(j=1;j<=n;j++){
       		printf("a[%d][%d] = ",i,j);
       		scanf("%d",&G[i][j]);
	}
			
 	for(i=1;i<=n;i++){
 		for(j=1;j<=n;j++){
       		printf("%4d",G[i][j]);
	    }
	   	printf("\n");
	}

    //visited is initialized to zero
   for(i=1;i<=n;i++)
        visited[i]=0;
 
    DFS(3);
    printf("\n");
    for(i=1;i<=n;i++)
    	printf("%4d",visited[i]);
    return 0;
}
 
void DFS(int i)
{
    int j;
	printf("\n%d",i);
    visited[i]=1;
	
	for(j=1;j<=n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}

