#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <memory>
#include <typeindex>
#include <stdexcept>
#include <string>

class Parameter {
private:
    //Base class to save type info.
	//Useful for inheritance and polymorphism.
    struct TypeHolder {
        std::type_index typeIndex;

        
        TypeHolder() = delete;  //No reason to create a TypeHolder with no type.
        template<typename Type>
        TypeHolder() : typeIndex(typeid(Type)) {}
        TypeHolder(std::type_index typeIndex);
        TypeHolder(const TypeHolder& value);
        TypeHolder(TypeHolder&& value) noexcept;
        virtual ~TypeHolder();

        virtual std::unique_ptr<TypeHolder> clone() const = 0;
        std::type_index getTypeIndex() const;
    };

	//TypeHolder child for holding values.
    template <typename Type>
    class ValueHolder : public TypeHolder {
        Type value;

    public:
        ValueHolder(const Type& value);
        ValueHolder(const ValueHolder<Type>& value);
        ValueHolder(ValueHolder<Type>&& value) noexcept;
        ~ValueHolder() = default;

        std::unique_ptr<TypeHolder> clone() const override;

        Type getValue() const;
    };

    std::unique_ptr<TypeHolder> holder;

public:
    Parameter() = delete;

    template<typename T>
    Parameter(const T& value);

    Parameter(const Parameter& value);
    Parameter(Parameter&& value) noexcept;
    ~Parameter();

    Parameter& operator=(const Parameter& other);
    Parameter& operator=(Parameter&& other) noexcept;

    template<typename T>
    T getValueAs() const;

    template<typename T>
    T getSafeValueAs() const;
};

#include "parameter.inl"

#endif // PARAMETER_HPP
