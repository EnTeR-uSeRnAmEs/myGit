#include <bits/stdc++.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

const int BASE = 41;
const int MAX_num = 35;
const int MAX_volume = 0x7f;

struct num
{
	int n;
	int color;
	int pitch;

	bool operator>(const num &a) const { return n > a.n; }
	bool operator>=(const num &a) const { return n >= a.n; }
	bool operator<(const num &a) const { return n < a.n; }
	bool operator<=(const num &a) const { return n <= a.n; }
	bool operator==(const num &a) const { return n == a.n; }
	bool operator!=(const num &a) const { return n != a.n; }
};
struct Music
{
	double volume_percent;
	int timbre;
	int channel;
	HMIDIOUT handle;
	int pause;
};
void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void COLOR(short x)
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x % 15 + 1);
}
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void play(double volume_percent, int timbre, int channel, int pitch, HMIDIOUT handle, int pause)
{
	int volume = volume_percent * 0x7f;
	midiOutShortMsg(handle, timbre << 8 | 0xC0 + channel);
	int msg = (volume << 16 | (BASE + pitch) << 8 | 0x90 + channel);
	midiOutShortMsg(handle, msg);
	Sleep(pause);
}

void show(num a, int location, int flag, Music m)
{
	int i;
	if (flag == 0 || flag == 2)
		i = 10;
	if (flag == 1)
		i = 20 + 2 * MAX_num;
	if (flag == 3)
	{
		gotoxy(i - 5, location + 3);
		cout << "{";
	}
	gotoxy(i - 3, location + 3);
	COLOR(15);
	cout << a.n;

	gotoxy(i, location + 3);
	COLOR(a.color);
	for (int j = 1; j <= 2 * a.n; j++)
	{
		cout << "█";
	}

	if (flag == 2)
	{
		gotoxy(i + 2 * a.n + 1, location + 3);
		COLOR(15);
		cout << "<-";
	}
	play(m.volume_percent, m.timbre, m.channel, a.pitch, m.handle, m.pause);
}

void del_show(num a, int location, int flag)
{
	int i;
	if (flag == 0)
		i = 10;
	else
		i = 20 + 2 * MAX_num;

	gotoxy(i - 3, location + 3);
	cout << "   ";

	gotoxy(i, location + 3);
	for (int j = 1; j <= 2 * a.n + 3; j++)
	{
		cout << " ";
	}
}

Music SetMusic(double volume_percent, int timbre, int channel, HMIDIOUT handle, int pause)
{
	Music music;
	music.volume_percent = volume_percent;
	music.timbre = timbre;
	music.channel = channel;
	music.handle = handle;
	music.pause = pause;
	return music;
}

void Image_Initialization(num *a, int n, HMIDIOUT handle)
{
	Music music;
	music = SetMusic(1, 1, 0, handle, 100);
	for (int i = 0; i <= n - 1; i++)
	{
		show(a[i], i, 0, music);
	}
}

void QuickSort(num *begin, num *end, int start, HMIDIOUT handle)
{

	Music music, silence, change, finish;
	music = SetMusic(0.9, 1, 0, handle, 250);
	silence = SetMusic(0, 1, 0, handle, 0);
	change = SetMusic(1, 10, 0, handle, 250);
	finish = SetMusic(1, 24, 0, handle, 250);

	if (begin >= end)
		return;
	int n = end - begin;

	gotoxy(3, start + 3);
	cout << "L->";
	gotoxy(3, start + n - 1 + 3);
	cout << "R->";

	int i = 0, j = n - 1;
	num tmp = *(begin + i);

	del_show(*(begin + i), start + i, 0);
	show(*(begin + i), start + i, 1, music);

	while (i < j)
	{

		while (*(begin + j) >= tmp && i < j)
		{
			show(*(begin + j), start + j, 2, music);
			del_show(*(begin + j), start + j, 0);
			show(*(begin + j), start + j, 0, silence);
			j--;
		}
		if (i == j)
			break;
		*(begin + i) = *(begin + j);
		del_show(*(begin + j), start + j, 0);
		show(*(begin + i), start + i, 2, change);

		while (*(begin + i) <= tmp && i < j)
		{
			show(*(begin + i), start + i, 2, music);
			del_show(*(begin + i), start + i, 0);
			show(*(begin + i), start + i, 0, silence);
			i++;
		}
		if (i == j)
			break;
		*(begin + j) = *(begin + i);
		del_show(*(begin + i), start + i, 0);
		show(*(begin + j), start + j, 2, change);
	}
	*(begin + i) = tmp;

	del_show(*(begin + i), start, 1);
	show(*(begin + i), start + i, 0, finish);
	cout << "  -finish";
	gotoxy(3, start + 3);
	cout << "   ";
	gotoxy(3, start + n - 1 + 3);
	cout << "   ";

	QuickSort(begin, begin + i, start, handle);
	QuickSort(begin + i + 1, end, start + i + 1, handle);
}

void build(num *a, int n)
{
	srand(time(NULL));
	// map<num, int> mp;
	num a_base[105];
	for (int i = 0; i <= n - 1; i++)
	{

		a[i].n = rand() % MAX_num + 1;
		// a[i].n = n - i;
		a[i].color = i + 1;
		a_base[i] = a[i];
		// mp[a[i]] = i;
		/*
		for(int j = 0; j <= i - 1; j++)
		{
			if(a[i].n == a[j].n)
			{
				i--;
				break;
			}
		}
		*/
	}
	sort(a_base, a_base + n);
	for (int i = 0; i <= n - 1; i++)
	{
		// cout << a_base[i].n << " ";
		for (int j = 0; j <= n - 1; j++)
		{
			if (a[i].n == a_base[j].n)
			{
				a[i].pitch = j;
				// cout << a[i].n << " " << a_base[j].n << " " << j << endl;
				break;
			}
		}
	}
}

void welcome()
{
	gotoxy(72, 18);
	cout << "正在生成数据，请稍后...";
	gotoxy(74, 20);
	cout << "----------------------------------";
	gotoxy(74, 21);
	cout << "|                                |";
	gotoxy(74, 22);
	cout << "----------------------------------";
	for (int i = 75; i <= 104; i++)
	{
		gotoxy(i, 21);
		cout << "■";
		Sleep(100);
	}
	gotoxy(72, 18);
	cout << "数据生成成功，按回车键开始";
	Sleep(500);
	int c;
	c = getchar();
	c = getchar();
	system("cls");
	gotoxy(1, 1);
}

int main()
{

	full_screen();

	num a[105];
	int n;
	gotoxy(50, 25);
	cout << "输入数字个数(不超过45):";
	cin >> n;
	if (n > 45)
		n = 45;
	welcome();
	cout << "数据规模：" << n;

	build(a, n);

	HMIDIOUT handle;				  // music
	midiOutOpen(&handle, 0, 0, 0, 0); // music

	Image_Initialization(a, n, handle);
	Sleep(1000);
	QuickSort(a, a + n, 0, handle);
	Sleep(1000);
	Image_Initialization(a, n, handle);
	// QuickSort(a, a + n);
	Sleep(3000);

	midiOutClose(handle); // music
	gotoxy(0, n + 10);

	return 0;
}
