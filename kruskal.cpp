#include"headfile.h"

void Kruskal(MGraph g){
	printf("Kruskal求最小生成树-----------------------------------------------------------:\n");
	int i,j,m,n,k=1,d=1;
	closeEdge edges[MAX];//存放边的数组，类型为closeEdge，分别记录两个顶点和权值
	int judge[MAX];////判断数组，用来判断该顶点是否已被使用
	for(i=0;i<g.vexnum;i++){//////////////////////将边的对应信息存入edges数组，第一位空出为后续排序准备
		for(j=0;j<g.vexnum;j++){
			if(g.arcs[i][j]!=MAXINT){
				edges[k].begin=g.vexs[i];
				edges[k].end=g.vexs[j];
				edges[k].weight=g.arcs[i][j];
				k++;
			}
		}
	}
    for(i=0;i<k;i++){/////////////////初始化判断数组，初始值均为自身对应位置值，表示该路终点为自身
		judge[i]=i;
	}
	QSort(edges,1,k-1);//////////快速排序
	for(i=1;i<k;i++){ //////判断是否存在回路
		n=JUDGE(judge,locatevex(g,edges[i].begin));///寻找头顶点的终点对应位置
		m=JUDGE(judge,locatevex(g,edges[i].end));////寻找尾顶点的终点对应位置
		if(n!=m){
			printf("%c%c ",edges[i].begin,edges[i].end);///两者不同即不形成回路，输出
			judge[n]=m;///将头顶点的终点置换为尾顶点
			d++;
		}
		if(d==g.arcnum) break;///当边数等于顶点数减一时所有顶点已被使用
	}
	printf("\n");
}
        
int Partition(closeEdge arr[],int low,int high)////////////一次快速排序
{
	int pivotkey;
	arr[0]=arr[low];///将零位作为标记点
	pivotkey=arr[low].weight;///////将权值作为关键字
	while(low<high){
		while(low<high && arr[high].weight>=pivotkey) --high;///从右边依次向左找权值比关键字小的
		arr[low]=arr[high];
		while(low<high && arr[low].weight<=pivotkey) ++low;////////////从左依次向右找权值比关键字大的
		arr[high]=arr[low];////换位
	}
	arr[low]=arr[0];///将关键字移动至最终位置
	return low;//返回最终关键字位置，划分原序列
}

void QSort(closeEdge arr[],int low,int high)
{
	int pivotloc;
	if(low<high){
		pivotloc=Partition(arr,low,high);/////////递归排序
		QSort(arr,low,pivotloc-1);
		QSort(arr,pivotloc+1,high);
	}
}

int JUDGE(int *parent,int i){
	while(parent[i]!=i){
		i=parent[i];
	}
	return i;
}



/*    原方法采用冒泡排序，考虑到效率问题舍弃，当边的数量过大时消耗时间明显增多，不适用，但对于此问题边数较少，影响不大，结果经过测验一致
void Kruskal(MGraph g){
	printf("Kruskal求最小生成树-----------------------------------------------------------:\n");
	int i,j,m,n,k=0,index,c,min;
	char a,b;
	closeEdge edges[MAX];
	int judge[MAX];
    for(i=0;i<g.arcnum;i++){
		judge[i]=1;
	}
	for(i=0;i<g.vexnum;i++){
		for(j=0;j<g.vexnum;j++){
			if(g.arcs[i][j]!=0){
				edges[k].begin=g.vexs[i];
				edges[k].end=g.vexs[j];
				edges[k].weight=g.arcs[i][j];
				k++;
			}
		}
	}
	for(i=0;i<k;i++){
		index=i;
		min=edges[i].weight;
		for(j=i+1;j<k;j++){
			if(edges[j].weight<min){
				min=edges[j].weight;
				index=j;
			}
		}
		a=edges[i].begin;
		b=edges[i].end;
		c=edges[i].weight;
		edges[i].begin=edges[index].begin;
		edges[i].end=edges[index].end;
		edges[i].weight=edges[index].weight;
		edges[index].begin=a;
		edges[index].end=b;
		edges[index].weight=c;
	}
	for(i=0;i<g.arcnum;i++){
		m=locatevex(g,edges[i].begin);
		n=locatevex(g,edges[i].end);
		if(judge[m]!=0 || judge[n]!=0){
			printf("%c%c ",edges[i].begin,edges[i].end);
			judge[m]=0;
			judge[n]=0;
		}
	}
	printf("\n");
}
*/
