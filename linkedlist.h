#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList {

    template <class N>
    struct Node {
        N item;
        Node<N> *next;
    };

public:
    LinkedList() :
        head(NULL),
        tail(NULL),
        size(0)
    {}

    void push_front(const T &item);
    void push_back(const T &item);

    void delete_top();

    int get_size() const { return size;  }

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

template <class T>
void LinkedList<T>::push_front(const T &item) {
    Node<T> *old_head = head;

    head = new Node<T>;
    head->item = item;
    head->next = old_head;

    if (size == 0)
        tail = head;

    size++;
}

template <class T>
void LinkedList<T>::push_back(const T &item) {
    Node<T> *old_tail = tail;

    tail = new Node<T>;
    tail->item = item;
    tail->next = NULL;

    if (size == 0)
        head = tail;
    else
        old_tail->next = tail;

    size++;
}

template <class T>
void LinkedList<T>::delete_top() {
    if (size == 0)
        throw "Empty list, can't delete";

    Node<T> *old_head = head;
    head = head->next;
    delete old_head;
    size--;
}

#endif // LINKEDLIST_H

