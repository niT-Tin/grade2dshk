//
// Created by liuze on 2021/9/30.
//


#ifndef FIRST_CLION_MYARRAY_H
#define FIRST_CLION_MYARRAY_H
#define INIT_SPACE 5

using namespace std;

template<class T>
class MyArray {
public:
    MyArray() {
        node = static_cast<T *> (new T[INIT_SPACE * sizeof(T)]);/*( malloc(INIT_SPACE * sizeof(T)))*/;
        this->cap = INIT_SPACE;
    }

    ~MyArray() {
        this->destroy_whole_array();
    }

//    void init_array();
    void destroy_whole_array();

    void search_item_by_index(int, T &);

    void get_top_item(T &);

    void get_last_item(T &);

    void insert_item_by_index(int, T &);

    void insert_item(T &);

    bool delete_item(int);

    bool delete_by_value(T val, bool(*)(T, T));

    void travel(void (*)(T *));

private:
    void resize(int);

    auto my_realloc(T *s, int) -> decltype(s);

    T *node;
    int cap{}; // 当前链式结构容量
    int len{}; // 当前链式结构长度(即元素个数)
};

//
// Created by liuze on 2021/9/30.
//

template<class T>
auto MyArray<T>::my_realloc(T *src, int size) -> decltype(src) {

    // 申请新的内存空间
    T *t = new T[size];

    // 将src指向的元素复制到新的空间
    for (int i = 0; i < this->len; i++)
        t[i] = src[i];

    /* 此处存在隐患，src与this->node指向同一块内存，但是此处delete掉了src,如果再对
     * this->node进行delete操作则会出现错误。
     * 目前暂时忽略这个隐患
    */
    // 释放src指向的内存空间
    delete[] src;

    // 返回指向新内存空间的指针
    return t;
}

// 调整结构内存大小(此处只增加容量)
template<class T>
void MyArray<T>::resize(int size) {
    T *t; // 声明暂时元素指针
    // 如果分配内存空间失败，则直接返回
    if (!(t = this->my_realloc(this->node, size))) {
        cout << "get memory failed" << endl;
        return;
    }
    //将指向新内存的指针赋值给原始指针
    this->node = t;
    // 更新容量值
    this->cap = size;
}


// 释放整个结构所占用的内存
template<class T>
void MyArray<T>::destroy_whole_array() {
    // 释放节点指针指向的内存
    free(this->node);
}


// 根据下标查找元素
template<class T>
void MyArray<T>::search_item_by_index(int pos, T &val) {
    // 判断下标是否越界
    if (pos < 0 || pos > this->len)
        return;
    val = this->node[pos];
//    this->len++;
}


// 获取结构最后一个元素
template<class T>
void MyArray<T>::get_last_item(T &val) {
    // 获取下标为len - 1的元素
//    cout << "this->len = " << this->len << endl;
    val = this->node[this->len - 1];
}


// 获得顶部（结构最开始的）元素
template<class T>
void MyArray<T>::get_top_item(T &val) {
    // 获得下标为0的元素
    val = this->node[0];
}


// 默认在尾部插入元素
template<class T>
void MyArray<T>::insert_item(T &val) {
    // 判断容量是否小于等于当前元素总数
    if (this->cap <= this->len)
        // 如果小于等于则将空间扩大为原来的两倍
        this->resize(this->cap * 2);
    // 在链式结构尾部插入元素
    this->insert_item_by_index(this->len, val);
}


// 根据下标插入元素
template<class T>
void MyArray<T>::insert_item_by_index(int pos, T &val) {
    // 判断插入位置是否越界，或者元素个数大于结构容量
    if (pos < 0 || pos > this->cap || this->len >= this->cap)
        this->resize(this->cap * 2);
    // 将pos以及之后的元素全部向后移动一位
    for (int i = this->len; i > pos; i--)
        this->node[i] = this->node[i - 1];
    // 将pos位置存入新的元素
    this->node[pos] = val;
    // 将结构存储长度增加1

//    cout << this->node[pos] << endl;
    this->len++;
}


// 根据元素值删除元素
template<class T>
bool MyArray<T>::delete_by_value(T val, bool(*c)(T, T)) {
    // 判断len是否已经超过cap
    if (this->len > this->cap)
        // 如果成立则直接返回false
        return false;
    // 循环找出与提供值相等的元素
    for (int i = 0; i < this->len; i++) {
        // 使用提供的比较函数
        if (c(this->node[i], val))
            // 相等则删除
            this->delete_item(i);
    }
}


// 根据位置下标删除元素
template<class T>
bool MyArray<T>::delete_item(int pos) {
    int i;
    // 判断下标是否越界
    if (pos < 0 || pos > this->cap)
        return false;
    // 将pos以及之后的元素全部向前移动一位
    for (i = pos; i < this->len - 1; i++)
        this->node[i] = this->node[i + 1];
    // 将结构长度减1
    this->len--;
    return true;
}


// 将指定函数作用到整个结构
template<class T>
void MyArray<T>::travel(void (*apply)(T *)) {
    apply(this->node);
}

#endif //FIRST_CLION_MYARRAY_H
