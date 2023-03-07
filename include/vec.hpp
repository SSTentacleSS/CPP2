#include <vector>

namespace miit::world
{
  template <class... T>
  class Vec {
    private:
      std::vector<T> position;
    public:
      Vec(std::vector<T> position);
      ~Vec();
  };
} // namespace miit::graphic