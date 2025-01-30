#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <cstring>
#include <cstdint>

class Parameter {
    using size_t = unsigned long long;
    private:
        void* ptr;
        size_t size;
        bool isArray;
    public:
        Parameter() : ptr(nullptr), isArray(false) {}

        Parameter(const Parameter& value){
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

        template <typename T>
        Parameter(const T& value) {
            ptr = new T(value);
            size = sizeof(T);
            isArray = false;
        }

        template <typename T, size_t N>
        Parameter(const T (&value)[N]) {
            T* tptr = new T[N];
            size = sizeof(T) * N;
            isArray = true;

            std::memcpy(tptr, value, size);
            ptr = static_cast<void*>(tptr);
        }

        template<typename T>
        T GetValueAs() const {
            return *(static_cast<T*>(ptr));
        }

        template<typename T>
        static T GetValueAs(const Parameter& value){
            return *(static_cast<T*>(value.ptr));
        }

        ~Parameter() {
            if (ptr) {
                if (isArray) {
                    delete[] static_cast<int8_t*>(ptr); // Используем `int8_t*` вместо `char*`
                } else {
                    delete static_cast<int8_t*>(ptr);
                }
            }
        }
};

#endif//PARAMETER_HPP