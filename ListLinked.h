#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;   // Puntero al primer nodo de la lista
    int n;             // Número de elementos en la lista

public:
    ListLinked() : first(nullptr), n(0) {}
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) const override {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("Índice fuera de rango");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    friend ostream& operator<<(ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

    // Métodos heredados de la interfaz List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > size()) {
            throw out_of_range("Fuera de rango");
        }
        if (pos == 0) {
            prepend(e);
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node<T>* newNode = new Node<T>(e, current->next);
            current->next = newNode;
            ++n;
        }
    }

    void append(T e) override {
        if (first == nullptr) {
            first = new Node<T>(e);
        } else {
            Node<T>* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node<T>(e);
        }
        ++n;
    }

    void prepend(T e) override {
        Node<T>* newNode = new Node<T>(e, first);
        first = newNode;
        ++n;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("Fuera de rango");
        }
        Node<T>* current = first;
        if (pos == 0) {
            first = first->next;
            T data = current->data;
            delete current;
            --n;
            return data;
        }
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node<T>* toRemove = current->next;
        current->next = toRemove->next;
        T data = toRemove->data;
        delete toRemove;
        --n;
        return data;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("Fuera de rango");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) {
        Node<T>* current = first;
        int pos = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return pos;
            }
            current = current->next;
            ++pos;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() const {
        return n;
    }
};

#endif

