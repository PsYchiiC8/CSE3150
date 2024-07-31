// https://programmercave.com/blog/2020/04/16/Single-Elevator-Simulation-in-Cpp
//
//
//  ECElevatorSim.cpp
//  
//
//  Created by Yufeng Wu on 6/27/23.
//  Elevator simulation


#include "ECElevatorSim.h"
#include <algorithm>

using namespace std;



void ECElevatorSim::Simulate(int lenSim) {
    while(timer < lenSim) {
        std::cout<<"Time: "<< timer <<" Floor: "<<currFloor<<" Direction: "<<currState<<endl;

        // Clear processed requests from previous steps
        madeRequests.clear();
        floorOn.clear();
        floorOff.clear();
        waiting_Outside.clear();
        waiting_Inside.clear();

        floorReq = false;

        // Gather requests to be considered at the current time
        pendingRequests();

        if(madeRequests.size() == 0){
            SetCurrDir(EC_ELEVATOR_STOPPED);
            SetPrevDir(EC_ELEVATOR_STOPPED);
        } else{
            if(floorReq == true){
                getOff();
                getOn();
            } else if(floorReq == false){
                // check if the elevator is moving
                // if not find where to go
                // if it is, see if there are any requests in the current dir
                // if not, switch direction
                if(GetCurrDir() != EC_ELEVATOR_STOPPED){
                    if(!(onWay())){
                        keepMoving();
                    }
                } else if(GetCurrDir() == EC_ELEVATOR_STOPPED){
                    notMoving();
                }
            }
        }

        move();

        // the timer always get incremented regardless of the state
        timer++;
        
    }
}


void ECElevatorSim::pendingRequests(){
    floorOn.clear();
    floorOff.clear();
    madeRequests.clear();
    waiting_Outside.clear();
    waiting_Inside.clear();

    floorReq = false;

    for(auto &x : listRequests){
        if(x.GetTime() <= timer){
            if(x.GetRequestedFloor() == GetCurrFloor() && !(x.IsServiced())){
                if(!(x.IsFloorRequestDone())){
                    floorOn.push_back(x);
                    floorReq = true;
                } else if (x.IsFloorRequestDone()){
                    floorOff.push_back(x);
                    floorReq = true;
                }
            } else if (x.IsFloorRequestDone() == false){
                waiting_Outside.push_back(x);
            } else if (x.IsFloorRequestDone() == true){
                waiting_Inside.push_back(x);
            }
            
            if(x.IsServiced() == false){
                madeRequests.push_back(x);
            }
        }
    }
}

void ECElevatorSim::getOn(){
    for(auto &x : floorOn){
        if(x.get().GetRequestedFloor() == GetCurrFloor()){
            x.get().SetFloorRequestDone(true);
            std::cout<<"Passenger(s) got on the elevator"<<std::endl;
        }
    }
    SetPrevDir(GetCurrDir());
    SetCurrDir(EC_ELEVATOR_STOPPED);
}

void ECElevatorSim::getOff(){
    for(auto &x : floorOff){
        if(x.get().GetRequestedFloor() == GetCurrFloor()){
            x.get().SetArriveTime(timer);
            x.get().SetServiced(true);
            cout<<"Passenger(s) got off the elevator"<<endl;
        }
    }
    SetPrevDir(GetCurrDir());
    SetCurrDir(EC_ELEVATOR_STOPPED);
}

void ECElevatorSim::notMoving(){
    pendingRequests();

    if(oneReq()){
        return;
    }

    if(findByTime()){
        return;
    }

    multReq();
}

bool ECElevatorSim::onWay(){
    for(auto &x : madeRequests){
        if(x.get().GetRequestedFloor() > GetCurrFloor() && GetCurrDir() == EC_ELEVATOR_UP){
            return true;
        } else if(x.get().GetRequestedFloor() < GetCurrFloor() && GetCurrDir() == EC_ELEVATOR_DOWN){
            return true;
        }
    }

    return false;
}

void ECElevatorSim::move(){
    if(GetCurrDir() == EC_ELEVATOR_UP){
        SetCurrFloor(GetCurrFloor() + 1);
    } else if(GetCurrDir() == EC_ELEVATOR_DOWN){
        SetCurrFloor(GetCurrFloor() - 1);
    }
}

