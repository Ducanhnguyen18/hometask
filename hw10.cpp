#include<iostream>
using namespace std;

class BinaryTree
{
public:
    class Parrent;
    class Left;
    class Right;
    Parrent *parrent;
    BinaryTree(int x)
    {
        parrent = new Parrent(x);
        size++;
    }
    void Append(int data);
    void Three_Go(Left* current);
    void Three_Go(Right* current);
    void Reverse_Go(Left* current);
    void Reverse_Go(Right* current);
    int size = 0;

public:
    class Parrent
    {
    public:
        Parrent(int data, Left* pLeft = nullptr, Right* pRight = nullptr)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
        int data;
        Left* pLeft;
        Right* pRight;
    };
private:
    class Left
    {
    public:
        Left(int data, Left* pRight = nullptr, Left* pLeft = nullptr)
        {
            this->data = data;
            this->pRight = pRight;
            this->pLeft = pLeft;
        }
        int data;
        Left* pRight;
        Left* pLeft;
    };
    class Right
    {
    public:
        Right(int data, Right* pRight = nullptr, Right* pLeft = nullptr)
        {
            this->data = data;
            this->pRight = pRight;
            this->pLeft = pLeft;
        }
        int data;
        Right* pRight;
        Right* pLeft;
    };
};

void BinaryTree::Append(int data)
{
    if (data <= parrent->data)
    {
        if (parrent->pLeft == nullptr)
        {
            Left* current = new Left(data);
            parrent->pLeft = current;
            size++;
        }
        else
        {
            Left* current = this->parrent->pLeft;
            while ((current->pLeft != nullptr && current->pRight != nullptr) || (current->pLeft == nullptr && current->pRight !=nullptr) ||(current->pLeft != nullptr && current->pRight == nullptr))
            {
                if (data <= current->data)
                {
                    if (current->pLeft == nullptr)
                    {
                        current->pLeft = new Left(data);
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->pLeft;
                        if (current->pLeft == nullptr && current->pRight == nullptr)
                        {
                            if (data <= current->data)
                            {
                                current->pLeft = new Left(data);
                                size++;
                                return;
                            }
                            else
                            {
                                current->pRight = new Left(data);
                                size++;
                                return;
                            }
                        }
                    }
                }
                else
                {
                    if (current->pRight == nullptr)
                    {
                        current->pRight = new Left(data);
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->pRight;
                        if (current->pLeft == nullptr && current->pRight == nullptr)
                        {
                            if (data <= current->data)
                            {
                                current->pLeft = new Left(data);
                                size++;
                                return;
                            }
                            else
                            {
                                current->pRight = new Left(data);
                                size++;
                                return;
                            }
                        }
                    }
                }
            }
            if (data <= current->data)
            {
                current->pLeft = new Left(data);
                size++;
            }
            else
            {
                current->pRight = new Left(data);
                size++;
            }
            
        }
    }
    else
    {
        if (parrent->pRight == nullptr)
        {
            Right* current = new Right(data);
            parrent->pRight = current;
            size++;
        }
        else
        {
            Right* current = this->parrent->pRight;
            while ((current->pLeft != nullptr && current->pRight != nullptr) || (current->pLeft == nullptr && current->pRight != nullptr) || (current->pLeft != nullptr && current->pRight == nullptr))
            {
                if (data <= current->data)
                {
                    if (current->pLeft == nullptr)
                    {
                        current->pLeft = new Right(data);
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->pLeft;
                        if (current->pLeft == nullptr && current->pRight == nullptr)
                        {
                            if (data <= current->data)
                            {
                                current->pLeft = new Right(data);
                                size++;
                                return;
                            }
                            else
                            {
                                current->pRight = new Right(data);
                                size++;
                                return;
                            }
                        }
                    }
                }
                else
                {
                    if (current->pRight == nullptr)
                    {
                        current->pRight = new Right(data);
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->pRight;
                        if (current->pLeft == nullptr && current->pRight == nullptr)
                        {
                            if (data <= current->data)
                            {
                                current->pLeft = new Right(data);
                                size++;
                                return;
                            }
                            else
                            {
                                current->pRight = new Right(data);
                                size++;
                                return;
                            }
                        }
                    }
                }
            }
            if (data <= current->data)
            {
                current->pLeft = new Right(data);
                size++;
            }
            else
            {
                current->pRight = new Right(data);
                size++;
            }

        }
    }
        
    
}

void BinaryTree::Three_Go(Left* current)
{
    if (current)
    {
        Three_Go(current->pLeft);
        cout << current->data <<" ";
        Three_Go(current->pRight);
    }
}

void BinaryTree::Three_Go(Right* current)
{
    if (current)
    {
        Three_Go(current->pLeft);
        cout << current->data << " ";
        Three_Go(current->pRight);
    }
}

void BinaryTree::Reverse_Go(Left* current)
{
    if (current)
    {
        Reverse_Go(current->pRight);
        cout << current->data << " ";
        Reverse_Go(current->pLeft);
    }
    
}
void BinaryTree::Reverse_Go(Right* current)
{
    if (current)
    {
        Reverse_Go(current->pRight);
        cout << current->data << " ";
        Reverse_Go(current->pLeft);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int x;
    cout << "Введите корневой элемент" << endl;
    cin >> x;
    BinaryTree BT(x);
    BT.Append(8);
    BT.Append(9);
    BT.Append(4);
    BT.Append(7);
    BT.Append(11);
    BT.Append(5);
    BT.Append(10);
    BT.Append(6);
    BT.Three_Go(BT.parrent->pLeft);
    BT.Three_Go(BT.parrent->pRight);
    cout << endl;
    BT.Reverse_Go(BT.parrent->pRight);
    BT.Reverse_Go(BT.parrent->pLeft);

    
    return 0;
}
