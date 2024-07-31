//
//  ECConsoleUIListBox.cpp
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#include "ECConsoleUIListBox.h"
#include "ECConsoleUIItem.h"

#include <iostream>

class ECConsoleUIItem;

using namespace std;

ECConsoleUIListBox::ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR)
    : ECConsoleUIItem(xUL, yUL, xLR, yLR), xUL(xUL), yUL(yUL), xLR(xLR), yLR(yLR){
    indexChoice = 0;
    scrollIndex = 0;
}

void ECConsoleUIListBox::AddChoice(const std::string &text) {
    choices.push_back(text);
}

void ECConsoleUIListBox::Choose(int rIndex) {
    indexChoice = rIndex;
}

std::string ECConsoleUIListBox::GetTextAtRow(int r) const {

    if(r >= GetYUL() && r <= GetYLR()) {
        return choices[r + scrollIndex - GetYUL()];
    }

    return "";
}

int ECConsoleUIListBox::GetHighlightPosition(int &xLeft, int &xRight) const {
    if(choices.size() != 0){
        xLeft = 0;
        xRight = GetWidth()-1;
        return indexChoice - scrollIndex;
    }

    return -1;
}

void ECConsoleUIListBox::HdlKeyUp() {
    if (indexChoice > 0) {
        indexChoice -= 1;
        if (indexChoice < scrollIndex){
            scrollIndex -= 1;
        }
    }
}

void ECConsoleUIListBox::HdlKeyDown() {
    if (indexChoice < choices.size() - 1) {
        indexChoice += 1;
        if (indexChoice >= scrollIndex + GetHeight()){
            scrollIndex += 1;
        }
    }
}
