#include "ECMotorVehicle.h"

// Generic vehicle
ECMotorVehicle :: ECMotorVehicle() 
{
}

ECMotorVehicle ::  ~ECMotorVehicle()
{
  for(auto x : listParts)
  {
    delete x;
  }
  listParts.clear();

}

double ECMotorVehicle :: GetPrice() const
{
  double res = 0;
  for(auto x : listParts)
  {
    res += x->GetPrice();
  }
  res *= 1.5;
  res -= GetDiscount();
  res *= 1.0+GetTaxRate(); 

  return res; 
}
void ECMotorVehicle :: SetEngine( EC_ENGINE_TYPE t )
{
  listParts.push_back(new ECEngine(t));
}
// add a wheel of size s
void ECMotorVehicle:: AddWheel(int s)
{
  listParts.push_back(new ECWheel(s));
}

// add a light
void ECMotorVehicle :: AddLight()
{
  listParts.push_back(new ECLight);
}
  
//***************************************
// Car
ECCar :: ECCar(EC_ENGINE_TYPE t, int szWheel)
{
  SetEngine(t);
  for(int i = 0; i<4; ++i)
  {
    AddWheel( szWheel );

  }

  for(int i = 0; i<4; ++i)
  {
    AddLight();
  }
}

//*****************************************
// Truck 
ECTruck :: ECTruck(int numWheels, int szWheel)
{
  SetEngine(EC_ENGINE_6CYL);
  for(int i = 0; i<numWheels; ++i)
  {
    AddWheel( szWheel );

  }

  for(int i = 0; i<8; ++i)
  {
    AddLight();
  }
}

//************************************
// Motocycle
ECMotocycle :: ECMotocycle()
{
  SetEngine(EC_ENGINE_4CYL);
  for(int i = 0; i<2; ++i)
  {
    AddWheel( 17 );

  }

  for(int i = 0; i<2; ++i)
  {
    AddLight();
  }
}


