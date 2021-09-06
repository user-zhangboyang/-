#include"headfile.h"   //寻找邻接表的第一个邻接点

int locateALGraph(ALGraph G,char v) {
	int len;
	for (len = 0;len < G.vexnum;len++) {
		if (v == G.vertices[len].data)
			return len;
	}
	return -1;
}
