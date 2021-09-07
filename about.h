//----------------------------------------------------------------------------
#ifndef aboutH
#define aboutH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TfrmAbout : public TForm
{
__published:
	TPanel *Panel1;
	TLabel *ProductName;
	TLabel *Copyright;
        TButton *btnOk;
        TImage *Image2;
        TBevel *Bevel1;
    TLabel *Comments;
    TLabel *Label2;
    TLabel *Label3;
        void __fastcall btnOkClick(TObject *Sender);
        void __fastcall Label3Click(TObject *Sender);
        void __fastcall CommentsClick(TObject *Sender);
private:
public:
	virtual __fastcall TfrmAbout(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TfrmAbout *frmAbout;
//----------------------------------------------------------------------------
#endif    
