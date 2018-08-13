#pragma once

#include <array>

namespace frw
{
template <typename T, size_t N>
class Vector;

/// Common type aliases
using Vector2f = Vector<float, 2>;
using Vector3f = Vector<float, 3>;
using Vector4f = Vector<float, 4>;
using Vector2d = Vector<double, 2>;
using Vector3d = Vector<double, 3>;
using Vector4d = Vector<double, 4>;

template <typename T, size_t N>
class BaseVector
{
public:
    constexpr BaseVector() = default;
    constexpr BaseVector(std::array<T, N> vals) : data_(vals) {}

    // TODO: Too greedy for common use; may offer as make_vector for higher order Vectors
    // template <typename... Args>
    // BaseVector(Args&&... args)
    //    : data_({ std::forward<Args>(args)... })
    //{}

    constexpr BaseVector(const BaseVector<T, N>&) = default;
    constexpr BaseVector(BaseVector<T, N>&&) = default;
    constexpr BaseVector<T, N>& operator=(const BaseVector<T, N>&) = default;
    constexpr BaseVector<T, N>& operator=(BaseVector<T, N>&&) = default;
    ~BaseVector() = default;

    constexpr BaseVector<T, N> operator+(const BaseVector<T, N>& v) const
    {
        BaseVector<T, N> result;
        for (size_t i = 0; i < N; ++i) result.data_[i] = this->data_[i] + v.data_[i];
        return result;
    }

    constexpr BaseVector<T, N>& operator+=(const BaseVector<T, N>& v)
    {
        for (size_t i = 0; i < N; ++i) this->data_[i] += v.data_[i];
        return *this;
    }

    constexpr BaseVector<T, N> operator-(const BaseVector<T, N>& v) const
    {
        BaseVector<T, N> result;
        for (size_t i = 0; i < N; ++i) result.data_[i] = this->data_[i] - v.data_[i];
        return result;
    }

    constexpr BaseVector<T, N>& operator-=(const BaseVector<T, N>& v)
    {
        for (size_t i = 0; i < N; ++i) this->data_[i] -= v.data_[i];
        return *this;
    }

    constexpr BaseVector<T, N> operator*(const T& t) const
    {
        BaseVector<T, N> result = *this;
        for (T& val : result.data_) val *= t;
        return result;
    }

    constexpr BaseVector<T, N>& operator*=(const T& t)
    {
        for (T& val : data_) val *= t;
        return *this;
    }

    constexpr T Dot(const BaseVector<T, N>& v) const
    {
        T result = {};
        for (size_t i = 0; i < N; ++i) result += this->data_[i] * v.data_[i];
        return result;
    }

    constexpr BaseVector<T, N> Project(const BaseVector<T, N>& direction, bool direction_normalized = false)
    {
        BaseVector<T, N> normalized_direction = direction_normalized ? direction : Normal(direction);
        return normalized_direction * Dot(normalized_direction);
    }

    constexpr void Normalize() { *this *= 1 / Length(); }

    constexpr void Normalize(T length) { *this *= 1 / length; }

    constexpr T Magnitude() const { return Length(); }

    constexpr T Length() const
    {
        return sqrt(LengthSquared());  // TODO: Can you determine T to pick which sqrt? Do you need to?
    }

    constexpr T LengthSquared() const
    {
        T result = {};
        for (size_t i = 0; i < N; ++i) result += this->data_[i] * this->data_[i];
        return result;
    }

    constexpr const std::array<T, N>& Data() const { return data_; }

protected:
    std::array<T, N> data_ = {};
};

template <typename T, size_t N>
class Vector : public BaseVector<T, N>
{
public:
    using BaseVector<T, N>::BaseVector;
    using BaseVector<T, N>::operator+;
    using BaseVector<T, N>::operator+=;
    using BaseVector<T, N>::operator-;
    using BaseVector<T, N>::operator-=;
    using BaseVector<T, N>::operator*;
    using BaseVector<T, N>::operator*=;
    using BaseVector<T, N>::Dot;
    using BaseVector<T, N>::Project;
    using BaseVector<T, N>::Normalize;
    using BaseVector<T, N>::Magnitude;
    using BaseVector<T, N>::Length;
    using BaseVector<T, N>::LengthSquared;
    using BaseVector<T, N>::Data;

    Vector() = default;
    Vector(BaseVector<T, N> v) : BaseVector<T, N>(v) {}
};

template <typename T>
class Vector<T, 2> : public BaseVector<T, 2>
{
    static constexpr size_t N = 2;

public:
    using BaseVector<T, N>::BaseVector;
    using BaseVector<T, N>::operator+;
    using BaseVector<T, N>::operator+=;
    using BaseVector<T, N>::operator-;
    using BaseVector<T, N>::operator-=;
    using BaseVector<T, N>::operator*;
    using BaseVector<T, N>::operator*=;
    using BaseVector<T, N>::Dot;
    using BaseVector<T, N>::Project;
    using BaseVector<T, N>::Normalize;
    using BaseVector<T, N>::Magnitude;
    using BaseVector<T, N>::Length;
    using BaseVector<T, N>::LengthSquared;
    using BaseVector<T, N>::Data;

    Vector() = default;
    Vector(BaseVector<T, N> v) : BaseVector<T, N>(v) {}
    Vector(const T& x, const T& y) : BaseVector<T, N>({x, y}) {}
    Vector(T&& x, T&& y) : BaseVector<T, N>({x, y}) {}

