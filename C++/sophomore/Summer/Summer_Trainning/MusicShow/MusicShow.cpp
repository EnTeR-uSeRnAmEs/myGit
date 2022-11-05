#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<mutex>
#pragma comment(lib,"winmm.lib")
using namespace std;

mutex mtx;

char Notes[88][4] = {										  "A2", "#A2", "B2",	// 21,22,23
	"C1", "#C1", "D1", "#D1", "E1", "F1", "#F1", "G1", "#G1", "A1", "#A1", "B1",	// 24~35
	"C",  "#C",  "D",  "#D",  "E",  "F",  "#F",  "G",  "#G",  "A",  "#A",  "B",		// 36~47
	"c",  "#c",  "d",  "#d",  "e",  "f",  "#f",  "g",  "#g",  "a",  "#a",  "b",		// 48~59
	"c1", "#c1", "d1", "#d1", "e1", "f1", "#f1", "g1", "#g1", "a1", "#a1", "b1",	// 60~71(60中央C，小字1组c1)
	"c2", "#c2", "d2", "#d2", "e2", "f2", "#f2", "g2", "#g2", "a2", "#a2", "b2",	// 72~83
	"c3", "#c3", "d3", "#d3", "e3", "f3", "#f3", "g3", "#g3", "a3", "#a3", "b3",	// 84~95
	"c4", "#c4", "d4", "#d4", "e4", "f4", "#f4", "g4", "#g4", "a4", "#a4", "b4",	// 96~107
	"c5"};

struct Music{	
	int timbre;
	int pitch;
	int p;//1234567
};
queue<Music > music[15];
int MAXn = 150;
int mean_law[7] = {0, 2, 4, 5, 7, 9, 11};

void clear(queue<Music > &q)
{
	queue<Music > empty;
	swap(empty, q);
}
void full_screen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            
    int cy = GetSystemMetrics(SM_CYSCREEN);           

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);  
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
void COLOR(short x)
{
  if(x>=0 && x<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
  else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x%15 + 1);
}
void gotoxy(int x, int y) 
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

int Base = 48;
int instrument = 1;

void play(Music m,double volume_percent, int channel, HMIDIOUT handle, int pause, int base = Base)
{
	int volume = volume_percent * 0x7f;
	midiOutShortMsg(handle, m.timbre<<8 | 0xC<<4 | channel);//设置乐器 
	int msg = (volume << 16 | (m.pitch + base) << 8 | 0x9<<4 | channel);
	midiOutShortMsg(handle, msg);//发声
	Sleep(pause);
	return;	
}

void show_inf()
{
	mtx.lock();
	COLOR(15);
	gotoxy(2, 1);
	cout << "                              ";
	gotoxy(2, 1);
	cout << "当前乐器:" << instrument;
	gotoxy(2, 2);
	cout << "       ";
	gotoxy(2, 2);
	cout << "l = " << Notes[Base - 21];
	mtx.unlock();
}

void Initialization()
{
	
	string a[7] = {"Do", "Re", "Mi", "Fa", "Sol", "La", "Si"};
	show_inf();
	for(int j = 0; j <= 2; j++)
	{
		for(int i = 0; i <=6; i++)
		{
			COLOR(15);
			gotoxy(1, i + j * 8 + 5);
			cout << a[i];
		}
	}
	
}
int change_to_pitch(int a, bool f)
{
	if(a >= 49 && a <= 55)return mean_law[a - 49];
	if(a >= 59 && a <= 65 && f)return mean_law[a - 59] + 12;
	if(a >= 84 && a <= 90 && f)return mean_law[a - 84] + 13;
	if(a == 113)return mean_law[0] - 12;
	if(a == 119)return mean_law[1] - 12;
	if(a == 101)return mean_law[2] - 12;
	if(a == 114)return mean_law[3] - 12;
	if(a == 116)return mean_law[4] - 12;
	if(a == 121)return mean_law[5] - 12;
	if(a == 117)return mean_law[6] - 12;
	
	if(a == 81)return mean_law[0] - 11;
	if(a == 87)return mean_law[1] - 11;
	if(a == 69)return mean_law[2] - 11;
	if(a == 82)return mean_law[3] - 11;
	if(a == 84)return mean_law[4] - 11;
	if(a == 89)return mean_law[5] - 11;
	if(a == 85)return mean_law[6] - 11;
	
	if(a == 33)return mean_law[0] + 1;
	if(a == 64)return mean_law[1] + 1;
	if(a == 35)return mean_law[2] + 1;
	if(a == 36)return mean_law[3] + 1;
	if(a == 37)return mean_law[4] + 1;
	if(a == 94)return mean_law[5] + 1;
	if(a == 38)return mean_law[6] + 1;
	
	return -Base - 1;
}
int change_to_p(int a, bool f)
{
	if(a >= 49 && a <= 55)return a - 49;
	if(a >= 59 && a <= 65 && f)return a - 59 + 8;
	if(a >= 84 && a <= 90 && f)return a - 84 + 8;
	if(a == 113)return -8;
	if(a == 119)return -7;
	if(a == 101)return -6;
	if(a == 114)return -5;
	if(a == 116)return -4;
	if(a == 121)return -3;
	if(a == 117)return -2;
	
	if(a == 81)return -8;
	if(a == 87)return -7;
	if(a == 69)return -6;
	if(a == 82)return -5;
	if(a == 84)return -4;
	if(a == 89)return -3;
	if(a == 85)return -2;
	
	if(a == 33)return 0;
	if(a == 64)return 1;
	if(a == 35)return 2;
	if(a == 36)return 3;
	if(a == 37)return 4;
	if(a == 94)return 5;
	if(a == 38)return 6;
	
	return 100;
}

