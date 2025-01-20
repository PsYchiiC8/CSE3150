//
//  ECConsoleUIButton.h
//  
//
//  Created by Yufeng Wu on 3/6/24.
//

#ifndef ECConsoleUISearchButton_h
#define ECConsoleUISearchButton_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
#include "ECConsoleUIButton.h"
#include "ECAirlineSimulator.h"

#include "ECConsoleUIListBox.h"
#include "ECConsoleUIView.h"


//*****************************************************************************
// Console UI button: with a text and can be clicked

class ECConsoleUISearchButton : public ECConsoleUIButton
{
public:
    // specifiy the portion of the view for this button and the text
    ECConsoleUISearchButton(int xUL, int yUL, int xLR, int yLR, const std::string &textButton, ECAirlineSimulator *sim, ECConsoleUIListBox *origin, ECConsoleUIListBox *destinations, ECConsoleUIListBox *flights, ECConsoleUIView *viewTest);

    // Get position info
    int GetYUL() const { return ECConsoleUIItem::GetYUL()-1; }
    int GetYLR() const { return ECConsoleUIItem::GetYLR()+1; }
    int GetHeight() const { return GetYLR()-GetYUL()+1; }

    // Get displayed text at a specific row (absolute row in the screen/view sense; not specific to the item)
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    std::string GetTextAtRow(int r) const;

    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    int GetHighlightPosition(int &xLeft, int &xRight) const;
    
    // Handle up key
    // Is responding to keys? YES: button handles keys!
    bool IsHandlingKeys() const { return true; }
    // Handle enter key
    void HdlKeyEnter();
    
private:
    std::string strButton;

    ECAirlineSimulator *sim;
    ECConsoleUIListBox *origin;
    ECConsoleUIListBox *destinations;
    ECConsoleUIListBox *flights;
    ECConsoleUIView *viewTest;
};

#endif /* ECConsoleUIButton_h */
