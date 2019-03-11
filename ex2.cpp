#include<stdio.h>
#include<string.h>
#define maxV 100
// A structure to represent a stack 
struct GRAPH{
	int nV; // so dinh
	int nE; // so canh
	int type; // 0 vo huong 1 co huong
	int adjMatrix[maxV][maxV]; // adjecency matrix
};

/*int inputFile(GRAPH &g){
	FILE *f = fopen("D:\\LTDT\\test1.txt","rt");
	if(f == NULL)
		return 0;
	fscanf(f,"%d%d%d\n",&g.type,&g.nV,&g.nE);
	
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			g.adjMatrix[i][j] = 0;
		}
	}
	
	int dd,dc;
	for(int k=1;k<=g.nE;k++){
		fscanf(f,"%d%d\n",&dd,&dc);	
		printf("%d%d\n",dd,dc);	
		g.adjMatrix[dd][dc] = 1;
		if(g.type == 0)
			g.adjMatrix[dc][dd] = 1;
	}
	fclose(f);
	return 1;
}*/

int inputFile(GRAPH &g){
	
	FILE *f = fopen("D:\\LTDT\\test1.txt","rt");
	if(f == NULL)
		return 0;
	fscanf(f,"%d%d%d",&g.type,&g.nV,&g.nE);
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			fscanf(f,"%d",&g.adjMatrix[i][j]);
		}
	}
	fclose(f);
	return 1;
}


void outputMT(GRAPH g){
	if(g.type == 0)
		printf("Do thi vo huong\n");
	else
		printf("Do thi co huong\n");
		
	printf("Do thi co %d dinh va %d canh\n",g.nV,g.nE);
	printf("Ma tran ke\n");
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			printf("\t%d",g.adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void DFS(GRAPH g,int visited[],int i)
{
    int j;
	printf("\n%d",i);
    visited[i]=1;
	
	for(j=1;j<=g.nV;j++)
       if(!visited[j]&&g.adjMatrix[i][j]==1)
            DFS(g,visited,j);
}
int main() 
{ 
    GRAPH g;
    
	if(!inputFile(g))
		printf("Khong mo duoc file\n");
	else
		outputMT(g);
  
  	//visited is initialized to zero
  	int visited[g.nV];
    for(int i=1;i<=g.nV;i++)
        visited[i]=0;
 	
 	DFS(g,visited,1);
 	
 	
    return 0; 
} 
