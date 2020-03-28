#include <iostream>
#include<string>
#include <ctime>
#include <thread>
using namespace std;

int *runtime_code = new int(1); //����N�X

//�ˬd����

double max_x = 40.0;//�ŧi�̤j�d��
double max_y = 40.0;//�ŧi�̤j�d��
double full_x = max_x;
double full_y = max_y;

//�ŧi������
void Delay(int time)//time*1000�����
{
clock_t now = clock();
while(clock() - now < time);
}

class player {// �ŧi public ����
public:
    int x; //��l�y��x
    int y; //��l�y��y
    double re_set_coordinate(double new_x = 0,double new_y = 0){//���s�]�w�y�СA�P�ɥi�H�Ω��l�ơA��M�]�i�H�Ω�ץο��~
        x = new_x;
        y = new_y;
    }
    void console(){
        string command;
        while (*runtime_code == 1){
            cin >> command;
            if(command == string("exit")){
                *runtime_code = 0;
            }
            else if(command == string("SetCoordinate")){
                double i,j;
                cout << "��J�s��x�y��:";
                cin >> i;
                cout << "��J�s��y�y��:";
                cin >> j;
                cout << "��襤\n";
                int k = safe_check(i,j);
                if (k == 13395){
                    re_set_coordinate(i,j);
                    cout << "�w�ͮ�\n";
                }
                else{
                    cout << "��異��\n";
                };
            }
        }
    }
    bool safe_check(double checking_x, double checking_y){
        int check_code = 1;
        if ((checking_x <= full_x)&&(checking_y <= full_y)){
            check_code = 0;
        }
        if (check_code == 0){return true;}
        else {cout << "���~[1]�y�п��~\n";return false;}
    }
    void layout(){
        while (*runtime_code == 1){
            Delay(16);
            /*�@�����u����60��
            ����꧹����CPU����t��(kHz)*/
            cout << x << "," << y << endl;
        }
    }
};

/*
int main(){
    cout << "Hello! World!\n";
    cout << "�a�ϳ̤jX�b:" << full_x << endl;
    cout << "�a�ϳ̤jY�b:" << full_y << endl;
    cout << "";
    player My_Self;//�غc���a
    My_Self.re_set_coordinate(0,0);//��l�ƪ��a
	thread a(&player::console,&My_Self);
    thread b(&player::layout,&My_Self);
    a.join();
    b.join();


    return 0;
}*/

#ifndef LINUX
#include <tchar.h>
#include <windows.h>

//�ŧiWindows�{��
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

//�����W���������ܶq
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

#endif // LINUX

