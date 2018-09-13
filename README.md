## Resource
Extremely fast header only resource management library.

### Rationale
If you need a generic way of handling multiple resource classes in your project, the most elegant solution is to usually use some kind of dynamic casting method with derived classes. This has the downside of being slow, as the program needs to figure out in runtime which derived types we want from our base class container.

This resource library on the other hand creates `std::vector<std::pair<std::string, T>>` container and accessors for every resource `T` type you create. `T` of course could be any type. The cost of accessing a resource is the cost of accessing `std::vector<std::pair<std::string, T>>` element, which is extremely fast, compared to dynamic casting.

### Example

This example has 4 objects, where 2 of them belongs to the `Font` class, 1 of them belongs to the `Image` class and 1 of them belongs to the `ComplexConstructor`class. `Font` and `Image` could be any classes you like. `Resource<T>::Create("resource-name")` adds new resource of type `T`, which can be accessed with `Resource<T>::GetByName("resource-name")` accessor. It returns type `T` object.

```cpp
    #include "resource.h"


      /* Dummy classes for demonstration purposes. */
      class Image { int x = 10; };
      class Font { int y = 20; };
      class ComplexConstructor {
      public: 
        ComplexConstructor(int x, double y) { m_x = x; m_y = y; }
        int m_x;
        double m_y;
      };

      int main() {
        /* Fonts are in one static container. */
        Resource<Font>::Create("arial.ttf");
        Resource<Font>::Create("ubuntu.ttf");
        /* Images are in different static container. */
        Resource<Image>::Create("image.png");
        /* ComplexConstructor is initialized with 2 arguments. */
        Resource<ComplexConstructor>::Create("cc", 10, 2.4);

        /* Get Font resource. */
        Font arial = Resource<Font>::GetByName("arial.ttf");
        std::cout << arial.y << '\n'; // prints 20

        /* Get Image resource (with auto). */
        auto img = Resource<Image>::GetByName("image.png");
        std::cout << img.x << '\n'; // prints 10

        /* Get ComplexConstructor resource. */
        auto cc = Resource<ComplexConstructor>::GetByName("ComplexConstructor");
        std::cout << cc.x << ' ' << cc.y << '\n'; // prints 10 2.4

        exit(0);
    }
```

### How to install/use it?
Header-only inclusion is enough.

    wget https://raw.githubusercontent.com/Osteri/resource/master/resource.h
    #include "resource.h"

### TODO
- Possibly sort underlaying containers for faster access.
- Are duplicates problem?
