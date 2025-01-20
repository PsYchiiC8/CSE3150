#ifndef _EC_SPIDER_H
#define _EC_SPIDER_H

#include "ECLife.h"

// Spider
class ECSpider : public virtual ECLife 
{
public:
  ECSpider();
  ECSpider(double life);
  virtual ~ECSpider() {}; 

  // work and consume energy
  void Weave();

};

#endif
