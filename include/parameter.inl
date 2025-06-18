#ifndef PARAMETER_INL
#define PARAMETER_INL

// ----------- Parameter Implementation -----------

template<typename T>
Parameter::Parameter(const T& value) {
    holder = std::make_unique<ValueHolder<T>>(value);
}

template<typename T>
T Parameter::getValueAs() const {
    auto* derived = dynamic_cast<ValueHolder<T>*>(holder.get());
    if (!derived)
        throw std::runtime_error("Type mismatch in getValueAs");
    return derived->getValue();
}

template<typename T>
T Parameter::getSafeValueAs() const {
    if (std::type_index(typeid(T)) != holder->getTypeIndex())
        return T{};
    return getValueAs<T>();
}


// ----------- ValueHolder Implementation -----------

template <typename Type>
Parameter::ValueHolder<Type>::ValueHolder(const Type& value)
    : TypeHolder(typeid(Type)), value(value) {
}

template <typename T>
Parameter::ValueHolder<T>::ValueHolder(const ValueHolder<T>& other)
    : TypeHolder(other), value(other.value) {
}

template <typename T>
Parameter::ValueHolder<T>::ValueHolder(ValueHolder<T>&& other) noexcept
    : TypeHolder(other), value(std::move(other.value)) {
}

template <typename T>
std::unique_ptr<Parameter::TypeHolder> Parameter::ValueHolder<T>::clone() const {
    return std::make_unique<ValueHolder<T>>(*this);
}

template <typename T>
T Parameter::ValueHolder<T>::getValue() const {
    return value;
}

#endif // PARAMETER_INL