void ECElevatorSim::keepMoving(){
    bool otherDir = false;
    for(auto &x : madeRequests){
        if((x.get().GetRequestedFloor() > currFloor && GetCurrDir() == EC_ELEVATOR_UP) || (x.get().GetRequestedFloor() < currFloor && GetCurrDir() == EC_ELEVATOR_DOWN)){
            return;
        } else{
            otherDir = true;
        }
    }

    if(otherDir){
        if(GetCurrDir() == EC_ELEVATOR_UP){
            SetCurrDir(EC_ELEVATOR_DOWN);
        } else if(GetCurrDir() == EC_ELEVATOR_DOWN){
            SetCurrDir(EC_ELEVATOR_UP);
        }
    } else{
        SetCurrDir(GetPrevDir());
    
    }
}

bool ECElevatorSim::oneReq(){
    if(madeRequests.size() == 1){
        if(madeRequests[0].get().IsFloorRequestDone() == false){
            if(madeRequests[0].get().GetRequestedFloor() > currFloor){
                SetCurrDir(EC_ELEVATOR_UP);
                return true;
            } else if(madeRequests[0].get().GetRequestedFloor() < currFloor){
                SetCurrDir(EC_ELEVATOR_DOWN);
                return true;
            }
        } else{
            if(madeRequests[0].get().GetRequestedFloor() > currFloor){
                SetCurrDir(EC_ELEVATOR_UP);
                return true;
            } else if(madeRequests[0].get().GetRequestedFloor() < currFloor){
                SetCurrDir(EC_ELEVATOR_DOWN);
                return true;
            }
        }
    }

    return false;
}

bool ECElevatorSim::multReq(){
    if(madeRequests.size() > 1){
        for(auto &x : waiting_Inside){
            if(x.get().GetRequestedFloor() > currFloor && GetPrevDir() == EC_ELEVATOR_UP){
                SetCurrDir(EC_ELEVATOR_UP);
                return true;
            } else if (x.get().GetRequestedFloor() < currFloor && GetPrevDir() == EC_ELEVATOR_DOWN){
                SetCurrDir(EC_ELEVATOR_DOWN);
                return true;
            }
        }
    }

    return false;
}

bool ECElevatorSim::findByTime(){
    std::vector<ECElevatorSimRequest> earliest;

    earliest.push_back(madeRequests[0]);
    int numFirst = 1;

    for(auto &x : madeRequests){
        if(x.get().GetTime() < earliest[0].GetTime() && x.get().IsServiced() == false){
            earliest.clear();
            earliest.push_back(x);
            numFirst = 1;
        } else if(x.get().GetTime() == earliest[0].GetTime() && !(x.get() == earliest[0])){
            earliest.push_back(x);
            numFirst++;
        }
    }

    if(numFirst == 1){
        if(earliest[0].GetRequestedFloor() > currFloor){
            SetCurrDir(EC_ELEVATOR_UP);
            cout<<"Elevator is moving up 1"<<endl;
        } else if(earliest[0].GetRequestedFloor() < currFloor){
            SetCurrDir(EC_ELEVATOR_DOWN);
            cout<<"Elevator is moving down 1"<<endl;
        }
        return true;

    } else if(numFirst > 1){
        int above = numFloors;
        int below = numFloors;

        for(auto &x : madeRequests){
            if(x.get().GetRequestedFloor() > currFloor){
                above = min(above, abs(x.get().GetRequestedFloor() - GetCurrFloor()));
            } else if(x.get().GetRequestedFloor() < currFloor){
                below = min(below, abs(x.get().GetRequestedFloor() - GetCurrFloor()));
            }

            if((GetPrevDir() == EC_ELEVATOR_DOWN && x.get().GetRequestedFloor() < GetCurrFloor()) || (GetPrevDir() == EC_ELEVATOR_UP && x.get().GetRequestedFloor() > GetCurrFloor())){
                SetCurrDir(GetPrevDir());
                return true;
            }
        }

        if(above <= below){
            SetCurrDir(EC_ELEVATOR_UP);
            cout<<"Elevator is moving up 2"<<endl;
        } else{
            SetCurrDir(EC_ELEVATOR_DOWN);
            cout<<"Elevator is moving down 2"<<endl;
        }
        return true;
    }
    return false;
}

