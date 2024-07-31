//
//  ECConsoleUIButton.cpp
//  
//
//  Created by Yufeng Wu on 3/6/24.
//

#include "ECConsoleUIButton.h"
#include "ECConsoleUISearchButton.h"

#include "ECAirlineSimulator.h"
#include "ECFlightItinerary.h"
#include "ECFlight.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


//*****************************************************************************
// Console UI button: 

// specifiy the portion of the view for this list box
ECConsoleUISearchButton :: ECConsoleUISearchButton(int xUL, int yUL, int xLR, int yLR, const std::string &strButIn, ECAirlineSimulator *sim, ECConsoleUIListBox *origins, ECConsoleUIListBox *destinations, ECConsoleUIListBox *flights, ECConsoleUIView *viewTest) : 
    ECConsoleUIButton(xUL, yUL, xLR, yLR, strButIn), strButton(strButIn), sim(sim), origin(origins), destinations(destinations), flights(flights), viewTest(viewTest) {}

// Get displayed text at a specific row
// Text is relative to the item portion (i.e., relative to (xLR, yLR))
std::string ECConsoleUISearchButton :: GetTextAtRow(int r) const
{
    // there is only one line
    std::string str;
    int rconv = r - GetYUL();

    if( rconv <0 || /*rconv >= 1 ||*/ rconv >= GetHeight() )
    {
        return str;
    }

    // add a row of '----' right above/below
    if( rconv == 0 || rconv == GetHeight()-1 )
    {
        str += '+';
        for( int i=1 ; i<GetWidth() - 1; ++i)
        {
            str += '-';
        }
        str += '+';
    }
    else
    {
        // begin with a '|'
        //str += '|';

        // align to the center
        if( strButton.size() < GetWidth())
        {
            str += '|';
            for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
        }

        str += strButton;
        for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
            str += '|';

        // end with a '|'
        //str += '|';
    }

    // ensure the str is not too long
    str = str.substr(0, GetWidth());
    return str;
}

// Get highlighted part (if any); return the row with highlight
// if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
// Assume: at most a single row with highlighted part
int ECConsoleUISearchButton :: GetHighlightPosition(int &xLeft, int &xRight) const
{
    return -1;
}

// Handle enter key
void ECConsoleUISearchButton :: HdlKeyEnter()
{
    if((*origin).GetChoice() != (*destinations).GetChoice()){

        (*flights).Clear();         //clear the choices in the list box so they don't overlap

        std::vector<ECFlightItinerary> listItineraries;
        (*sim).SearchForFlights((*origin).GetTextAtRow(), (*destinations).GetTextAtRow(), listItineraries);
        
        if(listItineraries.size() == 0){
            (*flights).AddChoice("No flights found");
            (*flights).Choose(0);
            return;
        }

        std::string str;
        for(auto i : listItineraries){
            str.clear();

            for(int j = 0; j < i.GetNumSegments(); j++){
                ECFlight flight = *i.GetSegment(j);
                str += flight.GetSource();

                if(j < i.GetNumSegments() - 1){
                    str += "->";
                } else{
                    str += "->" + flight.GetDest();
                }
            }

            double depart = i.GetDepartTime();
            std::stringstream ss;
            ss << std::fixed << std::setprecision(2) << depart;
            std::string departStr = ss.str();

            double arrive = i.GetArrivalTime();
            std::stringstream ss2;
            ss2 << std::fixed << std::setprecision(2) << arrive;
            std::string arriveStr = ss2.str();

            double price = i.GetPrice();
            std::stringstream ss3;
            ss3 << std::fixed << std::setprecision(2) << price;
            std::string priceStr = ss3.str();

            str += "  Cost: $" + priceStr + " Depart: " + departStr + " Arrive: " + arriveStr;

            (*flights).AddChoice(str);

        }
        (*flights).Choose(0);
    } else{
        (*flights).Clear();
        (*flights).AddChoice("Origin and Destination cannot be the same");
        (*flights).Choose(0);
    }

    viewTest->Refresh();
    
}
