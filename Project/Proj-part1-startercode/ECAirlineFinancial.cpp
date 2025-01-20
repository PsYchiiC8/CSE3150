//
//  ECAirlineFinancial.cpp
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#include "ECAirlineFinancial.h"

#include <string>
#include <iostream>
using namespace std;

class ECFlightItinerary;

#include "ECFlightItinerary.h"

#include "ECFlight.h"

double ECAirlineFinancial::CalculatePrice(ECFlightItinerary& itinerary){
    double time = 0;
    for (int i = 0; i < itinerary.GetNumSegments(); i++){
        time += itinerary.GetSegment(i)->GetArrivalTime() - itinerary.GetSegment(i)->GetDepartureTime();
    }
    return time * 120;
}