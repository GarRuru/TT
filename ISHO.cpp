#include <iostream>
#include<conio.h>
#include<string>
#include <ctime>
#include <thread>
using namespace std;

int *runtime_code = new int(1); //����N�X

//�ˬd����

float max_x = 40.0;//�ŧi�̤j�d��
float max_y = 40.0;//�ŧi�̤j�d��
float full_x = max_x;
float full_y = max_y;

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
}


