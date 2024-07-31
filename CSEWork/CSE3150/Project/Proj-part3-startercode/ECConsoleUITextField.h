//
//  ECConsoleUITextField.h
//  
//
//  Created by Yufeng Wu on 5/24/23.
//

#ifndef ECConsoleUITextField_h
#define ECConsoleUITextField_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
class ECTextViewImp;

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUITextField : public ECConsoleUIItem
{
public:
    // specifiy the starting point of the text field
    ECConsoleUITextField(ECTextViewImp *pTextView, int xpos, int ypos, int len);
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const;

    // Are there any other function you might need to override?

    bool IsHandlingKeys() const { return true; }
    bool CanEdit() const { return canEdit; }

    void HdlKeyEnter();          // Handle the Enter key
    void HdlBackspaceKey();      // Handle the Backspace key
    void HdlOtherKey();
    
private:
    ECTextViewImp *pTextView;    // Pointer to the text view
    int length;                 // Length of the text field
    std::string text;           // Text in the text field
    int xUL, yUL;               // Upper left corner of the text field
    bool canEdit;
};

#endif /* ECConsoleUITextField_h */
