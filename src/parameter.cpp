#include "parameter.hpp"

Parameter::Parameter(const Parameter& value) {
    Destructor();

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

void Parameter::Destructor() {
    if (ptr) {
        if (isArray) {
            delete[] static_cast<int8_t*>(ptr);
        } else {
            delete static_cast<int8_t*>(ptr);
        }
        size = 0;
        isArray = false;
    }
}

Parameter::~Parameter() {
    Destructor();
}
