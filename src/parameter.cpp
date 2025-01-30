#include "parameter.hpp"

Parameter::Parameter(const Parameter& value) {
    size = value.size;
    isArray = value.isArray;

    if (!value.ptr) {
        ptr = nullptr;
        return;
    }

    if (isArray) {
        ptr = operator new(size);
        std::memcpy(ptr, value.ptr, size);
    } else {
        ptr = new int8_t[size];
        std::memcpy(ptr, value.ptr, size);
    }
}

Parameter::~Parameter() {
    if (ptr) {
        if (isArray) {
            delete[] static_cast<int8_t*>(ptr);
        } else {
            delete static_cast<int8_t*>(ptr);
        }
    }
}