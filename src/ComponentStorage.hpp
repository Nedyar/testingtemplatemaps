#pragma once

#include <iterator>
#include <stdint.h>
#include <vector>
using namespace std;

template <class T>
class ComponentStorage {
public:

    using iterator = typename vector<T>::iterator;
    using const_iterator = typename vector<T>::const_iterator;

    //////////////////////////////////////////////////
    //              THE RULE OF THE 3               //
    //////////////////////////////////////////////////

    explicit ComponentStorage(const size_t max_cap) {
        inner_vector.reserve(max_cap);
    };
    ComponentStorage(const ComponentStorage<T> &s) = delete;
    ~ComponentStorage() = default;

    //////////////////////////////////////////////////
    //                  ITERATORS                   //
    //////////////////////////////////////////////////

    iterator begin() noexcept {
        return inner_vector.begin();
    }
    iterator end() noexcept {
        return inner_vector.end();
    }
    const_iterator begin() const noexcept {
        return inner_vector.begin();
    }
    const_iterator end() const noexcept {
        return inner_vector.end();
    }
    const_iterator cbegin() const noexcept {
        return inner_vector.cbegin();
    }
    const_iterator cend() const noexcept {
        return inner_vector.cend();
    }


    //////////////////////////////////////////////////
    //                  CAPACITY                    //
    //////////////////////////////////////////////////

    size_t size() const noexcept {
        return inner_vector.size();
    }

    size_t capacity() const noexcept {
        return inner_vector.capacity();
    }

    bool empty() const noexcept {
        return inner_vector.empty();
    }

    //////////////////////////////////////////////////
    //               ELEMENT ACCESS                 //
    //////////////////////////////////////////////////

    T &operator[](const size_t index) {
        return inner_vector[index];
    }

    T &at(const size_t index) {
        return inner_vector.at(index);
    }

    T &front() {
        return inner_vector.front();
    }

    T &back() {
        return inner_vector.back();
    }

    //////////////////////////////////////////////////
    //                  MODIFIERS                   //
    //////////////////////////////////////////////////

    T *emplace_back(const uint32_t id) {
        if (inner_vector.size() < inner_vector.capacity())
            inner_vector.emplace_back(id);
        else
            throw "ComponentStorage is full";

        return &inner_vector.back();
    }

    uint32_t erase(T *component) {
        auto index = (component - &inner_vector[0]);
        inner_vector[index] = inner_vector.back();
        inner_vector.pop_back();
        return inner_vector[index].entityId;

    }

    void clear() {
        inner_vector.clear();
    }

private:
    vector<T> inner_vector;
};
