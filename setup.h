//---------------------------------------------------------------------------

#ifndef setupH
#define setupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmSetup : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox2;
    TShape *Shape1;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TComboBox *cmbPort;
    TComboBox *cmbBaudios;
    TComboBox *cmbData;
    TComboBox *cmbParidad;
    TComboBox *cmbStop;
    TBitBtn *BitBtn1;
    void __fastcall btnDesc1Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSetup(TComponent* Owner);
    void __fastcall mSetConnection(AnsiString COM, int BAUD, int DATA, AnsiString PARITY, AnsiString STOP);
    void __fastcall mExtractConnection(AnsiString &COM, int &BAUD, int &DATA, AnsiString &PARITY, AnsiString &STOP);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSetup *frmSetup;
//---------------------------------------------------------------------------
#endif
