//
//  ECAirport.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirport.h"

#include <iostream>
using namespace std;

ECAirport::ECAirport(){
    operating = false;
}

ECAirport::ECAirport(const std::string &nameAP, const std::string &codeIATA){
    name = nameAP;
    code = codeIATA;
    operating = true;
}

ECAirport::ECAirport(const ECAirport &rhs){
    name = rhs.GetName();
    code = rhs.GetCode();
    operating = rhs.IsOperating();
}



void ECAirportInfo::CreateAirport(const std::string &name, const std::string &code){
    ECAirport airport(name, code);
    airportMap[code] = airport;
}

const ECAirport& ECAirportInfo::GetAirport(const std::string &code) const {
    auto it = airportMap.find(code);
    if (it == airportMap.end()) {
        throw std::string("No airport with code: ") + code;
    }
    return it->second;
}

void ECAirportInfo::SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist){
    distanceMap[std::pair<std::string, std::string>(ap1Code, ap2Code)] = dist;
    distanceMap[std::pair<std::string, std::string>(ap2Code, ap1Code)] = dist;
}

int ECAirportInfo::GetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code) const{
    // cout<<"Getting distance between "<<ap1Code<<" and "<<ap2Code << " " << distanceMap.at(std::pair<std::string, std::string>(ap1Code, ap2Code)) <<endl;
    return distanceMap.at(std::pair<std::string, std::string>(ap1Code, ap2Code));
}

ECAirportInfo* ECAirportInfo::GetInstance() {
    if (instance == nullptr) {
        instance = new ECAirportInfo();
    }
    return instance;
}


ECAirportInfo* ECAirportInfo::instance = nullptr;

void ECAirportInfo::GetAirports(std::vector<std::string> &airports) const {
    for (auto it = airportMap.begin(); it != airportMap.end(); it++) {
        airports.push_back(it->first);
    }
}