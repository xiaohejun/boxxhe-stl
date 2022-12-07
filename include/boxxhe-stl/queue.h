#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "config.h"
#include "functional.h"
#include <vector>
#include <queue> // TODO 删除

BEGIN_NAMESPACE_BOXXHE






// TODO vector实现之后使用自己实现的，当前先使用vector的
template<class T, class Container = std::vector<T>, class Compare = BOXXHE::less<typename Container::value_type>>
class priority_queue {
public:
    //! 成员类型
    typedef Container container_type;
    typedef Compare value_compare;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::reference reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type size_type;

protected:
    //! 成员变量

    //! 承载优先队列元素的容器
    container_type container_;

    //! 优先队列中元素的比较函数对象
    value_compare comp_; 
    
public:
    //! 成员函数
    //! 默认空的构造函数 
    priority_queue() : container_(), comp_() {}

    //! 析构函数，TODO当前先使用默认
    ~priority_queue() = default;

    //! 复制构造函数
    //! TODO 待实现
    // priority_queue& operator=(const priority_queue& other);

    //! 元素访问
    //! 返回优先队列队头元素，返回值为常量引用，不可修改
    const_reference top() const { return container_.front(); }

    //! 容量

    //! 如果优先队列为空，返回true
    bool empty() const {return container_.empty(); }

    
};










END_NAMESPACE_BOXXHE

#endif
