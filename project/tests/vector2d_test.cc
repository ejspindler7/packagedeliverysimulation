#include "gtest/gtest.h"
#include "../include/vector_2d.h"

namespace csci3081 {

  class Vector2DTest : public ::testing::Test {
    public: 
      void SetUp() {
        v_0_0 = Vector2D(); 
        v_1_0 = Vector2D(1.0);
        v_1_1 = Vector2D(1.0, 1.0);
        v_1_2 = Vector2D(std::vector<float> {1.0, 2.0});
        v_1_3 = Vector2D(std::vector<float> {1.0, 2.0, 3.0});
        v_mixed = Vector2D(11.1, 12.2);
        unsupported_len_init_0 = Vector2D(std::vector<float> (0));
        unsupported_len_init_1 = Vector2D(std::vector<float> {1.0});
        unsupported_len_init_4 = Vector2D(std::vector<float> {1.0, 2.0, 3.0, 4.0});
      } // SetUp()

    protected:
      Vector2D v_0_0;
      Vector2D v_1_0;
      Vector2D v_1_1;
      Vector2D v_1_2;
      Vector2D v_1_3;
      Vector2D v_mixed;
      Vector2D unsupported_len_init_0;
      Vector2D unsupported_len_init_1;
      Vector2D unsupported_len_init_4;
  }; // Vector2DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(Vector2DTest, ConstructorTests) {
    EXPECT_EQ(v_0_0.GetX(), 0.0) << "v_0_0 - incorrect x initialization";
    EXPECT_EQ(v_0_0.GetY(), 0.0) << "v_0_0 - incorrect y initialization";
    EXPECT_EQ(v_0_0.GetZ(), 0.0) << "v_0_0 - incorrect z initialization";

    EXPECT_EQ(v_1_0.GetX(), 1.0) << "v_1_0 - incorrect x initialization";
    EXPECT_EQ(v_1_0.GetY(), 0.0) << "v_1_0 - incorrect y initialization";
    EXPECT_EQ(v_1_0.GetZ(), 0.0) << "v_1_0 - incorrect z initialization";

    EXPECT_EQ(v_1_1.GetX(), 1.0) << "v_1_1 - incorrect x initialization";
    EXPECT_EQ(v_1_1.GetY(), 0.0) << "v_1_1 - incorrect y initialization";
    EXPECT_EQ(v_1_1.GetZ(), 1.0) << "v_1_1 - incorrect z initialization";

    EXPECT_EQ(v_1_2.GetX(), 1.0) << "v_1_2 - incorrect x initialization";
    EXPECT_EQ(v_1_2.GetY(), 0.0) << "v_1_2 - incorrect y initialization";
    EXPECT_EQ(v_1_2.GetZ(), 2.0) << "v_1_2 - incorrect z initialization";

    EXPECT_EQ(v_1_3.GetX(), 1.0) << "v_1_3 - incorrect x initialization";
    EXPECT_EQ(v_1_3.GetY(), 0.0) << "v_1_3 - incorrect y initialization";
    EXPECT_EQ(v_1_3.GetZ(), 3.0) << "v_1_3 - incorrect z initialization";

    EXPECT_EQ(unsupported_len_init_0.GetX(), 0.0) 
      << "unsupported_len_init_0 - incorrect x initialization";
    EXPECT_EQ(unsupported_len_init_0.GetY(), 0.0) 
      << "unsupported_len_init_0 - incorrect y initialization";
    EXPECT_EQ(unsupported_len_init_0.GetZ(), 0.0) 
      << "unsupported_len_init_0 - incorrect z initialization";

    EXPECT_EQ(unsupported_len_init_1.GetX(), 0.0) 
      << "unsupported_len_init_2 - incorrect x initialization";
    EXPECT_EQ(unsupported_len_init_1.GetY(), 0.0) 
      << "unsupported_len_init_2 - incorrect y initialization";
    EXPECT_EQ(unsupported_len_init_1.GetZ(), 0.0) 
      << "unsupported_len_init_2 - incorrect z initialization";

    EXPECT_EQ(unsupported_len_init_4.GetX(), 0.0) 
      << "unsupported_len_init_4 - incorrect x initialization";
    EXPECT_EQ(unsupported_len_init_4.GetY(), 0.0) 
      << "unsupported_len_init_4 - incorrect y initialization";
    EXPECT_EQ(unsupported_len_init_4.GetZ(), 0.0) 
      << "unsupported_len_init_4 - incorrect z initialization";
  } // ConstructorTests

  TEST_F(Vector2DTest, SetComponentsTest) {
    v_0_0.SetComponents(1,2);
    EXPECT_FLOAT_EQ(v_0_0.GetX(), 1.0) << "v_0_0 - incorrect x set";
    EXPECT_FLOAT_EQ(v_0_0.GetY(), 0.0) << "v_0_0 - incorrect y set";
    EXPECT_FLOAT_EQ(v_0_0.GetZ(), 2.0) << "v_0_0 - incorrect z set";

    v_mixed.SetComponents(1,2,3);
    EXPECT_FLOAT_EQ(v_mixed.GetX(), 1.0) << "v_mixed - incorrect x set";
    EXPECT_FLOAT_EQ(v_mixed.GetY(), 0.0) << "v_mixed - incorrect y set";
    EXPECT_FLOAT_EQ(v_mixed.GetZ(), 3.0) << "v_mixed - incorrect z set";

    v_1_1.SetComponents(std::vector<float>{2,3,4});
    EXPECT_FLOAT_EQ(v_1_1.GetX(), 2.0) << "v_1_1 - incorrect x set";
    EXPECT_FLOAT_EQ(v_1_1.GetY(), 0.0) << "v_1_1 - incorrect y set";
    EXPECT_FLOAT_EQ(v_1_1.GetZ(), 4.0) << "v_1_1 - incorrect z set";

    v_1_2.SetComponents(std::vector<float>{2,3});
    EXPECT_FLOAT_EQ(v_1_2.GetX(), 2.0) << "v_1_2 - incorrect x set";
    EXPECT_FLOAT_EQ(v_1_2.GetY(), 0.0) << "v_1_2 - incorrect y set";
    EXPECT_FLOAT_EQ(v_1_2.GetZ(), 3.0) << "v_1_2 - incorrect z set";

    v_1_3.SetComponents(std::vector<float>{1,2,3,4});
    EXPECT_FLOAT_EQ(v_1_3.GetX(), 1.0) << "v_1_3 - incorrect x set";
    EXPECT_FLOAT_EQ(v_1_3.GetY(), 0.0) << "v_1_3 - incorrect y set";
    EXPECT_FLOAT_EQ(v_1_3.GetZ(), 3.0) << "v_1_3 - incorrect z set";
  }   
}  // namespace csci3081
