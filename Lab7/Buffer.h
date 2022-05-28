#ifndef LAB7_BUFFER_H
#define LAB7_BUFFER_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "errors.h"

template <typename T>
class CircularBuffer
{
public:
    class Iterator : public iterator<random_access_iterator_tag, T>
    {
    private:
        T *iter;

    public:
        using distanse = typename iterator<random_access_iterator_tag, T>::difference_type;

        Iterator() : iter(nullptr) {}

        explicit Iterator(T *other) : iter(other) {} // ïðåäîòâðàùàåò íåÿâíîå ïðåîáðàçîâàíèå òèïîâ ïðè êàìïèëÿöèè

        Iterator(const Iterator &other) : iter(other.iter) {}

        distanse operator-(const Iterator &other) const { return iter - other.iter; } // âîçâðàùàåò äèñòàíöèþ ìåæäó èòåðàòîðîì è äðóãîé äèñòàíöèåé

        Iterator operator+(distanse other) const { return Iterator(iter + other); } // ïðèáàâëÿåò äèñòàíöèþ ê èòåðàòîðó

        Iterator operator-(distanse other) const { return Iterator(iter - other); } // âû÷èòàåò äèñòàíöèþ èç èòåðàòîðà

        friend Iterator operator+(distanse a, const Iterator &b) { return Iterator(a + b.iterator); } // ïðèíèìàåò äèñòàíöèþ è èòåðàòîè è âîçâðàùàåò èõ ñóììó

        friend Iterator operator-(distanse a, const Iterator &b) { return Iterator(a - b.iterator); } // ïðèíèìàåò äèñòàíöèþ è èòåðàòîè è âîçâðàùàåò èõ ðàçíîñòü

        bool operator==(const Iterator &other) const { return iter == other.iter; }

        bool operator!=(const Iterator &other) const { return !(iter == other.iter); }

        bool operator>(const Iterator &other) const { return iter > other.iter; }

        bool operator<(const Iterator &other) const { return iter < other.iter; }

        bool operator>=(const Iterator &other) const { return !(iter < other.iter); }

        bool operator<=(const Iterator &other) const { return !(iter > other.iter); }

        T &operator*() const { return *iter; }

        T *operator->() const { return iter; }

        const T &operator[](int index) const { return iter[index]; }

        Iterator &operator=(const Iterator &other)
        {
            iter = other.iter;
            return *this;
        }

        Iterator &operator=(T *other)
        {
            iter = other;
            return *this;
        }

        Iterator &operator+=(distanse other)
        {
            iter += other;
            return *this;
        }

        Iterator &operator-=(distanse other)
        {
            iter -= other;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp(*this);
            ++iter;
            return tmp;
        }

        Iterator &operator++()
        {
            ++iter;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator tmp(*this);
            --iter;
            return tmp;
        }

        Iterator &operator--()
        {
            --iter;
            return *this;
        }
    };

    [[nodiscard]] int size() const
    {
        return arr_size;
    }

    [[nodiscard]] int capacity() const
    {
        return arr_capacity;
    }

    [[nodiscard]] bool empty() const
    {
        if (arr_size == zero_value)
            return true;
        else
            return false;
    }

    [[nodiscard]] Iterator end() const
    {
        return last_elem + 1;
    }

    [[nodiscard]] Iterator begin() const
    {
        return first_elem;
    }

    T &operator[](unsigned int index)
    {
        return arr[index];
    }

    [[nodiscard]] const T &at(int index) const
    {
        if (index < arr_size)
            return arr[index];
        else
            Errors::wrongIndex();
    }

    void changeCapacity(int value)
    {
        if (value > arr_capacity)
            arr_capacity = value;
        else
            Errors::wrongCapacity();
    }

    ~CircularBuffer()
    {
        delete[] arr;
    }

    explicit CircularBuffer(int value)
    {
        if (value >= zero_value)
        {
            arr_size = value;
            arr_capacity = (int)(value * 1.2);
            for (auto i = zero_value; i < value; ++i)
                arr[i] = zero_value;

            Iterator startIter(&arr[zero_value]);
            Iterator endIter(&arr[value - 1]);
            iter_start = iter_end = startIter;
            first_elem = &arr[zero_value];
            last_elem = &arr[value - 1];
        }
        else
            Errors::wrongBufferSize();
    }

