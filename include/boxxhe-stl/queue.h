#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "boxxhe-stl/config.h"
#include "boxxhe-stl/functional.h"
#include "boxxhe-stl/algorithm/push_heap.h"
#include "boxxhe-stl/algorithm/make_heap.h"
#include "boxxhe-stl/algorithm/pop_heap.h"

BEGIN_NAMESPACE_BOXXHE

/*!
 * @brief 优先队列是容器适配器，它提供常数时间的最大元素查找（默认大顶堆，可以通过Compare更改顺序），对数代价的插入与删除。
 * @tparam pT 存储的元素类型
 * @tparam Container 用于存储元素的底层容器类型。容器必须满足序列容器的要求，默认为vector TODO:实现了自己的vector之后替换
 * @tparam Compare 提供严格弱序的比较类型，注意比较 (Compare) 形参的定义，使得若其第一参数在弱序中先于其第二参数则返回 true, 但因为 priority_queue 首先输出最大元素，故“先来”的元素实际上最后输出。
 *                 比如传入less：生成大顶堆，传入greater：生成小顶堆
 */
template<class Tp, class Container = std::vector<Tp>, class Compare = std::less<typename Container::value_type>>
class priority_queue {
public:
    typedef Container container_type;
    typedef Compare value_compare;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::reference reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type size_type;

protected:
    /*!
     * @brief 承载优先队列元素的容器对象
     */
    container_type c_;

    /*!
     * @brief 优先队列中元素的比较函数对象
     */
    value_compare comp_; 
    
public:
    /*!
     * @brief 默认无参数构造函数，调用容器对象和比较对象的无参数构造函数进行构造初始化
     */
    inline priority_queue() : c_(), comp_() {}

    /*!
     * @brief 拷贝构造函数
     * @param q 用作源的另一个优先队列
     */
    inline priority_queue(const priority_queue& q) : c_(q.c_), comp_(q.comp_) {}

    /*!
     * @brief 复制赋值运算符
     * @param q 用作源的另一个优先队列
     * @return *this
     * @note 复杂度：通常为O(n)，等价于底层容器 operator= 的复杂度 
     */
    inline priority_queue& operator=(const priority_queue& q)
        { c_ = q.c_; comp_ = q.comp_; return *this; }

    /*!
     * @brief 移动构造函数
     * @param q 用作源的另一个优先队列，右值
     */
    inline priority_queue(priority_queue&& q)
        : c_(std::move(q.c_)), comp_(std::move(q.comp_)) {}
    
    /*!
     * @brief 移动赋值函数
     * @param q 用作源的另一个优先队列，右值
     * @return 
     */
    inline priority_queue& operator=(priority_queue&& q)
        { c_ = std::move(q.c_); comp_ = std::move(q.comp_); return *this; }

    /*!
     * @brief 一个参数的构造函数，传入比较函数，容器使用默认空构造函数
     * @param comp 比较函数对象
     */
    inline explicit priority_queue(const value_compare& comp)
        : c_(), comp_(comp) {}
    
    /*!
     * @brief 用c的内容复制构造底层容器c_。用comp的内容复制构造比较函数对象comp_
     * @param comp 比较函数对象
     * @param c 容器
     */
    inline priority_queue(const value_compare& comp, const container_type& c);

    /*!
     * @brief 构造函数c是右值引用
     * @param comp 比较函数对象
     * @param c 容器
     */
    inline priority_queue(const value_compare& comp, container_type&& c);

    /*!
     * @brief 构造函数，迭代器，带默认的比较函数对象
     * @tparam InputIter 单向输入迭代器
     * @param f 左闭区间
     * @param l 右开区间
     * @param comp 比较函数对象
     */
    template <class InputIter>
    priority_queue(InputIter f, InputIter l, const value_compare& comp = value_compare());

    /*!
     * @brief 构造函数，迭代器，容器为左值
     * @tparam InputIter 单项输入迭代器
     * @param f 左闭区间
     * @param l 右开区间
     * @param comp 比较函数对象
     * @param c 容器
     */
    template <class InputIter>
    priority_queue(InputIter f, InputIter l, const value_compare& comp, const container_type& c);

     /*!
     * @brief 构造函数，迭代器，容器为右值
     * @tparam InputIter 单项输入迭代器
     * @param f 左闭区间
     * @param l 右开区间
     * @param comp 比较函数对象
     * @param c 容器
     */
    template <class InputIter>
    priority_queue(InputIter f, InputIter l, const value_compare& comp, container_type&& c);