void show(int color, int kk)
{
	int size = music[kk].size();
	mtx.lock();
	
	for(int i = 1; i <= size; i++)
	{		
		Music m = music[kk].front();
		
		if(m.p >= -8 && m.p <= 14)
		{					
			gotoxy(min(MAXn, size) - i + 5, m.p + 5 + 8);
			COLOR(color);
			cout << "▋";
			gotoxy(min(MAXn, size) - i + 4, m.p + 5 + 8);
			cout << " ";
					
		}		
		music[kk].pop();
		music[kk].push(m);
	}
	
	
	for(int i = 5; i <= 28; i++)
	{
		gotoxy(MAXn + 4, i);
		cout << " ";
	}
	
	mtx.unlock();
	
	return;
}

void FreePlay(HMIDIOUT handle)
{
	int TIME = GetTickCount();
	clear(music[0]);
	int ch;
	bool flag = false;
	bool hit_flag = false;
	while (1)
	{
		Music m;
		if(!hit_flag)m.p = 100;		
	  	if (_kbhit())
		{
		   	ch = _getch();		
			//cout << ch << endl;			   	
		   	if(ch == 27)break;
		   	if(ch == 122)
			{
				Base--;
				Base = max(21, Base);
				show_inf();
				continue;
			}
		   	if(ch == 120)
			{
			   	Base++;
			   	Base = min(Base, 108);
			   	show_inf();
			   	continue;
			}
			if(ch == 99)
			{
				instrument--;
				instrument = max(instrument, 0);
				show_inf();
				continue;
			}
			if(ch == 118)
			{
				instrument++;
				instrument = min(127, instrument);
				show_inf();
				continue;
			}
		   	if(ch == 0)
		   	{
		   		flag = true;
		   		continue;
		   	}
		   	
			hit_flag = true;
			m.pitch = change_to_pitch(ch, flag); 
			m.p = change_to_p(ch, flag);
			m.timbre = instrument;
			play(m, 1, 0, handle, 0);
			//cout << ch << endl;
  		}
  		
  		
  		int time_now = GetTickCount() - TIME;
  		if(time_now >= 125)
  		{
  			time_now = 0;
  			TIME = GetTickCount();
  			music[0].push(m);
  			hit_flag = false;
  			if(music[0].size() > MAXn)music[0].pop();
  			show(12, 0);
  		}
 	}
}
struct note{
	int p;
	int pause;
};
struct settings{
	int base;
	int channel;
	int M_instrument;
};
vector <note > MyNotes[15];
settings setting[15];
void read_notes(char *file_name, int i)
{
	ifstream fcin;
	fcin.open(file_name);
	fcin >> setting[i].base >> setting[i].channel >> setting[i].M_instrument;

	note n;
	while(fcin >> n.p >> n.pause)
	{
		MyNotes[i].push_back(n);
	}  
	fcin.close();
}

