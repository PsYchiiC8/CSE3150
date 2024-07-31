#ifndef _EC_MOTOR_VEHICLE_H
#define _EC_MOTOR_VEHICLE_H

#include <vector>
#include "ECVehicleParts.h"

// Generic vehicle
class ECMotorVehicle
{
public:
  ECMotorVehicle();
  virtual ~ECMotorVehicle();
  double GetPrice() const;

protected:
  // set an engine of type t
  void SetEngine( EC_ENGINE_TYPE t );
  // add a wheel of size s
  void AddWheel(int s);
  // add a light
  void AddLight();

  // how much is discount?
  virtual int GetDiscount() const { return 0; }
  
  // how much is tax rate?
  virtual double GetTaxRate() const = 0;

private:
  // wlist of parts of the vehicle
  std::vector<ECPart *> listParts;
};

//*****************************************
// Car
class ECCar : public ECMotorVehicle
{
public:
  ECCar(EC_ENGINE_TYPE t, int szWheel);

protected:
  
  // how much is tax rate?
  virtual double GetTaxRate() const {return 0.1;}


};
//****************************************
// Truck 
class ECTruck : public ECMotorVehicle
{
public:
  ECTruck(int numWheels, int szWheel);

protected:
  // how much is discount?
  virtual int GetDiscount() const { return 1000; }
  
  // how much is tax rate?
  virtual double GetTaxRate() const { return 0.08;}
};

// Motocycle
class ECMotocycle : public ECMotorVehicle
{
public:
  ECMotocycle();

protected:
  // what to put here?
  // how much is discount?
  virtual int GetDiscount() const { return 100; }
  
  // how much is tax rate?
  virtual double GetTaxRate() const { return 0.15;}
};

#endif
