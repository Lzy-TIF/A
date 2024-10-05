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
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

int main() {
	std::fstream f;
	while (true) {
		if (KEY_DOWN(65) == true) { //检测按下"a" 
			f.open("KEY_DOWN.txt", std::ios::out);
			f << "a";
			f.close();
		}else
		if (KEY_DOWN(48) == true) { //检测按下"0"
			f.open("KEY_DOWN.txt", std::ios::out);
			f << "0";
			f.close();
		}else
		if (KEY_DOWN(49) == true) { //检测按下"1"
			f.open("KEY_DOWN.txt", std::ios::out);
			f << "1";
			f.close();
		}else
		if (KEY_DOWN(50) == true) { //检测按下"2"
			f.open("KEY_DOWN.txt", std::ios::out);
			f << "2";
			f.close();
		}
		else {
			f.open("KEY_DOWN.txt", std::ios::out);
			f << "null";
			f.close();
		}
	}
}