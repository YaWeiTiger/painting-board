#include "graphics.h"
#include <stdio.h>
void readmenu(void);//判断用户是否读取文件
void wholemenu(void);//打印全局菜单
void flee(void);//判断用户是否退出此程序
void maker(void);//打印制作人员名单
void suggestions(void);//弹出建议框
void paintmenu(void);//打印绘图菜单
void painting(void);//总函数 main函数调用
void repeal(void);//撤销函数
void filesave(void);//保存文件的函数
void fileread(void);//读取文件的函数
void filepaint(void);//用于画出文件中保存的图形
void initial(void);//初始化函数 结构体里每一项均赋值为0

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

DRAW draw[20];//定义100个可存储图形的结构体
int cnt = 0;//用于记录当前图形个数（撤销函数中使用）

void readmenu(void)
{
	char read;//read决定用户是否需要读取文件
	xyprintf(600, 300, "请使用英文输入法");
	delay_ms(2000);
	cleardevice();
	while (1)
	{
		xyprintf(10, 10, "欢迎您进入吖吖画板，请根据菜单做出选择，是否读取文件");
		xyprintf(10, 30, "1、读取");
		xyprintf(10, 50, "2、不读取");
		read = getch();
		if (read == '1')
		{
			cleardevice();
			xyprintf(10, 10, "已读取");
			getch();
			fileread();
			break;
		}
		else if (read == '2')
		{
			cleardevice();
			xyprintf(10, 10, "未读取");
			getch();
			break;
		}
		else
		{
			cleardevice();
			xyprintf(10, 10, "请您仔细阅读菜单后再做选择");
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
	line(200, 170, 200, 0);//这两条直线用于包围菜单
	setfont(18, 0, "宋体");
	char s2[] = "选择您想进行的操作：";
	xyprintf(10, 10, s2);
	xyprintf(10, 30, "1、清除屏幕");
	xyprintf(10, 50, "2、作画");
	xyprintf(10, 70, "3、关闭");
	xyprintf(10, 90, "4、返回上一步");
	xyprintf(10, 110, "5、撤销");
	xyprintf(10, 130, "6、制作人员");
	xyprintf(10, 150, "7、意见采纳");
	
}
void flee(void)
{
	char flee;//用于判断用户是否退出
	char save;//用于判断用户是否保存文件
	cleardevice();
	setfont(50, 0, "宋体");
	xyprintf(500, 300, "是否返回菜单(返回请输1)");
	xyprintf(500, 370, "不返回将退出此程序");
	flee = getch();
	if (flee == '1')
	{
		cleardevice();
		xyprintf(500, 300, "按任意键继续");
		getch();
		cleardevice();
		setfont(18, 0, "宋体");

	}
	else
	{
		cleardevice();
		setfont(50, 0, "宋体");
		xyprintf(500,300,"是否保存文件");
		xyprintf(500, 400, "保存请按1");
		xyprintf(500, 500, "不保存按任意键退出");
		save = getch();
		if (save == '1') 
		{
			cleardevice();
			filesave();
			xyprintf(500, 300, "已保存至文件“shape.txt”");
			xyprintf(500, 400, "按任意键退出");
			getch();
			cleardevice();
			xyprintf(500, 300, "正在退出，请稍后");
			delay_ms(2000);
			closegraph();
		}
		else
		{
			cleardevice();
			xyprintf(500, 300, "正在退出，请稍后");
			delay_ms(2000);
			closegraph();
		}
	}
}
void maker(void)
{
	xyprintf(500, 250, "学校：北京邮电大学");
	xyprintf(500, 270, "学院：计算机学院（国家示范性软件学院）");
	xyprintf(500, 290, "班级：2020211320班");
	xyprintf(500, 310, "姓名：胡家伟");
	setfont(50, 0, "宋体");
	xyprintf(600, 500, "侵权必究");
	setfont(18, 0, "宋体");
	getch();
}
void suggestions(void)
{
	char str[1000];
	inputbox_getline("意见箱", "请把您的意见填写在下面\n我们会认真对待", str, sizeof(str) / sizeof(*str));
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
	setfont(18, 0, "宋体");
	xyprintf(10, 10, "请选择具体作画方式:");
	xyprintf(10, 30, "1、圆弧");
	xyprintf(10, 50, "2、圆");
	xyprintf(10, 70, "3、多边形");
	xyprintf(10, 90, "4、椭圆弧线");
	xyprintf(10, 110, "5、线段");
	xyprintf(10, 130, "6、返回上一步");
	
}
void painting(void)
{
	char operate;//用于决定用户的操作
	char str[1000];//inputbox_getline函数中作为缓冲区使用
	int point;//绘制多边形时用来储存多边形的相关参数
	int i = 0;//存储多边形点坐标时使用的变量
	int data[500];//以上三行初始化用于多边形的描述
	initgraph(1280, 640);//初始化画板
	setcaption("吖吖画板");//画板标题
	setfont(18, 0, "宋体");
	setcolor(WHITE);
	initial();//初始化函数
read:
	readmenu();//读取菜单函数
	while (1)
	{
		wholemenu();//全局菜单函数
		operate = getch();
		if (operate != '1' && operate != '2' && operate != '3' && operate != '4' && operate != '5' && operate != '6'&& operate!='7')
		{
			cleardevice();
			xyprintf(10, 10, "请仔细阅读菜单后重新输入");
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
					inputbox_getline("圆弧的参数输入", "请输入线的颜色\n1、白色2、绿色3、红色", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入线的宽度", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入圆心的x轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入圆心的y轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入起始角的角度", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入终止角的角度", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].y = atoi(str);
					inputbox_getline("圆弧的参数输入", "请输入圆弧的半径", str, sizeof(str) / sizeof(*str));
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
					//绘制圆弧曲线
					cnt++;//绘制之后图形数量加1
					break;
				case '2':
					inputbox_getline("圆的参数输入", "请输入线的颜色\n1、白色2、绿色3、红色", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoif(str);
					inputbox_getline("圆的参数输入", "请输入线的宽度", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("圆的参数输入", "请输入圆心的x轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("圆的参数输入", "请输入圆心的y轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("圆的参数输入", "请输入圆心的半径", str, sizeof(str) / sizeof(*str));
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
					//绘制圆
					cnt++;//绘制之后图形数量加1
					break;
				case '3':
					inputbox_getline("多边形的参数输入", "请输入多边形填充的颜色\n1、白色2、绿色3、红色", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("多边形的参数输入", "请输入线的宽度", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("多边形边数", "请输入多边形的边数", str, (sizeof(str) / sizeof(*str)));
					draw[cnt].num = atoi(str);
					for (point = 0; point <= draw[cnt].num; point++)
					{
						inputbox_getline("多边形坐标", "请输入多边形点的x坐标\n(依次输入一个，每个点分别进行输入)", str, (sizeof(str) / sizeof(*str)));
						draw[cnt].axis[point].x = atoi(str);
						inputbox_getline("多边形坐标", "请输入多边形点的y坐标\n(依次输入一个，每个点分别进行输入)", str, (sizeof(str) / sizeof(*str)));
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
					}//以上while代码段实现了将结构体中的数据数组化
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
					//绘制多边形
					cnt++;//绘制之后图形数量加1
					break;
				case '4':
					inputbox_getline("椭圆弧线的参数输入", "请输入线的颜色\n1、白色2、绿色3、红色", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入线的宽度", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线中心的x轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线中心的y轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线的起始角角度", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线的终止角角度", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].y = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线x轴半径", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[2].x = atoi(str);
					inputbox_getline("椭圆弧线的参数输入", "请输入椭圆弧线y轴半径", str, sizeof(str) / sizeof(*str));
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
					//绘制圆锥曲线
					cnt++;//绘制之后图形数量加1
					break;
				case '5':
					inputbox_getline("线段的参数输入", "请输入线的颜色\n1、白色2、绿色3、红色", str, sizeof(str) / sizeof(*str));
					draw[cnt].color = atoi(str);
					inputbox_getline("线段的参数输入", "请输入线的宽度", str, sizeof(str) / sizeof(*str));
					draw[cnt].linewide = atoi(str);
					inputbox_getline("线段的参数输入", "请输入起始点的x轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].x = atoi(str);
					inputbox_getline("线段的参数输入", "请输入终止点的y轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[0].y = atoi(str);
					inputbox_getline("线段的参数输入", "请输入起始点的x轴坐标", str, sizeof(str) / sizeof(*str));
					draw[cnt].axis[1].x = atoi(str);
					inputbox_getline("线段的参数输入", "请输入起始点的y轴坐标", str, sizeof(str) / sizeof(*str));
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
					//绘制直线
					cnt++;//绘制之后图形数量加1
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
				cnt--;//撤销之后，图形数目减1
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
	int i = 0;//i用来和cnt比较，需要重画的图形的数目为cnt-1
	int point = 0;//用于取结构体中的多边形的坐标信息
	int pt = 0;//用于取出存储多边形信息的数组里面的值
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
		fprintf(fp, "%d\n",0);//用于分隔每一个图形的数据
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
	int i = 0;//i用来和cnt比较
	int point = 0;//用于取结构体中的多边形的坐标信息
	int pt = 0;//用于取出存储多边形信息的数组里面的值
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