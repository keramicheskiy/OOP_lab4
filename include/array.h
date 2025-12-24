#pragma once

#include <initializer_list>
#include <memory>

template <typename T>
class Array {
private:
    size_t size = 0, capacity = 0;
    std::unique_ptr<T[]> data;

public:
    Array() = default;

    Array(const size_t & size, const T& value = T());

    Array(const std::initializer_list<T> &list);

    Array(const Array& other);

    Array(Array&& other) noexcept;

    ~Array() = default;

    size_t getSize() const;

    size_t getCapacity() const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    void push(const T& element);

    T pop();

    void remove(size_t index);

    void clear();

    void set(size_t index, const T& element);

    void resize(size_t size);

    bool contains(const T& element) const;

    Array& operator=(const Array& other);

    Array& operator=(Array&& other) noexcept;

    bool operator==(const Array& other) const;

};

#include "array.tpp"