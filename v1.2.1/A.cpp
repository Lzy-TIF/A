#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cstdio>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//am=automatic[�Զ�] 
//al=accomplishment[�ɾ�]
//pg=Progress[����]
//wh=warehouse[�ֿ�]
//up=upgrade[����]
//$s[��A���] 
//a[����µļ�]
//al1=[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ����50$ 
//al2=[2.���߼������ - �Զ�(2)*1] - �����Զ�(1)*5 
//al3=[3.�����Ǯ - 5000$] - ���� $*2; 
//al4=[4.��ˮ������ - �Զ�(2)*200] - ���������ֿ�(2) 
//al5=[5.׬Ǯ��ħ - һ��׬] - ���� 
using namespace std;
int main () {
	int $=500,$s=10,max$=10000,am1=0,am2=0,am3=0,al3=0,al4=0,al5=0,wh1=0,wh2=0,wh3=0,al1=0,al2=0,pg1=0,pg2=0,up=0,a=65;
	while (1 == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
		max$ = 10000+2000*wh1+3000*wh2;
		cout<<"��Ǯ $ = [ ";
		while (pg1 < $*100/max$*20/100) {
			cout<<"��";
			pg1 = pg1+2;
		}
		while (pg2 < 20-pg1) {
			cout<<" ";
			pg2 = pg2+1;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
		cout<<"  ]";
		cout<<"	["<<$/100<<"/"<<max$/100<<"]"<<"               v1.21"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		cout<<"----------------------------------------------------------------------"<<endl;
		if (up == 0) {
			cout<<"����"<<endl; 
			cout<<"[";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
			cout<<"0";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
			cout<<".�������]     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
			cout<<"1";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
			cout<<".�Զ�(1) (10$)]     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
			cout<<"2";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
			cout<<".�ֿ�(1) (100$)]"<<endl<<endl;
		} else if (up == 1) {
			cout<<"���� - ѡ����壺"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
			cout<<"[0.�˳����]";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
			cout<<"     [";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
			cout<<"1";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
			cout<<".�Զ����]";
			if (al4 != 0) {
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"2";
				
				cout<<".�ֿ�]";
			}
			cout<<endl<<endl;
		} else if (up == 2) {
			cout<<"���� - �Զ������"<<endl;
			if (am1 == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
				cout<<"[0.�˳�����]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".��������(3) (100$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".ȫ������(3) ("<<am2*100<<"$)]"<<endl;
			} else if (am1 != 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
				cout<<"[0.�˳�����]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".��������(2) (20$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".ȫ������(2) ("<<am1*20<<"$)]"<<endl;
			}
		} else if (up == 3) {
			cout<<"���� - �ֿ⣺"<<endl;
			if (wh1 == 0) {
				cout<<"[0.�˳�����]";
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".��������(3) (1000$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".ȫ������(3) ("<<wh2*1000<<"$)]"<<endl;
			} else if (wh1 != 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
				cout<<"[0.�˳�����]";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<"     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".��������(2) (200$)]     [";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);//������ɫ����ɫ���
				cout<<"2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
				cout<<".ȫ������(2) ("<<wh1*200<<"$)]"<<endl;
			}
		}
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"�ɾͣ�"<<endl;
		if (al1 == 0) {
			cout<<"[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			cout<<"����50$"<<endl;	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		} else {
			cout<<"[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
			cout<<"�����"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		}
		if (al2 == 0) {
			cout<<"[2.���߼������ - �Զ�(2)*1] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			cout<<"�����Զ�(1)*5"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		} else {
			cout<<"[2.���߼������ - �Զ�(2)*1] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
			cout<<"�����"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		}
		if (al3 == 0) {
			cout<<"[3.�����Ǯ - 5000$] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			cout<<"���� $*2;"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		} else {
			cout<<"[3.�����Ǯ - 5000$] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
			cout<<"�����"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		}
		if (al4 == 0) {
			cout<<"[4.��ˮ������ - �Զ�(2)*200] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
			cout<<"���������ֿ�(2)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		} else {
			cout<<"[4.��ˮ������ - �Զ�(2)*200] - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);//���ú�ɫ����ɫ���
			cout<<"�����"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		}
		if (al5 == 0) {
			cout<<""<<endl;
		} else {
			cout<<""<<endl;
		}
		cout<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		//������� 
		if (KEY_DOWN (65) == true) {
			a = 65;
		} else if (KEY_DOWN (48) == true) {
			a = 48;
		} else if (KEY_DOWN (49) == true) {
			a = 49;
		} else if (KEY_DOWN (50) == true) {
			a = 50;
		}
		
		if (KEY_DOWN (a) == true) {//��ͼ
			cout<<"��ͼ��"<<endl<<"           -----";
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
			cout<<"��ͼ��"; 
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
		//�ɾ� 
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
		cout<<"״̬����"<<endl;
		if (am1 != 0) {//��ʾ��� (1)
			cout<<"�Զ����(1) x"<<am1<<"["<<am1/10<<"."<<am1-am1/10*10<<"/s]"<<endl;
		} 
		if (am2 != 0) {//��ʾ��� (2)
			cout<<"�Զ����(2) x"<<am2<<"["<<am2/10*2<<"."<<(am2-am2/10*10)*2 <<"/s]"<<endl;
		} 
		if (am3 != 0) {//��ʾ��� (3)
			cout<<"�Զ����(3) x"<<am3<<"["<<am3/10*5<<"."<<(am3-am3/10*10)*2 <<"/s]"<<endl;
		} 
		if (wh1 != 0) {//��ʾ�ֿ�(1)
			cout<<"�ֿ�(1) x"<<wh1<<"["<<wh1*20<<"]"<<endl;
		}
		if (wh2 != 0) {//��ʾ�ֿ�(2)
			cout<<"�ֿ�(2) x"<<wh2<<"["<<wh2*30<<"]"<<endl;
		}
		if (wh3 != 0) {//��ʾ�ֿ�(3)
			cout<<"�ֿ�(3) x"<<wh3<<"["<<wh3*50<<"]"<<endl;
		}
		if ($s != 1) {//��"A" 
			cout<<"A x"<<$s<<"["<<$s/10<<"."<<$s-$s/10*10<<"]"<<endl;
		}
		
		if (KEY_DOWN (65) == true) { //��ⰴ��"a" 
    		while (KEY_DOWN (65) == true) {}//��a+1$ 
    		$ = $+$s*10;
    		a = 65;
		}
		
		if (KEY_DOWN (48) == true) { //��ⰴ��"0"
			while (KEY_DOWN (48) == true) {}
			a = 48;
			if (up == 1) {//�������=ѡ����岢����0�ͽ�������Ϊ����
				up = 0;	
			} else if (up == 0) {//�������=���򲢰���0�ͽ�������Ϊѡ����� 
				up = 1;
			} else if (up == 2) {//�������=�Զ�����������0�ͽ�������Ϊѡ����� 
				up = 1;
			} else if (up == 3) {//�������=�ֿ�����������0�ͽ�������Ϊѡ����� 
				up = 1;
			}
		} 
		
		if (KEY_DOWN (49) == true) { //��ⰴ��"1" - �������� 
    		while (KEY_DOWN (49) == true) {}
    		a = 49;
    		if (up == 0 & $ >= 1000) {//�������=����$>=10Ԫ�͹���һ���Զ�(1)
    			am1 = am1+1;
    			$ = $-1000;
			} else if (up == 1) {//�������=ѡ����岢����1���ͽ�������Ϊ�Զ����� 
				up = 2;
			} else if (up == 2) {//�������=�Զ������� 
				if (am1 == 0 and am2 != 0 and $ >= 10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3) 
					$ = $-10000;
					am2 = am2-1;
					am3 = am3+1;
				} else if (am1 != 0 and $ >= 2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
					$ = $-2000;
					am1 = am1-1;
					am2 = am2+1;
				}
			} else if (up == 3) {//�������=�ֿ������� 
				if ($ >= 20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2) 
					$ = $-20000;
					wh1 = wh1-1;
					wh2 = wh2+1;
				} else if ($ >= 100000 and wh2 >= 1 and wh1 == 0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0 
					$ = $-100000;							       //������һ���ֿ�(2)����ֿ�(3) 
					wh2 = wh2-1;
					wh3 = wh3+1;
				}
			}
		}
		
		if (KEY_DOWN (50) == true) { //��ⰴ��"2" - ȫ������ 
			while (KEY_DOWN (50) == true) {}
			a = 50;
			if (up == 0 and $ >=10000) {//�������=����$>=100Ԫ�͹���һ���ֿ�(1)
				wh1 = wh1+1;
				$ = $-10000;
			} else if (up == 1){//�������=ѡ����岢����2���ͽ�������Ϊ�ֿ����� 
				up = 3;
			} else if (up == 2) {//�������=�Զ������� 
				if (am1 == 0 and $ >= am2*10000) {//����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3) 
					$ = $-am1*10000;
					am3 = am3+am2;
					am2 = am2*0; 
				} else if (am1 != 0 and $ >= am1*2000) {//����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
					$ = $-am1*2000;
					am2 = am2+am1;
					am1 = am1*0; 
				}	
			} else if (up == 3) {//�������=�ֿ�������
				if ($ >= wh1*20000 and wh1 >= 1) {//���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2) 
					$ = $-wh1*20000;
					wh2 = wh2+wh1;
					wh1 = wh1*0;
				} else if ($ >= wh2*100000 and wh2 >= 1 and wh1 ==0) {//���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0 
					$ = $-wh2*100000;							      //������һ���ֿ�(2)����ֿ�(3) 
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
