#include"headfile.h"

void creatMGraph(MGraph &g){    //创建无向邻接矩阵图
	int i,j,k,w,m,n;
	char v1,v2;
	FILE *fp=fopen("图的信息.txt","r");//打开存放信息的文档
	if(fp==NULL){
		printf("打开错误!\n");
		exit(0);
	}
	printf("再次输入你所建立的图的顶点数和边数m,n:\n");
	scanf("%d%d",&m,&n);
	g.vexnum=m;
	g.arcnum=n;
	for(i=0;i<g.vexnum;++i){		
		fscanf(fp," %c",&g.vexs[i]);	
	}	
	for(i=0;i<g.vexnum;++i){		
		for(j=0;j<g.vexnum;++j){			
			g.arcs[i][j]=MAXINT;		//初始定义所有边的权值为65536
		}
	}
	for(k=0;k<g.arcnum;++k){		
		fscanf(fp," %c%c%d",&v1,&v2,&w);
		i=locatevex(g,v1);	//确定顶点的位置	
		j=locatevex(g,v2);		
		g.arcs[i][j]=w;	
		g.arcs[j][i]=g.arcs[i][j];
	}
}
