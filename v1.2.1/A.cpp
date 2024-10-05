#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cstdio>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//am=automatic[自动] 
//al=accomplishment[成就]
//pg=Progress[进度]
//wh=warehouse[仓库]
//up=upgrade[升级]
//$s[按A点击] 
//a[最后按下的键]
//al1=[1.空间不足！ - 仓库(1)*2] - 奖励50$ 
//al2=[2.更高级的马达 - 自动(2)*1] - 奖励自动(1)*5 
//al3=[3.更多的钱 - 5000$] - 奖励 $*2; 
//al4=[4.流水化工厂 - 自动(2)*200] - 奖励解锁仓库(2) 
//al5=[5.赚钱狂魔 - 一秒赚] - 奖励 
using namespace std;
int main () {
	int $=500,$s=10,max$=10000,am1=0,am2=0,am3=0,al3=0,al4=0,al5=0,wh1=0,wh2=0,wh3=0,al1=0,al2=0,pg1=0,pg2=0,up=0,a=65;
	while (1 == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
		max$ = 10000+2000*wh1+3000*wh2;
		cout<<"金钱 $ = [ ";
		while (pg1 < $*100/max$*20/100) {
			cout<<"█";
			pg1 = pg1+2;
		}
		while (pg2 < 20-pg1) {
			cout<<" ";
			pg2 = pg2+1;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
		cout<<"  ]";
		cout<<"	["<<$/100<<"/"<<max$/100<<"]"<<"               v1.21"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		cout<<"----------------------------------------------------------------------"<<endl;
		if (up == 0) {
			cout<<"购买："<<endl; 
			cout<<"[";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
			cout<<"0";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
			cout<<".升级面板]     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
			cout<<"1";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
			cout<<".自动(1) (10$)]     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
			cout<<"2";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
			cout<<".仓库(1) (100$)]"<<endl<<endl;
		} else if (up == 1) {
			cout<<"升级 - 选择面板："<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
			cout<<"[0.退出面板]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
			cout<<"     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
			cout<<"1";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
			cout<<".自动点击]";
			if (al4 != 0) {
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"2";
				
				cout<<".仓库]";
			}
			cout<<endl<<endl;
		} else if (up == 2) {
			cout<<"升级 - 自动点击："<<endl;
			if (am1 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
				cout<<"[0.退出升级]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".依次升级(3) (100$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".全部升级(3) ("<<am2*100<<"$)]"<<endl;
			} else if (am1 != 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
				cout<<"[0.退出升级]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".依次升级(2) (20$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".全部升级(2) ("<<am1*20<<"$)]"<<endl;
			}
		} else if (up == 3) {
			cout<<"升级 - 仓库："<<endl;
			if (wh1 == 0) {
				cout<<"[0.退出升级]";
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".依次升级(3) (1000$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".全部升级(3) ("<<wh2*1000<<"$)]"<<endl;
			} else if (wh1 != 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
				cout<<"[0.退出升级]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".依次升级(2) (200$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//设置绿色和蓝色相加
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
				cout<<".全部升级(2) ("<<wh1*200<<"$)]"<<endl;
			}
		}
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"成就："<<endl;
		if (al1 == 0) {
			cout<<"[1.空间不足！ - 仓库(1)*2] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
			cout<<"奖励50$"<<endl;	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		} else {
			cout<<"[1.空间不足！ - 仓库(1)*2] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
			cout<<"已完成"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		}
		if (al2 == 0) {
			cout<<"[2.更高级的马达 - 自动(2)*1] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
			cout<<"奖励自动(1)*5"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		} else {
			cout<<"[2.更高级的马达 - 自动(2)*1] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
			cout<<"已完成"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		}
		if (al3 == 0) {
			cout<<"[3.更多的钱 - 5000$] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
			cout<<"奖励 $*2;"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		} else {
			cout<<"[3.更多的钱 - 5000$] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
			cout<<"已完成"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		}
		if (al4 == 0) {
			cout<<"[4.流水化工厂 - 自动(2)*200] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
			cout<<"奖励解锁仓库(2)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		} else {
			cout<<"[4.流水化工厂 - 自动(2)*200] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//设置红色和绿色相加
			cout<<"已完成"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		}
		if (al5 == 0) {
			cout<<""<<endl;
		} else {
			cout<<""<<endl;
		}
		cout<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		//按键检测 
		if (KEY_DOWN (65) == true) {
			a = 65;
		} else if (KEY_DOWN (48) == true) {
			a = 48;
		} else if (KEY_DOWN (49) == true) {
			a = 49;
		} else if (KEY_DOWN (50) == true) {
			a = 50;
		}
		
		if (KEY_DOWN (a) == true) {//视图
			cout<<"视图："<<endl<<"           -----";
			cout<<endl<<"          |  ";
			if (a == 65) {
				cout<<"A";
			} else if (a == 48) {
				cout<<"0";
			} else if (a == 49) {
				cout<<"1";
			} else if (a == 50) {
				cout<<"2";
			}
			cout<<"  |";
			cout<<endl<<"           -----";
		} else {
			cout<<"视图："; 
			cout<<"   -----";
			cout<<endl<<"        |  ";
			if (a == 65) {
				cout<<"A";
			} else if (a == 48) {
				cout<<"0";
			} else if (a == 49) {
				cout<<"1";
			} else if (a == 50) {
				cout<<"2";
			}
			cout<<"  |\\";
			cout<<endl<<"        \\-----\\"<<endl;	
		}
		
		cout<<endl<<"----------------------------------------------------------------------"<<endl;
		
		$ = $+am1;
		$ = $+am2*2;
		//成就 
		if (al1 == 0) {
			if (wh1 >= 2) {
				al1 = al1+1;
				$ = $+5000;
			}
		}
		if (al2 == 0) {
			if (am2 >= 1) {
				al2 = al2+1;
				am1 = am1+5;
			}
		}
		if (al3 == 0) {
			if ($ > 500000) {
				$ = $*2;
				al3 = al3+1;
			}
		}
		if (al4 == 0 and am2 >= 200) {
			al4 = al4+1;
		}
		cout<<"状态栏："<<endl;
		if (am1 != 0) {//显示点击 (1)
			cout<<"自动点击(1) x"<<am1<<"["<<am1/10<<"."<<am1-am1/10*10<<"/s]"<<endl;
		} 
		if (am2 != 0) {//显示点击 (2)
			cout<<"自动点击(2) x"<<am2<<"["<<am2/10*2<<"."<<(am2-am2/10*10)*2 <<"/s]"<<endl;
		} 
		if (am3 != 0) {//显示点击 (3)
			cout<<"自动点击(3) x"<<am3<<"["<<am3/10*5<<"."<<(am3-am3/10*10)*2 <<"/s]"<<endl;
		} 
		if (wh1 != 0) {//显示仓库(1)
			cout<<"仓库(1) x"<<wh1<<"["<<wh1*20<<"]"<<endl;
		}
		if (wh2 != 0) {//显示仓库(2)
			cout<<"仓库(2) x"<<wh2<<"["<<wh2*30<<"]"<<endl;
		}
		if (wh3 != 0) {//显示仓库(3)
			cout<<"仓库(3) x"<<wh3<<"["<<wh3*50<<"]"<<endl;
		}
		if ($s != 1) {//按"A" 
			cout<<"A x"<<$s<<"["<<$s/10<<"."<<$s-$s/10*10<<"]"<<endl;
		}
		
		if (KEY_DOWN (65) == true) { //检测按下"a" 
    		while (KEY_DOWN (65) == true) {}//按a+1$ 
    		$ = $+$s*10;
    		a = 65;
		}
		
		if (KEY_DOWN (48) == true) { //检测按下"0"
			while (KEY_DOWN (48) == true) {}
			a = 48;
			if (up == 1) {//如果界面=选择面板并按下0就将界面设为购买
				up = 0;	
			} else if (up == 0) {//如果界面=购买并按下0就将界面设为选择面板 
				up = 1;
			} else if (up == 2) {//如果界面=自动升级并按下0就将界面设为选择面板 
				up = 1;
			} else if (up == 3) {//如果界面=仓库升级并按下0就将界面设为选择面板 
				up = 1;
			}
		} 
		
		if (KEY_DOWN (49) == true) { //检测按下"1" - 依次升级 
    		while (KEY_DOWN (49) == true) {}
    		a = 49;
    		if (up == 0 & $ >= 1000) {//如果界面=购买并$>=10元就购买一个自动(1)
    			am1 = am1+1;
    			$ = $-1000;
			} else if (up == 1) {//如果界面=选择面板并按下1键就将界面设为自动升级 
				up = 2;
			} else if (up == 2) {//如果界面=自动升级： 
				if (am1 == 0 and am2 != 0 and $ >= 10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3) 
					$ = $-10000;
					am2 = am2-1;
					am3 = am3+1;
				} else if (am1 != 0 and $ >= 2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
					$ = $-2000;
					am1 = am1-1;
					am2 = am2+1;
				}
			} else if (up == 3) {//如果界面=仓库升级： 
				if ($ >= 20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2) 
					$ = $-20000;
					wh1 = wh1-1;
					wh2 = wh2+1;
				} else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0 
					$ = $-100000;							       //则消耗一个仓库(2)购买仓库(3) 
					wh2 = wh2-1;
					wh3 = wh3+1;
				}
			}
		}
		
		if (KEY_DOWN (50) == true) { //检测按下"2" - 全部升级 
			while (KEY_DOWN (50) == true) {}
			a = 50;
			if (up == 0 and $ >=10000) {//如果界面=购买并$>=100元就购买一个仓库(1)
				wh1 = wh1+1;
				$ = $-10000;
			} else if (up == 1){//如果界面=选择面板并按下2键就将界面设为仓库升级 
				up = 3;
			} else if (up == 2) {//如果界面=自动升级： 
				if (am1 == 0 and $ >= am2*10000) {//如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3) 
					$ = $-am1*10000;
					am3 = am3+am2;
					am2 = am2*0; 
				} else if (am1 != 0 and $ >= am1*2000) {//如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
					$ = $-am1*2000;
					am2 = am2+am1;
					am1 = am1*0; 
				}	
			} else if (up == 3) {//如果界面=仓库升级：
				if ($ >= wh1*20000 and wh1 >= 1) {//如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2) 
					$ = $-wh1*20000;
					wh2 = wh2+wh1;
					wh1 = wh1*0;
				} else if ($ >= wh2*100000 and wh2 >= 1 and wh1 ==0) {//如果$>=1000元并且仓库(2)>=1并且仓库(1)=0 
					$ = $-wh2*100000;							      //则消耗一个仓库(2)购买仓库(3) 
					wh3 = wh3+wh2;
					wh2 = wh2*0;
				} 
				
			}
		}
		
		if ($ > max$) {
			$ = max$;
		}
		_sleep(100);
		system ("cls");
		pg1 = 0;
		pg2 = 0;
	} 
}
