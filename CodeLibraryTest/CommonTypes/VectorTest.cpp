#include "CommonTypes/Vector.hpp"

#include <gtest/gtest.h>

using namespace balance;

TEST(VectorConstructionTest, DefaultConstruction)
{
    Vector3f v;
    ASSERT_FLOAT_EQ(v.X(), 0.0f);
    ASSERT_FLOAT_EQ(v.Y(), 0.0f);
    ASSERT_FLOAT_EQ(v.Z(), 0.0f);
}

TEST(VectorConstructionTest, AggregateConstruction)
{
    float x = 4.2f;
    float y = 1.9f;
    float z = -2.1f;

    auto AssertVectorEqualsXYZ = [&x, &y, &z](Vector3f& vec)
    {
        ASSERT_FLOAT_EQ(vec.X(), x);
        ASSERT_FLOAT_EQ(vec.Y(), y);
        ASSERT_FLOAT_EQ(vec.Z(), z);
    };

    Vector3f v{ { x, y, z } };
    // TODO: Syntax not supported with inheritance approach?
    //Vector3f v2({ x, y, z });
    AssertVectorEqualsXYZ(v);
    //AssertVectorEqualsXYZ(v2);

    std::array<float, 3> vals = { x, y, z };
    Vector3f v3 = vals;
    Vector3f v4 = { vals };
    AssertVectorEqualsXYZ(v3);
    AssertVectorEqualsXYZ(v4);
}

TEST(VectorConstructionTest, CopyConstruction)
{
    float x = 6.2f;
    float y = 10.2f;
    float z = 1.21f;

    auto AssertVectorEqualsXYZ = [&x, &y, &z](Vector3f& vec)
    {
        ASSERT_FLOAT_EQ(vec.X(), x);
        ASSERT_FLOAT_EQ(vec.Y(), y);
        ASSERT_FLOAT_EQ(vec.Z(), z);
    };

    Vector3f v = { { x, y, z } };
    Vector3f v2 = v;
    Vector3f v3(v);
    AssertVectorEqualsXYZ(v);
    AssertVectorEqualsXYZ(v2);
    AssertVectorEqualsXYZ(v3);
}

TEST(VectorConstructionTest, MoveConstruction)
{
    float x = 23.5f;
    float y = -124.53f;
    float z = 12.35f;

    auto AssertVectorEqualsXYZ = [&x, &y, &z](Vector3f& vec)
    {
        ASSERT_FLOAT_EQ(vec.X(), x);
        ASSERT_FLOAT_EQ(vec.Y(), y);
        ASSERT_FLOAT_EQ(vec.Z(), z);
    };

    Vector3f v = { { x, y, z } };
    AssertVectorEqualsXYZ(v);

    Vector3f v2 = std::move(v);
    AssertVectorEqualsXYZ(v2);

    Vector3f v3(Vector3f{ { x, y, z } });
    AssertVectorEqualsXYZ(v3);
}


TEST(VectorOperatorTest, Equality)
{
    float x = 12.532f;
    float y = 932.25f;
    float z = 12521.2f;
    float x2 = -125.325f;
    float y2 = 312.125f;
    float z2 = 326.12f;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    Vector3f v3 = { { x, y, z } };
    ASSERT_EQ(v, v);
    ASSERT_NE(v, v2);
    ASSERT_EQ(v, v3);
}

TEST(VectorOperatorTest, Addition)
{
    float x = 12.532f;
    float y = 932.25f;
    float z = 12521.2f;
    float x2 = -125.325f;
    float y2 = 312.125f;
    float z2 = 326.12f;
    float x3 = x + x2;
    float y3 = y + y2;
    float z3 = z + z2;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    Vector3f v3 = { { x3, y3, z3 } };

    Vector3f v4 = v + v2;
    ASSERT_EQ(v3, v4);
    v += v2;
    ASSERT_EQ(v, v3);
}

