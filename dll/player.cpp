#include "player.h"
#include <iostream>

// �ŧi���O���a
class player {
// �ŧi public ����
public:
    int x; //��l�y��x
    int y; //��l�y��y
    double re_set_coordinate(double,double);
    void console();
private:


};
double player::re_set_coordinate(double new_x = 0,double new_y = 0){
//���s�]�w�y�СA�P�ɥi�H�Ω��l�ơA��M�]�i�H�Ω�ץο��~
x = new_x;
y = new_y;
}
