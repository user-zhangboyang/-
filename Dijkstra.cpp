#include"headfile.h"

void Dijkstra(MGraph g){
	bool s[MAX];///////////布尔型数组，用来判断顶点是否已被使用
	int D[MAX];///////记录最小权值
	int path[MAX];/////最小路径上某个顶点的前驱节点
	int i,j,n,k,min,t;
	char x;
	printf("\n");
	printf("Dijkstar求最短距离的实现----------------------------------\n");
	printf("输入你选择的起点:\n");
	scanf(" %c",&x);
	n=locatevex(g,x);
	for(i=0;i<g.vexnum;i++){/////////////初始化，所有顶点未被使用，起点到每个点的最小距离为对应权值
		s[i]=false;
		D[i]=g.arcs[n][i];
		path[i]=n;
	}
	s[n]=true;////////标记使用过
	for(i=0;i<g.vexnum;i++){
		min=MAXINT;//////////设定一个大于所有权值的整数
		for(j=0;j<g.vexnum;j++){///////寻找权值数组中最小的
			if(!s[j] && D[j]<min){
				k=j;
				min=D[j];
			}
		}
		s[k]=true;////将对应顶点标记使用过
		for(j=0;j<g.vexnum;j++){/////////跳转到对应行更新权值数组，若从起点经过该点到目标点的距离小于从起点直接到该点的距离，则更换，考虑到初始数组时用零代表两点无边，故该点未被使用且对应最小权值为0时，只要经过点的权值和不为零即替换
			if(!s[j] && (min+g.arcs[k][j])<D[j]){
				D[j]=min+g.arcs[k][j];
				path[j]=k;////前驱节点更新
			}
		}
	}
	for(i=0;i<g.vexnum;i++){
		if(i==n) continue;
		if(path[i]==n) printf("%c<-%c %d\n",g.vexs[i],x,D[i]);/////输出
		else{
			t=path[i];
            printf("%c<-",g.vexs[i]);
			while(t!=n){
				printf("%c<-",g.vexs[t]);
				t=path[t];
			}
			printf("%c %d\n",x,D[i]);
		}
	}
	printf("\n");
}
