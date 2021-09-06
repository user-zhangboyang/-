#include"headfile.h"   
void read(){
	int m,n,i,w;
	char v1,v2,x;
    FILE *fp=fopen("图的信息.txt","w"); //自行创建文件
	if(fp==NULL){
		printf("打开错误\n");
		exit(0);
	}
	printf("请输入你想建立的图的顶点数和边数m,n:\n");  //可通过控制台写入后读取，也可通过直接创建文档写入读取
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++){
		scanf(" %c",&x);
		fprintf(fp,"%c",x);//写入顶点信息
	}
	fprintf(fp,"\n");//换行
	for(i=0;i<n;i++){
		scanf(" %c,%c,%d",&v1,&v2,&w);
		fprintf(fp,"%c%c%d",v1,v2,w);//写入边信息
		fprintf(fp,"\n");
	}
	fclose(fp);
}
