#include <string>
#include <cstdio>
#include <vector>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <graphics.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

// am=automatic[�Զ�]
// al=accomplishment[�ɾ�]
// pg=Progress[����]
// wh=warehouse[�ֿ�]
// uplevellevel=uplevelgrade[����]
//$add_s_show[��A���]
// a[����µļ�]
// al1=[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ����50$
// al2=[2.���߼������ - �Զ�(2)*1] - �����Զ�(1)*5
// al3=[3.�����Ǯ - 5000$] - ���� $*2;
// al4=[4.��ˮ������ - �Զ�(2)*200] - ���������ֿ�(2)
// al5=[5.׬Ǯ��ħ - һ��׬] - ����

int main()
{
	// ��ʼ��
	std::fstream f;
	ExMessage m;
	initgraph(640, 480, EX_SHOWCONSOLE);
	BeginBatchDraw();
	bool old_ui = true, exit = false;
	char KEY_DOWN_CF = 'null';
	double $add_s_show = 10;
	int $ = 500, $_max = 10000, am1 = 0, am2 = 0, am3 = 0, al3 = 0, al4 = 0, al5 = 0, wh1 = 0, wh2 = 0, wh3 = 0, al1 = 0, al2 = 0, pg1 = 0, pg2 = 0, uplevel = 0, a = 65;
	system("start configure/configure/x64/Debug/configure.exe");
	while (!exit)
	{
		if /*�ϰ汾����*/ (old_ui)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
			$_max = 10000 + 2000 * wh1 + 3000 * wh2;
			// ��Ǯ��ʾ
			std::cout << "��Ǯ $ = [ ";
			while (pg1 < $ * 100 / $_max * 20 / 100)
			{
				std::cout << "��";
				pg1 = pg1 + 2;
			}
			while (pg2 < 20 - pg1)
			{
				std::cout << " ";
				pg2 = pg2 + 1;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
			std::cout << "  ]";
			// �����ʾ & �汾����ʾ
			std::cout << "	[" << $ / 100 << "/" << $_max / 100 << "]" << "               v1.3" << std::endl
					  << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���

			std::cout << "----------------------------------------------------------------------" << std::endl;

			if (uplevel == 0)
			{
				std::cout << "����" << std::endl;
				std::cout << "[";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
				std::cout << "0";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
				std::cout << ".�������]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
				std::cout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
				std::cout << ".�Զ�(1) (10$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
				std::cout << "2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
				std::cout << ".�ֿ�(1) (100$)]" << std::endl
						  << std::endl;
			}
			else if (uplevel == 1)
			{
				std::cout << "���� - ѡ����壺" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // ���ú�ɫ
				std::cout << "[0.�˳����]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
				std::cout << "     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
				std::cout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
				std::cout << ".�Զ����]";
				if (al4 != 0)
				{
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "2";

					std::cout << ".�ֿ�]";
				}
				std::cout << std::endl
						  << std::endl;
			}
			else if (uplevel == 2)
			{
				std::cout << "���� - �Զ������" << std::endl;
				if (am1 == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // ���ú�ɫ
					std::cout << "[0.�˳�����]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".��������(3) (100$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".ȫ������(3) (" << am2 * 100 << "$)]" << std::endl;
				}
				else if (am1 != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // ���ú�ɫ
					std::cout << "[0.�˳�����]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".��������(2) (20$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".ȫ������(2) (" << am1 * 20 << "$)]" << std::endl;
				}
			}
			else if (uplevel == 3)
			{
				std::cout << "���� - �ֿ⣺" << std::endl;
				if (wh1 == 0)
				{
					std::cout << "[0.�˳�����]";
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".��������(3) (1000$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".ȫ������(3) (" << wh2 * 1000 << "$)]" << std::endl;
				}
				else if (wh1 != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // ���ú�ɫ
					std::cout << "[0.�˳�����]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".��������(2) (200$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ����ɫ���
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
					std::cout << ".ȫ������(2) (" << wh1 * 200 << "$)]" << std::endl;
				}
			}
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "�ɾͣ�" << std::endl;
			if (al1 == 0)
			{
				std::cout << "[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // ������ɫ
				std::cout << "����50$" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			else
			{
				std::cout << "[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
				std::cout << "�����" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			if (al2 == 0)
			{
				std::cout << "[2.���߼������ - �Զ�(2)*1] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // ������ɫ
				std::cout << "�����Զ�(1)*5" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			else
			{
				std::cout << "[2.���߼������ - �Զ�(2)*1] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
				std::cout << "�����" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			if (al3 == 0)
			{
				std::cout << "[3.�����Ǯ - 5000$] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // ������ɫ
				std::cout << "���� $*2;" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			else
			{
				std::cout << "[3.�����Ǯ - 5000$] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
				std::cout << "�����" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			if (al4 == 0)
			{
				std::cout << "[4.��ˮ������ - �Զ�(2)*200] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // ������ɫ
				std::cout << "���������ֿ�(2)" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			else
			{
				std::cout << "[4.��ˮ������ - �Զ�(2)*200] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // ���ú�ɫ����ɫ���
				std::cout << "�����" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ������ɫ���
			}
			if (al5 == 0)
			{
				std::cout << "" << std::endl;
			}
			else
			{
				std::cout << "" << std::endl;
			}
			std::cout << std::endl;
			std::cout << "----------------------------------------------------------------------" << std::endl;

			// �����ļ���ȡ
			f.open("configure/configure/KEY_DOWN.txt", std::ios::in);
			while (f >> KEY_DOWN_CF)
				;
			f.close();

			// �������
			if (KEY_DOWN_CF == 'a')
			{
				a = 65;
			}
			else if (KEY_DOWN_CF == '0')
			{
				a = 48;
			}
			else if (KEY_DOWN(49) == '1')
			{
				a = 49;
			}
			else if (KEY_DOWN(50) == '2')
			{
				a = 50;
			}

			if (KEY_DOWN(a) == true)
			{ // ��ͼ
				std::cout << "��ͼ��" << std::endl
						  << "           -----";
				std::cout << std::endl
						  << "          |  ";
				if (a == 65)
				{
					std::cout << "A";
				}
				else if (a == 48)
				{
					std::cout << "0";
				}
				else if (a == 49)
				{
					std::cout << "1";
				}
				else if (a == 50)
				{
					std::cout << "2";
				}
				std::cout << "  |";
				std::cout << std::endl
						  << "           -----";
			}
			else
			{
				std::cout << "��ͼ��";
				std::cout << "   -----";
				std::cout << std::endl
						  << "        |  ";
				if (a == 65)
				{
					std::cout << "A";
				}
				else if (a == 48)
				{
					std::cout << "0";
				}
				else if (a == 49)
				{
					std::cout << "1";
				}
				else if (a == 50)
				{
					std::cout << "2";
				}
				std::cout << "  |\\";
				std::cout << std::endl
						  << "        \\-----\\" << std::endl;
			}

			std::cout << std::endl
					  << "----------------------------------------------------------------------" << std::endl;

			$ = $ + am1;
			$ = $ + am2 * 2;
			// �ɾ�
			if (al1 == 0)
			{
				if (wh1 >= 2)
				{
					al1 = al1 + 1;
					$ = $ + 5000;
				}
			}
			if (al2 == 0)
			{
				if (am2 >= 1)
				{
					al2 = al2 + 1;
					am1 = am1 + 5;
				}
			}
			if (al3 == 0)
			{
				if ($ > 500000)
				{
					$ = $ * 2;
					al3 = al3 + 1;
				}
			}
			if (al4 == 0 && am2 >= 200)
			{
				al4 = al4 + 1;
			}
			std::cout << "״̬����" << std::endl;
			if (am1 != 0)
			{ // ��ʾ��� (1)
				std::cout << "�Զ����(1) x" << am1 << "[" << am1 / 10 << "." << am1 - am1 / 10 * 10 << "/s]" << std::endl;
			}
			if (am2 != 0)
			{ // ��ʾ��� (2)
				std::cout << "�Զ����(2) x" << am2 << "[" << am2 / 10 * 2 << "." << (am2 - am2 / 10 * 10) * 2 << "/s]" << std::endl;
			}
			if (am3 != 0)
			{ // ��ʾ��� (3)
				std::cout << "�Զ����(3) x" << am3 << "[" << am3 / 10 * 5 << "." << (am3 - am3 / 10 * 10) * 2 << "/s]" << std::endl;
			}
			if (wh1 != 0)
			{ // ��ʾ�ֿ�(1)
				std::cout << "�ֿ�(1) x" << wh1 << "[" << wh1 * 20 << "]" << std::endl;
			}
			if (wh2 != 0)
			{ // ��ʾ�ֿ�(2)
				std::cout << "�ֿ�(2) x" << wh2 << "[" << wh2 * 30 << "]" << std::endl;
			}
			if (wh3 != 0)
			{ // ��ʾ�ֿ�(3)
				std::cout << "�ֿ�(3) x" << wh3 << "[" << wh3 * 50 << "]" << std::endl;
			}

			// �������

			// if (KEY_DOWN(65) == true) { //��ⰴ��"a"
			//	while (KEY_DOWN(65) == true) {}//��a+1$
			//	$ = $ + $add_s_show * 10;
			//	a = 65;
			// }
			// if (KEY_DOWN(48) == true) { //��ⰴ��"0"
			//	while (KEY_DOWN(48) == true) {}
			//	a = 48;
			//	if (uplevel == 1) {//�������=ѡ����岢����0�ͽ�������Ϊ����
			//		uplevel = 0;
			//	}
			//	else if (uplevel == 0) {//�������=���򲢰���0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�����������0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�����������0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			// }
			// if (KEY_DOWN(49) == true) { //��ⰴ��"1" - ��������
			//	while (KEY_DOWN(49) == true) {}
			//	a = 49;
			//	if (uplevel == 0 && $ >= 1000) {//�������=����$>=10Ԫ�͹���һ���Զ�(1)
			//		am1 = am1 + 1;
			//		$ = $ - 1000;
			//	}
			//	else if (uplevel == 1) {//�������=ѡ����岢����1���ͽ�������Ϊ�Զ�����
			//		uplevel = 2;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�������
			//		if (am1 == 0 and am2 != 0 and $ >= 10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
			//			$ = $ - 10000;
			//			am2 = am2 - 1;
			//			am3 = am3 + 1;
			//		}
			//		else if (am1 != 0 and $ >= 2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
			//			$ = $ - 2000;
			//			am1 = am1 - 1;
			//			am2 = am2 + 1;
			//		}
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�������
			//		if ($ >= 20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
			//			$ = $ - 20000;
			//			wh1 = wh1 - 1;
			//			wh2 = wh2 + 1;
			//		}
			//		else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
			//			$ = $ - 100000;							       //������һ���ֿ�(2)����ֿ�(3)
			//			wh2 = wh2 - 1;
			//			wh3 = wh3 + 1;
			//		}
			//	}
			// }
			// if (KEY_DOWN(50) == true) { //��ⰴ��"2" - ȫ������
			//	while (KEY_DOWN(50) == true) {}
			//	a = 50;
			//	if (uplevel == 0 and $ >= 10000) {//�������=����$>=100Ԫ�͹���һ���ֿ�(1)
			//		wh1 = wh1 + 1;
			//		$ = $ - 10000;
			//	}
			//	else if (uplevel == 1) {//�������=ѡ����岢����2���ͽ�������Ϊ�ֿ�����
			//		uplevel = 3;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�������
			//		if (am1 == 0 and $ >= am2 * 10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
			//			$ = $ - am1 * 10000;
			//			am3 = am3 + am2;
			//			am2 = am2 * 0;
			//		}
			//		else if (am1 != 0 and $ >= am1 * 2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
			//			$ = $ - am1 * 2000;
			//			am2 = am2 + am1;
			//			am1 = am1 * 0;
			//		}
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�������
			//		if ($ >= wh1 * 20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
			//			$ = $ - wh1 * 20000;
			//			wh2 = wh2 + wh1;
			//			wh1 = wh1 * 0;
			//		}
			//		else if ($ >= wh2 * 100000 and wh2 >= 1 and wh1 == 0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
			//			$ = $ - wh2 * 100000;							      //������һ���ֿ�(2)����ֿ�(3)
			//			wh3 = wh3 + wh2;
			//			wh2 = wh2 * 0;
			//		}
			//	}
			// }
			// if (KEY_DOWN(65) == true) { //��ⰴ��"a"
			//	while (KEY_DOWN(65) == true) {}//��a+1$
			//	$ = $ + $add_s_show * 10;
			//	a = 65;
			// }
			// if (KEY_DOWN(48) == true) { //��ⰴ��"0"
			//	while (KEY_DOWN(48) == true) {}
			//	a = 48;
			//	if (uplevel == 1) {//�������=ѡ����岢����0�ͽ�������Ϊ����
			//		uplevel = 0;
			//	}
			//	else if (uplevel == 0) {//�������=���򲢰���0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�����������0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�����������0�ͽ�������Ϊѡ�����
			//		uplevel = 1;
			//	}
			// }
			// if (KEY_DOWN(49) == true) { //��ⰴ��"1" - ��������
			//	while (KEY_DOWN(49) == true) {}
			//	a = 49;
			//	if (uplevel == 0 && $ >= 1000) {//�������=����$>=10Ԫ�͹���һ���Զ�(1)
			//		am1 = am1 + 1;
			//		$ = $ - 1000;
			//	}
			//	else if (uplevel == 1) {//�������=ѡ����岢����1���ͽ�������Ϊ�Զ�����
			//		uplevel = 2;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�������
			//		if (am1 == 0 and am2 != 0 and $ >= 10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
			//			$ = $ - 10000;
			//			am2 = am2 - 1;
			//			am3 = am3 + 1;
			//		}
			//		else if (am1 != 0 and $ >= 2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
			//			$ = $ - 2000;
			//			am1 = am1 - 1;
			//			am2 = am2 + 1;
			//		}
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�������
			//		if ($ >= 20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
			//			$ = $ - 20000;
			//			wh1 = wh1 - 1;
			//			wh2 = wh2 + 1;
			//		}
			//		else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
			//			$ = $ - 100000;							       //������һ���ֿ�(2)����ֿ�(3)
			//			wh2 = wh2 - 1;
			//			wh3 = wh3 + 1;
			//		}
			//	}
			// }
			// if (KEY_DOWN(50) == true) { //��ⰴ��"2" - ȫ������
			//	while (KEY_DOWN(50) == true) {}
			//	a = 50;
			//	if (uplevel == 0 and $ >= 10000) {//�������=����$>=100Ԫ�͹���һ���ֿ�(1)
			//		wh1 = wh1 + 1;
			//		$ = $ - 10000;
			//	}
			//	else if (uplevel == 1) {//�������=ѡ����岢����2���ͽ�������Ϊ�ֿ�����
			//		uplevel = 3;
			//	}
			//	else if (uplevel == 2) {//�������=�Զ�������
			//		if (am1 == 0 and $ >= am2 * 10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
			//			$ = $ - am1 * 10000;
			//			am3 = am3 + am2;
			//			am2 = am2 * 0;
			//		}
			//		else if (am1 != 0 and $ >= am1 * 2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
			//			$ = $ - am1 * 2000;
			//			am2 = am2 + am1;
			//			am1 = am1 * 0;
			//		}
			//	}
			//	else if (uplevel == 3) {//�������=�ֿ�������
			//		if ($ >= wh1 * 20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
			//			$ = $ - wh1 * 20000;
			//			wh2 = wh2 + wh1;
			//			wh1 = wh1 * 0;
			//		}
			//		else if ($ >= wh2 * 100000 and wh2 >= 1 and wh1 == 0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
			//			$ = $ - wh2 * 100000;							      //������һ���ֿ�(2)����ֿ�(3)
			//			wh3 = wh3 + wh2;
			//			wh2 = wh2 * 0;
			//		}
			//	}
			// }
			if (KEY_DOWN_CF == 'a')
			{ // ��ⰴ��"a"
				while (KEY_DOWN(65) == true)
				{
				} // ��a+1$
				$ = $ + $add_s_show * 10;
				a = 65;
			}
			if (KEY_DOWN_CF == '0')
			{ // ��ⰴ��"0"
				while (KEY_DOWN(48) == true)
				{
				}
				a = 48;
				if (uplevel == 1)
				{ // �������=ѡ����岢����0�ͽ�������Ϊ����
					uplevel = 0;
				}
				else if (uplevel == 0)
				{ // �������=���򲢰���0�ͽ�������Ϊѡ�����
					uplevel = 1;
				}
				else if (uplevel == 2)
				{ // �������=�Զ�����������0�ͽ�������Ϊѡ�����
					uplevel = 1;
				}
				else if (uplevel == 3)
				{ // �������=�ֿ�����������0�ͽ�������Ϊѡ�����
					uplevel = 1;
				}
			}
			if (KEY_DOWN_CF == '1')
			{ // ��ⰴ��"1" - ��������
				while (KEY_DOWN(49) == true)
				{
				}
				a = 49;
				if (uplevel == 0 && $ >= 1000)
				{ // �������=����$>=10Ԫ�͹���һ���Զ�(1)
					am1 = am1 + 1;
					$ = $ - 1000;
				}
				else if (uplevel == 1)
				{ // �������=ѡ����岢����1���ͽ�������Ϊ�Զ�����
					uplevel = 2;
				}
				else if (uplevel == 2)
				{ // �������=�Զ�������
					if (am1 == 0 && am2 != 0 && $ >= 10000)
					{ // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
						$ = $ - 10000;
						am2 = am2 - 1;
						am3 = am3 + 1;
					}
					else if (am1 != 0 && $ >= 2000)
					{ // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
						$ = $ - 2000;
						am1 = am1 - 1;
						am2 = am2 + 1;
					}
				}
				else if (uplevel == 3)
				{ // �������=�ֿ�������
					if ($ >= 20000 && wh1 >= 1)
					{ // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
						$ = $ - 20000;
						wh1 = wh1 - 1;
						wh2 = wh2 + 1;
					}
					else if ($ >= 100000 && wh2 >= 1 && wh1 == 0)
					{					// ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
						$ = $ - 100000; // ������һ���ֿ�(2)����ֿ�(3)
						wh2 = wh2 - 1;
						wh3 = wh3 + 1;
					}
				}
			}
			if (KEY_DOWN_CF == '2')
			{ // ��ⰴ��"2" - ȫ������
				while (KEY_DOWN(50) == true)
				{
				}
				a = 50;
				if (uplevel == 0 && $ >= 10000)
				{ // �������=����$>=100Ԫ�͹���һ���ֿ�(1)
					wh1 = wh1 + 1;
					$ = $ - 10000;
				}
				else if (uplevel == 1)
				{ // �������=ѡ����岢����2���ͽ�������Ϊ�ֿ�����
					uplevel = 3;
				}
				else if (uplevel == 2)
				{ // �������=�Զ�������
					if (am1 == 0 && $ >= am2 * 10000)
					{ // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
						$ = $ - am1 * 10000;
						am3 = am3 + am2;
						am2 = am2 * 0;
					}
					else if (am1 != 0 && $ >= am1 * 2000)
					{ // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
						$ = $ - am1 * 2000;
						am2 = am2 + am1;
						am1 = am1 * 0;
					}
				}
				else if (uplevel == 3)
				{ // �������=�ֿ�������
					if ($ >= wh1 * 20000 && wh1 >= 1)
					{ // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
						$ = $ - wh1 * 20000;
						wh2 = wh2 + wh1;
						wh1 = wh1 * 0;
					}
					else if ($ >= wh2 * 100000 && wh2 >= 1 && wh1 == 0)
					{						  // ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
						$ = $ - wh2 * 100000; // ������һ���ֿ�(2)����ֿ�(3)
						wh3 = wh3 + wh2;
						wh2 = wh2 * 0;
					}
				}
			}

			if ($ > $_max)
			{
				$ = $_max;
			}
			_sleep(100);
			system("cls");
			pg1 = 0;
			pg2 = 0;
		}
		FlushBatchDraw();
	}
	closegraph();
}