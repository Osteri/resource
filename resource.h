#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include <optional>

/* Resource class. Ability to hold any object. Very fast.
 * Calls default constructors when creating objects. */

template<typename T>
class Resource {
public:
  template<class ...Args>
  static void Create(const std::string& name, Args... args);
  static auto& GetContainer();
  static T GetByName(const std::string& name);
private:
  static std::vector<std::pair<std::string, T>> cont;
};

template<typename T>
typename::std::vector<std::pair<std::string, T>> Resource<T>::cont;

template<typename T>
template<class ...Args>
void Resource<T>::Create(const std::string& name, Args... args) {
  cont.push_back( std::make_pair(std::string(name), T(args...)) );
}

template<typename T>
auto& Resource<T>::GetContainer() {
  return cont;
}

template<typename T>
T Resource<T>::GetByName(const std::string& name) {
  for(auto var : cont) {
   if(name == var.first) {
     return var.second;
   }
  }
  /* We should never get here. User has now garbage object because we didn't
   * find the right object by name. This usually happens when user has made a typo */
  throw std::invalid_argument("Resource::GetByName(\"" + name + "\") failed.");
}

#endif // RESOURCE_H
