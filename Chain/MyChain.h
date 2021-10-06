//
// Created by liuzehao on 2021/10/4.
//

#ifndef GRADE2DSHK_MYCHAIN_H
#define GRADE2DSHK_MYCHAIN_H

const int INIT_SPACE_CHAIN_SIZE = 5;

//template<class T>
//struct Node {
//    T data;
//    Node *next;
//};

template<class T>
class MyChain {
public:
    MyChain() {
        this->L = static_cast<MyChain<T> *>(malloc(sizeof(MyChain<T>) * INIT_SPACE_CHAIN_SIZE));
        this->L->next = static_cast<MyChain<T> *>(malloc(sizeof(MyChain<T>) * INIT_SPACE_CHAIN_SIZE));
        this->L->next->next = nullptr;
    }

    ~MyChain() {
        this->destroy_whole_list();
    }

    void travel(void(*)(T &));

    void insert_node_by_index(int, T);

    void insert_node(T);

    void search_node_by_index(int, T &) const;

    void delete_node_by_index(int);

    void delete_node_by_value(T, bool(*)(const T &, const T &));

    void destroy_whole_list();

    void list_split(MyChain<T> &);

private:
    int len{}; // 链表内节点个数
    MyChain *L;
    MyChain *next;
    T data;
};


// 拆分链表
template<class T>
void MyChain<T>::list_split(MyChain<T> &B) {

}

// 遍历列表，将apply函数作用于每个节点
template<class T>
void MyChain<T>::travel(void (*apply)(T &t)) {
    // 暂存头指针
    auto ts = this->L->next;
    // 判断指针是否为空
    while (ts->next) {
        // 不为空则使用apply函数作用于数据
        apply(ts->next->data);
        // 将指向节点的指针后移
        ts = ts->next;
    }
}


// 根据下标插入节点
template<class T>
void MyChain<T>::insert_node_by_index(int index, T d) {
    // 声明临时指针
    MyChain<T> *t, *cur;
    // 申请临时节点内存
    cur = static_cast<MyChain<T> *>(malloc(sizeof(MyChain<T>)));
    // 将下一个节点指针设置为空指针
    cur->next = nullptr;
    // 获取头节点指针
    t = this->L->next;
    // 用于计数节点
    int i = 0;
    // 遍历节点查找插入位置
    while (t && i++ < index)
        t = t->next;
    // 如果t为空指针表示已经走到链表末尾
    if (t->next == nullptr) {
        // 将插入数据赋值给成员变量
        cur->data = d;
        // 将链表的末尾指针指向当前节点
        /*
         * 此处多浪费了一个节点空间
         * */
        t->next = cur;
        // 如果走到下标位置的前一个
    } else if (--i == index) {
        // 数据赋值给当前节点
        cur->data = d;
        // 将当前节点的next指针指向原先下一个节点
        cur->next = t->next;
        // 将原先节点的next指针指向当前节点
        t->next = cur;
    }
    // 节点数增加1
    this->len++;
}


// 向链表尾部插入节点
template<class T>
void MyChain<T>::insert_node(T d) {
    // 在末尾插入节点数据,插入位置为len
    this->insert_node_by_index(this->len, d);
}


// 根据下标查找节点
template<class T>
void MyChain<T>::search_node_by_index(int index, T &d) const {
    // 节点计数器
    int i = 0;
    // 声明临时指针
    MyChain<T> *t;
    // 获取第一个节点指针
    t = this->L->next->next;
    // 遍历列表
    while (t && i++ < index)
        t = t->next;
    // 如果t等于空指针直接返回
    if (t == nullptr)
        return;
    // 获取数据
    d = t->data;
}


// 根据下标删除节点
template<class T>
void MyChain<T>::delete_node_by_index(int pos) {
    // 节点计数器
    int i = 0;
    // 声明临时指针
    MyChain<T> *t;
    // 获取第一个节点指针
    t = this->L->next->next;
    // 遍历链表找到pos前一个节点
    while (t && i++ < pos - 1)
        t = t->next;
    // 如果走到最后直接返回
    if (t == nullptr)
        return;
    // 获取t的下一个节点指针
    auto *tmp = t->next;
    // 将当前下一个节点指针指向下一个的下一个节点
    t->next = t->next->next;
    // 释放当前节点
    free(tmp);
}


// 根据节点数据删除节点
template<class T>
void MyChain<T>::delete_node_by_value(T d, bool(*c)(const T &, const T &)) {
    // 声明临时指针
    MyChain<T> *t;
    // 获取链表头节点指针
    t = this->L->next->next;
    // 保存前一个节点指针
    auto pre = this->L->next;
    // 判断节点是否为空
    while (t) {
        // 判断下一个节点数据是否与传入数据相等
        if (c(t->data, d)) {
            auto *tmp = t;
            // 将节点t删除
            pre->next = t->next;
            // 释放t节点内存
            free(tmp);
        } else
            // 更新pre指针指向的节点
            pre = t;
        // 将节点向后推移
        t = t->next;
    }
}


// 删除整个链表
template<class T>
void MyChain<T>::destroy_whole_list() {
    // 获取链表头指针
    auto *t = this->L->next;
    // 遍历列表
    while (t) {
        // 获取当前节点指针
        auto *tmp = t;
        // 将节点后移
        t = t->next;
        // 释放当前节点内存
        free(tmp);
    }
}

#endif //GRADE2DSHK_MYCHAIN_H
