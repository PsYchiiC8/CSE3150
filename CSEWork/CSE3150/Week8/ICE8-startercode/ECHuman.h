#ifndef _EC_HUMAN_H
#define _EC_HUMAN_H

#include "ECLife.h"

// Human
class ECHuman : public virtual ECLife
{
public:
  ECHuman();
  ECHuman(double life);
  virtual ~ECHuman() {}; 

  // work and consume energy
  void Run();

};

#endif
