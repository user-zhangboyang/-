#include"headfile.h"

void prim(MGraph g){
	int k,i,j,min;
	char x;
	char minclose[MAX];    //存放已被使用的顶点中到达未被使用顶点距离最小的点,minclose[i]=x,表示未被使用顶点中到达已被使用顶点中距离最小的是x
	int minweight[MAX];   //存放其他未使用顶点到该最近距离点的权值即距离
	printf("prim算法实现-----------------------------------------------------:\n");
	printf("选择你想要的起点:\n");
	scanf(" %c",&x);  //输入你想要的起点
	k=locatevex(g,x);//定位该起点在图中的位置
	for(i=0;i<g.vexnum;i++){           //////初始化构建一维数组，用来存放其他未使用顶点到该点的距离
		if(i!=k){
			minclose[i]=x;     //已使用顶点中到达第i个顶点最近的为x顶点，
			minweight[i]=g.arcs[k][i]; //将其对应的距离放入数组,-1表示已经使用该点，不再使用
		}
	}
	minclose[k]=x;//定义自己到自己
	minweight[k]=-1;//已使用
	for(i=1;i<g.vexnum;i++){           //prim生成最小数
		min=MAXINT;//最大值用于初次比较
		j=0;
		k=0;
		while(j<g.vexnum){ /////寻找数组中对应权值中最小值
			if(minweight[j]!=-1 && minweight[j]<min){  //当权值不为-1且小于min，标记其下标k
				min=minweight[j];
				k=j;
			}
			j++;
		}
		printf("%c%c ",minclose[k],g.vexs[k]);////输出对应最小边，minclose[k]对应已使用顶点，g.vexs[k]对应未使用顶点
		minweight[k]=-1;//将该顶点权值置为-1，表示已使用，接下来更新minweight和minclose数组中的内容，此时的k为刚被使用的顶点的价置
		for(j=0;j<g.vexnum;j++){ //在刚被使用顶点的对应行中遍历所有点，更新数组
			if(minweight[j]!=-1 && g.arcs[k][j]<minweight[j]){
				minweight[j]=g.arcs[k][j];     ///////////当minweight[i]!=-1,表示未被使用，g.arcs[k][j]表示第j个顶点到刚被使用的该点的距离即权值
				minclose[j]=g.vexs[k];          ///////当其小于第j个顶点到上一个被使用顶点的距离即权值时用此权值代替原数组中对应位置的相应权值
			}                                   //////将对应的最小对应顶点更新为刚被使用的顶点即第k个顶点
		}
	}
	printf("\n");
}
	
