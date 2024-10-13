// 颜色显示
#define set_color_white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 白色
#define set_color_red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);                                        // 红色
#define set_color_green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);                                    // 绿色
#define set_color_blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);                                      // 蓝色
#define set_color_yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);                  // 黄色
#define set_color_pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);                     // 粉红色
#define set_color_cyan SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);                   // 青色
#define set_colro_grey SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);                                                        // 灰色

// KEY_DOWN按键编码
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define zero 48
#define one 49
#define two 50
#define three 51
#define four 52
#define five 53
#define six 54
#define seven 55
#define eight 56
#define nine 57
#define A 65
#define B 66
#define C 67
#define D 68
#define E 69
#define F 70
#define G 71
#define H 72
#define I 73
#define J 74
#define K 75
#define L 76
#define M 77
#define N 78
#define O 79
#define P 80
#define Q 81
#define R 82
#define S 83
#define T 84
#define U 85
#define V 86
#define W 87
#define X 88
#define Y 89
#define Z 90