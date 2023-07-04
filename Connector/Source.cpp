#include <iostream>
#include <Windows.h>
#include "Device.h"
#include "Data.h"
#include "Connector.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Блок данных
    Resolution res;
    Point point(1, 1);
    //Блок Устройств
    Monitor mon;
    File file("C:\\TestFolder\\TEST.txt");
    //Создаём экземпляр коннектора
    Connector connect;

    //1
    connect(res, mon);

    mon.out();
    cout << endl;
    mon.in();
    cout << endl;
    mon.out();

    connect(res, file);
    file.out();
    file.in();


    connect(res, mon);
    cout << endl;
    mon.out();

    //2
    cout << endl;
    connect(point, mon);
    mon.out();
    cout << endl;
    mon.in();
    mon.out();

    connect(point, file);
    file.out();
    file.in();

    connect(point, mon);
    cout << endl;
    mon.out();
    
   

    return 0;
}