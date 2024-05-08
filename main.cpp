#include <iostream>

class Node
{
public:
    double data;
    Node* next;// создаем указатель на следующий элемент
public:
    Node(double data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Onelinkedlist
{
    public:
    Node *head , *tail;//ссылка на первый и последний элемент
    public:
    Onelinkedlist()//создаем конструктор
    {
        this->head = this->tail = NULL;
    }
    ~Onelinkedlist()//создаем диструктор 
    {
        while(head != NULL) pop_front();//удаляем пока есть в нем элементы   
    }
    void push_front(double data)//добавляем в начало
    {
        Node* node = new Node(data);
        node->next= head;
        head = node;
        if(tail == NULL) tail = node;//создаем первый объект
    }
    void push_back(double data)//добавляем в конец
    {
        Node* node = new Node(data);
        if(head == NULL) head = node;//создаем первый объект 
        if(tail != NULL) tail->next = node;
        tail = node ;
    }
    void pop_front()//удаляем с начала
    {
        if(head == NULL) return;//нечего удалять, потому что он пуст
        if(head == tail) //если у нас один объект
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node *node = head;
        head = node->next;
        delete node;
    }
    void pop_back()//удаляем с конца
    {
        if(tail == NULL) return;//удалять нечего
        if(head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        for(; node->next != tail; node ->next);
        node->next = NULL;
        delete tail;
        tail = node;
    }
    void delete_num(double num) {//удаляем элемент равный заданному числу 
        Node* cur = head;
        Node* prev = nullptr;
        while (cur != nullptr) {// пока объект существует 
            if (cur->data == num) {
                if (cur == head) {
                    pop_front();//удаляем с начала 
                    cur = head;
                } else {
                    prev->next = cur->next;
                    delete cur;
                    cur = prev->next;
                    if (cur == nullptr) tail = prev;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    Onelinkedlist lst;
    // добавление элементов
    lst.push_back(1.0);
    lst.push_back(2.0);
    lst.push_back(3.0);
    lst.push_back(4.0);
    lst.push_back(5.0);

    double num;
    std::cout << "Введите вещественное число, которое нужно удалить: ";
    std::cin >> num;

    // удаление элементов равных заданному числу
    lst.delete_num(num);

    // вывод списка
    for (Node* node = lst.head; node != nullptr; node = node->next)
        std::cout << node->data << " ";
    std::cout << "\n";

    return 0;
}