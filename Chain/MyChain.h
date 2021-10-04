//
// Created by liuzehao on 2021/10/4.
//

#ifndef GRADE2DSHK_MYCHAIN_H
#define GRADE2DSHK_MYCHAIN_H

template<class T>
class MyChain {
public:
    MyChain(){}
    ~MyChain(){}
    void travel(void(*)(T));
    void insert_node_by_index(int, T);
    void insert_node(T);
    void search_node_by_index(int, T &) const;
    void delete_node_by_index(int);
    void delete_node_by_value(T, bool(*)(T, T));
    void destroy_whole_list();

private:
    int len{}; // 链表内节点个数
    MyChain *L;
    MyChain *next;
    T data;
};


// 遍历列表，将apply函数作用于每个节点
template<class T>
void MyChain<T>::travel(void (*apply)(T t))
{
    // 暂存头指针
    auto ts = this->L;
    // 判断指针是否为空
    while(ts)
    {
        // 不为空则使用apply函数作用于数据
        apply(ts->next->data);
        // 将指向节点的指针后移
        ts = ts->next;
    }
}

// 根据下标插入节点
template<class T>
void MyChain<T>::insert_node_by_index(int index, T d)
{
    
}


// 向链表尾部插入节点
template<class T>
void MyChain<T>::insert_node(T d)
{
    
}


// 根据下标查找节点
template<class T>
void MyChain<T>::search_node_by_index(int index, T &d) const
{
    
}


// 根据下标删除节点
template<class T>
void MyChain<T>::delete_node_by_index(int pos)
{
    
}


// 根据节点数据删除节点
template<class T>
void MyChain<T>::delete_node_by_value(T d, bool(*c)(T, T))
{
    
}


// 删除整个链表
template<class T>
void MyChain<T>::destroy_whole_list()
{

}

#endif //GRADE2DSHK_MYCHAIN_H
