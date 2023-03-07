#include <vec.hpp>
#include <type_traits>

namespace miit::world
{
  template <long... T>
  class Vec2 : public Vec<T, T>
  {
    public:
      Vec2(long x, long y);
  };
  
} // namespace miit::graphic
