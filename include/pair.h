#pragma once

template <typename T>
class Pair {
public:
    T first;
    T second;

    Pair() = default;

    Pair(T& first, T& second) : first(first), second(second) {}

    bool operator==(const Pair& other) const {
        return this->first == other.first && this->second == other.second;
    }
};
