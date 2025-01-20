//
//  ECFlightItinerary.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

ECFlightItinerary::ECFlightItinerary(){
    numSegments = 0;
    departTime = 0;
}

ECFlightItinerary::ECFlightItinerary(const std::vector<ECFlight *> &flights){
    numSegments = 0;
    departTime = 0;
    arrivalTime = 0;
    for (int i = 0; i < flights.size(); i++){
        addSegment(flights[i]);
    }
}

int ECFlightItinerary::GetNumSegments() const{
    return numSegments;
}

ECFlight *ECFlightItinerary::GetSegment(int segIndex) const{
    return segments[segIndex];
}

double ECFlightItinerary::GetFlightTime() const{
    double timeAllSegments = 0;
    for (auto x : segments){
        timeAllSegments += (x->GetArrivalTime() - x->GetDepartureTime());
    }
    return timeAllSegments;
    // return arrivalTime - departTime;
}

double ECFlightItinerary::GetDepartTime() const{
    return departTime;
}

double ECFlightItinerary::GetArrivalTime() const{
    return arrivalTime;
}

// double ECFlightItinerary::GetTotalTime() const{
    
// }

double ECFlightItinerary::GetPrice() const{
    double price = GetFlightTime() * 120;

    return price;
}

std::string ECFlightItinerary::GetSource() const{
    return segments[0]->GetSource();
}

std::string ECFlightItinerary::GetDest() const{
    return segments[numSegments - 1]->GetDest();
}

void ECFlightItinerary::addSegment(ECFlight *flight){
    segments.push_back(flight);
    numSegments++;
    if (numSegments == 1){
        departTime = flight->GetDepartureTime();
    }
    arrivalTime = flight->GetArrivalTime();
}