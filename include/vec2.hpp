#include <vector>
#include <vec.hpp>

using std::vector;

namespace miit::world
{
  class Vec2 : protected Vec
  {
    public:
      explicit Vec2(long x, long y);
      ~Vec2();
  }; // TODO: Implement basic methods for Vec2
  
} // namespace miit::graphic
