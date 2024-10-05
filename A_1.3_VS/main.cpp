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

// am=automatic[自动]
// al=accomplishment[成就]
// pg=Progress[进度]
// wh=warehouse[仓库]
// uplevellevel=uplevelgrade[升级]
//$add_s_show[按A点击]
// a[最后按下的键]
// al1=[1.空间不足！ - 仓库(1)*2] - 奖励50$
// al2=[2.更高级的马达 - 自动(2)*1] - 奖励自动(1)*5
// al3=[3.更多的钱 - 5000$] - 奖励 $*2;
// al4=[4.流水化工厂 - 自动(2)*200] - 奖励解锁仓库(2)
// al5=[5.赚钱狂魔 - 一秒赚] - 奖励

int main()
{
	// 初始化
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
		if /*老版本界面*/ (old_ui)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
			$_max = 10000 + 2000 * wh1 + 3000 * wh2;
			// 金钱显示
			std::cout << "金钱 $ = [ ";
			while (pg1 < $ * 100 / $_max * 20 / 100)
			{
				std::cout << "█";
				pg1 = pg1 + 2;
			}
			while (pg2 < 20 - pg1)
			{
				std::cout << " ";
				pg2 = pg2 + 1;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
			std::cout << "  ]";
			// 库存显示 & 版本号显示
			std::cout << "	[" << $ / 100 << "/" << $_max / 100 << "]" << "               v1.3" << std::endl
					  << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加

			std::cout << "----------------------------------------------------------------------" << std::endl;

			if (uplevel == 0)
			{
				std::cout << "购买：" << std::endl;
				std::cout << "[";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
				std::cout << "0";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
				std::cout << ".升级面板]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
				std::cout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
				std::cout << ".自动(1) (10$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
				std::cout << "2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
				std::cout << ".仓库(1) (100$)]" << std::endl
						  << std::endl;
			}
			else if (uplevel == 1)
			{
				std::cout << "升级 - 选择面板：" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // 设置红色
				std::cout << "[0.退出面板]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
				std::cout << "     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
				std::cout << "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
				std::cout << ".自动点击]";
				if (al4 != 0)
				{
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "2";

					std::cout << ".仓库]";
				}
				std::cout << std::endl
						  << std::endl;
			}
			else if (uplevel == 2)
			{
				std::cout << "升级 - 自动点击：" << std::endl;
				if (am1 == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // 设置红色
					std::cout << "[0.退出升级]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".依次升级(3) (100$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".全部升级(3) (" << am2 * 100 << "$)]" << std::endl;
				}
				else if (am1 != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // 设置红色
					std::cout << "[0.退出升级]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".依次升级(2) (20$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".全部升级(2) (" << am1 * 20 << "$)]" << std::endl;
				}
			}
			else if (uplevel == 3)
			{
				std::cout << "升级 - 仓库：" << std::endl;
				if (wh1 == 0)
				{
					std::cout << "[0.退出升级]";
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".依次升级(3) (1000$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".全部升级(3) (" << wh2 * 1000 << "$)]" << std::endl;
				}
				else if (wh1 != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); // 设置红色
					std::cout << "[0.退出升级]";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << "     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "1";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".依次升级(2) (200$)]     [";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置绿色和蓝色相加
					std::cout << "2";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
					std::cout << ".全部升级(2) (" << wh1 * 200 << "$)]" << std::endl;
				}
			}
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "成就：" << std::endl;
			if (al1 == 0)
			{
				std::cout << "[1.空间不足！ - 仓库(1)*2] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // 设置绿色
				std::cout << "奖励50$" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			else
			{
				std::cout << "[1.空间不足！ - 仓库(1)*2] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
				std::cout << "已完成" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			if (al2 == 0)
			{
				std::cout << "[2.更高级的马达 - 自动(2)*1] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // 设置绿色
				std::cout << "奖励自动(1)*5" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			else
			{
				std::cout << "[2.更高级的马达 - 自动(2)*1] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
				std::cout << "已完成" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			if (al3 == 0)
			{
				std::cout << "[3.更多的钱 - 5000$] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // 设置绿色
				std::cout << "奖励 $*2;" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			else
			{
				std::cout << "[3.更多的钱 - 5000$] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
				std::cout << "已完成" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			if (al4 == 0)
			{
				std::cout << "[4.流水化工厂 - 自动(2)*200] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); // 设置绿色
				std::cout << "奖励解锁仓库(2)" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
			}
			else
			{
				std::cout << "[4.流水化工厂 - 自动(2)*200] - ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); // 设置红色和绿色相加
				std::cout << "已完成" << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 设置三色相加
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

			// 案件文件读取
			f.open("configure/configure/KEY_DOWN.txt", std::ios::in);
			while (f >> KEY_DOWN_CF)
				;
			f.close();

			// 按键检测
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
			{ // 视图
				std::cout << "视图：" << std::endl
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
				std::cout << "视图：";
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
			// 成就
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
			std::cout << "状态栏：" << std::endl;
			if (am1 != 0)
			{ // 显示点击 (1)
				std::cout << "自动点击(1) x" << am1 << "[" << am1 / 10 << "." << am1 - am1 / 10 * 10 << "/s]" << std::endl;
			}
			if (am2 != 0)
			{ // 显示点击 (2)
				std::cout << "自动点击(2) x" << am2 << "[" << am2 / 10 * 2 << "." << (am2 - am2 / 10 * 10) * 2 << "/s]" << std::endl;
			}
			if (am3 != 0)
			{ // 显示点击 (3)
				std::cout << "自动点击(3) x" << am3 << "[" << am3 / 10 * 5 << "." << (am3 - am3 / 10 * 10) * 2 << "/s]" << std::endl;
			}
			if (wh1 != 0)
			{ // 显示仓库(1)
				std::cout << "仓库(1) x" << wh1 << "[" << wh1 * 20 << "]" << std::endl;
			}
			if (wh2 != 0)
			{ // 显示仓库(2)
				std::cout << "仓库(2) x" << wh2 << "[" << wh2 * 30 << "]" << std::endl;
			}
			if (wh3 != 0)
			{ // 显示仓库(3)
				std::cout << "仓库(3) x" << wh3 << "[" << wh3 * 50 << "]" << std::endl;
			}

			// 按键检测

			// if (KEY_DOWN(65) == true) { //检测按下"a"
			//	while (KEY_DOWN(65) == true) {}//按a+1$
			//	$ = $ + $add_s_show * 10;
			//	a = 65;
			// }
			// if (KEY_DOWN(48) == true) { //检测按下"0"
			//	while (KEY_DOWN(48) == true) {}
			//	a = 48;
			//	if (uplevel == 1) {//如果界面=选择面板并按下0就将界面设为购买
			//		uplevel = 0;
			//	}
			//	else if (uplevel == 0) {//如果界面=购买并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			// }
			// if (KEY_DOWN(49) == true) { //检测按下"1" - 依次升级
			//	while (KEY_DOWN(49) == true) {}
			//	a = 49;
			//	if (uplevel == 0 && $ >= 1000) {//如果界面=购买并$>=10元就购买一个自动(1)
			//		am1 = am1 + 1;
			//		$ = $ - 1000;
			//	}
			//	else if (uplevel == 1) {//如果界面=选择面板并按下1键就将界面设为自动升级
			//		uplevel = 2;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级：
			//		if (am1 == 0 and am2 != 0 and $ >= 10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
			//			$ = $ - 10000;
			//			am2 = am2 - 1;
			//			am3 = am3 + 1;
			//		}
			//		else if (am1 != 0 and $ >= 2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
			//			$ = $ - 2000;
			//			am1 = am1 - 1;
			//			am2 = am2 + 1;
			//		}
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级：
			//		if ($ >= 20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
			//			$ = $ - 20000;
			//			wh1 = wh1 - 1;
			//			wh2 = wh2 + 1;
			//		}
			//		else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
			//			$ = $ - 100000;							       //则消耗一个仓库(2)购买仓库(3)
			//			wh2 = wh2 - 1;
			//			wh3 = wh3 + 1;
			//		}
			//	}
			// }
			// if (KEY_DOWN(50) == true) { //检测按下"2" - 全部升级
			//	while (KEY_DOWN(50) == true) {}
			//	a = 50;
			//	if (uplevel == 0 and $ >= 10000) {//如果界面=购买并$>=100元就购买一个仓库(1)
			//		wh1 = wh1 + 1;
			//		$ = $ - 10000;
			//	}
			//	else if (uplevel == 1) {//如果界面=选择面板并按下2键就将界面设为仓库升级
			//		uplevel = 3;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级：
			//		if (am1 == 0 and $ >= am2 * 10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
			//			$ = $ - am1 * 10000;
			//			am3 = am3 + am2;
			//			am2 = am2 * 0;
			//		}
			//		else if (am1 != 0 and $ >= am1 * 2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
			//			$ = $ - am1 * 2000;
			//			am2 = am2 + am1;
			//			am1 = am1 * 0;
			//		}
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级：
			//		if ($ >= wh1 * 20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
			//			$ = $ - wh1 * 20000;
			//			wh2 = wh2 + wh1;
			//			wh1 = wh1 * 0;
			//		}
			//		else if ($ >= wh2 * 100000 and wh2 >= 1 and wh1 == 0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
			//			$ = $ - wh2 * 100000;							      //则消耗一个仓库(2)购买仓库(3)
			//			wh3 = wh3 + wh2;
			//			wh2 = wh2 * 0;
			//		}
			//	}
			// }
			// if (KEY_DOWN(65) == true) { //检测按下"a"
			//	while (KEY_DOWN(65) == true) {}//按a+1$
			//	$ = $ + $add_s_show * 10;
			//	a = 65;
			// }
			// if (KEY_DOWN(48) == true) { //检测按下"0"
			//	while (KEY_DOWN(48) == true) {}
			//	a = 48;
			//	if (uplevel == 1) {//如果界面=选择面板并按下0就将界面设为购买
			//		uplevel = 0;
			//	}
			//	else if (uplevel == 0) {//如果界面=购买并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级并按下0就将界面设为选择面板
			//		uplevel = 1;
			//	}
			// }
			// if (KEY_DOWN(49) == true) { //检测按下"1" - 依次升级
			//	while (KEY_DOWN(49) == true) {}
			//	a = 49;
			//	if (uplevel == 0 && $ >= 1000) {//如果界面=购买并$>=10元就购买一个自动(1)
			//		am1 = am1 + 1;
			//		$ = $ - 1000;
			//	}
			//	else if (uplevel == 1) {//如果界面=选择面板并按下1键就将界面设为自动升级
			//		uplevel = 2;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级：
			//		if (am1 == 0 and am2 != 0 and $ >= 10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
			//			$ = $ - 10000;
			//			am2 = am2 - 1;
			//			am3 = am3 + 1;
			//		}
			//		else if (am1 != 0 and $ >= 2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
			//			$ = $ - 2000;
			//			am1 = am1 - 1;
			//			am2 = am2 + 1;
			//		}
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级：
			//		if ($ >= 20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
			//			$ = $ - 20000;
			//			wh1 = wh1 - 1;
			//			wh2 = wh2 + 1;
			//		}
			//		else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
			//			$ = $ - 100000;							       //则消耗一个仓库(2)购买仓库(3)
			//			wh2 = wh2 - 1;
			//			wh3 = wh3 + 1;
			//		}
			//	}
			// }
			// if (KEY_DOWN(50) == true) { //检测按下"2" - 全部升级
			//	while (KEY_DOWN(50) == true) {}
			//	a = 50;
			//	if (uplevel == 0 and $ >= 10000) {//如果界面=购买并$>=100元就购买一个仓库(1)
			//		wh1 = wh1 + 1;
			//		$ = $ - 10000;
			//	}
			//	else if (uplevel == 1) {//如果界面=选择面板并按下2键就将界面设为仓库升级
			//		uplevel = 3;
			//	}
			//	else if (uplevel == 2) {//如果界面=自动升级：
			//		if (am1 == 0 and $ >= am2 * 10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
			//			$ = $ - am1 * 10000;
			//			am3 = am3 + am2;
			//			am2 = am2 * 0;
			//		}
			//		else if (am1 != 0 and $ >= am1 * 2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
			//			$ = $ - am1 * 2000;
			//			am2 = am2 + am1;
			//			am1 = am1 * 0;
			//		}
			//	}
			//	else if (uplevel == 3) {//如果界面=仓库升级：
			//		if ($ >= wh1 * 20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
			//			$ = $ - wh1 * 20000;
			//			wh2 = wh2 + wh1;
			//			wh1 = wh1 * 0;
			//		}
			//		else if ($ >= wh2 * 100000 and wh2 >= 1 and wh1 == 0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
			//			$ = $ - wh2 * 100000;							      //则消耗一个仓库(2)购买仓库(3)
			//			wh3 = wh3 + wh2;
			//			wh2 = wh2 * 0;
			//		}
			//	}
			// }
			if (KEY_DOWN_CF == 'a')
			{ // 检测按下"a"
				while (KEY_DOWN(65) == true)
				{
				} // 按a+1$
				$ = $ + $add_s_show * 10;
				a = 65;
			}
			if (KEY_DOWN_CF == '0')
			{ // 检测按下"0"
				while (KEY_DOWN(48) == true)
				{
				}
				a = 48;
				if (uplevel == 1)
				{ // 如果界面=选择面板并按下0就将界面设为购买
					uplevel = 0;
				}
				else if (uplevel == 0)
				{ // 如果界面=购买并按下0就将界面设为选择面板
					uplevel = 1;
				}
				else if (uplevel == 2)
				{ // 如果界面=自动升级并按下0就将界面设为选择面板
					uplevel = 1;
				}
				else if (uplevel == 3)
				{ // 如果界面=仓库升级并按下0就将界面设为选择面板
					uplevel = 1;
				}
			}
			if (KEY_DOWN_CF == '1')
			{ // 检测按下"1" - 依次升级
				while (KEY_DOWN(49) == true)
				{
				}
				a = 49;
				if (uplevel == 0 && $ >= 1000)
				{ // 如果界面=购买并$>=10元就购买一个自动(1)
					am1 = am1 + 1;
					$ = $ - 1000;
				}
				else if (uplevel == 1)
				{ // 如果界面=选择面板并按下1键就将界面设为自动升级
					uplevel = 2;
				}
				else if (uplevel == 2)
				{ // 如果界面=自动升级：
					if (am1 == 0 && am2 != 0 && $ >= 10000)
					{ // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
						$ = $ - 10000;
						am2 = am2 - 1;
						am3 = am3 + 1;
					}
					else if (am1 != 0 && $ >= 2000)
					{ // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
						$ = $ - 2000;
						am1 = am1 - 1;
						am2 = am2 + 1;
					}
				}
				else if (uplevel == 3)
				{ // 如果界面=仓库升级：
					if ($ >= 20000 && wh1 >= 1)
					{ // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
						$ = $ - 20000;
						wh1 = wh1 - 1;
						wh2 = wh2 + 1;
					}
					else if ($ >= 100000 && wh2 >= 1 && wh1 == 0)
					{					// 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
						$ = $ - 100000; // 则消耗一个仓库(2)购买仓库(3)
						wh2 = wh2 - 1;
						wh3 = wh3 + 1;
					}
				}
			}
			if (KEY_DOWN_CF == '2')
			{ // 检测按下"2" - 全部升级
				while (KEY_DOWN(50) == true)
				{
				}
				a = 50;
				if (uplevel == 0 && $ >= 10000)
				{ // 如果界面=购买并$>=100元就购买一个仓库(1)
					wh1 = wh1 + 1;
					$ = $ - 10000;
				}
				else if (uplevel == 1)
				{ // 如果界面=选择面板并按下2键就将界面设为仓库升级
					uplevel = 3;
				}
				else if (uplevel == 2)
				{ // 如果界面=自动升级：
					if (am1 == 0 && $ >= am2 * 10000)
					{ // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
						$ = $ - am1 * 10000;
						am3 = am3 + am2;
						am2 = am2 * 0;
					}
					else if (am1 != 0 && $ >= am1 * 2000)
					{ // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
						$ = $ - am1 * 2000;
						am2 = am2 + am1;
						am1 = am1 * 0;
					}
				}
				else if (uplevel == 3)
				{ // 如果界面=仓库升级：
					if ($ >= wh1 * 20000 && wh1 >= 1)
					{ // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
						$ = $ - wh1 * 20000;
						wh2 = wh2 + wh1;
						wh1 = wh1 * 0;
					}
					else if ($ >= wh2 * 100000 && wh2 >= 1 && wh1 == 0)
					{						  // 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
						$ = $ - wh2 * 100000; // 则消耗一个仓库(2)购买仓库(3)
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