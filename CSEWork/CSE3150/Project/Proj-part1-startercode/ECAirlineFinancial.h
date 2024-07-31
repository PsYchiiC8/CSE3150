//
//  ECAirlineFinancial.h
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h

class ECFlightItinerary;
class ECAirlineOperation;
class ECFlight;


// ****************************************************************************
// Airline finanical: budgetting, pricing and money bookkeeping

class ECAirlineFinancial {
public:
    double CalculatePrice(ECFlightItinerary& itinerary);

private:
    ECAirlineOperation* operation;
};

#endif
