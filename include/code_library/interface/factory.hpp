// Reference: http://www.nirfriedman.com/2018/04/29/unforgettable-factory/
#pragma once

#include <memory>
#include <string>
#include <unordered_map>

template <typename Base, typename... Args>
class Factory
{
private:
    class Key
    {
        Key() = default;

        template <typename T>
        friend struct Registrar;
    };

public:
    template <typename T>
    struct Registrar : public Base
    {
        friend T;

        static bool registerT()
        {
            const auto name = demangle(typeid(T).name());
            Factory::data()[name] = [](Args... args) -> std::unique_ptr<Base>
            {
                return std::make_unique<T>(std::forward<Args>(args)...);
            };
            return true;
        }
        static bool registered;

    private:
        Registrar() : Base(Key{}) { (void)registered; }
    };

    template <typename... T>
    static std::unique_ptr<Base> make(const std::string& s, T&&... args)
    {
        return data().at(s)(std::forward<T>(args)...);
    }

    friend Base;

private:
    using FuncType = std::unique_ptr<Base>(*)(Args...);
    Factory() = default;

    static auto& data()
    {
        static std::unordered_map<std::string, FuncType> s;
        return s;
    }
};

template <typename Base, typename... Args>
template <typename T>
bool Factory<Base, Args...>::Registrar<T>::registered = Factory<Base, Args...>::Registrar<T>::registerT();