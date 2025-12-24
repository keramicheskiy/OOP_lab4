#include "array.h"
#include <cstddef>
#include <string>
#include <initializer_list>
#include <math.h>
#include <fmt/core.h>
#include "pair.h"
#include <memory>
using namespace std;

template <typename T>
Array<T>::Array(const size_t & size, const T& value) : size(size), capacity(size), data(std::make_unique<T[]>(size)) {
    for (int i = 0; i < size; i++)
        data[i] = value;
}

template <typename T>
Array<T>::Array(const std::initializer_list<T> &list) : size(list.size()), capacity(size), data(std::make_unique<T[]>(size)) {
    int i = 0;
    for (const auto& element : list)
        data[i++] = element;
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size), capacity(other.capacity), data(std::make_unique<T[]>(size)) {
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
size_t Array<T>::getCapacity() const {
    return capacity;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size)
        throw out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size)
        throw out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

template <typename T>
void Array<T>::push(const T& element) {
    if (size == capacity) {
        size_t newCap = capacity ? capacity * 2 : 1;
        auto newData = std::make_unique<T[]>(newCap);
        for (int i = 0; i < size; i++)
            newData[i] = std::move(data[i]);
        data = std::move(newData);
        capacity = newCap;
    }
    data[size++] = element;
}

template <typename T>
T Array<T>::pop() {
    if (size == 0) throw out_of_range("Pop is forbidden for empty arrays.");

    T value = std::move(data[--size]);
    return value;
}

template <typename T>
void Array<T>::remove(size_t index) {
    if (index >= size) return;
    for (size_t i = index; i + 1 < size; ++i)
        data[i] = std::move(data[i + 1]);
    size--;
}

template <typename T>
void Array<T>::clear() {
    data.reset();
    size = 0;
    capacity = 0;
}

template <typename T>
void Array<T>::set(size_t index, const T& element) {
    if (index >= size)
        throw out_of_range(fmt::format("Index out of range: {}", index));
    data[index] = element;
}

template <typename T>
void Array<T>::resize(size_t newSize) {
    auto newData = std::make_unique<T[]>(newSize);
    for (int i = 0; i < std::min(size, newSize); i++)
        newData[i] = std::move(data[i]);
    data = std::move(newData);
    size = std::min(newSize, size);
    capacity = newSize;
}

template <typename T>
bool Array<T>::contains(const T& element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) return true;
    }
    return false;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) return *this;

    auto newData = std::make_unique<T[]>(other.capacity);
    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[i];
    data = std::move(newData);
    size = other.size;
    capacity = other.capacity;

    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this == &other) return *this;

    data = std::move(other.data);
    size = other.size;
    capacity = other.capacity;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array& other) const {
    if (size != other.size) return false;

    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}
