#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:

    MyArray(int capacity)
    {
        cout << "MyArray的有参构造的调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAdress = new T[this->m_Capacity];
    }

    MyArray(const MyArray& arr)
    {
        cout <<"MyArray中拷贝构造的调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->m_Size = arr.pAdress;

        this->pAdress = new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAdress[i] = arr.pAdress[i];
        }
    }

    //operator= 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr)
    {
        cout << "MyArray的operator调用" << endl;
        if (this == &arr)
        {
            return *this;
        }

        //先判断原来兑取是否有数据，如果有先释放
        if (this->pAdress != NULL)
        {
            delete[] this->pAdress;
            this->pAdress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAdress = new T[arr.m_Capacity];
        for (int i = 0 ;i < this->m_Size; i++)
        {
            this->pAdress[i] = arr.pAdress[i];
        }
        return *this;
    }

    //尾删法
    void Push_Back(const T &val)
    {
        //判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAdress[this->m_Size] = val;
        this->m_Size++;
    }

    void Pop_Back()
    {
        //让用户访问不到最后一个元素
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;  
    }

    T operator[](int index)
    {
        return this->pAdress[index];
    }

    //返回数组的容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    int getSize()
    {
        return this->m_Size;
    }

    ~MyArray()
    {
        cout << "MyArray的析构函数的调用" << endl;
        if(this->pAdress != NULL)
        {
            delete[] this->pAdress;
            this->pAdress = NULL;
        }
    }

private:
    int m_Capacity;
    int m_Size;
    T *pAdress;
};