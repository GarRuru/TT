#include <iostream>
#include<string>
#include <ctime>
#include <thread>
#include <fstream>
using namespace std;

char set_file_need_name[] = ("1.txt");//�Ӧr�ꬰ�]�w�ɮ�
//int *runtime_code = new int(1); //����N�X
int runtime_code [1] = {0};

double max_x = 40.0;//�ŧi�̤j�d��
double max_y = 40.0;//�ŧi�̤j�d��
double full_x = max_x;
double full_y = max_y;

//�ŧi������
void Delay(int time){//time*1000�����
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

//�ˬd����

bool Find_set(string a="a",string c="c",string b="="){
    ifstream in(set_file_need_name);
    string line;//���
    string need_str = a+b+c;//�r��X��
    if((a=="a")&&(c=="c")){//�i�Hĵ�i
        cout << "�A�O���O�ѰO�F����?\n";
    }
    if(in){// �����ɮ�
        while (getline(in,line)) // line�����]�A�C�檺�����
        {
            cout << line << endl;
            if(line == need_str){
                cout <<"OK" << endl;
                return true;
            }
            else{
                cout << "�ӵ���Ƥ��s�b�άO��";
                *runtime_code = 3;
                return false;
            }
        }
    }
    else // �S�����ɮ�
    {
        cout <<"�S�����ɮ�" << endl;
        return false;
    }
}

//void GUARD(int **runtime_code){
void GUARD(int runtime_code[1]){
    if(Find_set("GUARD","ON")){
    }
}

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
    HWND hwnd;//�o�O�����������v
    MSG messages;//���B�O�s�����ε{�Ǫ�����
    WNDCLASSEX wincl;//�������O���ƾڵ��c

    /* �������c */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;//�������D
    wincl.lpfnWndProc = WindowProcedure;//Windows�եΦ��\��
    wincl.style = CS_DBLCLKS;//��������
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* �ϥ��q�{�ϼЩM���Ы��w */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;//������檬�A:�L
    wincl.cbClsExtra = 0;//�������O��S���h�l���r�`
    wincl.cbWndExtra = 0;//���c�ε����Ա�
    /* �ϥ�Windows���q�{�C��@�����f���I�� */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* ���U�������O�A�p�G���ѡA�h�h�X�{�� */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* �����O�w�������U�A�N�Ыص{�� */
    hwnd = CreateWindowEx (
           0,//�����X�R�ܼ�
           szClassName,//���O�W��
           _T("Code::Blocks Template Windows App"),//���D��r
           WS_OVERLAPPEDWINDOW,//�w�]����
           CW_USEDEFAULT,//�����X�{����m:�Ѩt�ΨM�w
           CW_USEDEFAULT,//��ܦ�m
           544,//���ε{�����e��
           375,//���ε{�������� �ϥΪ��O���������
           HWND_DESKTOP,//���w���Y�F�誺�l���� �o�̫��w���ୱ���l����
           NULL,//���ε{�������:�L
           hThisInstance,//�{�ǹ�ҳB�z�{��
           NULL//�����Ыؼƾ�:�L
           );

    /* �ϵ����b�ù��W�i�� */
    ShowWindow (hwnd, nCmdShow);
    /************************
    *   �o�̥i�H�[�I����   *
    ************************/
    /* �B������`���C ���N�@���B���GetMessage()��^0���� */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* �N������������ഫ���r�Ů��� */
        TranslateMessage(&messages);
        /* �o�e����������L�{ */
        DispatchMessage(&messages);
    }

    /* �{�Ǫ���^�Ȭ�0 - PostQuitMessage()���X���ƭ� */
    return messages.wParam;
}


/* Windows���DispatchMessage()�եΦ���� */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)//�B�̮���
    {
        case WM_DESTROY:
            PostQuitMessage (0);//�NWM_QUIT�o�e������ǦC
            break;
        default://�Ω�ڭ̤��B�z������
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

#else
int main(){
    cout << "Hello! World!\n";
    cout << "�a�ϳ̤jX�b:" << full_x << endl;
    cout << "�a�ϳ̤jY�b:" << full_y << endl;
    cout << "";
    player My_Self;//�غc���a
    My_Self.re_set_coordinate(0,0);//��l�ƪ��a
    //thread RunTime_Code_Reseter(&GUARD,&runtime_code);
    thread RunTime_Code_Reseter(&GUARD,&runtime_code[1]);
	thread command_line(&player::console,&My_Self);
    thread player_control(&player::layout,&My_Self);
    RunTime_Code_Reseter.join();
    command_line.join();
    player_control.join();


    return 0;
}

#endif // LINUX
