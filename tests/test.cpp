#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "resource.h"

/* Test classes. */
class Font {
public:
  int x = 10;
};
class Image {};

class ComplexConstructor
{
public:
  ComplexConstructor(int x, double y)
    : m_x(x), m_y(y)
  {
  }
  int get_x() { return m_x; }
  double get_y() { return m_y; }
private:
  int m_x;
  double m_y;
};
/* End of test classes. */

TEST(tc0, font) {
  // Create objects with no arguments (aka default ctor)
  Resource<Font>::Create("font1.ttf");
  Resource<Font>::Create("ubuntu.ttf");
  auto f1 = Resource<Font>::GetByName("font1.ttf");
  EXPECT_EQ(f1.x, 10);
}

TEST(tc0, complex_ctor) {
  // Create objects with custom arguments (aka non-default ctor)
  Resource<ComplexConstructor>::Create("ComplexConstructor", 2, 2.4);
  Resource<ComplexConstructor>::Create("ComplexConstructor2", 3, 1.6);
  auto cont = Resource<ComplexConstructor>::GetContainer();
  EXPECT_EQ(cont.size(), 2);
}

TEST(tc0, image) {
  Resource<Font>::Create("ubuntu.ttf");
  // Get Image container and print all Image names.
  auto container = Resource<Image>::GetContainer();
  for(const auto& var : container)
    EXPECT_EQ("ubuntu.ttf", var.first);
}

TEST(tc0, throw_test) {
  EXPECT_ANY_THROW(Resource<Font>::GetByName("not_found_ABCDEFG.ttf"));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
