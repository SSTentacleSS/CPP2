#include <vec.hpp>

using miit::world::Vec;


inline bool Vec::operator<(const Vec &other) const
{
  return this->length() < other.length();
}


inline bool Vec::operator>(const Vec &other) const
{
  return this->length() > other.length();
}


inline bool Vec::operator==(const Vec &other) const
{
  for (size_t i = 0; i < this->position.size(); i++)
    if (this->position.at(i) != other.position.at(i))
      return false;
  return true;
}


inline bool Vec::operator!=(const Vec &other) const
{
  return !(*this == other);
}


inline const Vec Vec::operator+(const Vec &other) const
{
  vector<long> addedPosition;

  for (size_t i = 0; i < this->position.size(); i++)
    addedPosition.push_back(this->position.at(i) + other.position.at(i));
  return Vec(addedPosition);
}


inline const Vec Vec::operator-(const Vec &other) const
{
  vector<long> substractedPosition;

  for (size_t i = 0; i < this->position.size(); i++)
    substractedPosition.push_back(this->position.at(i) - other.position.at(i));
  return Vec(substractedPosition);
}


inline const Vec Vec::operator*(double scale) const
{
  return this->scale(scale);
}


inline const Vec Vec::operator/(double descale) const
{
  return this->descale(descale);
}


inline Vec &Vec::operator+=(const Vec &other)
{
  return this->set(*this + other);
}


inline Vec &Vec::operator-=(const Vec &other)
{
  return this->set(*this + other);
}


inline Vec &Vec::operator*=(double scale)
{
  return this->set(*this * scale);
}


inline Vec &Vec::operator/=(double scale)
{
  return this->set(*this / scale);
}