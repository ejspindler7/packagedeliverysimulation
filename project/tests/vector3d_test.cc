#include "gtest/gtest.h"
#include "../include/vector_3d.h"

namespace csci3081 {

  class Vector3DTest : public ::testing::Test {
    public: 
      void SetUp() {
        v_0_0_0 = Vector3D(); 
        v_1_0_0 = Vector3D(1.0);
        v_1_1_0 = Vector3D(1.0, 1.0);
        v_1_1_1 = Vector3D(1.0, 1.0, 1.0);
        v_1_2_3 = Vector3D(std::vector<float> {1.0, 2.0, 3.0});
        v_mixed = Vector3D(10.0, 11.1, 12.2);
        unsupported_len_init_0 = Vector3D(std::vector<float> (0));
        unsupported_len_init_2 = Vector3D(std::vector<float> {1.0, 2.0});
        unsupported_len_init_4 = Vector3D(std::vector<float> {1.0, 2.0, 3.0, 4.0});
      } // SetUp()

    protected:
      Vector3D v_0_0_0;
      Vector3D v_1_0_0;
      Vector3D v_1_1_0;
      Vector3D v_1_1_1;
      Vector3D v_1_2_3;
      Vector3D v_mixed;
      Vector3D unsupported_len_init_0;
      Vector3D unsupported_len_init_2;
      Vector3D unsupported_len_init_4;
  }; // Vector3DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(Vector3DTest, ConstructorTests) {
    EXPECT_FLOAT_EQ(v_0_0_0.GetX(), 0.0) << "v_0_0_0 - incorrect x initialization";
    EXPECT_FLOAT_EQ(v_0_0_0.GetY(), 0.0) << "v_0_0_0 - incorrect y initialization";
    EXPECT_FLOAT_EQ(v_0_0_0.GetZ(), 0.0) << "v_0_0_0 - incorrect z initialization";

    EXPECT_FLOAT_EQ(v_1_0_0.GetX(), 1.0) << "v_1_0_0 - incorrect x initialization";
    EXPECT_FLOAT_EQ(v_1_0_0.GetY(), 0.0) << "v_1_0_0 - incorrect y initialization";
    EXPECT_FLOAT_EQ(v_1_0_0.GetZ(), 0.0) << "v_1_0_0 - incorrect z initialization";

    EXPECT_FLOAT_EQ(v_1_1_0.GetX(), 1.0) << "v_1_1_0 - incorrect x initialization";
    EXPECT_FLOAT_EQ(v_1_1_0.GetY(), 1.0) << "v_1_1_0 - incorrect y initialization";
    EXPECT_FLOAT_EQ(v_1_1_0.GetZ(), 0.0) << "v_1_1_0 - incorrect z initialization";

    EXPECT_FLOAT_EQ(v_1_1_1.GetX(), 1.0) << "v_1_1_1 - incorrect x initialization";
    EXPECT_FLOAT_EQ(v_1_1_1.GetY(), 1.0) << "v_1_1_1 - incorrect y initialization";
    EXPECT_FLOAT_EQ(v_1_1_1.GetZ(), 1.0) << "v_1_1_1 - incorrect z initialization";

    EXPECT_FLOAT_EQ(v_1_2_3.GetX(), 1.0) << "v_1_2_3 - incorrect x initialization";
    EXPECT_FLOAT_EQ(v_1_2_3.GetY(), 2.0) << "v_1_2_3 - incorrect y initialization";
    EXPECT_FLOAT_EQ(v_1_2_3.GetZ(), 3.0) << "v_1_2_3 - incorrect z initialization";

    EXPECT_FLOAT_EQ(unsupported_len_init_0.GetX(), 0.0) 
      << "unsupported_len_init_0 - incorrect x initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_0.GetY(), 0.0) 
      << "unsupported_len_init_0 - incorrect y initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_0.GetZ(), 0.0) 
      << "unsupported_len_init_0 - incorrect z initialization";

    EXPECT_FLOAT_EQ(unsupported_len_init_2.GetX(), 0.0) 
      << "unsupported_len_init_2 - incorrect x initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_2.GetY(), 0.0) 
      << "unsupported_len_init_2 - incorrect y initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_2.GetZ(), 0.0) 
      << "unsupported_len_init_2 - incorrect z initialization";

