// Test code for console UI
#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include "ECConsoleUITextField.h"
#include "ECConsoleUIButton.h"
#include "ECConsoleUISearchButton.h"

#include "ECAirport.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"

#include <iostream>

using namespace std;

#include <fstream>
#include <string>

// This function will find all the spaces in a string and store their indexes in a vector to use
void findSpaces(string &line, std::vector<int> &spaces){
    spaces.clear();
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' '){
            spaces.push_back(i);
        }
    }
}

// This function will take care of finding which rows have information we need and adding them to the simulator
void parse(ECAirlineSimulator &sim, std::string &filename){
    std::ifstream file(filename);
    
    // Check if file opened successfully
    if (!file) {
        std::cerr << "Unable to open file\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if(&line[0] == "#"){
            continue;
        } else{
            std::vector<int> spaces;
            findSpaces(line, spaces);

            string port;
            string name;

            string port1;
            string port2;
            double dist;
            double depart;
            int cap;
            double operationCost;

            //idk why it needs these weird numbers but it works, so I'm not going to question it
            //I'm just going to leave it as is, I'm not going to question it
            //without -6, the second airport name somehow has some of the following characters that goes after it with it

            switch(line[0]) {
                case '1':
                    //add airport

                    port = line.substr(spaces[0] + 1, spaces[1] - 2);
                    name = line.substr(spaces[1] + 1, line.size() - 1);

                    sim.AddAirport(name, port);
                    break;
                case '2':
                    //set distance between airports

                    port1 = line.substr(spaces[0] + 1, spaces[1] - 2);
                    port2 = line.substr(spaces[1] + 1, spaces[2] - 6);
                    dist = std::stod(line.substr(spaces[2] + 1, line.size() - 1));

                    sim.SetDistBtwAirports(port1, port2, dist);
                    break;
                case '3':
                    //add flight

                    port1 = line.substr(spaces[0] + 1, spaces[1] - 2);
                    port2 = line.substr(spaces[1] + 1, spaces[2] - 6);
                    depart = std::stod(line.substr(spaces[2] + 1, spaces[3] - 2));
                    cap = std::stoi(line.substr(spaces[3] + 1, spaces[4] - 2));
                    operationCost = std::stod(line.substr(spaces[4] + 1, line.size() - 1));

                    sim.AddFlight(port1, port2, depart, cap, operationCost);
                    break;
                default:
                    break;
            }
        }
    }
}

static void Console(ECConsoleUIView &viewTest, std::string &file, ECAirlineSimulator *sim){
    parse(*sim, file);
    (*sim).DoneFlightAdding();

    // create several labels
    std::string title_name = "Airline Reservation System";
    ECConsoleUITextLabel *title = new ECConsoleUITextLabel((viewTest.GetColNumInView() - title_name.size()) / 2, 1, title_name);
    title->SetHighlight(true);
    viewTest.AddUIItem(title);

    ECConsoleUITextLabel *origin = new ECConsoleUITextLabel(15, 3, "Origination");
    viewTest.AddUIItem(origin);
    ECConsoleUITextLabel *destination = new ECConsoleUITextLabel(50, 3, "Destination");
    viewTest.AddUIItem(destination);
    
    // Create a border (well, not very pretty)
    string horizBar;
    for(int i=0; i<viewTest.GetColNumInView(); ++i)
    {
        horizBar += '-';
    }

    
    ECConsoleUITextLabel *topBar = new ECConsoleUITextLabel(0, 0, horizBar);
    viewTest.AddUIItem(topBar);
    ECConsoleUITextLabel *bottomBar = new ECConsoleUITextLabel(0, viewTest.GetRowNumInView() - 1, horizBar);
    viewTest.AddUIItem(bottomBar);

    //Origins & destinations list boxes
    ECConsoleUIListBox *origins = new ECConsoleUIListBox(15, 4, 35, 6);
    ECConsoleUIListBox *destinations = new ECConsoleUIListBox(50, 4, 70, 6);
    std::vector<std::string> airports;
    (*sim).GetAirports(airports);
    for(auto i : airports)
    {
        origins->AddChoice(i);
        destinations->AddChoice(i);
    }

    origins->Choose(0);
    viewTest.AddUIItem(origins);

    destinations->Choose(0);
    viewTest.AddUIItem(destinations);

    // list box for flights
    std::string flight_str = "Flights";
    int flight_dist = (viewTest.GetColNumInView() - flight_str.size()) / 2;
    ECConsoleUITextLabel *flights = new ECConsoleUITextLabel(flight_dist, 11, flight_str);
    viewTest.AddUIItem(flights);
    ECConsoleUIListBox *list_flights = new ECConsoleUIListBox(5, 12, viewTest.GetColNumInView(), 15);
    list_flights->AddChoice("");
    list_flights->Choose(0);
    viewTest.AddUIItem(list_flights);
    
    
    // Add a text field to input name
    ECConsoleUITextLabel *passenger = new ECConsoleUITextLabel(20, 16, "Enter Passenger Name:");
    viewTest.AddUIItem(passenger);
    ECConsoleUITextField *name = new ECConsoleUITextField(viewTest.GetView(), 20, 17, 20);
    viewTest.AddUIItem(name);


    std::string search_name = "Search For Flights";
    int search_dist = (viewTest.GetColNumInView() - search_name.size()) / 2;
    ECConsoleUISearchButton *search = new ECConsoleUISearchButton(search_dist, 9, search_dist + search_name.size() + 1, 9, search_name, sim, origins, destinations, list_flights, &viewTest);
    viewTest.AddUIItem(search);
// #endif
}


int main(int argc, char* argv[])
{
    //
    ECAirlineSimulator sim;

    ECTextViewImp wndTest;
    
    // Create a console UI view
    ECConsoleUIView viewUI(&wndTest);
    
    // Add a few UI items
    std::string arg1(argv[1]);
    Console(viewUI, arg1, &sim);
    
    // Display it
    viewUI.Refresh();
    
    // Show the window
    try {
        wndTest.Show();
    }
    catch(std::string ex)
    {
        cout << "Exception: " << ex << endl;
    }
    return 0;
}
