//
// Created by liuzehao on 2021/10/4.
//

#ifndef GRADE2DSHK_UTILS_H
#define GRADE2DSHK_UTILS_H


template<class T>
// src 原数据首地址
// size 要扩容后的内存大小
// 当前结构内存储的数据元素的个数
auto my_realloc(T *src, int size, int len) -> decltype(src) {

    // 申请新的内存空间
    T *t = new T[size];

    // 将src指向的元素复制到新的空间
    for (int i = 0; i < len; i++)
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


#endif //GRADE2DSHK_UTILS_H
