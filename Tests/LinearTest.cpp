//
// Created by liuze on 2021/9/30.
//
#include <iostream>
#include "../Linear/MyArray.h"

using namespace std;

bool compare(int, int);
void visit(const int&);

int main(void)
{
    cout << "Hello World" << endl;
    srand(static_cast<unsigned int>(time(NULL)));

    MyArray<int> test1;
    int a = 10;

    test1.insert_item(a);
//
//    for (int i = 0; i < 20; i++)
//        test1.insert_item(i);

//    int b;
//    cout << b << endl;
//    test1.get_top_item(b);
//    cout << b << endl;
    cout << "-----------------------" << endl;

    int a1;
    for (int i = 0; i < 10; i++)
    {
        a1 = rand() % 1000;
        test1.insert_item_by_index(i, a1);
        int t;
        test1.search_item_by_index(i, t);
        cout << "a1 = " << a1 << endl;
    }
    cout << "======================" << endl;

    for (int i = 0; i <10; i ++)
    {
        int t;
        test1.search_item_by_index(i, t);
        cout << "get = " << t << endl;
    }

    cout << "======================" << endl;
    int t1;
    test1.get_top_item(t1);
    cout << "top = " << t1 << endl;

    test1.get_last_item(t1);
    cout << "last = " << t1 << endl;

    test1.delete_by_value(a, compare);


    cout << "======================" << endl;
    test1.get_last_item(t1);
    cout << "last = " << t1 << endl;


    cout << "======================" << endl;
    test1.travel(visit);

    return 0;
}

bool compare(int a, int b)
{
    return a == b;
}

void visit(const int &t)
{
    cout << "t = " << t << endl;
}