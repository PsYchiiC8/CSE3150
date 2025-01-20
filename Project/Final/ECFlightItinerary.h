//
//  ECFlightItinerary.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlightItinerary_h
#define ECFlightItinerary_h

#include <vector>
#include <string>

class ECFlight;
class ECAirlineFinancial;

// ****************************************************************************
// Flight itineary: consisting segments of flights so to go from one airport to another airport

class ECFlightItinerary
{
public:
    ECFlightItinerary();

    ECFlightItinerary(const std::vector<ECFlight *> &flights);
    
    // access/edit segments
    // Return the number of segments of the itineary
    int GetNumSegments() const;
    
    // Return a segment
    ECFlight *GetSegment(int segIndex) const;
    
    // Get flight time: from departure to arrival
    double GetFlightTime() const;
    
    // Get departure time
    double GetDepartTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;

    // double GetTotalTime() const;
    
    // Price 
    double GetPrice() const;

    void addSegment(ECFlight *flight);
    
    std::string GetSource() const;

    std::string GetDest() const;

    void removeLastFlight() {
        if (!segments.empty()) {
            segments.pop_back();
        }
    }
    
private:
    // your code
    std::vector<ECFlight *> segments;
    int numSegments;
    double departTime;
    double arrivalTime;

};

#endif /* ECFlightItinerary_h */
