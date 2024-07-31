//
//  ECFlight.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlight_h
#define ECFlight_h

#include <string>


// ****************************************************************************
// Flight: service between two airports at a specific time;

class ECAirportInfo;

class ECFlight 
{
public:
    ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn);
    
    virtual ~ECFlight(){}
    
    // Get departure time
    double GetDepartureTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    // Set max passenger for this flight
    void SetMaxNumPassengers(int m);
    
    // Get src airport code
    std::string GetSource() const;
    
    // Get destination code
    std::string GetDest() const;

    // more to add...
    // void SetArriveTime(double tmArriveIn);
    // void SetArriveTime(ECAirportInfo *airportInfo);
    void SetArriveTime();

    void SetDepartureTime(double tmDepartIn);

    int GetMaxNumPassengers() const;

    int GetNumPassengers() const;

private:
    // your code
    std::string src;
    std::string dest;
    double tmDepart;
    double tmArrive;
    int maxPassengers;
    int numPassengers;
};

#endif /* ECFlight_h */
