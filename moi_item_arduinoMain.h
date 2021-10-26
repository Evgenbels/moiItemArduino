/***************************************************************
 * Name:      moi_item_arduinoMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-10-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MOI_ITEM_ARDUINOMAIN_H
#define MOI_ITEM_ARDUINOMAIN_H

#include "wx/msgdlg.h"

#include "moi_item_arduinoApp.h"


#include "GUIFrame.h"

class moi_item_arduinoFrame: public GUIFrame
{
    public:
        moi_item_arduinoFrame(wxFrame *frame);
        ~moi_item_arduinoFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // MOI_ITEM_ARDUINOMAIN_H
