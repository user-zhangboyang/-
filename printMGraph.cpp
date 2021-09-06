#include"headfile.h"   //输出邻接矩阵图

void printMGraph(MGraph g){
	int i,j;
	for(i=0;i<g.vexnum;i++){
		for(j=0;j<g.vexnum;j++){
			printf("%d ",g.arcs[i][j]);
		}
		printf("\n");
	}
}
