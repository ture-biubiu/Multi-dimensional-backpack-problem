#include<stdio.h>
#include<stdlib.h>

struct goods 
{
	int n;						//��Ʒ���� 
	int m;						//��Ʒ��������
	float best;					//����ֵ
	double value[50];			//��Ʒ��ֵ
	int weight[50][50];			//��Ʒ����ֵ(�������������������)
	int limit[50];				//���������Ե�Լ������
}Point;
             
             
//int a;  						//��������
int x[50];						//��Ʒ��ѡȡ״̬
int flag[50];                   //���ŵ�ѡȡ״̬
double maxValue = 0;            //����ֵ
double tempValue = 0;           //��ǰ����ֵ
double tempWeight[50];			//��ǰ��ƷԼ����

//�����ͺ������жϵ�ǰ����Լ����������Ʒ��Լ���Ƿ�ᳬ������Լ������
bool Bound(int t){
	int i;
	for (i = 0; i < Point.m; i++)//������ǰ��Ʒ����������
	{
		if (tempWeight[i] + Point.weight[i][t] <= Point.limit[i])
			continue;
		else break;
	}
	if (i == Point.m)  //�����ϲŷ�����ֵ
		return true;
	else
		return false;
}

//���ݺ���
void BackTrack(int t)
{
		//�Ѿ����������ڵ�
		
	if (t >= Point.n) //�����Ҷ�ӽڵ�
	{   

		if (tempValue >= maxValue)				//�����ǰ�������ܼ�ֵ������һ�ε�����ֵ
		{   
			maxValue = tempValue;    			//������ֵ����
			for (int i = 0; i < Point.n; i++) 	//��������ѡȡ������·��
			{    
				flag[i] = x[i];
			}
		}
		return;
	}
	
	//����������
	if ( Bound(t) ) 			//�����ǰԼ��+��һ����ƷԼ��<=�������Լ������      ��ֵ����
	{  
		for (int i = 0; i < Point.m; i++)
		{
			tempWeight[i] += Point.weight[i][t];       //��ǰԼ���ͼ�����һ��Լ��
		}
		tempValue += Point.value[t];
		x[t] = 1;                    //1��ʾ���뱳�� 
		
		
		BackTrack(t + 1);          // ����
		for (int i = 0; i < Point.m; i++) 				//��ѡ������ݻָ�ԭ����Լ��
		{
			tempWeight[i] -= Point.weight[i][t];        //��ǰԼ���ͼ�ȥ��һ����Լ��
		}
		tempValue -= Point.value[t];					//���ݻָ�ԭ���ļ�ֵ
		x[t] = 0;										//0��ʾ�����뱳�� 

	}
	
	//��װ�������Ʒ��ֱ�������ұߵĽڵ�

	//����������
		BackTrack(t + 1);

}

//���뺯�� 
int intput()
{
	int j, k;
	scanf("%d", &Point.n);
	scanf("%d", &Point.m);
	//scanf("%f", &Point.best);//��ȡ��������n����Լ������m��������
	for (j = 0; j < Point.n; j++) {
		scanf("%lf", &Point.value[j]);//��ȡ��Ʒ��ֵ����
	}
	for (j = 0; j < Point.m; j++)
		for (k = 0; k < Point.n; k++)
			scanf("%d", &Point.weight[j][k]);//��ȡ��Ʒ�����Ķ�ά����
	for (j = 0; j < Point.m; j++)
		scanf("%d", &Point.limit[j]);//��ȡ������������
		
		
	//��ʼ��	
	maxValue = 0;					
	tempValue = 0;
	for (int i = 0; i < Point.m; i++)
	{
		tempWeight[i] = 0;
	}	
		
	return 0;
}

 
//������� 
void output()
{
	printf("����ֵΪ��%0.1f\n", maxValue);
	printf("���Ž������Ϊ��\nѡȡ��");
	for (int i = 0; i < Point.n; i++)
	{
		if (flag[i] == 1)
			printf("%d ", i + 1);
	}
	printf("����Ʒ\n");

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
ʱ�临�Ӷȷ��� 
 
*/ 
