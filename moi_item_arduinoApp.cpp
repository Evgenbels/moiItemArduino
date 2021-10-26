/***************************************************************
 * Name:      moi_item_arduinoApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-10-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "moi_item_arduinoApp.h"
#include "moi_item_arduinoMain.h"

IMPLEMENT_APP(moi_item_arduinoApp);

bool moi_item_arduinoApp::OnInit()
{
    moi_item_arduinoFrame* frame = new moi_item_arduinoFrame(0L);
    
    frame->Show();
    
    return true;
}
