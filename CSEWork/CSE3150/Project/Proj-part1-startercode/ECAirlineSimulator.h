//
//  ECAirlineSimulator.hpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//  Simulate airline activities: booking, flights, etc

#ifndef ECAirlineSimulator_h
#define ECAirlineSimulator_h

#include <string>
#include <set>
#include <vector>

class ECAirlineOperation;
class ECAirlineTicketing;
class ECAirlineFinancial;
class ECFlightItinerary;
class ECFlight;

//****************************************************************************
// Airline simulator

class ECAirlineSimulator
{
public:
    ECAirlineSimulator();
    virtual ~ECAirlineSimulator();
    
    // *****************************************************
    // Configuration
    
    void AddAirport(const std::string &name, const std::string &airportCode);

    void AddFlight(std::string &origin, std::string &destination, double departureTime, int capacity, int costToOperate);

    void SearchForFlights(const std::string &origin, const std::string &destination, std::vector<ECFlightItinerary> &flights);

    void DFS(const std::string &current, const std::string &destination, std::set<std::string> &visited, std::vector<ECFlight *> &currentPath, std::vector<ECFlightItinerary> &listItineraries);
    
    void SetDistBtwAirports(const std::string &origin, const std::string &destination, int distance);

    void DoneFlightAdding() { doneFlightAdding = true; };
    
private:
    // initialize
    void Init();
    
    // key data member
    ECAirlineOperation *pAirlineOp;
    ECAirlineFinancial *pAirlineFin;
    ECAirlineTicketing *pAirlineTicket;

    bool doneFlightAdding;
};


#endif /* ECAirlineSimulator_h */