    void resize(int newSize)
    {
        if (newSize <= zero_value)
        { // óäàëÿåì áóôôåð
            arr_size = arr_capacity = zero_value;
            iter_end = first_elem = iter_start = last_elem--;
        }
        else if (newSize == arr_size - 1 || newSize == arr_size)
        { // äåëàåì íà 1 ìåíüøå èëè îñòàâëÿåì òîò æå ðàçìåð
            arr_size--;
            iter_end = &arr[arr_size - 1];
        }
        else if (newSize > arr_size)
        { // óâåëè÷èâàåì ðàçìåð
            T *tmpArr = arr;
            int prevSize = arr_size;
            arr_size = newSize;
            arr_capacity = (int)(newSize * 1.2);
            arr = tmpArr;
            iter_end = &arr[prevSize];
            last_elem = &arr[arr_size - 1];
        }
        else
            Errors::makeBufferSmaller();
    }

    void clear()
    {
        resize(-1);
    }

#ifdef NOT_CIRCULAR
    // ÍÅ ìåíÿåò êàïàñèòè
    void emplace_back(T value)
    {
        if (size() + 1 <= arr_capacity)
        {
            *(++iter_end) = value;
            iter_cur++;
            arr_size++;
        }
        else
            fullBuffer();
    }

    // ÍÅ ìåíÿåò êàïàñèòè
    void emplace_begin(T value)
    {
        if (size() + 1 <= arr_capacity)
        {
            T tmp = arr[zero_value];
            iter_end = &arr[arr_size];

            for (int i = arr_size; i > zero_value; --i)
                arr[i] = arr[i - 1];

            *iter_start = value;
            iter_cur++;
        }
        else
            fullBuffer();
    }

    void pop_back()
    {
        if (arr_size > 1)
            resize(arr_size - 1);
        else
            clear();
    }

    void pop_front()
    {
        if (arr_size < 1)
            clear();
        else
        {
            for (int i = zero_value; i < arr_size - 1; ++i)
                arr[i] = arr[i + 1];
            arr_size--;
            iter_end--;
        }
    }

    // ïðîâåðÿåò êàïàñèòè è óâåëè÷èâàåò åãî åñëè íàäî
    void push_back(T value)
    {
        if (size() + 1 < arr_capacity)
        {
            *(++iter_end) = value;
            arr_size++;
            iter_cur++;
        }
        else
        {
            T *tmpArr = arr;
            unsigned int prevSize = size();

            if (arr_size >= 5)
            {
                arr_size++;
                arr_capacity = (int)(arr_size * 1.2);
            }
            else
                arr_size++;

            *arr = *tmpArr;
            arr[prevSize] = value;
            iter_end = &arr[prevSize];
            iter_cur++;
        }
    }

    // ïðîâåðÿåò êàïàñèòè è óâåëè÷èâàåò åãî åñëè íàäî
    void push_front(T value)
    {
        if (size() + 1 < arr_capacity)
        {
            T tmp = arr[zero_value];
            resize(arr_size + 1);

            for (int i = arr_size; i > zero_value; --i)
                arr[i] = arr[i - 1];
            arr[zero_value] = tmp;

            *iter_start = value;
            iter_cur++;
        }
        else
        {
            T tmp = arr[zero_value];
            unsigned int prevSize = size();

            resize(arr_size + 1);

            for (int i = arr_size; i > zero_value; --i)
                arr[i] = arr[i - 1];
            arr[zero_value] = tmp;

            *iter_start = value;
            iter_end = &arr[prevSize];
            iter_cur++;
        }
    }
#endif // NOT_CIRCULAR

    void circular_push_front(T value)
    {
        *iter_start = value;
        (iter_start == first_elem) ? iter_start = last_elem : --iter_start;
    }

    void circular_push_back(T value)
    {
        *iter_end = value;
        (iter_end == last_elem) ? iter_end = first_elem : ++iter_end;
    }

    void circular_pop_front()
    {
        *iter_start = zero_value;
        (iter_start == last_elem) ? iter_start = first_elem : ++iter_start;
    }

    void circular_pop_back()
    {
        *iter_end = zero_value;
        (iter_end == first_elem) ? iter_end = last_elem : --iter_end;
    }

private:
    int arr_size = zero_value, arr_capacity = zero_value;
    T *arr = new T[arr_size];
    Iterator iter_start, iter_end, first_elem, last_elem;
};

#endif