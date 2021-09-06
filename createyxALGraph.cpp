#include"headfile.h"   //创建有向邻接表

int creatyxALGraph(ALGraph &G){
	int m,n,i,j,k,w;
	char v1, v2;
	FILE *fp=fopen("图的信息.txt","r");//打开存放信息的文档
	if(fp==NULL){
		printf("打开错误!\n");
		exit(0);
	}
	printf("再次输入你所建立的图的顶点数和边数m,n:\n");
	scanf("%d%d",&m,&n);
	G.vexnum=m;
	G.arcnum=n;		
	for (i = 0;i < G.vexnum;++i){
		fscanf (fp," %c",&G.vertices[i].data);			//构造顶点向量
        G.vertices[i].firstarc = NULL;	
	}
	for (k = 0;k < G.arcnum;++k) {
		fscanf(fp," %c%c%d",&v1,&v2,&w);							//一个一个读入
		i = locateALGraph(G, v1); j = locateALGraph(G, v2);		//确定v1和v2在G中位置
		if (i == -1 || j == -1) { printf("ERROR!No such data!");return 0; }
		ArcNode *newNode = (ArcNode*)malloc(sizeof(ArcNode));
		newNode->adjvex = j;newNode->info = (int*)malloc(sizeof(int));*(newNode->info) = w;
		newNode->nextarc = G.vertices[i].firstarc;newNode->vex=v2;
		G.vertices[i].firstarc = newNode;
	}
	return 1;
}