TEST(VectorOperatorTest, Subtraction)
{
    float x = 12.532f;
    float y = 932.25f;
    float z = 12521.2f;
    float x2 = -125.325f;
    float y2 = 312.125f;
    float z2 = 326.12f;
    float x3 = x - x2;
    float y3 = y - y2;
    float z3 = z - z2;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    Vector3f v3 = { { x3, y3, z3 } };

    Vector3f v4 = v - v2;
    ASSERT_EQ(v3, v4);
    v -= v2;
    ASSERT_EQ(v, v3);
}

TEST(VectorOperatorTest, Multiplication)
{
    float x = 12.532f;
    float y = 463.214f;
    float z = 1215.632f;
    float t = -12.62f;
    float x2 = x * t;
    float y2 = y * t;
    float z2 = z * t;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    Vector3f v3 = v * t;
    ASSERT_EQ(v2, v3);
    v *= t;
    ASSERT_EQ(v, v2);
}

TEST(VectorFunctionTest, Dot)
{
    float x = 12.532f;
    float y = 932.25f;
    float z = 12521.2f;
    float x2 = -125.325f;
    float y2 = 312.125f;
    float z2 = 326.12f;
    float x3 = x * x2;
    float y3 = y * y2;
    float z3 = z * z2;
    float sum = x3 + y3 + z3;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    float dot = v.Dot(v2);
    float dot2 = v2.Dot(v);
    float dot3 = Dot(v, v2);
    EXPECT_FLOAT_EQ(dot, sum);
    EXPECT_FLOAT_EQ(dot2, sum);
    EXPECT_FLOAT_EQ(dot3, sum);
}

TEST(VectorFunctionTest, Cross)
{
    float x = 12.532f;
    float y = 932.25f;
    float z = 12521.2f;
    float x2 = -125.325f;
    float y2 = 312.125f;
    float z2 = 326.12f;

    Vector3f v = { { x, y, z } };
    Vector3f v2 = { { x2, y2, z2 } };
    Vector3f cross = Cross(v, v2);
    ASSERT_FLOAT_EQ(cross.X(), (y * z2 - z * y2));
    ASSERT_FLOAT_EQ(cross.Y(), (z * x2 - x * z2));
    ASSERT_FLOAT_EQ(cross.Z(), (x * y2 - y * x2));
}

TEST(VectorFunctionTest, Project)
{
    float x = 125.532f;
    float y = 346.23f;
    float z = -12.532f;
    float x2 = -52.12f;
    float y2 = 346.23f;
    float z2 = 63.3f;

    Vector3f v = { {x, y, z} };
    Vector3f v2 = { {x2, y2, z2} };
    Vector3f v3 = v.Project(v2);
    Vector3f v4 = v2 * (v.Dot(v2) / v2.LengthSquared());
    ASSERT_FLOAT_EQ(v3.X(), v4.X());
    ASSERT_FLOAT_EQ(v3.Y(), v4.Y());
    ASSERT_FLOAT_EQ(v3.Z(), v4.Z());
}

TEST(VectorFunctionTest, Normalize)
{
    float x = 325.634f;
    float y = 12.523f;
    float z = 236.23f;

    Vector3f v = { {x, y, z} };
    Vector3f v2(v);
    ASSERT_NE(v.Length(), 1.0f);
    v.Normalize();
    v2.Normalize(v2.Length());
    ASSERT_FLOAT_EQ(v.Length(), 1.0f);
    ASSERT_FLOAT_EQ(v2.Length(), 1.0f);
}

TEST(VectorFunctionTest, Length)
{
    float x = 325.634f;
    float y = 12.523f;
    float z = 236.23f;
    float length_squared = x * x + y * y + z * z;

    Vector3f v = { { x, y, z } };
    ASSERT_FLOAT_EQ(v.LengthSquared(), length_squared);
    ASSERT_FLOAT_EQ(v.Length(), sqrtf(length_squared));
}