    constexpr T& X() { return this->data_[0]; }
    constexpr T& Y() { return this->data_[1]; }
    constexpr const T& X() const { return this->data_[0]; }
    constexpr const T& Y() const { return this->data_[1]; }
};

template <typename T>
class Vector<T, 3> : public BaseVector<T, 3>
{
    static constexpr size_t N = 3;

public:
    using BaseVector<T, N>::BaseVector;
    using BaseVector<T, N>::operator+;
    using BaseVector<T, N>::operator+=;
    using BaseVector<T, N>::operator-;
    using BaseVector<T, N>::operator-=;
    using BaseVector<T, N>::operator*;
    using BaseVector<T, N>::operator*=;
    using BaseVector<T, N>::Dot;
    using BaseVector<T, N>::Project;
    using BaseVector<T, N>::Normalize;
    using BaseVector<T, N>::Magnitude;
    using BaseVector<T, N>::Length;
    using BaseVector<T, N>::LengthSquared;
    using BaseVector<T, N>::Data;

    Vector() = default;
    Vector(BaseVector<T, N> v) : BaseVector<T, N>(v) {}
    Vector(const T& x, const T& y, const T& z) : BaseVector<T, N>({x, y, z}) {}
    Vector(T&& x, T&& y, T&& z) : BaseVector<T, N>({x, y, z}) {}

    constexpr T& X() { return this->data_[0]; }
    constexpr T& Y() { return this->data_[1]; }
    constexpr T& Z() { return this->data_[2]; }
    constexpr const T& X() const { return this->data_[0]; }
    constexpr const T& Y() const { return this->data_[1]; }
    constexpr const T& Z() const { return this->data_[2]; }

    constexpr Vector<T, 3> Cross(const Vector<T, 3>& v) const
    {
        return Vector<T, 3>{{(this->data_[1] * v.data_[2] - this->data_[2] * v.data_[1]),
                             (this->data_[2] * v.data_[0] - this->data_[0] * v.data_[2]),
                             (this->data_[0] * v.data_[1] - this->data_[1] * v.data_[0])}};
    }
};

template <typename T>
class Vector<T, 4> : public BaseVector<T, 4>
{
    static constexpr size_t N = 4;

public:
    using BaseVector<T, N>::BaseVector;
    using BaseVector<T, N>::operator+;
    using BaseVector<T, N>::operator+=;
    using BaseVector<T, N>::operator-;
    using BaseVector<T, N>::operator-=;
    using BaseVector<T, N>::operator*;
    using BaseVector<T, N>::operator*=;
    using BaseVector<T, N>::Dot;
    using BaseVector<T, N>::Project;
    using BaseVector<T, N>::Normalize;
    using BaseVector<T, N>::Magnitude;
    using BaseVector<T, N>::Length;
    using BaseVector<T, N>::LengthSquared;
    using BaseVector<T, N>::Data;

    Vector() = default;
    Vector(BaseVector<T, N> v) : BaseVector<T, N>(v) {}
    Vector(const T& x, const T& y, const T& z, const T& w) : BaseVector<T, N>({x, y, z, w}) {}
    Vector(T&& x, T&& y, T&& z, T&& w) : BaseVector<T, N>({x, y, z, w}) {}
    Vector(const BaseVector<T, 3>& v, const T& w) : BaseVector<T, N>({v.X(), v.Y(), v.Z(), w}) {}
    Vector(BaseVector<T, 3>&& v, T&& w) : BaseVector<T, N>({v.X(), v.Y(), v.Z(), w}) {}

    constexpr explicit operator Vector<T, 3>() const { return Vector<T, 3>(data_[0], this->data_[1], this->data_[2]); }

    constexpr T& X() { return this->data_[0]; }
    constexpr T& Y() { return this->data_[1]; }
    constexpr T& Z() { return this->data_[2]; }
    constexpr T& W() { return this->data_[3]; }
    constexpr const T& X() const { return this->data_[0]; }
    constexpr const T& Y() const { return this->data_[1]; }
    constexpr const T& Z() const { return this->data_[2]; }
    constexpr const T& W() const { return this->data_[3]; }
};

template <typename T, size_t N>
constexpr bool operator==(const Vector<T, N>& l, const Vector<T, N>& r)
{
    for (size_t i = 0; i < N; ++i)
    {
        if (l.Data()[i] != r.Data()[i]) return false;
    }
    return true;
}

template <typename T, size_t N>
constexpr bool operator!=(const Vector<T, N>& l, const Vector<T, N>& r)
{
    return !(l == r);
}

template <typename T, size_t N>
constexpr T Dot(const Vector<T, N>& l, const Vector<T, N>& r)
{
    return l.Dot(r);
}

template <typename T>
constexpr Vector<T, 3> Cross(const Vector<T, 3>& l, const Vector<T, 3>& r)
{
    return l.Cross(r);
}

template <typename T, size_t N>
constexpr Vector<T, N> Project(const Vector<T, N>& v, const Vector<T, N>& direction, bool direction_normalized = false)
{
    return v.Project(direction, direction_normalized);
}

template <typename T, size_t N>
constexpr BaseVector<T, N> Normal(const BaseVector<T, N>& v)
{
    BaseVector<T, N> result(v);
    result.Normalize();
    return result;
}

template <typename T, size_t N>
constexpr BaseVector<T, N> Normal(const BaseVector<T, N>& v, T length)
{
    BaseVector<T, N> result(v);
    result.Normalize(length);
    return result;
}

template <typename T, size_t N>
constexpr T Length(const Vector<T, N>& v)
{
    return v.Length();
}

template <typename T, size_t N>
constexpr T LengthSquared(const Vector<T, N>& v)
{
    return v.LengthSquared();
}
}