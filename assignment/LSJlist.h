#pragma once

namespace lsj
{
    template<typename T>
    class list
    {
    public:
        ~list()
        {
            clear();
        }

        class node;

        class iterator
        {
            friend list;
        public:
            iterator() {}
            iterator(list* _List, node* _Node)
                : List(_List), Node(_Node) {}

            bool operator==(const iterator& _Other) const
            {
                return List == _Other.List && Node == _Other.Node;
            }

            bool operator!=(const iterator& _Other) const
            {
                return !(*this == _Other);
            }

            T& operator*()
            {
                return Node->Value;
            }

            iterator& operator++()
            {
                Node = Node->Next;
                return *this;
            }

            iterator operator++(int)
            {
                iterator Result = *this;
                ++(*this);
                return Result;
            }

            iterator& operator--()
            {
                Node = Node->Prev;
                return *this;
            }

            iterator operator--(int)
            {
                iterator Result = *this;
                --(*this);
                return Result;
            }
        private:
            list* List = nullptr;
            node* Node = nullptr;
        };

    private:
        class node
        {
        public:
            T Value;
            list* List = nullptr;
            node* Prev = nullptr;
            node* Next = nullptr;
        };

        node* Head = nullptr;
        node* Tail = nullptr;
        int Size = 0;
    public:
        int size()
        {
            return Size;
        }

        bool empty()
        {
            return 0 == Size;
        }

        void push_front(T _Data)
        {
            node* NewNode = new node();
            NewNode->Value = _Data;
            NewNode->List = this;

            if (0 == Size)
            {
                Head = Tail = NewNode;
                ++Size;
                return;
            }

            Head->Prev = NewNode;
            NewNode->Next = Head;
            Head = NewNode;
            ++Size;
        }

        void push_back(T _Data)
        {
            node* NewNode = new node();
            NewNode->Value = _Data;
            NewNode->List = this;

            if (0 == Size)
            {
                Head = Tail = NewNode;
                ++Size;
                return;
            }

            Tail->Next = NewNode;
            NewNode->Prev = Tail;
            Tail = NewNode;
            ++Size;
        }

        void pop_front()
        {
            if (0 == Size)
            {
                return;
            }

            if (1 == Size)
            {
                delete Head;
                Head = Tail = nullptr;
                --Size;
                return;
            }

            Head = Head->Next;
            delete Head->Prev;
            Head->Prev = nullptr;
            --Size;
        }

        void pop_back()
        {
            if (0 == Size)
            {
                return;
            }

            if (1 == Size)
            {
                delete Tail;
                Head = Tail = nullptr;
                --Size;
                return;
            }

            Tail = Tail->Prev;
            Tail->Next = nullptr;
            delete Tail->Next;
            --Size;
        }

        T& front()
        {
            return Head->Value;
        }

        T& back()
        {
            return Tail->Value;
        }

        void clear()
        {
            while (Size > 0)
            {
                pop_front();
            }
        }

        iterator insert(const iterator& _pos, const T& _value)
        {
            if (this != _pos.List)
            {
                MsgBoxAssert("다른 리스트의 iterator를 인자로 넣었습니다.");
                return end();
            }

            // push front
            if (Head == _pos.Node)
            {
                push_front(_value);
                return begin();
            }

            // push back
            if (_pos == end())
            {
                push_back(_value);
                return iterator(this, Tail);
            }

            node* NewNode = new node();
            NewNode->Value = _value;
            NewNode->List = this;

            node* PrevNode = _pos.Node->Prev;
            PrevNode->Next = NewNode;
            NewNode->Prev = PrevNode;
            _pos.Node->Prev = NewNode;
            NewNode->Next = _pos.Node;

            ++Size;
            return iterator(this, NewNode);
        }

        iterator erase(iterator& _pos)
        {
            if (this != _pos.List)
            {
                MsgBoxAssert("다른 리스트의 iterator를 인자로 넣었습니다.");
                return end();
            }

            if (_pos == end())
            {
                MsgBoxAssert("end iterator를 인자로 넣었습니다.");
                return end();
            }

            // pop_front
            if (Head == _pos.Node)
            {
                pop_front();
                return begin();
            }

            // pop_back
            if (Tail == _pos.Node)
            {
                pop_back();
                return end();
            }

            node* PrevNode = _pos.Node->Prev;
            node* NextNode = _pos.Node->Next;
            PrevNode->Next = NextNode;
            NextNode->Prev = PrevNode;

            delete _pos.Node;
            _pos.Node = nullptr;

            --Size;
            return iterator(this, PrevNode);
        }

        iterator begin()
        {
            return iterator(this, Head);
        }

        iterator end()
        {
            return iterator(this, nullptr);
        }
    };
}
