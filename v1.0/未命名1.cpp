#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cstdio>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//am=automatic[???] 
//al=accomplishment[???]
//pg=Progress[????]
//wh=warehouse[???]
//show[???]
//up=upgrade[????]
//al1=[1.????????????] - ????50$ 
//al2=[2.????????(2)] - ???????(1)*5 
//
using namespace std;
int main () {
	int $=10000,max$=10000,am1=0,am2=0,wh1=0,al1=0,al2=0,show=0,pg1=0,pg2=0,up=0;
	while (1 == 1) {
		max$ = 10000+5000*wh1;
		cout<<"$ = [";
		while (pg1 < $*100/max$*20/100) {
			cout<<"|";
			pg1 = pg1+1;
		}
		while (pg2 < 20-pg1) {
			cout<<" ";
			pg2 = pg2+1;
		}
		cout<<"]";
		cout<<"	["<<$/100<<"/"<<max$/100<<"]"<<endl<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		if (up == 0) {
			cout<<"????"<<endl; 
			if (am1 != 0) {	
				cout<<"[0.???????]	";
			} 
			cout<<"[1.???(1) (10$)] 	[2.???(1) (100$)]"<<endl<<endl;
		} else {
			cout<<"??????��"<<endl;
			cout<<"[0.??????]	[1.????????(2) (20$)]	[2.???????(2) ("<<am1*20<<"$)]"<<endl<<endl;
		} 
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"????"<<endl;
		if (al1 == 0) {
			cout<<"[1.????????????] - ????50$"<<endl;	
		} 
		if (al2 == 0) {
			cout<<"[2.????????(2)] - ???????(1)*5 "<<endl;
		}
		cout<<endl;
		cout<<"----------------------------------------------------------------------"<<endl;
		
		if (KEY_DOWN (65) == true) {//???"A"
			cout<<endl<<"?????"<<endl<<"           -----";
			cout	  <<endl<<"          |  A  |";
			cout	  <<endl<<"           -----";
		} else {
			cout<<endl<<"?????"; 
			cout	<<"   -----";
			cout<<endl<<"        |  A  |\\";
			cout<<endl<<"        \\-----\\";
			
		}
		
		$ = $+am1;
		$ = $+am2*2;
		
		if (al1 == 0) {
			if (wh1 >= 1) {
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
		
		if (am1 != 0) {//?????? 
			cout<<"??????(1) x"<<am1<<"["<<am1/10<<"."<<am1-am1/10*10 <<"/s]"<<endl;
		} 
		if (am2 != 0) {//?????? 
			cout<<"??????(2) x"<<am2<<"["<<am2/10*2<<"."<<(am2-am2/10*10)*2 <<"/s]"<<endl;
		} 
		if (KEY_DOWN (65) == true) {//????? 
    		while (KEY_DOWN (65) == true) {}
    		$ = $+100;
		}
		
		if (KEY_DOWN (48) == true) {
			while (KEY_DOWN (48) == true) {}
			if (up == 0) {
				up = 1;
			} else {
				up = 0;
			}
		} 
		
		if ($ >= 1000) {
			if (KEY_DOWN (49) == true) {//????? 
    			while (KEY_DOWN (49) == true) {}
    			if (up == 0) {
    				am1 = am1+1;
    				$ = $-1000;
				} else {
					if ($ > 50) {
						if (am1 != 0) {
							$ = $-2000;
							am1 = am1-1;
							am2 = am2+1;
						}
					} 
				}
			}
		}
		
		if (KEY_DOWN (50) == true) {
			while (KEY_DOWN (50) == true) {}
			if (up == 0) {
				if ($ >= 10000){
					wh1 = wh1+1;
					$ = $-10000;
				}
			} else {
				if ($ > am1*2000) {
					$ = $-am1*2000;
					am2 = am2+am1;
					am1 = am1*0; 
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
