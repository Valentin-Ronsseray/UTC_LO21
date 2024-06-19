#if !defined(_Container_T_H)
#define _Container_T_H

#include <string>
#include <stdexcept>

namespace TD {

    template <class T>
    class Container // <Abstract>
    {
    protected:
        size_t nbElts;
    public:
        size_t size() const { return nbElts; }
        bool empty() const { return nbElts == 0; }
        virtual T& element(size_t i) = 0;
        virtual const T& element(size_t i) const = 0;
        virtual T& front();
        virtual const T& front() const {if (!empty()) return element(0);};
        virtual T& back() {if (!empty()) return element(nbElts - 1);};
        virtual const T& back() const {if (!empty()) return element(nbElts - 1);};
        virtual void push_back(const T& x) = 0;
        virtual void pop_back() = 0;
        virtual void clear() {while (!empty()) pop_back(); };
        Container(size_t n) : nbElts(n) {}
        virtual ~Container() {}
    };

    template <class T>
    T& Container<T>::front() {
        if (!empty()) throw return element(0);
        throw ContainerException("Container is empty");
    }

    class ContainerException : public std::exception {
    protected:
        std::string info;
    public:
        ContainerException(const std::string& i = "") noexcept : info(i) {}
        const char* what() const noexcept { return info.c_str(); }
        ~ContainerException() noexcept {}
    };

}

#endif