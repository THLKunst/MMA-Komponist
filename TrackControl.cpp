#include <wx/wx.h>
#include "TrackControl.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include "TrackParamSet.h"


TrackControl::TrackControl(wxPanel *parent, int id)
      : wxPanel(parent, id, wxDefaultPosition, wxSize(400, 70))
{
 
  m_parent = parent;

  // you shouldn't have an empty paint event handler
  // at the very least you need to create a wxPaintDC in it
  // Connect(wxEVT_PAINT, wxPaintEventHandler(TrackControl::OnPaint));
  Connect(wxEVT_SIZE, wxSizeEventHandler(TrackControl::OnSize));

  // wxPanel* MyBigPanel = new wxPanel(m_parent, wxID_ANY,  wxPoint(10, 10), wxSize(450, 70));
  // MyBigPanel->SetBackgroundColour(wxColour(100, 100, 50));
  SetBackgroundColour(wxColour(100, 100, 50));

  wxBoxSizer* MyBigBS = new wxBoxSizer(wxHORIZONTAL);

  wxPanel* TrackAmp = new wxPanel(this);
  TrackAmp->SetBackgroundColour(wxColour(100, 100, 20));
  MyBigBS->Add(TrackAmp, 1, wxEXPAND | wxALL, 0);
  
  wxPanel* TrackPitch = new wxPanel(this);
  TrackPitch->SetBackgroundColour(wxColour(100, 100, 70));
  MyBigBS->Add(TrackPitch, 1, wxEXPAND | wxALL, 0);
  
  wxButton *EditTrack = new wxButton(this, wxID_ANY, "Edit");
  EditTrack->Bind( wxEVT_BUTTON, &TrackControl::OnEdit, this );
  MyBigBS->Add(EditTrack, 1, wxEXPAND | wxALL, 0);
  
  wxButton *DeleteTrack = new wxButton(this, wxID_ANY, "Delete");
  DeleteTrack->Bind( wxEVT_BUTTON, &TrackControl::OnDelete, this );
  MyBigBS->Add(DeleteTrack, 1, wxEXPAND | wxALL, 0);
  
  wxTextCtrl* TrackName = new wxTextCtrl(this, wxID_ANY);
  MyBigBS->Add(TrackName, 1, wxEXPAND | wxALL, 0);

  SetSizer(MyBigBS);
}

void TrackControl::OnPaint(wxPaintEvent& event)
{
  wxPaintDC dc(this);
}

void TrackControl::OnSize(wxSizeEvent& event)
{
  event.Skip();
  Refresh();
}

void TrackControl::OnEdit( wxCommandEvent &evt )
{
   wxMessageBox( "This will start the Option to Edit the Track", "Function in Work", wxOK | wxICON_WARNING );
   TrackParamSet* EditDialog = new TrackParamSet("Parameter Editor");
   EditDialog->ShowModal();
}
void TrackControl::OnDelete( wxCommandEvent &evt )
{
   wxMessageBox( "This will start the Option to Cancel the Edit of this Track", "Function in Work", wxOK | wxICON_WARNING );
}
