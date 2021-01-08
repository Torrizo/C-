#include <graphics.h>              // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <windows.h>				//�õ��˶�ʱ����sleep()
#include <math.h>
#include <string.h>
#define PI 3.1416
int r[3][4] = { { 30, 20, 130, 60 }, { 170, 20, 220, 60 }, { 260, 20, 310, 60 } };//������ť�Ķ�ά����
float alpha, R, h0, sim_t;//��ײʱ��������ʧ�ʣ���İ뾶����ʼ�߶ȡ�����ʱ��
//��ť�жϺ���
int button_judge(int x, int y)
{
	if (x>r[0][0] && x<r[0][2] && y>r[0][1] && y<r[0][3])return 1;
	if (x>r[1][0] && x<r[1][2] && y>r[1][1] && y<r[1][3])return 2;
	if (x>r[2][0] && x<r[2][2] && y>r[2][1] && y<r[2][3])return 3;
	return 0;
}
//��ʼ��ͼ��
void init_figure()
{
	int i;
	setrop2(R2_COPYPEN);//��ǰ��ɫ
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);//ʵ��
	rectangle(30, 100, 420, 330);//�����
	setlinestyle(PS_DOT);//����
	for (i = 30 + 39; i<420; i += 39)
	{
		line(i, 100, i, 330);//��ֱ������
	}
	for (i = 100 + 23; i<330; i += 23)
	{
		line(30, i, 420, i);//ˮƽ������
	}
}
//��������
int simulation()
{
	char t[3];//�ٷ�ֵ���ַ�
	char *out_text;
	float dt = 0.01;//������10ms
	float dy = 230 / h0;//��λ������
	long int N = (long int)(sim_t / dt);//��������
	float *h = (float*)calloc(N, sizeof(float));//�߶�
	float *v = (float*)calloc(N, sizeof(float));//�ٶȣ���ֱ����
	long int i;//��������
	float process_duty;//����
	RECT r = { 370, 35, 400, 65 };//�ٷ�ֵ��ʾ����ľ���ָ��
	init_figure();//��ʼ��ͼ������
	setrop2(R2_COPYPEN);//��ǰ��ɫ
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillrectangle(354, 19, 411, 81);//����ԭ����������
	setlinestyle(PS_NULL);//������
	setbkmode(TRANSPARENT);//����������䱳��Ϊ͸��
	//���㲽��
	h[0] = h0; v[0] = 0;
	BeginBatchDraw();//��ʼ������
	for (i = 1; i<N; i++)
	{
		if (h[i - 1]>R)//δ������ײ
		{
			v[i] = v[i - 1] - 9.8*dt;//�ٶȼ���
		}
		else//������ײ��������ʧalpha���ٶ���ʧalpha�Ŀ���
		{
			v[i] = -sqrt(alpha)*v[i - 1];
		}
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillrectangle(354, 19, 416, 81);//����ԭ����������
		h[i] = h[i - 1] + v[i] * dt;//�߶ȼ���
		process_duty = (i + 1) / (float)(N);
		setlinestyle(PS_SOLID);
		putpixel(30 + (int)(process_duty * 390), 330 - (int)(h[i] * dy), RED);
		setfillcolor(BLUE);
		setlinestyle(PS_NULL);
		fillpie(355, 20, 415, 80, 0, process_duty * 2 * PI);
		setfillcolor(WHITE);
		fillcircle(385, 50, 20);
		sprintf(t, "%d", (int)(process_duty*100.0));//����ת��Ϊ�ַ���
		out_text = strcat(t, "%");//���һ���ٷֺ�
		drawtext(out_text, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Sleep(dt * 1000);
		FlushBatchDraw();//ˢ�»�����
	}
	EndBatchDraw();//����������
	free(h);
	free(v);
	return 0;
}
int main()
{
	int i, event = 0;
	char s[30];//�����ַ�������
	short win_width, win_height;//���崰�ڵĿ�Ⱥ͸߶�
	win_width = 480; win_height = 360;
	initgraph(win_width, win_height);//��ʼ�����ڣ�������
	for (i = 0; i<256; i += 5)
	{
		setbkcolor(RGB(i, i, i));//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
		cleardevice();//������ȡ���ڱ���ɫ��
		Sleep(30);//��ʱ30ms
	}
	RECT R1 = { r[0][0], r[0][1], r[0][2], r[0][3] };
	RECT R2 = { r[1][0], r[1][1], r[1][2], r[1][3] };
	RECT R3 = { r[2][0], r[2][1], r[2][2], r[2][3] };
	LOGFONT f;//������ʽָ��
	gettextstyle(&f);					//��ȡ������ʽ
	_tcscpy(f.lfFaceName, _T("����"));	//��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	settextcolor(BLACK);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
	drawtext("�������", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("����", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R2���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("�˳�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R3���������֣�ˮƽ���У���ֱ���У�������ʾ
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	MOUSEMSG m;//���ָ��

	while (true)
	{
		m = GetMouseMsg();//��ȡһ�������Ϣ

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//������ɫΪ����ɫ
			setlinestyle(PS_SOLID, 3);//���û�����ʽΪʵ�֣�10��
			setfillcolor(WHITE);//�����ɫΪ��ɫ
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//��¼��һ�δ����İ�ť
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//�п������Σ�X1,Y1,X2,Y2��
				}
			}
			else
			{
				if (event != 0)//�ϴδ����İ�ťδ������Ϊԭ������ɫ
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//����ͬ��Ϊԭ����ɫ
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)
			for (i = 0; i <= 10; i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//����Բ��ɫ
				circle(m.x, m.y, 2 * i);
				Sleep(20);//ͣ��30ms
				circle(m.x, m.y, 2 * i);//Ĩȥ�ոջ���Բ
			}
			//���հ�ť�ж����������Ĳ���
			switch (button_judge(m.x, m.y))
			{
				//��ԭ��ťԭ��
			case 1:
				InputBox(s, 30, "��������ײʱ��������ʧ�ʡ���İ뾶����ʼ�߶ȡ�����ʱ��");
				sscanf(s, "%f%f%f%f", &alpha, &R, &h0, &sim_t);//�������ַ�������ɨ�赽ȫ�ֱ�������
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 2:
				simulation();//��������
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 3:
				closegraph();//�رջ�ͼ����
				exit(0);//�����˳�
			default:
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				//printf("\r\n(%d,%d)",m.x,m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
		}
	}
	return 0;
}
