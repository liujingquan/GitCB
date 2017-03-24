#include "BranchDialog.h"

//(*InternalHeaders(BranchDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(BranchDialog)
//*)

BEGIN_EVENT_TABLE(BranchDialog,wxDialog)
	//(*EventTable(BranchDialog)
	//*)
END_EVENT_TABLE()

BranchDialog::BranchDialog(wxWindow* parent)
{
	//(*Initialize(BranchDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("BranchDialog"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Choicebook1 = (wxChoicebook*)FindWindow(XRCID("ID_CHOICEBOOK1"));
	//*)
}

BranchDialog::~BranchDialog()
{
	//(*Destroy(BranchDialog)
	//*)
}