void play_music(int color, HMIDIOUT handle, int kk)
{
	int TIME = GetTickCount();
	Sleep(1000);
	//freopen(file_name, "r", stdin);
	int base;
	//fcin >> base;
	base = setting[kk].base;
	int channel;
	//fcin >> channel;
	channel = setting[kk].channel;
	clear(music[channel]);
	int M_instrument = 0;
	//fcin >> M_instrument;
	M_instrument = setting[kk].M_instrument;
	
	Music m;
	int pause;
	char c;
	//while(fcin >> m.p >> pause)
	for(int i = 0; i <= (int)MyNotes[kk].size() - 1; i++)
	{
		bool t_flag = false;
		int time_t = GetTickCount();
		
		m.p = MyNotes[kk][i].p;
		pause = MyNotes[kk][i].pause;
		
		if(m.p < 0)m.pitch = mean_law[m.p + 8] - 12;
		if(m.p >= 0 && m.p <= 6)m.pitch = mean_law[m.p];
		if(m.p >= 8 && m.p <= 14)m.pitch = mean_law[m.p - 8] + 12;
		if(m.p == 15)m.pitch = -1;
			
		m.timbre = M_instrument;
		play(m, 1, channel, handle, 0, base);
		//music[channel].push(m);
		//if(music[channel].size() > MAXn)music[channel].pop(); 		
  		
  		//int find_t1 = GetTickCount();
  		while(pause > 0)
  		{ 	
		  	int time_now = GetTickCount() - TIME;
					 
			t_flag = true;			
			if(time_now >= 125)
  			{
  				time_now = 0;
  				TIME = GetTickCount();
							
  				music[channel].push(m);
  				//hit_flag = false;
  				if(music[channel].size() > MAXn)music[channel].pop();
  				show(color, channel);
  			}
  			
  			m.pitch = -1;	
			m.p = 15; 
			 
  			int tpause = min(125, pause);
			pause -= tpause;			
			int time_n = GetTickCount();			
			Sleep(time_t + tpause - time_n - 2);
			time_t = GetTickCount(); 				
  		}
		//int find_t2 = GetTickCount();
		
		//gotoxy(1, kk);
		//cout << find_t2 - find_t1;
		
	}
	while(true)
  	{ 	
	  	int time_now = GetTickCount() - TIME;		 			
		if(time_now >= 125)
  		{
  			time_now = 0;
 			TIME = GetTickCount();
							
  			music[channel].push(m);
  			//hit_flag = false;
  			if(music[channel].size() > MAXn)music[channel].pop();
  			show(color, channel);
  		}
  		m.pitch = -1;	
		m.p = 15;  	
  	}
}

void song(char song_name[], int thread_num, HMIDIOUT handle)
{	
	Initialization();	
	
	//int thread_num = 2;
	
	for(int i = 1; i <= thread_num; i++)
	{				
		char file_name[55];
		for(int j = 0; ; j++)
		{
			file_name[j] = song_name[j];
			if(j >= 1)
			{
				if(song_name[j - 1] == '\0')break;
			}
		}
		
		char cn[2] = "0";
		cn[0] += i;
		strcat(file_name, cn);
		strcat(file_name, ".txt");
		
		read_notes(file_name, i - 1);
	}
	for(int i = 1; i <= thread_num; i++)
	{
		thread PLAY(play_music, i + 2, handle, i - 1);	
		PLAY.detach();		
			
	}
	FreePlay(handle);
	
	gotoxy(1, 30);
	
}

struct SONG{
	char name[105];
	int voices;
};
SONG MySongs[15] = {{"两只老虎", 1}, {"D大调卡农(节选)", 2}, {"生日快乐", 1}, {"Your Reality", 3}, {"教父（节选）", 1}};
int SongNum = 5;

int menu()
{
	int n;
	system("cls");
	gotoxy(20, 5);
	cout << "键盘演奏键位:F1-F7对应高音do-si";
 	gotoxy(20, 6);
	cout << "             1-7对应中音do-si";
	gotoxy(20, 7);
	cout << "             Q-U对应低音do-si";
	gotoxy(20, 8);
	cout << "shift+上述按键升半音, Z,X调整音高, C,V调整乐器, esc退出";
	
	gotoxy(60, 13);
	cout << "在播放歌曲的同时也可以用键盘演奏哦~"; 
	gotoxy(75, 15);
	cout << "-----------------------------------" << endl;
	gotoxy(75, 16);
	cout << "|              目录               |" << endl;
	gotoxy(75, 17);
	cout << "|请选择曲目：                     |" << endl;
	for(int i = 18; i <= 17 + SongNum; i++)
	{
		gotoxy(75, i);cout << "|" << i - 17 << "." << MySongs[i - 18].name;
		gotoxy(109, i);cout << "|";
	}
	gotoxy(75, 18 + SongNum);
	cout << "|" << SongNum + 1 << ".自由弹奏";
	gotoxy(109, 18 + SongNum);
	cout << "|";
	gotoxy(75, 19 + SongNum);
	cout << "|" << SongNum + 2 << ".退出";
	gotoxy(109, 19 + SongNum);
	cout << "|";
	gotoxy(75, 20 + SongNum);
	cout << "-----------------------------------" << endl;
	gotoxy(88, 17);
	cin >> n;
	system("cls");
	return n;
}

int main()
{
	HMIDIOUT handle;//music
	midiOutOpen(&handle,0,0,0,0);//music
	
	full_screen();

	int type = menu();
	//int type = 2;
	if(type == SongNum + 2)return 0; 
	if(type == SongNum + 1)
	{
		Initialization();
		FreePlay(handle);
		
	}
	else song(MySongs[type - 1].name, MySongs[type - 1].voices, handle);
	
	
	midiOutClose(handle);//music
	return 0;
}
