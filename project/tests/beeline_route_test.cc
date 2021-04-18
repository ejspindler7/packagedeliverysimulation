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

    //point 1 should be src 
    //point 2 should be src with baseline height in the y position
    //point 3 should be dest with baseline height in the y pos
    Vector3D vec_src = Vector3D(src);
    Vector3D vec_dest = Vector3D(dest);

    //ensure point1 gets set correctly 
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_src.GetX())
      << "point 1 x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), vec_src.GetY())
      << "point 1 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_src.GetZ())
      << "point 1 z position incorrectly set";

    //ensure point2 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_src.GetX())
      << "point 2 x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), 5.5)
      << "point 2 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_src.GetZ())
      << "point 2 z position incorrectly set";

    //ensure point3 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_dest.GetX())
      << "point 3 x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), 5.5)
      << "point 3 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_dest.GetZ())
      << "point 3 z position incorrectly set";

    //ensure point4 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_dest.GetX())
      << "dest x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), vec_dest.GetY())
      << "dest y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_dest.GetZ())
      << "dest z position incorrectly set";

    route.pop();
    //ensure route is now empty
    EXPECT_EQ(route.size(), 0)
      << "route incorrect length";

  }

}  // namespace csci3081
