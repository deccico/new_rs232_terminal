//---------------------------------------------------------------------------

#ifndef cmdsH
#define cmdsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmTabla : public TForm
{
__published:	// IDE-managed Components
    TSpeedButton *btnCHK;
    TBitBtn *BitBtn2;
    TStringGrid *gridCMD;
    TBitBtn *BitBtn1;
    TCheckBox *chkOnTop;
    TBitBtn *BitBtn3;
    TStatusBar *StatusBar1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall gridCMDSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall btnCHKClick(TObject *Sender);
    void __fastcall chkOnTopClick(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
private:	// User declarations
    AnsiString sBuffer;   //buffer de entrada

public:		// User declarations
    __fastcall TfrmTabla(TComponent* Owner);
    void __fastcall mBuscar(AnsiString sCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTabla *frmTabla;
//---------------------------------------------------------------------------
#endif
