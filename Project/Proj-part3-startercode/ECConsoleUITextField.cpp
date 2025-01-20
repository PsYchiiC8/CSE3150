//
//  ECConsoleUITextField.cpp
//  
//
//  Created by Yufeng Wu on 5/24/23.
//

#include "ECConsoleUITextField.h"
#include "ECTextViewImp.h"

using namespace std;

#include <iostream>

ECConsoleUITextField::ECConsoleUITextField(ECTextViewImp *pTextView, int xpos, int ypos, int len)
    : ECConsoleUIItem(xpos, ypos, xpos + len - 1, ypos), pTextView(pTextView), length(len), text(": Your name here!"), canEdit(false) {
        pTextView->SetCursorY(ypos);
}

std::string ECConsoleUITextField::GetTextAtRow(int r) const {
    if(r == GetYUL()) {
        return text;
    }

    return "";
}

int ECConsoleUITextField::GetHighlightPosition(int &xLeft, int &xRight) const {
    if (text.size() >= 2) {
        xLeft = 0;
        xRight = GetXUL() + text.size();
        if(CanEdit()){
            pTextView->SetCursorX(xRight);
        }
        return GetXLR();
    }
    return -1;
}

void ECConsoleUITextField::HdlKeyEnter() {
    canEdit = true;
    pTextView->SetCursorX(GetXUL());
    pTextView->SetCursorY(GetYUL());
    if(text == ": Your name here!"){
        text.clear();
        text = ": ";
    }
}

void ECConsoleUITextField::HdlBackspaceKey() {
    if (text.size() > 2 && CanEdit()) {
        text.pop_back();
    }
}

void ECConsoleUITextField::HdlOtherKey() {
    if (CanEdit()) {
        if(pTextView->GetPressedKey() == BACKSPACE) {
            HdlBackspaceKey();
        } else if (pTextView->GetPressedKey() == CTRL_C){
            canEdit = false;
        } else{
            text.push_back(pTextView->GetPressedKey());
        }
    }
}