    EXPECT_FLOAT_EQ(unsupported_len_init_4.GetX(), 0.0) 
      << "unsupported_len_init_4 - incorrect x initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_4.GetY(), 0.0) 
      << "unsupported_len_init_4 - incorrect y initialization";
    EXPECT_FLOAT_EQ(unsupported_len_init_4.GetZ(), 0.0) 
      << "unsupported_len_init_4 - incorrect z initialization";
  } // ConstructorTests

  TEST_F(Vector3DTest, SetComponentsTest) {
    v_0_0_0.SetComponents(std::vector<float>{1,2,3});
    EXPECT_FLOAT_EQ(v_0_0_0.GetX(), 1.0) << "v_0_0_0 - incorrect x set";
    EXPECT_FLOAT_EQ(v_0_0_0.GetY(), 2.0) << "v_0_0_0 - incorrect y set";
    EXPECT_FLOAT_EQ(v_0_0_0.GetZ(), 3.0) << "v_0_0_0 - incorrect z set";

    v_1_2_3.SetComponents(std::vector<float>{1,2,3,4}); // should have no effect
    EXPECT_FLOAT_EQ(v_1_2_3.GetX(), 1.0) << "v_1_2_3 - incorrect x set";
    EXPECT_FLOAT_EQ(v_1_2_3.GetY(), 2.0) << "v_1_2_3 - incorrect y set";
    EXPECT_FLOAT_EQ(v_1_2_3.GetZ(), 3.0) << "v_1_2_3 - incorrect z set";
  }   

  TEST_F(Vector3DTest, NormalizeTest) {
    v_1_0_0.Normalize(); // already unit length
    EXPECT_FLOAT_EQ(v_1_0_0.GetX(), 1.0) << "v_1_0_0 - x incorrect normalization";
    EXPECT_FLOAT_EQ(v_1_0_0.GetY(), 0.0) << "v_1_0_0 - y incorrect normalization";
    EXPECT_FLOAT_EQ(v_1_0_0.GetZ(), 0.0) << "v_1_0_0 - z incorrect normalization";

    v_1_1_1.Normalize(); 
    EXPECT_FLOAT_EQ(v_1_1_1.GetX(), 0.57735026919) << "v_1_1_1 - x incorrect normalization";
    EXPECT_FLOAT_EQ(v_1_1_1.GetY(), 0.57735026919) << "v_1_1_1 - y incorrect normalization";
    EXPECT_FLOAT_EQ(v_1_1_1.GetZ(), 0.57735026919) << "v_1_1_1 - z incorrect normalization";
  }  

  TEST_F(Vector3DTest, ScaleTest) {
    v_1_1_1.Scale(2); 
    EXPECT_FLOAT_EQ(v_1_1_1.GetX(), 2.0) << "v_1_1_1 - x incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_1_1.GetY(), 2.0) << "v_1_1_1 - y incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_1_1.GetZ(), 2.0) << "v_1_1_1 - z incorrect scaling";

    v_1_0_0.Scale(-1); 
    EXPECT_FLOAT_EQ(v_1_0_0.GetX(), -1.0) << "v_1_0_0 - x incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_0_0.GetY(), 0.0)  << "v_1_0_0 - y incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_0_0.GetZ(), 0.0)  << "v_1_0_0 - z incorrect scaling";
  }

  TEST_F(Vector3DTest, ReverseDirectionTest) {
    v_1_1_1.ReverseDirection(); 
    EXPECT_FLOAT_EQ(v_1_1_1.GetX(), -1.0) << "v_1_1_1 - x incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_1_1.GetY(), -1.0) << "v_1_1_1 - y incorrect scaling";
    EXPECT_FLOAT_EQ(v_1_1_1.GetZ(), -1.0) << "v_1_1_1 - z incorrect scaling";

    v_1_0_0.ReverseDirection(); 
    EXPECT_FLOAT_EQ(v_1_0_0.GetX(), -1.0) << "v_1_0_0 - x incorrect reverse";
    EXPECT_FLOAT_EQ(v_1_0_0.GetY(), 0.0)  << "v_1_0_0 - y incorrect reverse";
    EXPECT_FLOAT_EQ(v_1_0_0.GetZ(), 0.0)  << "v_1_0_0 - z incorrect reverse";
  }

  TEST_F(Vector3DTest, DotProductTest) {
    float res = v_1_1_1.DotProduct(v_1_0_0); 
    EXPECT_FLOAT_EQ(res, 1.0) << "v_1_1_1 v_1_0_0- incorrect dotproduct";

    res = v_1_2_3.DotProduct(v_mixed); 
    EXPECT_FLOAT_EQ(res, 68.8) << "v_1_2_3 v_mixed- incorrect dotproduct";
  }

  TEST_F(Vector3DTest, CrossProductTest) {
    Vector3D res = v_1_1_1.CrossProduct(v_1_1_0); 
    EXPECT_FLOAT_EQ(res.GetX(), -1.0) << "v_1_1_1 v_1_1_0 - x incorrect Cross product";
    EXPECT_FLOAT_EQ(res.GetY(), 1.0)  << "v_1_1_1 v_1_1_0 - y incorrect Cross product";
    EXPECT_FLOAT_EQ(res.GetZ(), 0.0)  << "v_1_1_1 v_1_1_0 - z incorrect Cross product";

    Vector3D res2 = v_1_2_3.CrossProduct(v_mixed); 
    EXPECT_FLOAT_EQ(res2.GetX(), -8.9)  << "v_1_2_3 v_mixed - x incorrect Cross product";
    EXPECT_FLOAT_EQ(res2.GetY(), 17.8)  << "v_1_2_3 v_mixed - y incorrect Cross product";
    EXPECT_FLOAT_EQ(res2.GetZ(), -8.9)  << "v_1_2_3 v_mixed - z incorrect Cross product";
  }

  TEST_F(Vector3DTest, AdditionOperatorTest) {
    Vector3D res = v_1_1_1 + v_1_1_0; 
    EXPECT_FLOAT_EQ(res.GetX(), 2.0) << "v_1_1_1 v_1_1_0 - x incorrect sum";
    EXPECT_FLOAT_EQ(res.GetY(), 2.0)  << "v_1_1_1 v_1_1_0 - y incorrect sum";
    EXPECT_FLOAT_EQ(res.GetZ(), 1.0)  << "v_1_1_1 v_1_1_0 - z incorrect sum";

    Vector3D res2 = v_1_2_3 + v_mixed; 
    EXPECT_FLOAT_EQ(res2.GetX(), 11.0)  << "v_1_2_3 v_mixed - x incorrect sum";
    EXPECT_FLOAT_EQ(res2.GetY(), 13.1)  << "v_1_2_3 v_mixed - y incorrect sum";
    EXPECT_FLOAT_EQ(res2.GetZ(), 15.2)  << "v_1_2_3 v_mixed - z incorrect sum";
  }

  TEST_F(Vector3DTest, SubtractionOperatorTest) {
    Vector3D res = v_1_1_1 - v_1_1_0; 
    EXPECT_FLOAT_EQ(res.GetX(), 0.0) << "v_1_1_1 v_1_1_0 - x incorrect subtraction";
    EXPECT_FLOAT_EQ(res.GetY(), 0.0)  << "v_1_1_1 v_1_1_0 - y incorrect subtraction";
    EXPECT_FLOAT_EQ(res.GetZ(), 1.0)  << "v_1_1_1 v_1_1_0 - z incorrect subtraction";

    Vector3D res2 = v_1_2_3 - v_mixed; 
    EXPECT_FLOAT_EQ(res2.GetX(), -9.0)  << "v_1_2_3 v_mixed - x incorrect subtraction";
    EXPECT_FLOAT_EQ(res2.GetY(), -9.1)  << "v_1_2_3 v_mixed - y incorrect subtraction";
    EXPECT_FLOAT_EQ(res2.GetZ(), -9.2)  << "v_1_2_3 v_mixed - z incorrect subtraction";
  }

  TEST_F(Vector3DTest, EqualityOperatorTest) {
    bool res = v_1_1_1 == v_1_1_1; 
    EXPECT_EQ(res, true) << "v_1_1_1 v_1_1_1 - incorrect equality check";

    res = v_1_1_1 == v_1_1_0; 
    EXPECT_EQ(res, false) << "v_1_1_1 v_1_1_0 - incorrect equality check";

    res = v_1_1_1 == v_1_0_0; 
    EXPECT_EQ(res, false) << "v_1_1_1 v_1_0_0 - incorrect equality check";

    res = v_1_2_3 == v_mixed; 
    EXPECT_EQ(res, false) << "v_1_2_3 v_mixed - incorrect equality check";
  }
}  // namespace csci3081
