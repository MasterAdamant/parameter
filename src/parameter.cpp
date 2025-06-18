#include "../include/parameter.hpp"

Parameter::TypeHolder::TypeHolder(std::type_index typeIndex)
    : typeIndex(typeIndex) {
}

Parameter::TypeHolder::TypeHolder(const TypeHolder& value)
    : typeIndex(value.typeIndex) {
}

Parameter::TypeHolder::TypeHolder(TypeHolder&& value) noexcept
    : typeIndex(std::move(value.typeIndex)) {
}

Parameter::TypeHolder::~TypeHolder() {}

std::type_index Parameter::TypeHolder::getTypeIndex() const {
    return typeIndex;
}

// Copy constructor
Parameter::Parameter(const Parameter& other) {
    if (other.holder)
        holder = other.holder->clone();
}

// Move constructor
Parameter::Parameter(Parameter&& other) noexcept
    : holder(std::move(other.holder)) {
}

// Destructor
Parameter::~Parameter() = default;

// Assignment operators
Parameter& Parameter::operator=(const Parameter& other) {
    if (this != &other) {
        holder = other.holder ? other.holder->clone() : nullptr;
    }
    return *this;
}

Parameter& Parameter::operator=(Parameter&& other) noexcept {
    holder = std::move(other.holder);
    return *this;
}
