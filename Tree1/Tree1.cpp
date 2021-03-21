﻿#include <iostream>
using namespace std;
#define tab "\t"

class Tree
{
    class Element
    {
        int Data;
        Element *pLeft, *pRight;
    public:
        Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
        {
            cout << "EConstructor:\t" << this << endl;
        }
        ~Element()
        {
            cout << "EDestructor:\t" << this << endl;
        }
        bool is_leaf()
        {
            return pLeft == pRight;
        }
        friend class Tree;
    }*Root;
public:
    Element* getRoot()
        {
            return this->Root;
        }
    Tree() :Root(nullptr)
    {
        cout << "EConstructor:\t" << this << endl;
    }
    Tree(const Tree& other)
    {
        copy(other.Root);
        cout << "CopyConstructor:" << this << endl;
    }
    ~Tree()
    {
        clear(this->Root);
        cout << "TDestructor:\t" << this << endl;
    }
    void insert(int Data)
    {
        insert(Data, this->Root);
    }
    int minValue()
    {
        if (this->Root);
        return minValue(this->Root);
        return 0;
    }
    int maxValue()
    {
        return this->Root ? maxValue(this->Root) : 0;
        return 0;
    }
    int size()
    {
        return this->Root ? count(this->Root) : 0;
    }
    int sum()
    {
        return this->Root ? sum(this->Root) : 0;
    }
    double avg()
    {
        return (double)sum(this->Root)/count (this->Root);
    }
    void clear()
    {
        clear(this->Root);
        this->Root == nullptr;
    }
    void print()
    {
        print(this->Root);
        cout << endl;
    }
private:
    void insert(int Data, Element* Root)//Root - корневой элемент поддерева
    {
        if (this->Root == nullptr)this->Root = new Element(Data);
        if (Root == nullptr)return;// если зашли в ветку, а она пустая, то сразу же выходим из нее
        if (Data < Root->Data)
        {
            if (Root->pLeft == nullptr)
                Root->pLeft = new Element(Data);
            else
                insert(Data, Root->pLeft);
        }
        else /*if (Data > Root->Data)*/
        {
            if (Root->pRight)insert(Data, Root->pRight);
            else Root->pRight = new Element(Data);
        }
    }
    int minValue(Element* Root)
    {
        if (Root->pLeft == nullptr)return Root->Data;
        else return minValue(Root->pLeft);
    }
    int maxValue(Element* Root)
    {
       // if (Root->pRight)return maxValue(Root->pRight);
       // else return Root->Data;
       return Root->pRight ? maxValue(Root->pRight) : Root->Data;
    }
    int count(Element* Root)
    {
        if (Root == nullptr) return 0;
        // if (Root->is_leaf())return 1;
        // else return count(Root->pLeft) + count(Root->pRight) + 1;
        return Root->is_leaf() ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;
    }
    int sum(Element* Root)
    {
        if (Root == nullptr) return 0;
       // if (Root->is_leaf())return 1;
        else return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
    }
    void copy(Element* Root)
    {
        if (Root == nullptr) return;
        insert(Root->Data, this->Root);
        copy(Root->pLeft);
        copy(Root->pRight);
    }
    void clear(Element* Root)
    {
        if (Root == nullptr)return;
        clear(Root->pLeft);
        clear(Root->pRight);
        delete Root;
    }
    void print(Element* Root)
    {
        if (Root == nullptr)return;
        print(Root->pLeft);
        cout << Root->Data << tab;
        print(Root->pRight);
    }

};

void main()
    {
        setlocale(LC_ALL, "Russian");
        int n;  //размер дерева
        cout << "Введите количество элементов: "; cin >> n;
        Tree t;
        for (int i = 0; t.size() < n;  i++)
        {
                                         // t.insert(rand() % 100, t.getRoot());
            t.insert(rand() % 100);
            // cout << rand() % 100 << tab;
        };
                                         //t.print(t.getRoot());
                                         //cout << endl;
        t.print();
        cout << "Минимальное значение в дереве: " << t.minValue() << endl;
        cout << "Максимальное значение в дереве: " << t.maxValue() << endl;
        cout << "Количество элементов дерева: " << t.size() << endl;
        cout << "Сумма элементов дерева: " << t.sum() << endl;
        cout << "Среднее арифметическое значение элементов дерева: " << t.avg() << endl;
        Tree t2 = t;
        t2.print();
};