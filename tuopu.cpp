#include"headfile.h"

void topu(ALGraph g){
	sqstack S;
	int i,k,count=0,e;
	ArcNode *p;
    int indegree[MAX];
	printf("拓扑排序实现:-------------------------------------------------------------------------\n");
	for(i=0;i<g.vexnum;i++){/////////初始化indegree数组，入度均为0
		indegree[i]=0;
	}
	for(i=0;i<g.vexnum;i++){/////////////遍历整个邻接表，构建indegree数组
		p=g.vertices[i].firstarc;
		while(p){
			indegree[p->adjvex]++;////////链表后每个元素出现一次入度便增加一
			p=p->nextarc;
		}
	}
	initstack(S);
	for(i=0;i<g.vexnum;i++){/////////////将入度为零的顶点位置编号放入栈
		if(indegree[i]==0) push(S,i);
	}
	while(judgestack(S)){///////栈不为空时循环
		pop(S,e);
		printf("%c ",g.vertices[e].data);/////取出栈中元素并输出
		count++;
		p=g.vertices[e].firstarc;///////定位到该顶点的链表
		while(p){/////////将链表中各顶点的入度减一并判断是否为0，是的话入栈
			k=p->adjvex;
			if(--indegree[k]==0) push(S,k);
			p=p->nextarc;
		}
	}
	printf("\n");
    if(count<g.vexnum) printf("图存在环!\n");
}

int initstack(sqstack &s){
	s.base=(int*) malloc (stack_init_size*sizeof(int));
	if(!s.base) return 0;//分配失败
	s.top=s.base;
	s.stacksize=stack_init_size;
	return 1;
}

int push(sqstack &s,int e){
	if(s.top-s.base>=s.stacksize){//栈满
		s.base=(int*) realloc (s.base,(s.stacksize+stackincrement)*sizeof(int));
		if(!s.base) return 0;
		s.top=s.base+s.stacksize;
		s.stacksize+=stackincrement;
	}
	*s.top++=e;
	return 1;
}

int pop(sqstack &s,int &e){
	if(s.top==s.base) return 0;
	e=*--s.top;
	return 1;
}

int judgestack(sqstack s){
	if(s.top!=s.base){
		return 1;
	}
	else{
		return 0;
	}
}
