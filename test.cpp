// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/notebook.h>
#include <wx/colour.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include "TrackControl.h"


class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxPanel* TrackBuket;
    wxBoxSizer* TrackSizer;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButtonGenerate(wxCommandEvent& event);
    void OnButtonNewTrack(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1,
    ID_Generate = 2,
    ID_InstruGrid = 3,
    ID_NeueSpur = 4,
    ID_Test = 5
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(ID_Generate, MyFrame::OnButtonGenerate)
    EVT_BUTTON(ID_NeueSpur, MyFrame::OnButtonNewTrack)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Das kleine Precomposer Programm", wxPoint(50, 50), wxSize(500, 800) );
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Generate PreComposition...\tCtrl-G",
                     "Default Operation");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to CreCos PreComposer!" );

    // Main Notebook
    wxNotebook *myNotebook =  new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxSize(500, 800), wxNB_MULTILINE );

   // Excludieren der wxNotebokkPages
   // Anlegen der Panels
   wxPanel* SpurParamOver = new wxPanel(myNotebook);
   wxPanel* InstrumentOver = new wxPanel(myNotebook);
   wxPanel* GenerateOver = new wxPanel(myNotebook);

   // Setzen der Panel Farben
   SpurParamOver->SetBackgroundColour(wxColour(1,1,1));
   InstrumentOver->SetBackgroundColour(wxColour(1,1,200));
   GenerateOver->SetBackgroundColour(wxColour(200,1,1));

   // Erstellen des Generator Panels
   // Anlegen des Panels Iteration


   // Anlegen Panel für Generate:Lange
   wxPanel* PanGenerateLange = new wxPanel(GenerateOver);
	
   // Anlegen Panel für Generate:Iteration
   wxPanel* PanGenerateIteration = new wxPanel(GenerateOver);

   // Anlegen der BoxSizer
   wxBoxSizer *BSLange = new wxBoxSizer(wxHORIZONTAL);
   wxStaticText *BeschriftLange = new wxStaticText(PanGenerateLange, -1, "Anzahl der zu erreichenden Bars(Takte)"); 
   BSLange->Add(BeschriftLange , 1, wxALL, 8);
   wxSpinCtrl *SpinLange = new wxSpinCtrl(PanGenerateLange);   
   SpinLange->SetRange(1,800);
   BSLange->Add(SpinLange, 1, wxALL, 8);
   PanGenerateLange->SetSizer(BSLange);
   PanGenerateLange->SetBackgroundColour(wxColour(200,200,1));

   wxBoxSizer *BSIteration = new wxBoxSizer(wxHORIZONTAL);
   // Erzeugung der Iteration Einstellung
   wxStaticText *BeschriftIteration = new wxStaticText(PanGenerateIteration, -1, "Anzahl der maximalen Iterationen"); 
   BSIteration->Add(BeschriftIteration , 1, wxALL, 8);
   wxSpinCtrl *SpinIteration = new wxSpinCtrl(PanGenerateIteration);   
   SpinIteration->SetRange(1, 10000);
   BSIteration->Add(SpinIteration, 1, wxALL, 8);
   PanGenerateIteration->SetSizer(BSIteration);
   PanGenerateIteration->SetBackgroundColour(wxColour(200,1,200));
   	
   // Defineren des Generate Buttons
   wxButton *GenerPreComp = new wxButton(GenerateOver, ID_Generate, "Generiere PreComposition" );

   // Integrieren der BoxSizer
   wxBoxSizer *BSGenerate = new wxBoxSizer(wxVERTICAL);
   BSGenerate->Add(PanGenerateLange, 1, wxEXPAND | wxALL, 8);
   BSGenerate->Add(PanGenerateIteration, 1, wxEXPAND | wxALL, 8);
   BSGenerate->Add(GenerPreComp, 0.5, wxEXPAND | wxALL, 8);
   GenerateOver->SetSizer(BSGenerate);

   // Einfügen der Panels ins Notebook
   myNotebook->AddPage( SpurParamOver, L"Spur Parameter Übersicht" );
   myNotebook->AddPage( InstrumentOver, L"Instrumenten Übersicht" );
   myNotebook->AddPage( GenerateOver, L"Generator" );

   // Erstellen des Instrument Panels InstrumentOver 
   // Anlegen eines passenden BoxSizers 
   wxBoxSizer *BSInstrum = new wxBoxSizer(wxVERTICAL);
   wxGrid* InstrumentGrid = new wxGrid(InstrumentOver, ID_InstruGrid);
   BSInstrum->Add(InstrumentGrid,  1, wxEXPAND | wxALL, 8);
   InstrumentOver->SetSizer(BSInstrum);
   InstrumentGrid->CreateGrid(16,1);
   InstrumentGrid->SetColLabelValue(0, "Spur-Name");
   InstrumentGrid->SetColSize( 0, 400 );
   // Ausprobieren eines Cell Editors
   wxString strChoices[3] = {"one", "two", "three"};
   for(int x = 0; x<16; x++)
   {
	InstrumentGrid->SetCellEditor( x,0, new wxGridCellChoiceEditor(3, strChoices));
   }

   // Setzen des Rahmens des Spur Setzers 
   wxBoxSizer *BSSpur = new wxBoxSizer(wxVERTICAL);
   wxButton *NewTrack = new wxButton(SpurParamOver, ID_NeueSpur, "Erzeuge Neue Spur"); 
   BSSpur->Add(NewTrack, 0,  wxEXPAND | wxALL, 8);
   this->TrackBuket = new wxPanel(SpurParamOver);
   BSSpur->Add(this->TrackBuket, 1, wxEXPAND | wxALL, 0);
   SpurParamOver->SetSizer(BSSpur);
   this->TrackSizer = new wxBoxSizer(wxVERTICAL);
   this->TrackBuket->SetSizer(this->TrackSizer);
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is the growing CreCo PreComposer",
                  "About CreCo PreComposer", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("This will Produce the PreComposition");
}

void MyFrame::OnButtonGenerate(wxCommandEvent& event)
{
    wxMessageBox( "This will start the Generating of the PreComposition", "Function in Work", wxOK | wxICON_WARNING );
}
void MyFrame::OnButtonNewTrack(wxCommandEvent& event)
{
    wxMessageBox( "This will create a New Track Item", "Function in Work", wxOK | wxICON_WARNING );
    TrackControl* TrackCon1 = new TrackControl(this->TrackBuket, wxID_ANY);
    this->TrackSizer->Add(TrackCon1, 1,  wxALL, 8);
    this->TrackBuket->Layout();
}
