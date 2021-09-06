#include"headfile.h"  //输出邻接表图

int printALGraph(ALGraph G) {
	int i;
	ArcNode *p;
	for(i=0;i<G.vexnum;i++){
		printf("%c ",G.vertices[i]);
		p=G.vertices[i].firstarc;
		while(p){
			printf("%c(权值)%d ",p->vex,*(p->info));
			p=p->nextarc;
		}
		printf("\n");
	}
	return 1;
}
