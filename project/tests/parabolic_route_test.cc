#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/parabolic_route.h"
#include "picojson_test_objects.h"

namespace csci3081 {

  class ParabolicRouteTest : public ::testing::Test {
    public: 
      void SetUp() {
        //max_height gets set to 400, base_height to 300
        parabolic_obj_1 = ParabolicRoute(1);
        parabolic_obj_2 = ParabolicRoute(1, 200, 300);
      } // SetUp()

      virtual void TearDown() {}

    protected:
        ParabolicRoute parabolic_obj_1;
        ParabolicRoute parabolic_obj_2;

  }; // ParabolicRouteTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(ParabolicRouteTest, GetRoute) {

    //first check parabolic_obj_1 

    std::vector<float> src = {1.0, 1.0, 1.0};
    std::vector<float> dest = {2.0,2.0,2.0};

    std::queue<Vector3D> route = parabolic_obj_1.GetRoute(src, dest);

    //check that the size of the route is 5
    EXPECT_EQ(route.size(), 5)
      << "route is not the correct size for 1 step";

    Vector3D vec_src = Vector3D(src);
    Vector3D vec_dest = Vector3D(dest);

    //point_2 = src with base_height in the y pos
    Vector3D point_2 = Vector3D(src);
    //base_height = 300
    point_2.SetY(300);

    //point_3 = midpoint between src and dest 
    //y component set to max_height 
    Vector3D source(src);
    Vector3D destination(dest);
    Vector3D to_dest = destination - source;
    float dist_dest = to_dest.Magnitude();
    Vector3D mid_point = source + to_dest.Scale(0.5);
    Vector3D point_3 = Vector3D(mid_point);
    point_3.SetY(400);

    //point_4 = dest with base_height in the y pos 
    Vector3D point_4 = Vector3D(dest);
    //base_height = 300
    point_4.SetY(300);

    //ensure src gets set correctly 
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_src.GetX())
      << "src x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.front().GetY(), vec_src.GetY())
      << "src y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_src.GetZ())
      << "src z position incorrectly set";

    //ensure point_2 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_2.GetX())
      << "point 2 x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.front().GetY(), point_2.GetY())
      << "point 2 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_2.GetZ())
      << "point 2 z position incorrectly set";

    
    //ensure point_3 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_3.GetX())
      << "point 3 x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), point_3.GetY())
      << "point 3 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_3.GetZ())
      << "point 3 z position incorrectly set";


    //ensure point_4 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_4.GetX())
      << "point 4 x position incorrectly set";

    //should be max_height
    EXPECT_FLOAT_EQ(route.front().GetY(), point_4.GetY())
      << "point 4 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_4.GetZ())
      << "point 4 z position incorrectly set";
    

    //ensure dest gets set correctly 
    EXPECT_FLOAT_EQ(route.back().GetX(), vec_dest.GetX())
      << "dest x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.back().GetY(), vec_dest.GetY())
      << "dest y position incorrectly set";

    EXPECT_FLOAT_EQ(route.back().GetZ(), vec_dest.GetZ())
      << "dest z position incorrectly set";

    //Now check parabolic_obj_2

    src = {1.1, 1.2, 1.3};
    dest = {2.1,2.2,2.3};

    route = parabolic_obj_2.GetRoute(src, dest);

    //check that the size of the route is 5
    EXPECT_EQ(route.size(), 5)
      << "route is not the correct size for 1 step";

    vec_src = Vector3D(src);
    vec_dest = Vector3D(dest);

    //point_2 = src with base_height in the y pos
    point_2 = Vector3D(src);
    //base_height = 200
    point_2.SetY(200);

    //point_3 = midpoint between src and dest 
    //y component set to max_height 
    source = Vector3D(src);
    destination = Vector3D(dest);
    to_dest = destination - source;
    dist_dest = to_dest.Magnitude();
    mid_point = source + to_dest.Scale(0.5);
    point_3 = Vector3D(mid_point);
    point_3.SetY(300);

    //point_4 = dest with base_height in the y pos 
    point_4 = Vector3D(dest);
    //base_height = 200
    point_4.SetY(200);

    //ensure src gets set correctly 
    EXPECT_FLOAT_EQ(route.front().GetX(), vec_src.GetX())
      << "src x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.front().GetY(), vec_src.GetY())
      << "src y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), vec_src.GetZ())
      << "src z position incorrectly set";

    //ensure point_2 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_2.GetX())
      << "point 2 x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.front().GetY(), point_2.GetY())
      << "point 2 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_2.GetZ())
      << "point 2 z position incorrectly set";

    
    //ensure point_3 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_3.GetX())
      << "point 3 x position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetY(), point_3.GetY())
      << "point 3 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_3.GetZ())
      << "point 3 z position incorrectly set";


    //ensure point_4 gets set correctly 
    route.pop();
    EXPECT_FLOAT_EQ(route.front().GetX(), point_4.GetX())
      << "point 4 x position incorrectly set";

    //should be max_height
    EXPECT_FLOAT_EQ(route.front().GetY(), point_4.GetY())
      << "point 4 y position incorrectly set";

    EXPECT_FLOAT_EQ(route.front().GetZ(), point_4.GetZ())
      << "point 4 z position incorrectly set";
    

    //ensure dest gets set correctly 
    EXPECT_FLOAT_EQ(route.back().GetX(), vec_dest.GetX())
      << "dest x position incorrectly set";

    //should be base_height 
    EXPECT_FLOAT_EQ(route.back().GetY(), vec_dest.GetY())
      << "dest y position incorrectly set";

    EXPECT_FLOAT_EQ(route.back().GetZ(), vec_dest.GetZ())
      << "dest z position incorrectly set";

  }
}  // namespace csci3081
