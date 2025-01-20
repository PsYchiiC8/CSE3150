//
//  ECAirlineOperation.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//  About operation of an airline: especially flights management

#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h

#include <vector>

#include "ECAirport.h"
#include "ECFlight.h"
// #include "ECAirportInfo.h"

class ECFlight;
class ECAirlineFinancial;
class ECAirlineTicketing;
class ECFlightItinerary;


// put your code about airline operation here...
class ECAirlineOperation{
public:
    ECAirlineOperation();
    ~ECAirlineOperation();
    void AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate );
    // void deleteFlight(ECFlight *flight);
    // void updateFlight();

    void AddAirport(const std::string &name, const std::string &airportCode);

    void PostFlightSetup();

    void SetDistBtwAirports(const std::string &origin, const std::string &destination, int distance);

    std::vector<ECFlight *> GetFlightsFrom(const std::string &airportCode);

private:
    std::vector<ECFlight *> flights;
    ECAirlineFinancial *airlineFinancial;
    std::map<std::string, std::vector<ECFlight> > adjList;
};

#endif
