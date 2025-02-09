#include "Rectangle.hpp"
#include <vector>
#include <gtest/gtest.h>

TEST(RectangleTest, Constructor) {
  Rectangle r({10, 10});
  EXPECT_EQ(Vector_d(10, 10), r.getSize());
  EXPECT_EQ(Vector_d::zero(), r.getPosition());
  EXPECT_EQ(0.0, r.getRotation());

  Rectangle r2({10, 10}, {20, 7}, 0.4);
  EXPECT_EQ(Vector_d(10, 10), r2.getSize());
  EXPECT_EQ(Vector_d(20, 7), r2.getPosition());
  EXPECT_DOUBLE_EQ(0.4, r2.getRotation());
}

TEST(RectangleTest, Position) {
  Rectangle r({10, 10});
  r.move({10, 10});
  EXPECT_EQ(Vector_d(10, 10), r.getPosition());

  r.move({20, -30});
  EXPECT_EQ(Vector_d(30, -20), r.getPosition());

  r.setPosition({10, 10});
  EXPECT_EQ(Vector_d(10, 10), r.getPosition());
}

TEST(RectangleTest, Rotation) {
  Rectangle r({10, 10});
  r.rotate(0.2);
  EXPECT_DOUBLE_EQ(0.2, r.getRotation());

  r.rotate(-0.7);
  EXPECT_DOUBLE_EQ(-0.5, r.getRotation());

  r.setRotation(1.2);
  EXPECT_DOUBLE_EQ(1.2, r.getRotation());
}

TEST(RectangleTest, Resize) {
  Rectangle r({10, 10});
  r.resize({2, 3});
  EXPECT_EQ(Vector_d(20, 30), r.getSize());

  r.resize(0.5);
  EXPECT_EQ(Vector_d(10, 15), r.getSize());

  r.setSize({1, 1});
  EXPECT_EQ(Vector_d(1, 1), r.getSize());
}

TEST(RectangleTest, Vertices) {
  Rectangle r({10, 20}, {0, 10}, M_PI / 2.0);

  auto vertices = r.vertices();

  EXPECT_DOUBLE_EQ(10, vertices[0].x);
  EXPECT_DOUBLE_EQ(5, vertices[0].y);

  EXPECT_DOUBLE_EQ(10, vertices[1].x);
  EXPECT_DOUBLE_EQ(15, vertices[1].y);

  EXPECT_DOUBLE_EQ(-10, vertices[2].x);
  EXPECT_DOUBLE_EQ(15, vertices[2].y);

  EXPECT_DOUBLE_EQ(-10, vertices[3].x);
  EXPECT_DOUBLE_EQ(5, vertices[3].y);
}

// TEST(RectangleTest, Normals) {
//   Rectangle r({10, 20}, {0, 20}, M_PI / 4.0);
//
//   auto normals = r.normals();
//
//   EXPECT_DOUBLE_EQ(0.70710678118654746, normals[0].x);
//   EXPECT_DOUBLE_EQ(-0.70710678118654746, normals[0].y);
//
//   EXPECT_DOUBLE_EQ(0.70710678118654746, normals[1].x);
//   EXPECT_DOUBLE_EQ(0.70710678118654746, normals[1].y);
//
//   EXPECT_DOUBLE_EQ(-0.70710678118654746, normals[2].x);
//   EXPECT_DOUBLE_EQ(0.70710678118654746, normals[2].y);
//
//   EXPECT_DOUBLE_EQ(-0.70710678118654746, normals[3].x);
//   EXPECT_DOUBLE_EQ(-0.70710678118654746, normals[3].y);
// }


TEST(RectangleTest, OStream) {
  Rectangle r({10, 10});
  std::stringstream stringstream;
  stringstream << r;
  EXPECT_TRUE(stringstream.str() == "Rectangle((10, 10), (0, 0), 0)");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
