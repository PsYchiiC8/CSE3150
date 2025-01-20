//
//  ECAirlineSimulator.cpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//

#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECFlightItinerary.h"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

ECAirlineSimulator::ECAirlineSimulator(){
    Init();
}

#include "ECAirlineOperation.h" // Include the header file for ECAirlineOperation

ECAirlineSimulator::~ECAirlineSimulator(){
    delete pAirlineOp;
    delete pAirlineFin;
}

void ECAirlineSimulator::Init(){
    pAirlineOp = new ECAirlineOperation();
    pAirlineFin = new ECAirlineFinancial();
    pAirlineTicket = new ECAirlineTicketing();
    doneFlightAdding = false;
    
}

void ECAirlineSimulator::AddAirport(const std::string & name, const std::string &airportCode){
    pAirlineOp->AddAirport(name, airportCode);
}

void ECAirlineSimulator::AddFlight(std::string &origin, std::string &destination, double departureTime, int capacity, int costToOperate){
    if (doneFlightAdding){
        cout << "Error: cannot add flight after doneFlightAdding" << endl;
        return;
    }
    pAirlineOp->AddFlight(origin, destination, departureTime, capacity, costToOperate);
}

void ECAirlineSimulator::SetDistBtwAirports(const std::string &origin, const std::string &destination, int distance){
    pAirlineOp->SetDistBtwAirports(origin, destination, distance);
}




void ECAirlineSimulator::SearchForFlights(const std::string &origin, const std::string &destination, std::vector<ECFlightItinerary> &listItineraries){
    std::set<std::string> visited;
    std::vector<ECFlight *> currentPath;
    DFS(origin, destination, visited, currentPath, listItineraries);
}

void ECAirlineSimulator::DFS(const std::string &current, const std::string &destination, std::set<std::string> &visited, std::vector<ECFlight *> &currentPath, std::vector<ECFlightItinerary> &listItineraries){
    visited.insert(current);

    if (current == destination) {
        listItineraries.push_back(ECFlightItinerary(currentPath));
    } else {
        std::vector<ECFlight *> outgoingFlights = pAirlineOp->GetFlightsFrom(current);
        std::cout<<"here"<<std::endl;

        for (auto flight : outgoingFlights) {
            if ((visited.find((*flight).GetDest()) == visited.end()) && ((currentPath.size() == 0) || (*flight).GetDepartureTime() >= currentPath.back()->GetArrivalTime())){
                cout<<"here"<<endl;
                currentPath.push_back(flight);

                DFS((*flight).GetDest(), destination, visited, currentPath, listItineraries);
                currentPath.pop_back();
            }
        }
    }
    visited.erase(current);
}

void ECAirlineSimulator::GetAirports(std::vector<std::string> &listAirports){
    pAirlineOp->GetAirports(listAirports);
}
