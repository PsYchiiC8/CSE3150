//
//  ECAirlineTicketing.h
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h

#include <vector>

#include "ECAirlineOperation.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"

class ECFlightItinerary;
class ECAirlineOperation;
class ECAirlineFinancial;

using namespace std;

// ****************************************************************************
// Airline ticketing: search for flights, issue tickets, etc

class ECAirlineTicketing {
public:
    void SearchForItinerary();

    void OrderItineraries(vector<ECFlightItinerary> &itineraries);

    std::vector<ECFlightItinerary> GetItineraries();

private:
    ECAirlineOperation *operation;
    ECAirlineFinancial *financial;
};

#endif /* ECAirlineTicketing_h */
