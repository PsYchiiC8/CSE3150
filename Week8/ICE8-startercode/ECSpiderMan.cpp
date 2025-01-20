#include "ECSpiderMan.h"
#include <iostream>
using namespace std;

// Spiderman
ECSpiderMan :: ECSpiderMan(double life) : ECSpider(life), ECHuman(life), ECLife(life)
{
}

void ECSpiderMan :: Work()
{
  // do run and weave 
  Weave();
  Run();
}

