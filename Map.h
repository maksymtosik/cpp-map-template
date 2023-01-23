#pragma once
#include <iostream>
#include <string>

class KeyAlreadyExistsException : public std::exception {
    public:
        const char* what() const throw() {
            return "Key already exists\n";
        }
};

class KeyNotFoundException : public std::exception {
    public:
        const char* what() const throw() {
            return "Key not found\n";
        }
};

template <class Key, class Value> class Map {
    public:
        Key* keys;
        Value* values;
        int size;
        int capacity;
        Map();
        Map(const Map<Key, Value>& map);
        Map& operator=(const Map<Key, Value>& map);
        ~Map();
        void add(Key key, Value value);
        void remove(Key key);
        Value* find(Key key);
    private:
        void resize();
};

template <class Key, class Value> std::ostream& operator<<(std::ostream& stream, const Map<Key, Value>& map);

template <class Key, class Value> Map<Key, Value>::Map() {
    this->size = 0;
    this->capacity = 5;
    this->keys = new Key[this->capacity];
    this->values = new Value[this->capacity];
}

template <class Key, class Value> Map<Key, Value>::Map(const Map<Key, Value>& map) {
    this->size = map.size;
    this->capacity = map.capacity;
    this->keys = new Key[this->capacity];
    this->values = new Value[this->capacity];
    for (int i = 0; i < size; i++) {
        this->keys[i] = map.keys[i];
        this->values[i] = map.values[i];
    }
}

template <class Key, class Value> Map<Key, Value>& Map<Key, Value>::operator=(const Map<Key, Value>& map) {
    if (this != &map) {
        delete[] this->keys;
        delete[] this->values;
        this->size = map.size;
        this->capacity = map.capacity;
        this->keys = new Key[this->capacity];
        this->values = new Value[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->keys[i] = map.keys[i];
            this->values[i] = map.values[i];
        }
    }
  return *this;
}

template <class Key, class Value> Map<Key, Value>::~Map() {
    delete[] this->keys;
    delete[] this->values;
}

template <class Key, class Value> void Map<Key, Value>::add(Key key, Value value) {
    for(int i = 0; i < this->size; i++) {
        if (this->keys[i] == key) {
        throw KeyAlreadyExistsException();
        }
    }
    if (this->size == this->capacity) {
        this->resize();
    }
    this->keys[this->size] = key;
    this->values[this->size] = value;
    this->size++;
}

template <class Key, class Value> Value* Map<Key, Value>::find(Key key) {
    for (int i = 0; i < this->size; i++) {
        if (this->keys[i] == key) {
            return &this->values[i];
        }
    }
    throw KeyNotFoundException();
    return 0;
}

template <class Key, class Value> void Map<Key, Value>::remove(Key key) {
    for (int i = 0; i < this->size; i++) {
        if (this->keys[i] == key) {
        for (int j = i; j < this->size - 1; j++) {
            this->keys[j] = this->keys[j + 1];
            this->values[j] = this->values[j + 1];
        }
        this->size--;
        return;
    }
    }
    throw KeyNotFoundException();
}

template <class Key, class Value> std::ostream& operator<<(std::ostream& stream, const Map<Key, Value>& map) {
    for (int i = 0; i < map.size; i++) {
        stream << map.keys[i] << ": " << map.values[i] << std::endl;
    }
    return stream;
}

template <class Key, class Value> void Map<Key, Value>::resize() {
    this->capacity *= 2;
    Key* newKeys = new Key[this->capacity];
    Value* newValues = new Value[this->capacity];
    for (int i = 0; i < size; i++) {
        newKeys[i] = this->keys[i];
        newValues[i] = this->values[i];
    }
    delete[] this->keys;
    delete[] this->values;
    this->keys = newKeys;
    this->values = newValues;
}   
