//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "about.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TfrmAbout *frmAbout;
//--------------------------------------------------------------------- 
__fastcall TfrmAbout::TfrmAbout(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TfrmAbout::btnOkClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TfrmAbout::Label3Click(TObject *Sender)
{
        ShellExecute(Handle,"open","mailto:ikis@gmx.net",
        NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TfrmAbout::CommentsClick(TObject *Sender)
{
        ShellExecute(Handle,"open","http://adrian.org.ar",
             NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

