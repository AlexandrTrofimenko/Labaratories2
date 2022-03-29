#include <iostream>
#include <fstream>
#include <iomanip>
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
void PASS(Elem* v,int indent)
{
    if (v != nullptr)
    {
        if (v->right)
        {
            PASS(v->right, indent + 4);
        }
        if (indent)
        {
            std::cout << std::setw(indent) << ' ';
        }
        if (v->right)
        {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << v->data << "\n ";
        if (v->left)
        {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            PASS(v->left, indent + 4);
        }
    }
    
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
 
void SEARCHING(int data, Elem* v, int c) // c - глубина 
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
            PASS(root, 2);
            std::cout << "======" <<std::endl;
        }
        else if (a == '?')
        {
            SEARCHING(b, root, 0);
            std::cout << '\n';
        }
        else if (a == '-')
        {
            DELETE(b, root);
            std::cout << "Deleting" <<std::endl;
            PASS(root, 2);
            std::cout << "Deleting" << std::endl;
        }
        else if (a == 'E')
        {
            break;
        }
    }
    CLEAR(root);
    return 0;
}