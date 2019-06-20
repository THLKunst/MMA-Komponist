#include <wx/wx.h>

class TrackParamSet : public wxDialog
{
public:
  TrackParamSet(const wxString& );
  void OnOk( wxCommandEvent &evt );
  void OnCancel( wxCommandEvent &evt );
};
