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
am=automatic[�Զ�]
al=accomplishment[�ɾ�]
pg=Progress[����]
wh=warehouse[�ֿ�]
uplevellevel=uplevelgrade[����]
$add_s_show[��A���]
last_down[����µļ�]
al[0]=[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ����50$
al[1]=[2.���߼������ - �Զ�(2)*1] - �����Զ�(1)*5
al[2]=[3.�����Ǯ - 5000$] - ���� $*2;
al[3]=[4.��ˮ������ - �Զ�(2)*200] - ���������ֿ�(2)
al[4]=[5.׬Ǯ��ħ - һ��׬] - ����
norr=number of rows remaining[ʣ������] max:8
cls_time[ˢ��ʣ��ʱ��]
rfs=refresh
*/

int main()
{
    // ��ʼ��
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
        // ��Ǯ��ʾ
        printf("��Ǯ $ = [ ");
        while (pg1 < $ * 100 / $_max * 20 / 100)
        {
            printf("��");
            pg1 = pg1 + 2;
        }
        while (pg2 < 20 - pg1)
        {
            printf(" ");
            pg2 = pg2 + 1;
        }
        printf("  ]");
        // �����ʾ && �汾����ʾ
        printf("  [%d/%d]                v1.3.1\n", $ / 100, $_max / 100);
        set_color_white;

        printf("----------------------------------------------------------------------\n");

        // �̵�
        if (uplevel == 0)
        {
            printf("����: \n[");
            set_color_cyan;
            printf("0");
            set_color_white;
            printf(".�������]     [");
            set_color_cyan;
            printf("1");
            set_color_white;
            printf(".�Զ�(1) (10$)]     [");
            set_color_cyan;
            printf("2");
            set_color_white;
            printf(".�ֿ�(1) (100$)]\n\n");
        }
        else if (uplevel == 1)
        {
            printf("���� - ѡ����壺\n");
            set_color_red;
            printf("[0.�˳����]");
            set_color_white;
            printf("     [");
            set_color_cyan;
            printf("1");
            set_color_white;
            printf(".�Զ����]");
            if (al[3] != 0)
            {
                printf("     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".�ֿ�]");
            }
            printf("\n\n");
        }
        else if (uplevel == 2)
        {
            printf("���� - �Զ����: \n");
            if (am[0] == 0)
            {
                set_color_red;
                printf("[0.�˳�����]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".��������(3) (100$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".ȫ������(3) (%d$)]\n\n",am[1] * 100);
            }
            else if (am[0] != 0)
            {
                set_color_red;
                printf("[0.�˳�����]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".��������(2) (20$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".ȫ������(2) (%d$)]\n\n", am[0] * 20);
            }
        }
        else if (uplevel == 3)
        {
            printf("���� - �ֿ�: \n");
            if (wh[0] == 0)
            {
                printf("[0.�˳�����]     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".��������(3) (1000$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".ȫ������(3) (%d$)]\n\n", wh[1] * 1000);
            }
            else if (wh[0] != 0)
            {
                set_color_red;
                printf("[0.�˳�����]");
                set_color_white;
                printf("     [");
                set_color_cyan;
                printf("1");
                set_color_white;
                printf(".��������(2) (200$)]     [");
                set_color_cyan;
                printf("2");
                set_color_white;
                printf(".ȫ������(2) (%d$)]\n\n", wh[0] * 200);
            }
        }

        printf("----------------------------------------------------------------------\n");

        // �ɾ�
        printf("�ɾ�: \n");
        if (al[0] == 0)
        {
            printf("[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ");
            set_color_green;
            printf("����50$\n");
            set_color_white;
        }
        else
        {
            printf("[1.�ռ䲻�㣡 - �ֿ�(1)*2] - ");
            set_color_yellow;
            printf("�����\n");
            set_color_white;
        }
        if (al[1] == 0)
        {
            printf("[2.���߼������ - �Զ�(2)*1] - ");
            set_color_green;
            printf("�����Զ�(1)*5\n");
            set_color_white;
        }
        else
        {
            printf("[2.���߼������ - �Զ�(2)*1] - ");
            set_color_yellow;
            printf("�����\n");
            set_color_white;
        }
        if (al[2] == 0)
        {
            printf("[3.�����Ǯ - 5000$] - ");
            set_color_green;
            printf("���� $*2\n");
            set_color_white;
        }
        else
        {
            printf("[3.�����Ǯ - 5000$] - ");
            set_color_yellow;
            printf("�����\n");
            set_color_white;
        }
        if (al[3] == 0)
        {
            printf("[4.��ˮ������ - �Զ�(2)*200] - ");
            set_color_green;
            printf("���������ֿ�(2)\n");
            set_color_white;
        }
        else
        {
            printf("[4.��ˮ������ - �Զ�(2)*200] - ");
            set_color_yellow;
            printf("�����\n");
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

        // �������
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

        // ��ͼ
        if (KEY_DOWN(last_down) == true)
        {
            printf("��ͼ: \n           -----\n          |  ");
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
            printf("��ͼ:    -----\n        |  ");
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

        // �ɾ�
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

        // ״̬��
        printf("״̬��: \n");
        if (am[0] > 0)
        { // ��ʾ��� (1)
            printf("�Զ����(1) ��%d[%d.%d/s]\n", am[0], am[0] / 10, am[0] - am[0] / 10 * 10);
        }
        if (am[1] > 0)
        { // ��ʾ��� (2)
            printf("�Զ����(2) ��%d[%d.%d/s]\n", am[1], am[1] / 10 * 2, (am[1] - am[1] / 10 * 10) * 2);
        }
        if (am[2] > 0)
        { // ��ʾ��� (3)
            printf("�Զ����(3) ��%d[%d.%d/s]\n", am[2], am[2] / 10 * 5, (am[2] - am[2] / 10 * 10) * 2);
        }
        if (wh[0] > 0)
        { // ��ʾ�ֿ�(1)
            printf("�ֿ�(1) ��%d[%d]\n", wh[0], wh[0] * 20);
        }
        if (wh[1] > 0)
        { // ��ʾ�ֿ�(2)
            printf("�ֿ�(2) ��%d[%d]\n", wh[1], wh[1] * 30);
        }
        if (wh[2] > 0)
        { // ��ʾ�ֿ�(3)
            printf("�ֿ�(3) ��%d[%d]\n", wh[2], wh[2] * 50);
        }

        // �������
        if (KEY_DOWN(A) == true)
        { // ��ⰴ��"a"
            while (KEY_DOWN(A) == true)
            {
            } // ��a+1$
            $ = $ + $add_s_show * 10;
            last_down = A;
        }
        if (KEY_DOWN(zero) == true)
        { // ��ⰴ��"0"
            while (KEY_DOWN(zero) == true)
            {
            }
            last_down = zero;
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
        if (KEY_DOWN(one) == true)
        { // ��ⰴ��"1" - ��������
            while (KEY_DOWN(one) == true)
            {
            }
            last_down = one;
            if (uplevel == 0 && $ >= 1000)
            { // �������=����$>=10Ԫ�͹���һ���Զ�(1)
                am[0] = am[0] + 1;
                $ = $ - 1000;
            }
            else if (uplevel == 1)
            { // �������=ѡ����岢����1���ͽ�������Ϊ�Զ�����
                uplevel = 2;
            }
            else if (uplevel == 2)
            { // �������=�Զ�������
                if (am[0] == 0 and am[1] != 0 and $ >= 10000)
                { // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
                    $ = $ - 10000;
                    am[1] = am[1] - 1;
                    am[2] = am[2] + 1;
                }
                else if (am[0] != 0 and $ >= 2000)
                { // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
                    $ = $ - 2000;
                    am[0] = am[0] - 1;
                    am[1] = am[1] + 1;
                }
            }
            else if (uplevel == 3)
            { // �������=�ֿ�������
                if ($ >= 20000 and wh[0] >= 1)
                { // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
                    $ = $ - 20000;
                    wh[0] = wh[0] - 1;
                    wh[1] = wh[1] + 1;
                }
                else if ($ >= 100000 and wh[1] >= 1 and wh[0] == 0)
                {                   // ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
                    $ = $ - 100000; // ������һ���ֿ�(2)����ֿ�(3)
                    wh[1] = wh[1] - 1;
                    wh[2] = wh[2] + 1;
                }
            }
        }
        if (KEY_DOWN(two) == true)
        { // ��ⰴ��"2" - ȫ������
            while (KEY_DOWN(two) == true)
            {
            }
            last_down = two;
            if (uplevel == 0 and $ >= 10000)
            { // �������=����$>=100Ԫ�͹���һ���ֿ�(1)
                wh[0] = wh[0] + 1;
                $ = $ - 10000;
            }
            else if (uplevel == 1)
            { // �������=ѡ����岢����2���ͽ�������Ϊ�ֿ�����
                uplevel = 3;
            }
            else if (uplevel == 2)
            { // �������=�Զ�������
                if (am[0] == 0 and $ >= am[1] * 10000)
                { // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
                    $ = $ - am[0] * 10000;
                    am[2] = am[2] + am[1];
                    am[1] = am[1] * 0;
                }
                else if (am[0] != 0 and $ >= am[0] * 2000)
                { // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
                    $ = $ - am[0] * 2000;
                    am[1] = am[1] + am[0];
                    am[0] = am[0] * 0;
                }
            }
            else if (uplevel == 3)
            { // �������=�ֿ�������
                if ($ >= wh[0] * 20000 and wh[0] >= 1)
                { // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
                    $ = $ - wh[0] * 20000;
                    wh[1] = wh[1] + wh[0];
                    wh[0] = wh[0] * 0;
                }
                else if ($ >= wh[1] * 100000 and wh[1] >= 1 and wh[0] == 0)
                {                           // ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
                    $ = $ - wh[1] * 100000; // ������һ���ֿ�(2)����ֿ�(3)
                    wh[2] = wh[2] + wh[1];
                    wh[1] = wh[1] * 0;
                }
            }
        }
        if (KEY_DOWN(A) == true)
        { // ��ⰴ��"a"
            while (KEY_DOWN(A) == true)
            {
            } // ��a+1$
            $ = $ + $add_s_show * 10;
            last_down = A;
        }
        if (KEY_DOWN(zero) == true)
        { // ��ⰴ��"0"
            while (KEY_DOWN(zero) == true)
            {
            }
            last_down = zero;
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
        if (KEY_DOWN(one) == true)
        { // ��ⰴ��"1" - ��������
            while (KEY_DOWN(one) == true)
            {
            }
            last_down = one;
            if (uplevel == 0 && $ >= 1000)
            { // �������=����$>=10Ԫ�͹���һ���Զ�(1)
                am[0] = am[0] + 1;
                $ = $ - 1000;
            }
            else if (uplevel == 1)
            { // �������=ѡ����岢����1���ͽ�������Ϊ�Զ�����
                uplevel = 2;
            }
            else if (uplevel == 2)
            { // �������=�Զ�������
                if (am[0] == 0 and am[1] != 0 and $ >= 10000)
                { // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
                    $ = $ - 10000;
                    am[1] = am[1] - 1;
                    am[2] = am[2] + 1;
                }
                else if (am[0] != 0 and $ >= 2000)
                { // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
                    $ = $ - 2000;
                    am[0] = am[0] - 1;
                    am[1] = am[1] + 1;
                }
            }
            else if (uplevel == 3)
            { // �������=�ֿ�������
                if ($ >= 20000 and wh[0] >= 1)
                { // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
                    $ = $ - 20000;
                    wh[0] = wh[0] - 1;
                    wh[1] = wh[1] + 1;
                }
                else if ($ >= 100000 and wh[1] >= 1 and wh[0] == 0)
                {                   // ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
                    $ = $ - 100000; // ������һ���ֿ�(2)����ֿ�(3)
                    wh[1] = wh[1] - 1;
                    wh[2] = wh[2] + 1;
                }
            }
        }
        if (KEY_DOWN(two) == true)
        { // ��ⰴ��"2" - ȫ������
            while (KEY_DOWN(two) == true)
            {
            }
            last_down = two;
            if (uplevel == 0 and $ >= 10000)
            { // �������=����$>=100Ԫ�͹���һ���ֿ�(1)
                wh[0] = wh[0] + 1;
                $ = $ - 10000;
            }
            else if (uplevel == 1)
            { // �������=ѡ����岢����2���ͽ�������Ϊ�ֿ�����
                uplevel = 3;
            }
            else if (uplevel == 2)
            { // �������=�Զ�������
                if (am[0] == 0 and $ >= am[1] * 10000)
                { // ����Զ�(1)����0����$>=100Ԫ������һ���Զ�(2)�����Զ�(3)
                    $ = $ - am[0] * 10000;
                    am[2] = am[2] + am[1];
                    am[1] = am[1] * 0;
                }
                else if (am[0] != 0 and $ >= am[0] * 2000)
                { // ����Զ�(1)������0����$>=20Ԫ������һ���Զ�(1)�����Զ�(2)
                    $ = $ - am[0] * 2000;
                    am[1] = am[1] + am[0];
                    am[0] = am[0] * 0;
                }
            }
            else if (uplevel == 3)
            { // �������=�ֿ�������
                if ($ >= wh[0] * 20000 and wh[0] >= 1)
                { // ���$>=200Ԫ���Ҳֿ�(1)>=1�����Ĳֿ�(1)����ֿ�(2)
                    $ = $ - wh[0] * 20000;
                    wh[1] = wh[1] + wh[0];
                    wh[0] = wh[0] * 0;
                }
                else if ($ >= wh[1] * 100000 and wh[1] >= 1 and wh[0] == 0)
                {                           // ���$>=1000Ԫ���Ҳֿ�(2)>=1���Ҳֿ�(1)=0
                    $ = $ - wh[1] * 100000; // ������һ���ֿ�(2)����ֿ�(3)
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