#ifndef _EC_VEHICLE_PARTS_H
#define _EC_VEHICLE_PARTS_H

#include <string>

//base class for all parts
class ECPart
{
  public:
  virtual ~ECPart() {}
  virtual int GetPrice() const = 0; 
};

// Engine type
enum EC_ENGINE_TYPE
{
  EC_ENGINE_4CYL = 0,
  EC_ENGINE_6CYL = 1,
  EC_ENGINE_ELECTRIC = 2
};

// Engine
class ECEngine : public ECPart
{
public:
  ECEngine(EC_ENGINE_TYPE type ) : t(type) {}
  virtual int GetPrice() const
  {
    if( t == EC_ENGINE_4CYL )
    {
      return 1000;
    }
    else if( t == EC_ENGINE_6CYL )
    {
      return 1500;
    }
    else if( t == EC_ENGINE_ELECTRIC )
    {
      return 3000;
    }
    throw std::string("Bad type");
    return 0;
  }

private:
  EC_ENGINE_TYPE t;
};

// Wheel
class ECWheel : public ECPart
{
public:
  ECWheel(int size) :s(size) {}
  virtual int GetPrice() const
  {
    if (s == 17)
    {
      return 100;
    }
    else if( s == 19 )
    {
      return 150;
    }
    throw std::string("Bad wheel");
    return 0;
  }

private:
  int s;
};

// light
class ECLight : public ECPart
{
public:
  virtual int GetPrice() const { return 50; }
};

#endif
