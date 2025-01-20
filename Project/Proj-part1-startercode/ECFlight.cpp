//
//  ECFlight.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlight.h"
#include "ECAirport.h"

#include <iostream>
using namespace std;

class ECAirportInfo;

ECFlight::ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn) {
    src = srcIn;
    dest = destIn;
    tmDepart = tmDepartIn;
    SetArriveTime();
    maxPassengers = maxPassengersIn;
    numPassengers = 0;
}

double ECFlight::GetDepartureTime() const{
    return tmDepart;
}

double ECFlight::GetArrivalTime() const{
    return tmArrive;
}

void ECFlight::SetMaxNumPassengers(int m){
    maxPassengers = m;
}

std::string ECFlight::GetSource() const{
    return src;
}

std::string ECFlight::GetDest() const{
    return dest;
}

int ECFlight::GetMaxNumPassengers() const{
    return maxPassengers;
}

int ECFlight::GetNumPassengers() const{
    return numPassengers;
}

void ECFlight::SetArriveTime(){
    tmArrive = GetDepartureTime() + ECAirportInfo::GetInstance()->GetDistanceBtw(GetSource(), GetDest()) / 500.0;
}

void ECFlight::SetDepartureTime(double tmDepartIn){
    tmDepart = tmDepartIn;
}