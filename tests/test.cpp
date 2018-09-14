#include <iostream>
#include <string>

#include "resource.h"

#include "gtest/gtest.h"

TEST(sample_test_case, sample_test) {
  EXPECT_EQ(1,1);
}

// #include <iostream>
// #include <string>
// 
// #include "resource.h"
// 
// /* Test classes. */
// class Font {
// public:
//   int x = 10;
// };
// class Image {};
// 
// class ComplexConstructor
// {
// public:
//   ComplexConstructor(int x, double y)
//     : m_x(x), m_y(y)
//   {
//   }
//   int get_x() { return m_x; }
//   double get_y() { return m_y; }
// private:
//   int m_x;
//   double m_y;
// };
// /* Test classes. */
// class Font {
// public:
//   int x = 10;
// };
// class Image {};
// 
// class ComplexConstructor
// {
// public:
//   ComplexConstructor(int x, double y)
//     : m_x(x), m_y(y)
//   {
//   }
//   int get_x() { return m_x; }
//   double get_y() { return m_y; }
// private:
//   int m_x;
//   double m_y;
// };
// /* End of test classes. */
// 
// int main()
// {
//   /*****************************************************/
//   /* Practical examples of how to use Resource class.   */
//   /*****************************************************/
// 
//   /************ Store resources. ***********************/
//   Resource<Font>::Create("font1.ttf");
//   Resource<Font>::Create("ubuntu.ttf");
//   Resource<Image>::Create("1.png");
//   Resource<Image>::Create("2.jpg");
//   // Create object with custom arguments (aka non-default constructor).
//   Resource<ComplexConstructor>::Create("ComplexConstructor", 2, 2.4);
//   Resource<ComplexConstructor>::Create("ComplexConstructor2", 3, 1.6);
//   /*****************************************************/
// 
//   /* Get Image container and print all Image names. ****/
//   {
//     auto container = Resource<Image>::GetContainer();
//     for(const auto& var : container)
//       std::cout << var.first << '\n';
//   }
// 
// //  /* Get specific Font resource (aka object) by name (recommended). */
// //  {
// //    auto font = Resource<Font>::GetByName("ubuntu.ttf");
// //    if(font.has_value())
// //      std::cout << font.value().x << '\n'; // Font object has int member x so we can print it
// //  }
// 
//   /* Catch garbage values by exception (recommended). */
//   {
//     try {
//       auto font = Resource<Font>::GetByName("ubuntu.ttf");
//       std::cout << font.x << '\n';
//     } catch (std::invalid_argument& e) {
//       std::cerr << e.what() << '\n';
//     }
//   }
// 
//   /* Catch garbage values by exception (recommended). */
//   {
//     try {
//       auto font = Resource<Font>::GetByName("made_a_typo");
//       font.x = 2; // oops, there is no such font
//     } catch (std::invalid_argument& e) {
//       std::cerr << e.what() << '\n';
//     }
//   }
// 
//   /* Test ComplexConstructor object. */
//   {
//     auto cc = Resource<ComplexConstructor>::GetByName("ComplexConstructor");
//     std::cout << cc.get_x() << ' ' << cc.get_y() << '\n';
// 
//     auto container = Resource<ComplexConstructor>::GetContainer();
//     std::cout << "ComplexConstructor has " << container.size() << " instances stored." << '\n';
//   }
// 
// //  /* Don't check object validity at all (not recommended). Dangerous. */
// //  {
// //    auto font = Resource<Font>::GetByName("made_a_typo");
// //    font.x = 2; // oops, there is no such font
// //  }
// 
//   exit(1);
// }
