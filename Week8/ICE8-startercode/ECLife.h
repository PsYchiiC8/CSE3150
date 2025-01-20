#ifndef _EC_LIFE_H
#define _EC_LIFE_H

#include <string>

// Life 
class ECLife
{
public:
  ECLife(double life) : lifeRemain(life) {}
  double GetLifeRemain() const { return lifeRemain; }
  void SetLife(double f) { lifeRemain = f; }
  virtual ~ECLife() {}; 

private:
  double lifeRemain;
};

#endif
