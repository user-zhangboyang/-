#include"headfile.h"     //寻找邻接矩阵的邻接点

int locatevex(MGraph g,char v){
	int i;
	for(i=0;i<g.vexnum;++i){
		if(g.vexs[i]==v){
			return i;
		}
	}
	return -1;
}//确定顶点的位置
