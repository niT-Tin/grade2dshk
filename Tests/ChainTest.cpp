//
// Created by liuze on 2021/10/6.
//

#include <iostream>
#include <string>
#include "../Chain/MyChain.h"

using namespace std;

struct Student {
    string name;
    int age{};
    friend ostream & operator<<(ostream & os, Student& a)
    {
        return os << "name: " << a.name << " age: " << a.age;
    }
};

// 比较（姓名）函数
bool compare_name(const Student&, const Student&);

// 比较（年龄）函数
bool compare_age(const Student&, const Student&);

// 遍历函数
void visit(Student&);

int main(void)
{
    // 初始化链表
    MyChain<Student> dList;

    // 测试数据表格
    Student s[] = {
            {"name1", 17},
            {"name2", 18},
            {"name3", 17},
            {"name4", 20}
    };

    for (const auto & i : s) {
        dList.insert_node(i);
    }
    dList.travel(visit);

    Student s2 = {"name5", 21};

    cout << "================================" << endl;

    dList.insert_node_by_index(2, s2);

    dList.travel(visit);

    Student s3;
    dList.search_node_by_index(2, s3);
    cout << "================================" << endl;
    cout << s3 << endl;

    cout << "================================" << endl;
    dList.delete_node_by_index(2);
    dList.travel(visit);

    cout << "================================" << endl;
    Student s4 = {"name5", 17};
    dList.delete_node_by_value(s4, compare_age);
    dList.travel(visit);

    return 0;
}

bool compare_name(const Student& a, const Student& b)
{
    return a.name == b.name;
}

bool compare_age(const Student& a, const Student& b)
{
    return a.age == b.age;
}

void visit( Student& s)
{
    cout << s << endl;
}