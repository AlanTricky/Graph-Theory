#include<stdio.h>
#define maxV 100

struct DOTHI{
	int nV; // so dinh
	int nE; // so canh
	int type; // 0 vo huong 1 co huong
	int mtke[maxV][maxV]; // mtke
};
int inputFile(DOTHI &g){
	FILE *f = fopen("D:\\LTDT\\test.txt","rt");
	if(f == NULL)
		return 0;
	fscanf(f,"%d%d%d\n",&g.type,&g.nV,&g.nE);
	int dd,dc;
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			g.mtke[i][j] = 0;
		}
	}
	
	for(int k=1;k<=g.nV;k++){
		fscanf(f,"%d%d\n",&dd,&dc);		
		g.mtke[dd][dc] = 1;
		if(g.type == 0)
			g.mtke[dc][dd] = 1;
	}
	fclose(f);
	return 1;
}
void outputMT(DOTHI g){
	if(g.type == 0)
		printf("Do thi vo huong\n");
	else
		printf("Do thi co huong\n");
		
	printf("Do thi co %d dinh va %d canh\n",g.nV,g.nE);
	printf("Ma tran ke\n");
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			printf("\t%d",g.mtke[i][j]);
		}
		printf("\n");
	}
}
int outputFile(DOTHI g){
	FILE *fout = fopen("D:\\LTDT\\test1.txt","w");
	if(fout == NULL)
		return 0;
	if(g.type == 0)
		fprintf(fout,"Do thi vo huong\n");
	else
		fprintf(fout,"Do thi co huong\n");
		
	fprintf(fout,"Do thi co %d dinh va %d canh\n",g.nV,g.nE);
	fprintf(fout,"Ma tran ke\n");
	for(int i=1;i<=g.nV;i++){
		for(int j=1;j<=g.nV;j++){
			fprintf(fout,"\t%d",g.mtke[i][j]);
		}
		fprintf(fout,"\n");
	}
}

int bac(DOTHI g,int v){
	if(g.type == 1)
		return -1;
	if(v<=0 || v>g.nV)
		return -1;
	int bac=0;
	for(int k=0;k<g.nV;k++){
		if(g.mtke[v][k] == 1)
			bac++;
	}
	return bac;
}
int bacRa(DOTHI g,int v){
	if(g.type == 0)
		return -1;
	if(v<=0 || v>g.nV)
		return -1;
	int bac=0;
	for(int k=0;k<g.nV;k++){
		if(g.mtke[v][k] == 1)
			bac++;
	}
	return bac;
}
int bacVao(DOTHI g,int v){
	if(g.type == 0)
		return -1;
	if(v<=0 || v>g.nV)
		return -1;
	int bac=0;
	for(int k=0;k<g.nV;k++){
		if(g.mtke[k][v] == 1)
			bac++;
	}
	return bac;
}
int main(){
	DOTHI g;
	if(!inputFile(g))
		printf("Khong mo duoc file\n");
	else
		outputMT(g);
	if(!outputFile(g))
		printf("Khong mo duoc file\n");
	return 0;
}
