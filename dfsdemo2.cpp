#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#define maxV 100

int visited[10];
// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    //printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
// A structure to represent a stack 
struct GRAPH{
	int nV; // so dinh
	int nE; // so canh
	int type; // 0 vo huong 1 co huong
	int adjMatrix[maxV][maxV]; // adjecency matrix
};

int inputFile(GRAPH &g){
	FILE *f = fopen("D:\\LTDT\\test.txt","rt");
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

void DFS(Stack* st,GRAPH g,int visited[],int s){
	push(st,s);			// Dua s vao Stack
	while (!isEmpty(st))		//Trong khi Stack chua rong
	{	
		int v = pop(st);		// Lay v ra khoi Stack
		if (visited[v] != 1)	// Neu v chua xet
		{
			printf("%d\n",v);
		    visited[v] = 1;
		    for (int i=g.nV; i>=1; i--)
				if (!visited[i] && g.adjMatrix[v][i] != 0)
					push(st,i);
		}
	}

}
// Driver program to test above functions 
int main() 
{ 
    Stack* stack = createStack(100); 

    GRAPH g;
	if(!inputFile(g))
		printf("Khong mo duoc file\n");
	else
		outputMT(g);
  
  	//visited is initialized to zero
    for(int i=1;i<=g.nV;i++)
        visited[i]=0;
 	
 	DFS(stack,g,visited,1);
    return 0; 
} 
