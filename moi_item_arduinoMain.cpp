/***************************************************************
 * Name:      moi_item_arduinoMain.cpp
 * Purpose:   Code for Application Frame
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

#include "moi_item_arduinoMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


moi_item_arduinoFrame::moi_item_arduinoFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
Maximize(true);

fConfig=new wxConfig("sklad_pc");
fConfig->SetPath("/Main");
zakl=fConfig->ReadLong("ZAKL",2);
//sfsiz=fConfig->ReadLong("SFSIZ",10);
delete fConfig;

m_notebook1->SetSelection(zakl);

CA=new wxGridCellAttr();
CA1=new wxGridCellAttr();
CA2=new wxGridCellAttr();
CA->SetAlignment(wxALIGN_LEFT,wxALIGN_CENTER_VERTICAL);
CA->SetReadOnly();
CA1->SetAlignment(wxALIGN_CENTER,wxALIGN_CENTER_VERTICAL);
CA1->SetReadOnly();
CA2->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTER_VERTICAL);
CA2->SetReadOnly();

m_grid1->SetColAttr(0,CA1);
m_grid1->SetColAttr(1,CA);
m_grid1->SetColAttr(2,CA2);
//m_grid1->SetColAttr(3,CA2);
//m_grid1->SetColAttr(4,CA2);
//m_grid1->SetColAttr(5,CA2);

m_grid1->SetColLabelValue(0,"ID");
m_grid1->SetColLabelValue(1,L"Тип");
m_grid1->SetColLabelValue(2,L"Наименование");
m_grid1->SetColLabelValue(3,L"Кол-во");
m_grid1->SetColLabelValue(4,L"Интерфейс");
m_grid1->SetColLabelValue(5,L"Маркировка");
m_grid1->SetColLabelValue(6,L"Прим");
m_grid1->SetColSize(0,40);
m_grid1->SetColSize(1,40);
m_grid1->SetColSize(2,250);
m_grid1->SetColSize(3,50);
m_grid1->SetColSize(4,80);
m_grid1->SetColSize(5,100);
m_grid1->SetColSize(6,50);
m_grid1->SetRowLabelSize(40);

//m_grid1->ClearGrid();

m_grid1->SetCellValue("12345678",0,0);
m_grid1->SetCellValue(L"Yfbvtyjdfybt Наименование 12345678",0,1);
m_grid1->SetCellValue("123456.78",0,2);
m_grid1->SetCellValue("123456.78",0,3);
m_grid1->SetCellValue("123456.78",0,4);
m_grid1->SetCellValue("123456.78",0,5);

}

moi_item_arduinoFrame::~moi_item_arduinoFrame()
{
zakl=m_notebook1->GetSelection();
fConfig=new wxConfig("sklad_pc");
fConfig->SetPath("/Main");
fConfig->Write("ZAKL",zakl);
//sfsiz=fConfig->ReadLong("SFSIZ",10);
delete fConfig;
}

void moi_item_arduinoFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void moi_item_arduinoFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void moi_item_arduinoFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to...1"));
}
