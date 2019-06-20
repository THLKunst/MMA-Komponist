#include <wx/stattext.h>
#include "TrackParamSet.h"
#include <wx/spinctrl.h>

TrackParamSet::TrackParamSet(const wxString & title)
       : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 300))
{
	wxBoxSizer* MainBS = new wxBoxSizer(wxVERTICAL);
	// Setzen der Parameter Fläschen	
	wxPanel* DurationPanel = new wxPanel(this);
	DurationPanel->SetBackgroundColour(wxColour(0,0, 200));
	wxPanel* AmplitudePanel = new wxPanel(this);
	AmplitudePanel->SetBackgroundColour(wxColour(200, 0, 0));
	wxPanel* ComandPanel = new wxPanel(this);
	ComandPanel->SetBackgroundColour(wxColour(200,200, 0));

        MainBS->Add(DurationPanel, 1, wxEXPAND | wxALL, 0);
	MainBS->Add(AmplitudePanel, 1, wxEXPAND | wxALL, 0);
	MainBS->Add(ComandPanel, 1, wxEXPAND | wxALL, 0);

	// Setzen der Command Controls.
	wxBoxSizer* ComandBS = new wxBoxSizer(wxHORIZONTAL);
	wxButton *OkBtn = new wxButton(ComandPanel, wxID_ANY, "Ok");
	OkBtn->Bind( wxEVT_BUTTON, &TrackParamSet::OnOk, this );
	ComandBS->Add(OkBtn, 1, wxEXPAND | wxALL, 0);
	
	wxButton *CancelBtn = new wxButton(ComandPanel, wxID_ANY, "Cancel");
	CancelBtn->Bind( wxEVT_BUTTON, &TrackParamSet::OnCancel, this );
	ComandBS->Add(CancelBtn, 1, wxEXPAND | wxALL, 0);
	ComandPanel->SetSizer(ComandBS);

	// Setzen der Duration Controls
	wxBoxSizer* DurationBS = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* DurationLabel = new wxStaticText(DurationPanel, wxID_ANY, "Duration Settings ( min%, max%)");
	DurationBS->Add(DurationLabel, 1, wxEXPAND | wxALL, 0);
	wxSpinCtrl* SpinDurationMin = new wxSpinCtrl(DurationPanel);
	SpinDurationMin->SetRange(0,100);
	DurationBS->Add(SpinDurationMin, 1, wxALL, 0);
	wxSpinCtrl* SpinDurationMax = new wxSpinCtrl(DurationPanel);
	SpinDurationMax->SetRange(0,100);
	DurationBS->Add(SpinDurationMax, 1, wxALL, 0);
	DurationPanel->SetSizer(DurationBS);
	
	// Setzen der Amplitude Controls
	wxBoxSizer* AmplitudeBS = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* AmplitudeLabel = new wxStaticText(AmplitudePanel, wxID_ANY, "Amplitude Settings ( min%, max%)");
	AmplitudeBS->Add(AmplitudeLabel, 1, wxEXPAND | wxALL, 0);
	wxSpinCtrl* SpinAmplitudeMin = new wxSpinCtrl(AmplitudePanel);
	SpinAmplitudeMin->SetRange(0,100);
	AmplitudeBS->Add(SpinAmplitudeMin, 1, wxALL, 0);
	wxSpinCtrl* SpinAmplitudeMax = new wxSpinCtrl(AmplitudePanel);
	SpinAmplitudeMax->SetRange(0,100);
	AmplitudeBS->Add(SpinAmplitudeMax, 1, wxALL, 0);
	AmplitudePanel->SetSizer(AmplitudeBS);


        SetSizer(MainBS);

}

void TrackParamSet::OnOk( wxCommandEvent &evt )
{
   wxMessageBox( "This will store the Track Parameter and Close this Ecitor", "Function in Work", wxOK | wxICON_WARNING );
}

void TrackParamSet::OnCancel( wxCommandEvent &evt )
{
   wxMessageBox( "This will store the Track Parameter and Close this Ecitor", "Function in Work", wxOK | wxICON_WARNING );
}
        
