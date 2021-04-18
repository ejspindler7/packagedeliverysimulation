#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/beeline_route.h"
#include "picojson_test_objects.h"

namespace csci3081 {

  class BeelineRouteTest : public ::testing::Test {
    public: 
      void SetUp() {
        beeline_obj = BeelineRoute(5.5);
      } // SetUp()

      virtual void TearDown() {}

    protected:
      BeelineRoute beeline_obj;

  }; // BeelineRouteTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(BeelineRouteTest, GetRoute) {
    std::vector<float> src = {1.0,1.0,1.0};
    std::vector<float> dest = {1.0,1.0,1.0};
    std::queue<Vector3D> route = beeline_obj.GetRoute(src, dest);

    Vector3D vec_src = Vector3D(src);
    Vector3D vec_dest = Vector3D(dest);

    //ensure src gets set correctly 
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_src.GetX())
      << "src x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), vec_src.GetY())
      << "src y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_src.GetZ())
      << "src z position incorrectly set";

    //ensure dest gets set correctly 
    EXPECT_FLOAT_EQ(route.back().GetX(), vec_dest.GetX())
      << "dest x position incorrectly set";

    EXPECT_FLOAT_EQ(route.back().GetY(), vec_dest.GetY())
      << "dest y position incorrectly set";

    EXPECT_FLOAT_EQ(route.back().GetZ(), vec_dest.GetZ())
      << "dest z position incorrectly set";

  }

}  // namespace csci3081
