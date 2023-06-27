#include "graphics.h"
#include <stdio.h>
void readmenu(void);//�ж��û��Ƿ��ȡ�ļ�
void wholemenu(void);//��ӡȫ�ֲ˵�
void flee(void);//�ж��û��Ƿ��˳��˳���
void maker(void);//��ӡ������Ա����
void suggestions(void);//���������
void paintmenu(void);//��ӡ��ͼ�˵�
void painting(void);//�ܺ��� main��������
void repeal(void);//��������
void filesave(void);//�����ļ��ĺ���
void fileread(void);//��ȡ�ļ��ĺ���
void filepaint(void);//���ڻ����ļ��б����ͼ��
void initial(void);//��ʼ������ �ṹ����ÿһ�����ֵΪ0

typedef struct {
	int x;
	int y;
}AXIS;
typedef struct {
	int shape;
	int color;
	int linewide;
	int num;
	AXIS axis[50];
}DRAW;

DRAW draw[20];//����100���ɴ洢ͼ�εĽṹ��
int cnt = 0;//���ڼ�¼��ǰͼ�θ���������������ʹ�ã�

void readmenu(void)
{
	char read;//read�����û��Ƿ���Ҫ��ȡ�ļ�
	xyprintf(600, 300, "��ʹ��Ӣ�����뷨");
	delay_ms(2000);
	cleardevice();
	while (1)
	{
		xyprintf(10, 10, "��ӭ������߹߹���壬����ݲ˵�����ѡ���Ƿ��ȡ�ļ�");
		xyprintf(10, 30, "1����ȡ");
		xyprintf(10, 50, "2������ȡ");
		read = getch();
		if (read == '1')
		{
			cleardevice();
			xyprintf(10, 10, "�Ѷ�ȡ");
			getch();
			fileread();
			break;
		}
		else if (read == '2')
		{
			cleardevice();
			xyprintf(10, 10, "δ��ȡ");
			getch();
			break;
		}
		else
		{
			cleardevice();
			xyprintf(10, 10, "������ϸ�Ķ��˵�������ѡ��");
			getch();
			cleardevice();
		}
	}
}
void wholemenu(void)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	bar(0, 0, 200, 200);
	setlinewidth(3);
	setcolor(WHITE);
	line(0, 170, 200, 170);
	line(200, 170, 200, 0);//������ֱ�����ڰ�Χ�˵�
	setfont(18, 0, "����");
	char s2[] = "ѡ��������еĲ�����";
	xyprintf(10, 10, s2);
	xyprintf(10, 30, "1�������Ļ");
	xyprintf(10, 50, "2������");
	xyprintf(10, 70, "3���ر�");
	xyprintf(10, 90, "4��������һ��");
	xyprintf(10, 110, "5������");
	xyprintf(10, 130, "6��������Ա");
	xyprintf(10, 150, "7���������");
	
}
void flee(void)
{
	char flee;//�����ж��û��Ƿ��˳�
	char save;//�����ж��û��Ƿ񱣴��ļ�
	cleardevice();
	setfont(50, 0, "����");
	xyprintf(500, 300, "�Ƿ񷵻ز˵�(��������1)");
	xyprintf(500, 370, "�����ؽ��˳��˳���");
	flee = getch();
	if (flee == '1')
	{
		cleardevice();
		xyprintf(500, 300, "�����������");
		getch();
		cleardevice();
		setfont(18, 0, "����");

	}
	else
	{
		cleardevice();
		setfont(50, 0, "����");
		xyprintf(500,300,"�Ƿ񱣴��ļ�");
		xyprintf(500, 400, "�����밴1");
		xyprintf(500, 500, "�����水������˳�");
		save = getch();
		if (save == '1') 
		{
			cleardevice();
			filesave();
			xyprintf(500, 300, "�ѱ������ļ���shape.txt��");
			xyprintf(500, 400, "��������˳�");
			getch();
			cleardevice();
			xyprintf(500, 300, "�����˳������Ժ�");
			delay_ms(2000);
			closegraph();
		}
		else
		{
			cleardevice();
			xyprintf(500, 300, "�����˳������Ժ�");
			delay_ms(2000);
			closegraph();
		}
	}
}
void maker(void)
{
	xyprintf(500, 250, "ѧУ�������ʵ��ѧ");
	xyprintf(500, 270, "ѧԺ�������ѧԺ������ʾ�������ѧԺ��");
	xyprintf(500, 290, "�༶��2020211320��");
	xyprintf(500, 310, "����������ΰ");
	setfont(50, 0, "����");
	xyprintf(600, 500, "��Ȩ�ؾ�");
	setfont(18, 0, "����");
	getch();
}
void suggestions(void)
{
	char str[1000];
	inputbox_getline("�����", "������������д������\n���ǻ�����Դ�", str, sizeof(str) / sizeof(*str));
}
void paintmenu(void)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	bar(0, 0, 220, 200);
	setlinewidth(3);
	setcolor(WHITE);
	line(0, 150, 200, 150);
	line(200, 150, 200, 0);
	setfont(18, 0, "����");
	xyprintf(10, 10, "��ѡ�����������ʽ:");
	xyprintf(10, 30, "1��Բ��");
	xyprintf(10, 50, "2��Բ");
	xyprintf(10, 70, "3�������");
	xyprintf(10, 90, "4����Բ����");
	xyprintf(10, 110, "5���߶�");
	xyprintf(10, 130, "6��������һ��");
	
}
void painting(void)
{
	char operate;//���ھ����û��Ĳ���
	char str[1000];//inputbox_getline��������Ϊ������ʹ��
	int point;//���ƶ����ʱ�����������ε���ز���
	int i = 0;//�洢����ε�����ʱʹ�õı���
	int data[500];//�������г�ʼ�����ڶ���ε�����
	initgraph(1280, 640);//��ʼ������
	setcaption("߹߹����");//�������
	setfont(18, 0, "����");
	setcolor(WHITE);
	initial();//��ʼ������
read:
	readmenu();//��ȡ�˵�����
	while (1)
	{
		wholemenu();//ȫ�ֲ˵�����
		operate = getch();
		if (operate != '1' && operate != '2' && operate != '3' && operate != '4' && operate != '5' && operate != '6'&& operate!='7')
		{
			cleardevice();
			xyprintf(10, 10, "����ϸ�Ķ��˵�����������");
			getch();
			cleardevice();
		}
		else
		{
			switch (operate)
			{
			case '1':
				cleardevice();
				break;
			case '2':
				paintmenu();
				draw[cnt].shape = getch();
				switch (draw[cnt].shape)
				{
				case '1':
					inputbox_getline("Բ���Ĳ�������", "�������ߵ���ɫ\n1����ɫ2����ɫ3����ɫ", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "�������ߵĿ��", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "������Բ�ĵ�x������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "������Բ�ĵ�y������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "��������ʼ�ǵĽǶ�", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "��������ֹ�ǵĽǶ�", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].y = atoi(str);
					inputbox_getline("Բ���Ĳ�������", "������Բ���İ뾶", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[2].x = atoi(str);
					setlinewidth(draw[cnt].linewide);
					switch (draw[cnt].color)
					{
					case 1:
						setcolor(WHITE);
						break;
					case 2:
						setcolor(GREEN);
						break;
					case 3:
						setcolor(RED);
						break;
					}
					arc(draw[cnt].axis[0].x, draw[cnt].axis[0].y, draw[cnt].axis[1].x, draw[cnt].axis[1].y, draw[cnt].axis[2].x);
					//����Բ������
					cnt++;//����֮��ͼ��������1
					break;
				case '2':
					inputbox_getline("Բ�Ĳ�������", "�������ߵ���ɫ\n1����ɫ2����ɫ3����ɫ", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoif(str);
					inputbox_getline("Բ�Ĳ�������", "�������ߵĿ��", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("Բ�Ĳ�������", "������Բ�ĵ�x������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("Բ�Ĳ�������", "������Բ�ĵ�y������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("Բ�Ĳ�������", "������Բ�ĵİ뾶", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					setlinewidth(draw[cnt].linewide);
					switch (draw[cnt].color)
					{
					case 1:
						setcolor(WHITE);
						break;
					case 2:
						setcolor(GREEN);
						break;
					case 3:
						setcolor(RED);
						break;
					}
					circle(draw[cnt].axis[0].x, draw[cnt].axis[0].y, draw[cnt].axis[1].x);
					//����Բ
					cnt++;//����֮��ͼ��������1
					break;
				case '3':
					inputbox_getline("����εĲ�������", "����������������ɫ\n1����ɫ2����ɫ3����ɫ", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("����εĲ�������", "�������ߵĿ��", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("����α���", "���������εı���", str, (sizeof(str) / sizeof(*str)));
					draw[cnt].num = atoi(str);
					for (point = 0; point <= draw[cnt].num; point++)
					{
						inputbox_getline("���������", "���������ε��x����\n(��������һ����ÿ����ֱ��������)", str, (sizeof(str) / sizeof(*str)));
						draw[cnt].axis[point].x = atoi(str);
						inputbox_getline("���������", "���������ε��y����\n(��������һ����ÿ����ֱ��������)", str, (sizeof(str) / sizeof(*str)));
						draw[cnt].axis[point].y = atoi(str);
					}
					point = 0;
					while (i < 2 * draw[cnt].num)
					{
						data[i] = draw[cnt].axis[point].x;
						i++;
						data[i] = draw[cnt].axis[point].y;
						i++;
						point++;
					}//����while�����ʵ���˽��ṹ���е��������黯
					setlinewidth(draw[cnt].linewide);
					switch (draw[cnt].color)
					{
					case 1:
						setfillcolor(WHITE);
						break;
					case 2:
						setfillcolor(GREEN);
						break;
					case 3:
						setfillcolor(RED);
						break;
					}
					fillpoly(draw[cnt].num, data);
					//���ƶ����
					cnt++;//����֮��ͼ��������1
					break;
				case '4':
					inputbox_getline("��Բ���ߵĲ�������", "�������ߵ���ɫ\n1����ɫ2����ɫ3����ɫ", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "�������ߵĿ��", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ�������ĵ�x������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ�������ĵ�y������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ���ߵ���ʼ�ǽǶ�", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ���ߵ���ֹ�ǽǶ�", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].y = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ����x��뾶", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[2].x = atoi(str);
					inputbox_getline("��Բ���ߵĲ�������", "��������Բ����y��뾶", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[2].y = atoi(str);
					setlinewidth(draw[cnt].linewide);
					switch (draw[cnt].color)
					{
					case 1:
						setcolor(WHITE);
						break;
					case 2:
						setcolor(GREEN);
						break;
					case 3:
						setcolor(RED);
						break;
					}
					ellipse(draw[cnt].axis[0].x, draw[cnt].axis[0].y, draw[cnt].axis[1].x, draw[cnt].axis[1].y, draw[cnt].axis[2].x, draw[cnt].axis[2].y);
					//����Բ׶����
					cnt++;//����֮��ͼ��������1
					break;
				case '5':
					inputbox_getline("�߶εĲ�������", "�������ߵ���ɫ\n1����ɫ2����ɫ3����ɫ", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("�߶εĲ�������", "�������ߵĿ��", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("�߶εĲ�������", "��������ʼ���x������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("�߶εĲ�������", "��������ֹ���y������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("�߶εĲ�������", "��������ʼ���x������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("�߶εĲ�������", "��������ʼ���y������", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].y = atoi(str);
					setlinewidth(draw[cnt].linewide);
					switch (draw[cnt].color)
					{
					case 1:
						setcolor(WHITE);
						break;
					case 2:
						setcolor(GREEN);
						break;
					case 3:
						setcolor(RED);
						break;
					}
					line(draw[cnt].axis[0].x, draw[cnt].axis[0].y, draw[cnt].axis[1].x, draw[cnt].axis[1].y);
					//����ֱ��
					cnt++;//����֮��ͼ��������1
					break;
				case '6':
					break;
				}
				break;
			case '3':
				flee();
				break;
			case'4':
				cleardevice();
				goto read;
				break;
			case '5':
				cleardevice();
				repeal();
				cnt--;//����֮��ͼ����Ŀ��1
				break;
			case '6':
				maker();
				cleardevice();
				break;
			case '7':
				suggestions();
				break;
			}
		}
		
		
	}
}
void repeal(void) 
{
	int i = 0;//i������cnt�Ƚϣ���Ҫ�ػ���ͼ�ε���ĿΪcnt-1
	int point = 0;//����ȡ�ṹ���еĶ���ε�������Ϣ
	int pt = 0;//����ȡ���洢�������Ϣ�����������ֵ
	int data[100];
	for (i = 0; i < cnt-1 ; i++)
	{
		switch (draw[i].shape)
		{
		case '1':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			arc(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y, draw[i].axis[2].x);
			break;
		case '2':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			circle(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x);
			break;
		case '3':
			while (pt < 2 * draw[i].num)
			{
				data[pt] = draw[i].axis[point].x;
				i++;
				data[i] = draw[i].axis[point].y;
				i++;
				point++;
			}
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setfillcolor(WHITE);
				break;
			case 2:
				setfillcolor(GREEN);
				break;
			case 3:
				setfillcolor(RED);
				break;
			}
			fillpoly(draw[i].num, data);
			break;
		case '4':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			ellipse(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y, draw[i].axis[2].x, draw[i].axis[2].y);
			break;
		case '5':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			line(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y);
			break;
		}

	}
	
}
void filesave(void)
{
	int num1, num2;
	FILE* fp;
	fp = fopen("shape.txt", "w");
	fprintf(fp, "%d\n", cnt);
	for (num1 = 0; num1 < cnt; num1++)
	{
		fprintf(fp, "%d\n", draw[num1].shape);
		fprintf(fp, "%d %d %d\n", draw[num1].color, draw[num1].linewide,draw[num1].num);
		for (num2 = 0; num2 <= 50; num2++)
		{
			if (draw[num1].axis[num2].x == 0)
			{
				break;
			}
			else
			{
				fprintf(fp, "%d ", draw[num1].axis[num2].x);
			}
			if (draw[num1].axis[num2].y == 0)
			{
				break;
			}
			else
			{
				fprintf(fp, "%d ", draw[num1].axis[num2].y);
			}
		}
		fprintf(fp, "\n");
		fprintf(fp, "%d\n",0);//���ڷָ�ÿһ��ͼ�ε�����
	}
	fclose(fp);
}
void fileread(void)
{
	int num1, num2;
	FILE* fp;
	fp = fopen("shape.txt", "r");
	fscanf(fp, "%d\n", &cnt);
	for (num1 = 0; num1 <= cnt; num1++)
	{
		fscanf(fp, "%d\n", &draw[num1].shape);
		fscanf(fp, "%d %d %d\n", &draw[num1].color, &draw[num1].linewide, &draw[num1].num);
		for (num2 = 0; num2 <= 50; num2++)
		{
			fscanf(fp, "%d ", &draw[num1].axis[num2].x);
			if (draw[num1].axis[num2].x == 0)
			{
				break;
			}
			fscanf(fp, "%d", &draw[num1].axis[num2].y);
			if (draw[num1].axis[num2].y == 0)
			{
				break;
			}
		}
	}
	fclose(fp);
	filepaint();
}
void filepaint(void)
{
	int i = 0;//i������cnt�Ƚ�
	int point = 0;//����ȡ�ṹ���еĶ���ε�������Ϣ
	int pt = 0;//����ȡ���洢�������Ϣ�����������ֵ
	int data[100];
	for (i = 0; i <= cnt; i++)
	{
		switch (draw[i].shape)
		{
		case '1':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			arc(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y, draw[i].axis[2].x);
			break;
		case '2':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			circle(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x);
			break;
		case '3':
			while (pt < 2 * draw[i].num)
			{
				data[pt] = draw[i].axis[point].x;
				i++;
				data[i] = draw[i].axis[point].y;
				i++;
				point++;
			}
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setfillcolor(WHITE);
				break;
			case 2:
				setfillcolor(GREEN);
				break;
			case 3:
				setfillcolor(RED);
				break;
			}
			fillpoly(draw[i].num, data);
			break;
		case '4':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			ellipse(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y, draw[i].axis[2].x, draw[i].axis[2].y);
			break;
		case '5':
			setlinewidth(draw[i].linewide);
			switch (draw[i].color)
			{
			case 1:
				setcolor(WHITE);
				break;
			case 2:
				setcolor(GREEN);
				break;
			case 3:
				setcolor(RED);
				break;
			}
			line(draw[i].axis[0].x, draw[i].axis[0].y, draw[i].axis[1].x, draw[i].axis[1].y);
			break;
		}

	}

}
void initial(void)
{
	int num1, num2;
	for (num1 = 0; num1 <= 20; num1++)
	{
		draw[num1].shape = 0;
		draw[num1].num = 0;
		draw[num1].linewide = 0;
		draw[num1].color = 0;
		for (num2 = 0; num2 <= 50; num2++)
		{
			draw[num1].axis[num2].x = 0;
			draw[num1].axis[num2].y = 0;
		}
	}
}