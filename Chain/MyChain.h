//
// Created by liuzehao on 2021/10/4.
//

#ifndef GRADE2DSHK_MYCHAIN_H
#define GRADE2DSHK_MYCHAIN_H

template<class T>
class MyChain {
public:
    void travel(void(*)(T));
    void insert_item_by_index(int, T) const;
};


#endif //GRADE2DSHK_MYCHAIN_H
