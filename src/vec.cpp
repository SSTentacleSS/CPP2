#include <vector>
#include <cmath>
#include <vec.hpp>

using std::size_t;
using std::pow;
using std::sqrt;
using miit::world::Vec;


Vec::Vec(const vector<long> position) : position(position) {}


Vec::~Vec() {}


Vec &Vec::set(const Vec &other)
{
  this->position = other.position;

  return *this;
}


Vec& Vec::copy(Vec &other) const
{
  other.position = this->position;
  return other;
}


const Vec Vec::clone() const
{
  return Vec(this->position);
}


const Vec Vec::scale(double scale) const
{
  vector<long> scaled = {};

  for (long positionComponent : this->position)
    scaled.push_back(positionComponent * scale);
  return Vec(scaled);
}


const Vec Vec::descale(double descale) const
{
  vector<long> descaled = {};

  for (long positionComponent : this->position)
    descaled.push_back(positionComponent / descale);
  return Vec(descaled);
}


const double Vec::length() const
{
  return sqrt(this->dot(*this));
}


const double Vec::distance(const Vec &other) const
{
  double dvector = 0;

  for (size_t i = 0; i < this->position.size(); i++)
    dvector += (other.position.at(i) - this->position.at(i)) << 2;
  return sqrt(dvector);
}


const double Vec::dot(const Vec &other) const
{
  double dotProduct = 0;

  for (size_t i = 0; i < this->position.size(); i++)
    dotProduct += this->position.at(i) * other.position.at(i);
  return dotProduct;
}