#include <vector>

using std::size_t;
using std::vector;

namespace miit::world
{
  class Vec {
    protected:
      vector<long> position;
    public:
      explicit Vec(const vector<long> position);
      ~Vec();

      Vec& copy(Vec &other) const;
      Vec& set(const Vec& other);

      const Vec clone() const;
      const Vec scale(double scale) const;
      const Vec descale(double descale) const;
      const double length() const;
      const double distance(const Vec& other) const;
      const double dot(const Vec& other) const;

      inline bool operator<(const Vec& other) const;
      inline bool operator>(const Vec& other) const;
      inline bool operator==(const Vec& other) const;
      inline bool operator!=(const Vec& other) const;

      inline const Vec operator+(const Vec& other) const;
      inline const Vec operator-(const Vec& other) const;
      inline const Vec operator*(double scale) const;
      inline const Vec operator/(double descale) const;

      inline Vec& operator+=(const Vec &other);
      inline Vec& operator-=(const Vec &other);
      inline Vec& operator*=(double scale);
      inline Vec& operator/=(double descale);
  };
} // namespace miit::graphic