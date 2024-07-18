#include "ECClass.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class for class
ECClass::ECClass() {
}

void ECClass::AddStudent(const ECStudent &s) {
    listStu.push_back(s);
}

double ECClass::GetAveMedian() const {
    if (listStu.size() == 0) {
        throw std::string("Empty class");
    }
    vector<double> listSs;
    //iterate through list of students
    //Get each average and add to a list
    for (auto x: listStu) {
        listSs.push_back(x.GetAve());
    }
    std::sort(listSs.begin(), listSs.end());
    return listSs[listSs.size() / 2];

    //if no scores, median is 0.0

    //sort list of averages
    //get middle average
    //return
}

std::string ECClass::GetRankedStudentName(int n) const {
    vector <pair<double, string>> listSs;
    //list of pairs of names and scores

    //iterate through students append their info to this list
    for (auto x: listStu) {
        listSs.push_back(std::make_pair(-1 * x.GetAve(), x.GetName()));
    }
    std::sort(listSs.begin(), listSs.end());
    return listSs[n].second;
    //return empty string
    //sort list of students and scores (by score)
    //get student at that position
    //return their name
}