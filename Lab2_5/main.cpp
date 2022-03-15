#include <iostream>
#include <fstream>

struct Elem
{
    int data;          // Данные 
    // Указатели на соседние вершины
    Elem* left;
    Elem* right;
    Elem* parent;
};

// Инициализация корня 
Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;        
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

// Добавление элемента
void ADD(int data, Elem*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

// Обход дерева
void PASS(Elem* v)
{
    if (v == nullptr)
        return;
    

    PASS(v->left);
   
    std::cout << v->data << std::endl;

    PASS(v->right);

     
}

Elem* SEARCH(int data, Elem* v)     // v - элемент, с которого начинаем поиск
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}


void DELETE(int data, Elem*& root)
{
   
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }  
    if (u->left == nullptr && u->right != nullptr && u == root)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
  
    if (u->left != nullptr && u->right == nullptr && u == root)
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }   
    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}
 
void SEARCHING(int data, Elem* v, int c)
{
    if (v == nullptr)
    {
        std::cout << "n";
        return;
    }
    else if (v->data == data)
    {
        std::cout << c;
        return;
    }
    else if (data < v->data)
        SEARCHING(data, v->left, c + 1);
    else
        SEARCHING(data, v->right, c + 1);
}
void CLEAR(Elem*& v)
{
    if (v == nullptr)
        return;
  

    CLEAR(v->left);
    

    CLEAR(v->right);


    delete v;
    v = nullptr;
}


int main()
{
    Elem* root = nullptr;
    std::ifstream in("input.txt");
    char a;
    int b;
    while (!in.eof())
    {
        in >> a;
        in >> b;
        if (a == '+')
        {
            ADD(b, root);
        }
        else if (a == '?')
        {
            SEARCHING(b, root, 1);
            std::cout << '\n';
        }
        else if (a == '-')
        {
            DELETE(b, root);
        }
        else if (a == 'E')
        {
            break;
        }

    }
    return 0;
}