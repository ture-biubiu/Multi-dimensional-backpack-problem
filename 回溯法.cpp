#include<stdio.h>
#include<stdlib.h>

struct goods 
{
	int n;						//物品数量 
	int m;						//物品属性数量
	float best;					//最优值
	double value[50];			//物品价值
	int weight[50][50];			//物品属性值(重量、体积等限制条件)
	int limit[50];				//背包各属性的约束上限
}Point;
             
             
//int a;  						//几组数据
int x[50];						//物品的选取状态
int flag[50];                   //最优的选取状态
double maxValue = 0;            //最大价值
double tempValue = 0;           //当前最大价值
double tempWeight[50];			//当前物品约束和

//布尔型函数，判断当前背包约束加上新物品的约束是否会超出背包约束上限
bool Bound(int t){
	int i;
	for (i = 0; i < Point.m; i++)//遍历当前物品的所有属性
	{
		if (tempWeight[i] + Point.weight[i][t] <= Point.limit[i])
			continue;
		else break;
	}
	if (i == Point.m)  //都符合才返回真值
		return true;
	else
		return false;
}

//回溯函数
void BackTrack(int t)
{
		//已经搜索到根节点
		
	if (t >= Point.n) //如果到叶子节点
	{   

		if (tempValue >= maxValue)				//如果当前方案的总价值大于上一次的最大价值
		{   
			maxValue = tempValue;    			//将最大价值交换
			for (int i = 0; i < Point.n; i++) 	//保存最优选取方案的路径
			{    
				flag[i] = x[i];
			}
		}
		return;
	}
	
	//搜索左子树
	if ( Bound(t) ) 			//如果当前约束+下一个物品约束<=背包最大约束限制      价值类似
	{  
		for (int i = 0; i < Point.m; i++)
		{
			tempWeight[i] += Point.weight[i][t];       //当前约束和加上下一个约束
		}
		tempValue += Point.value[t];
		x[t] = 1;                    //1表示放入背包 
		
		
		BackTrack(t + 1);          // 回溯
		for (int i = 0; i < Point.m; i++) 				//不选择则回溯恢复原来的约束
		{
			tempWeight[i] -= Point.weight[i][t];        //当前约束和减去上一个的约束
		}
		tempValue -= Point.value[t];					//回溯恢复原来的价值
		x[t] = 0;										//0表示不放入背包 

	}
	
	//不装入这个物品，直接搜索右边的节点

	//遍历右子树
		BackTrack(t + 1);

}

//输入函数 
int intput()
{
	int j, k;
	scanf("%d", &Point.n);
	scanf("%d", &Point.m);
	//scanf("%f", &Point.best);//读取变量数（n），约束数（m），最优
	for (j = 0; j < Point.n; j++) {
		scanf("%lf", &Point.value[j]);//读取物品价值数组
	}
	for (j = 0; j < Point.m; j++)
		for (k = 0; k < Point.n; k++)
			scanf("%d", &Point.weight[j][k]);//读取物品质量的二维数组
	for (j = 0; j < Point.m; j++)
		scanf("%d", &Point.limit[j]);//读取背包上限数组
		
		
	//初始化	
	maxValue = 0;					
	tempValue = 0;
	for (int i = 0; i < Point.m; i++)
	{
		tempWeight[i] = 0;
	}	
		
	return 0;
}

 
//输出函数 
void output()
{
	printf("最大价值为：%0.1f\n", maxValue);
	printf("最优解决方案为：\n选取第");
	for (int i = 0; i < Point.n; i++)
	{
		if (flag[i] == 1)
			printf("%d ", i + 1);
	}
	printf("件物品\n");

	printf("\n");

}

int main()
{
	intput();
	BackTrack(0);
	output();
	return 0;
}

/*
时间复杂度分析 
 
*/ 
