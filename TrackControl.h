#ifndef TRACKcONTROLL_H
#define TRACKcONTROLL_H

#include <wx/wx.h>

class  TrackControl: public wxPanel
{
public:
  TrackControl(wxPanel *parent, int id );

  wxPanel *m_parent;


  void OnSize(wxSizeEvent& event);
  void OnPaint(wxPaintEvent& event); 
  void OnEdit( wxCommandEvent &evt );
  void OnDelete( wxCommandEvent &evt );
private: 

};

#endif

