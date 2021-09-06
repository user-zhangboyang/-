#include"headfile.h"
void main(){
	MGraph g1,g2;
	ALGraph g3,g4;
	char x;
	printf("算法功能如下:请输入A-K选择你要进行的操作,输入L结束,其他情况均错误!\n");
	printf("-------------------------------------------------------\n");
	printf("-------------------A:图的信息的录入--------------------\n");
	printf("-------------------B:创建无向邻接表图------------------\n");
	printf("-------------------C:创建无向邻接矩阵图----------------\n");
    printf("-------------------D:创建有向邻接矩阵图----------------\n");
    printf("-------------------E:创建有向邻接矩阵图----------------\n");
    printf("-------------------F:输出无向邻接表图和有向矩阵图------\n");
    printf("-------------------G:输出无向和有向邻接矩阵图----------\n");
	printf("-------------------H:实现prim算法----------------------\n");
	printf("-------------------I:实现Kruskal算法-------------------\n");
	printf("-------------------J:实现Dijkstra算法------------------\n");
	printf("-------------------K:实现拓扑排序算法------------------\n");
	printf("-------------------------------------------------------\n");
    while(true){///////////循环结构体来实现操作
		printf("输入你想进行的操作编号:\n");
		fflush(stdin);
		x=getchar();
		if(x<65||x>76){/////超越界限的输入无效重新输入
			printf("输入错误重新输入!\n");
			continue;
		}
		switch(x){////////////switch语句选择进行的操作
		    default:break;
		    case 'A':read();break;
		    case 'B':creatALGraph(g3);printf("无向邻接表图创建完成!\n");break;
			case 'C':creatMGraph(g1);printf("无向邻接矩阵图创建完成!\n");break;
			case 'D':creatyxMGraph(g2);printf("有向邻接矩阵图创建完成!\n");break;
			case 'E':creatyxALGraph(g4);printf("有向邻接表图创建完成!\n");break;
			case 'F':printf("无向邻接表图如下:\n");printALGraph(g3);printf("\n");printf("有向邻接表图如下:\n");printALGraph(g4);break;
			case 'G':printf("无向邻接矩阵图如下:\n");printMGraph(g1);printf("\n");printf("有向邻接矩阵图如下:\n");printMGraph(g2);break;
			case 'H':printf("无向邻接矩阵图prim算法:\n");prim(g1);printf("有向邻接矩阵图prim算法:\n");prim(g2);break;
			case 'I':printf("无向邻接矩阵图kruskal算法:\n");Kruskal(g1);printf("有向邻接矩阵图kruskal算法:\n");Kruskal(g2);break;
			case 'J':printf("无向邻接矩阵图Dijiskra算法:\n");Dijkstra(g1);printf("有向邻接矩阵图Dijiskra算法:\n");Dijkstra(g2);break;
			case 'K':topu(g4);break;

		}
		if(x=='L') break;//////////输入L时结束整个程序
	}
}
