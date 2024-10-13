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
#include "Lzy_TIF.h"
/*
am=automatic[自动]
al=accomplishment[成就]
pg=Progress[进度]
wh=warehouse[仓库]
uplevellevel=uplevelgrade[升级]
$add_s_show[按A点击]
last_down[最后按下的键]
al[0]=[1.空间不足！ - 仓库(1)*2] - 奖励50$
al[1]=[2.更高级的马达 - 自动(2)*1] - 奖励自动(1)*5
al[2]=[3.更多的钱 - 5000$] - 奖励 $*2;
al[3]=[4.流水化工厂 - 自动(2)*200] - 奖励解锁仓库(2)
al[4]=[5.赚钱狂魔 - 一秒赚] - 奖励
norr=number of rows remaining[剩余行数] max:8
cls_time[刷新剩余时间]
rfs=refresh
*/

int main()
{
    // 初始化
    HANDLE hOutput;
    COORD coord = {0, 0};
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    std::fstream f;
    double $add_s_show = 10;
    bool rfs_new = false;
    int $ = 500, $_max = 10000, am[8] = {0, 0, 0}, al[8] = {0, 0, 0, 0, 0}, wh[8] = {0, 0, 0}, pg1 = 0, pg2 = 0, uplevel = 0, last_down = 65, cls_time = 25;
    while (true)
    {
        SetConsoleCursorPosition(hOutput, coord);

        set_color_yellow;
        $_max = 10000 + 2000 * wh[0] + 3000 * wh[1];
        // 金钱显示
        printf("金钱 $ = [ ");
        while (pg1 < $ * 100 / $_max * 20 / 100)
        {
            printf("█");
            pg1 = pg1 + 2;
        }
        while (pg2 < 20 - pg1)
        {
            printf(" ");
            pg2 = pg2 + 1;
        }
        printf("  ]");
        // 库存显示 && 版本号显示
        printf("  [%d/%d]                v1.3.1\n", $ / 100, $_max / 100);
        set_color_white;

        printf("----------------------------------------------------------------------\n");

        // 商店
        if (uplevel == 0)
        {
            printf("购买: \n[");
            set_color_cyan;
            printf("0");
            set_color_white;
            printf(".升级面板]     [");
            set_color_cyan;
            printf("1");
            set_color_white;
            printf(".自动(1) (10$)]     [");
            set_color_cyan;
            printf("2");
            set_color_white;
            printf(".仓库(1) (100$)]\n\n");
        }
        else if (uplevel == 1)
        {
            printf("升级 - 选择面板：\n");
            set_color_red;
            printf("[0.退出面板]");
            set_color_white;
            printf("     [");
            set_color_cyan;
            printf("1");
            set_color_white;
            printf(".自动点击]");
            if (al[3] != 0)
            {
                printf("     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".仓库]");
            }
            printf("\n\n");
        }
        else if (uplevel == 2)
        {
            printf("升级 - 自动点击: \n");
            if (am[0] == 0)
            {
                set_color_red;
                printf("[0.退出升级]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".依次升级(3) (100$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".全部升级(3) (%d$)]\n\n",am[1] * 100);
            }
            else if (am[0] != 0)
            {
                set_color_red;
                printf("[0.退出升级]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".依次升级(2) (20$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".全部升级(2) (%d$)]\n\n", am[0] * 20);
            }
        }
        else if (uplevel == 3)
        {
            printf("升级 - 仓库: \n");
            if (wh[0] == 0)
            {
                printf("[0.退出升级]     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".依次升级(3) (1000$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".全部升级(3) (%d$)]\n\n", wh[1] * 1000);
            }
            else if (wh[0] != 0)
            {
                set_color_red;
                printf("[0.退出升级]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".依次升级(2) (200$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".全部升级(2) (%d$)]\n\n", wh[0] * 200);
            }
        }

        printf("----------------------------------------------------------------------\n");

        // 成就
        printf("成就: \n");
        if (al[0] == 0)
        {
            printf("[1.空间不足！ - 仓库(1)*2] - ");
            set_color_green;
            printf("奖励50$\n");
            set_color_white;
        }
        else
        {
            printf("[1.空间不足！ - 仓库(1)*2] - ");
            set_color_yellow;
            printf("已完成\n");
            set_color_white;
        }
        if (al[1] == 0)
        {
            printf("[2.更高级的马达 - 自动(2)*1] - ");
            set_color_green;
            printf("奖励自动(1)*5\n");
            set_color_white;
        }
        else
        {
            printf("[2.更高级的马达 - 自动(2)*1] - ");
            set_color_yellow;
            printf("已完成\n");
            set_color_white;
        }
        if (al[2] == 0)
        {
            printf("[3.更多的钱 - 5000$] - ");
            set_color_green;
            printf("奖励 $*2\n");
            set_color_white;
        }
        else
        {
            printf("[3.更多的钱 - 5000$] - ");
            set_color_yellow;
            printf("已完成\n");
            set_color_white;
        }
        if (al[3] == 0)
        {
            printf("[4.流水化工厂 - 自动(2)*200] - ");
            set_color_green;
            printf("奖励解锁仓库(2)\n");
            set_color_white;
        }
        else
        {
            printf("[4.流水化工厂 - 自动(2)*200] - ");
            set_color_yellow;
            printf("已完成\n");
            set_color_white;
        }
        if (al[4] == 0)
        {
            printf("\n");
        }
        else
        {
            printf("\n");
        }
        printf("\n");

        printf("----------------------------------------------------------------------\n");

        // 按键检测
        if (KEY_DOWN(A) == true)
        {
            last_down = A;
        }
        else if (KEY_DOWN(zero) == true)
        {
            last_down = zero;
        }
        else if (KEY_DOWN(one) == true)
        {
            last_down = one;
        }
        else if (KEY_DOWN(two) == true)
        {
            last_down = two;
        }

        // 视图
        if (KEY_DOWN(last_down) == true)
        {
            printf("视图: \n           -----\n          |  ");
            if (last_down == A)
            {
                printf("A");
            }
            else if (last_down == zero)
            {
                printf("0");
            }
            else if (last_down == one)
            {
                printf("1");
            }
            else if (last_down == two)
            {
                printf("2");
            }
            printf("  |\n           -----");
        }
        else
        {
            printf("视图:    -----\n        |  ");
            if (last_down == A)
            {
                printf("A");
            }
            else if (last_down == zero)
            {
                printf("0");
            }
            else if (last_down == one)
            {
                printf("1");
            }
            else if (last_down == two)
            {
                printf("2");
            }
            printf("  |\\\n        \\-----\\\n");
        }
        printf("\n");

        printf("----------------------------------------------------------------------\n");

        $ = $ + am[0];
        $ = $ + am[1] * 2;

        // 成就
        if (al[0] == 0)
        {
            if (wh[0] >= 2)
            {
                al[0] = al[0] + 1;
                $ = $ + 5000;
            }
        }
        if (al[1] == 0)
        {
            if (am[1] >= 1)
            {
                al[1] = al[1] + 1;
                am[0] = am[0] + 5;
            }
        }
        if (al[2] == 0)
        {
            if ($ > 500000)
            {
                $ = $ * 2;
                al[2] = al[2] + 1;
            }
        }
        if (al[3] == 0 && am[1] >= 200)
        {
            al[3] = al[3] + 1;
        }

        // 状态栏
        printf("状态栏: \n");
        if (am[0] > 0)
        { // 显示点击 (1)
            printf("自动点击(1) ×%d[%d.%d/s]\n", am[0], am[0] / 10, am[0] - am[0] / 10 * 10);
        }
        if (am[1] > 0)
        { // 显示点击 (2)
            printf("自动点击(2) ×%d[%d.%d/s]\n", am[1], am[1] / 10 * 2, (am[1] - am[1] / 10 * 10) * 2);
        }
        if (am[2] > 0)
        { // 显示点击 (3)
            printf("自动点击(3) ×%d[%d.%d/s]\n", am[2], am[2] / 10 * 5, (am[2] - am[2] / 10 * 10) * 2);
        }
        if (wh[0] > 0)
        { // 显示仓库(1)
            printf("仓库(1) ×%d[%d]\n", wh[0], wh[0] * 20);
        }
        if (wh[1] > 0)
        { // 显示仓库(2)
            printf("仓库(2) ×%d[%d]\n", wh[1], wh[1] * 30);
        }
        if (wh[2] > 0)
        { // 显示仓库(3)
            printf("仓库(3) ×%d[%d]\n", wh[2], wh[2] * 50);
        }

        // 按键检测
        if (KEY_DOWN(A) == true)
        { // 检测按下"a"
            while (KEY_DOWN(A) == true)
            {
            } // 按a+1$
            $ = $ + $add_s_show * 10;
            last_down = A;
        }
        if (KEY_DOWN(zero) == true)
        { // 检测按下"0"
            while (KEY_DOWN(zero) == true)
            {
            }
            last_down = zero;
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
        if (KEY_DOWN(one) == true)
        { // 检测按下"1" - 依次升级
            while (KEY_DOWN(one) == true)
            {
            }
            last_down = one;
            if (uplevel == 0 && $ >= 1000)
            { // 如果界面=购买并$>=10元就购买一个自动(1)
                am[0] = am[0] + 1;
                $ = $ - 1000;
            }
            else if (uplevel == 1)
            { // 如果界面=选择面板并按下1键就将界面设为自动升级
                uplevel = 2;
            }
            else if (uplevel == 2)
            { // 如果界面=自动升级：
                if (am[0] == 0 and am[1] != 0 and $ >= 10000)
                { // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
                    $ = $ - 10000;
                    am[1] = am[1] - 1;
                    am[2] = am[2] + 1;
                }
                else if (am[0] != 0 and $ >= 2000)
                { // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
                    $ = $ - 2000;
                    am[0] = am[0] - 1;
                    am[1] = am[1] + 1;
                }
            }
            else if (uplevel == 3)
            { // 如果界面=仓库升级：
                if ($ >= 20000 and wh[0] >= 1)
                { // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
                    $ = $ - 20000;
                    wh[0] = wh[0] - 1;
                    wh[1] = wh[1] + 1;
                }
                else if ($ >= 100000 and wh[1] >= 1 and wh[0] == 0)
                {                   // 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
                    $ = $ - 100000; // 则消耗一个仓库(2)购买仓库(3)
                    wh[1] = wh[1] - 1;
                    wh[2] = wh[2] + 1;
                }
            }
        }
        if (KEY_DOWN(two) == true)
        { // 检测按下"2" - 全部升级
            while (KEY_DOWN(two) == true)
            {
            }
            last_down = two;
            if (uplevel == 0 and $ >= 10000)
            { // 如果界面=购买并$>=100元就购买一个仓库(1)
                wh[0] = wh[0] + 1;
                $ = $ - 10000;
            }
            else if (uplevel == 1)
            { // 如果界面=选择面板并按下2键就将界面设为仓库升级
                uplevel = 3;
            }
            else if (uplevel == 2)
            { // 如果界面=自动升级：
                if (am[0] == 0 and $ >= am[1] * 10000)
                { // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
                    $ = $ - am[0] * 10000;
                    am[2] = am[2] + am[1];
                    am[1] = am[1] * 0;
                }
                else if (am[0] != 0 and $ >= am[0] * 2000)
                { // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
                    $ = $ - am[0] * 2000;
                    am[1] = am[1] + am[0];
                    am[0] = am[0] * 0;
                }
            }
            else if (uplevel == 3)
            { // 如果界面=仓库升级：
                if ($ >= wh[0] * 20000 and wh[0] >= 1)
                { // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
                    $ = $ - wh[0] * 20000;
                    wh[1] = wh[1] + wh[0];
                    wh[0] = wh[0] * 0;
                }
                else if ($ >= wh[1] * 100000 and wh[1] >= 1 and wh[0] == 0)
                {                           // 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
                    $ = $ - wh[1] * 100000; // 则消耗一个仓库(2)购买仓库(3)
                    wh[2] = wh[2] + wh[1];
                    wh[1] = wh[1] * 0;
                }
            }
        }
        if (KEY_DOWN(A) == true)
        { // 检测按下"a"
            while (KEY_DOWN(A) == true)
            {
            } // 按a+1$
            $ = $ + $add_s_show * 10;
            last_down = A;
        }
        if (KEY_DOWN(zero) == true)
        { // 检测按下"0"
            while (KEY_DOWN(zero) == true)
            {
            }
            last_down = zero;
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
        if (KEY_DOWN(one) == true)
        { // 检测按下"1" - 依次升级
            while (KEY_DOWN(one) == true)
            {
            }
            last_down = one;
            if (uplevel == 0 && $ >= 1000)
            { // 如果界面=购买并$>=10元就购买一个自动(1)
                am[0] = am[0] + 1;
                $ = $ - 1000;
            }
            else if (uplevel == 1)
            { // 如果界面=选择面板并按下1键就将界面设为自动升级
                uplevel = 2;
            }
            else if (uplevel == 2)
            { // 如果界面=自动升级：
                if (am[0] == 0 and am[1] != 0 and $ >= 10000)
                { // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
                    $ = $ - 10000;
                    am[1] = am[1] - 1;
                    am[2] = am[2] + 1;
                }
                else if (am[0] != 0 and $ >= 2000)
                { // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
                    $ = $ - 2000;
                    am[0] = am[0] - 1;
                    am[1] = am[1] + 1;
                }
            }
            else if (uplevel == 3)
            { // 如果界面=仓库升级：
                if ($ >= 20000 and wh[0] >= 1)
                { // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
                    $ = $ - 20000;
                    wh[0] = wh[0] - 1;
                    wh[1] = wh[1] + 1;
                }
                else if ($ >= 100000 and wh[1] >= 1 and wh[0] == 0)
                {                   // 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
                    $ = $ - 100000; // 则消耗一个仓库(2)购买仓库(3)
                    wh[1] = wh[1] - 1;
                    wh[2] = wh[2] + 1;
                }
            }
        }
        if (KEY_DOWN(two) == true)
        { // 检测按下"2" - 全部升级
            while (KEY_DOWN(two) == true)
            {
            }
            last_down = two;
            if (uplevel == 0 and $ >= 10000)
            { // 如果界面=购买并$>=100元就购买一个仓库(1)
                wh[0] = wh[0] + 1;
                $ = $ - 10000;
            }
            else if (uplevel == 1)
            { // 如果界面=选择面板并按下2键就将界面设为仓库升级
                uplevel = 3;
            }
            else if (uplevel == 2)
            { // 如果界面=自动升级：
                if (am[0] == 0 and $ >= am[1] * 10000)
                { // 如果自动(1)等于0并且$>=100元则消耗一个自动(2)购买自动(3)
                    $ = $ - am[0] * 10000;
                    am[2] = am[2] + am[1];
                    am[1] = am[1] * 0;
                }
                else if (am[0] != 0 and $ >= am[0] * 2000)
                { // 如果自动(1)不等于0并且$>=20元则消耗一个自动(1)购买自动(2)
                    $ = $ - am[0] * 2000;
                    am[1] = am[1] + am[0];
                    am[0] = am[0] * 0;
                }
            }
            else if (uplevel == 3)
            { // 如果界面=仓库升级：
                if ($ >= wh[0] * 20000 and wh[0] >= 1)
                { // 如果$>=200元并且仓库(1)>=1则消耗仓库(1)购买仓库(2)
                    $ = $ - wh[0] * 20000;
                    wh[1] = wh[1] + wh[0];
                    wh[0] = wh[0] * 0;
                }
                else if ($ >= wh[1] * 100000 and wh[1] >= 1 and wh[0] == 0)
                {                           // 如果$>=1000元并且仓库(2)>=1并且仓库(1)=0
                    $ = $ - wh[1] * 100000; // 则消耗一个仓库(2)购买仓库(3)
                    wh[2] = wh[2] + wh[1];
                    wh[1] = wh[1] * 0;
                }
            }
        }

        if ($ > $_max)
        {
            $ = $_max;
        }
        _sleep(100);
        if (cls_time == 0)
        {
            cls_time = 25;
            system("cls");
        }
        else
        {
            cls_time = cls_time - 1;
        }
        pg1 = 0;
        pg2 = 0;
    }
}