    // TODO: Alloc的这几个构造函数还没咋搞懂，先不写了

    /*!
     * @brief 检查优先队列中底层容器是否为空
     * @return 若底层容器为空，返回true，否则为false
     * @note 复杂度：O(1)
     */
    inline bool empty() const { return c_.empty(); }
    
    /*!
     * @brief 返回优先队列中的元素个数，即底层容器中的元素数
     * @return 容器的元素数
     * @note 复杂度：O(1)
     */
    inline size_type size() const { return c_.size(); }

    /*!
     * @brief 返回优先队列顶元素的const引用。此元素将在调用 pop() 时被移除。若使用默认比较函数，则返回的元素亦为优先队列中最大的元素。
     * @return 优先队列顶元素的引用，即堆头元素
     * @note  复杂度：O(1)
     */
    inline const_reference top() const { return c_.front(); }

    /*!
     * @brief 将val加入到优先队列中
     * @param v 要加入的值
     * @note 复杂度：O(logn)
     */
    inline void push(const value_type& v);

    /*!
     * @brief 将val(右值)加入到优先队列中
     * @param v 要加入的右值
     * @note 复杂度：O(logn)
     */
    inline void push(value_type&& v);

    /*!
     * @brief 推入新元素到 priority_queue 原位构造元素，即不进行移动或复制操作。以与提供给函数者准确相同的参数调用元素的构造函数。
     * @tparam ...Args 转发给元素构造函数的参数类型
     * @param ...args 转发给元素构造函数的参数
     */
    template <class... Args>
    inline void emplace(Args&&... args);

    /*!
     * @brief 从 priority_queue 移除顶元素
     */
    inline void pop();

    /*!
     * @brief 和q交换元素内容
     * @param q 要交换的队列
     */
    inline void swap(priority_queue& q);
};

template <class Tp, class Container, class Compare>
inline
priority_queue<Tp, Container, Compare>::priority_queue(const Compare& comp,
                                                       const container_type& c)
    : c_(c), comp_(comp)
{
    boxxhe::make_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
inline
priority_queue<Tp, Container, Compare>::priority_queue(const value_compare& comp,
                                                       container_type&& c)
    : c_(std::move(c)), comp_(comp)
{
    boxxhe::make_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
template <class InputIter>
inline
priority_queue<Tp, Container, Compare>::priority_queue(InputIter f, InputIter l,
                                                       const value_compare& comp)
    : c_(f, l), comp_(comp)
{
    boxxhe::make_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
template <class InputIter>
inline
priority_queue<Tp, Container, Compare>::priority_queue(InputIter f, InputIter l,
                                                       const value_compare& comp,
                                                       const container_type& c)
    : c_(c), comp_(comp)
{
    c_.insert(c_.end(), f, l);
    boxxhe::make_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
template <class InputIter>
inline
priority_queue<Tp, Container, Compare>::priority_queue(InputIter f, InputIter l,
                                                       const value_compare& comp,
                                                       container_type&& c)
    : c_(std::move(c)), comp_(comp)
{
    c_.insert(c_.end(), f, l);
    boxxhe::make_heap(c_.begin(), c_.end(), comp_);
} 

template <class Tp, class Container, class Compare>
inline
void
priority_queue<Tp, Container, Compare>::push(const value_type& v)
{
    c_.push_back(v);
    boxxhe::push_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
inline
void
priority_queue<Tp, Container, Compare>::push(value_type&& v)
{
    c_.push_back(std::move(v));
    boxxhe::push_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Container, class Compare>
template <class... Args>
inline
void
priority_queue<Tp, Container, Compare>::emplace(Args&&... args)
{
    c_.emplace_back(std::forward<Args>(args)...);
    boxxhe::push_heap(c_.begin(), c_.end(), comp_);
}

template <class Tp, class Containter, class Compare>
inline
void
priority_queue<Tp, Containter, Compare>::pop()
{
    boxxhe::pop_heap(c_.begin(), c_.end(), comp_);
    c_.pop_back();
}

template <class Tp, class Container, class Compare>
inline
void
priority_queue<Tp, Container, Compare>::swap(priority_queue& q)
{
    using boxxhe::swap;
    swap(c_, q.c_);
    swap(comp_, q.comp_);
}

template<class Tp, class Container, class Compare>
inline
void
swap(priority_queue<Tp, Container, Compare>& x,
     priority_queue<Tp, Container, Compare>& y)
{
    x.swap(y);
}

END_NAMESPACE_BOXXHE

#endif
