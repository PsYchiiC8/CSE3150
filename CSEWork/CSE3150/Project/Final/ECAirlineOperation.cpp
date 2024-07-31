//
//  ECAirlineOperation.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"

class ECFlightItinerary;
class ECAirlineOperation;
class ECAirlineFinancial;
class ECFlight;

#include <iostream>
#include <string>

using namespace std;

ECAirlineOperation::ECAirlineOperation(){
    airlineFinancial = new ECAirlineFinancial();
}

ECAirlineOperation::~ECAirlineOperation(){
    delete airlineFinancial;
    for (int i = 0; i < flights.size(); i++){
        delete flights[i];
    }
    flights.clear();
}

void ECAirlineOperation::AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate ){
    ECFlight *flight = new ECFlight(srcAirport, destAirport, tmDepart, maxPassengers);
    flights.push_back(flight);
}

void ECAirlineOperation::AddAirport(const std::string &name, const std::string &airportCode){
    ECAirportInfo::GetInstance()->CreateAirport(name, airportCode);
}

void ECAirlineOperation::PostFlightSetup(){
    return;    
}

void ECAirlineOperation::SetDistBtwAirports(const std::string &origin, const std::string &destination, int distance){
    ECAirportInfo::GetInstance()->SetDistanceBtw(origin, destination, distance);
}

std::vector<ECFlight *> ECAirlineOperation::GetFlightsFrom(const std::string &airportCode){
    std::vector<ECFlight *> flightsFrom;

    for (int i = 0; i < flights.size(); i++){
        if (flights[i]->GetSource() == airportCode){
            flightsFrom.push_back(flights[i]);
        }
    }

    return flightsFrom;
}

void ECAirlineOperation::GetAirports(std::vector<std::string> &listAirports){
    ECAirportInfo::GetInstance()->GetAirports(listAirports);
}