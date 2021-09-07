//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "setup.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSetup *frmSetup;
//---------------------------------------------------------------------------
__fastcall TfrmSetup::TfrmSetup(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TfrmSetup::btnDesc1Click(TObject *Sender)
{
    frmMain->mDesconectar();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSetup::BitBtn1Click(TObject *Sender)
{
    frmMain->mConectar();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//establece los controles de conexión de acuerdo a los parámetros del ini
void __fastcall TfrmSetup::mSetConnection(AnsiString COM, int BAUD, int DATA, AnsiString PARITY, AnsiString STOP)
{
    int i;

    //COM
    for (cmbPort->ItemIndex=0,i=0; i < cmbPort->Items->Count; i++){
        if (cmbPort->Text == AnsiString(COM))
            break;
        cmbPort->ItemIndex++;
    }
    if (cmbPort->Text != AnsiString(COM))
        cmbPort->ItemIndex=1;  //valor por defecto en caso de error

    //BAUDIO
    for (cmbBaudios->ItemIndex=0,i=0; i < cmbBaudios->Items->Count; i++){
        if (cmbBaudios->Text == AnsiString(BAUD))
            break;
        cmbBaudios->ItemIndex++;
    }
    if (frmMain->mChauCaracter(cmbBaudios->Text,' ') != AnsiString(BAUD))
        cmbBaudios->ItemIndex=6;  //valor por defecto en caso de error

    //Data Bits
    for (cmbData->ItemIndex=0,i=0; i < cmbData->Items->Count; i++){
        if (cmbData->Text == AnsiString(DATA))
            break;
        cmbData->ItemIndex++;
    }
    if (cmbData->Text != AnsiString(DATA))
        cmbData->ItemIndex=3;  //valor por defecto en caso de error

    //Paridad
    for (cmbParidad->ItemIndex=0,i=0; i < cmbParidad->Items->Count; i++){
        if (cmbParidad->Text == PARITY)
            break;
        cmbParidad->ItemIndex++;
    }
    if (cmbParidad->Text != PARITY)
        cmbParidad->ItemIndex=0;  //valor por defecto en caso de error

    //sTOP
    for (cmbStop->ItemIndex=0,i=0; i < cmbStop->Items->Count; i++){
        if (cmbStop->Text == AnsiString(STOP))
            break;
        cmbStop->ItemIndex++;
    }
    if (cmbStop->Text != AnsiString(STOP))
        cmbStop->ItemIndex=2;  //valor por defecto en caso de error

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//establece los parámetros de conexión a ser grabados en el ini para que se correspondan con los controles
void __fastcall TfrmSetup::mExtractConnection(AnsiString &COM,int &BAUD,int &DATA,AnsiString &PARITY,AnsiString &STOP)
{
    COM=cmbPort->Text;
    BAUD=frmMain->mChauCaracter(cmbBaudios->Text,' ').ToInt();
    DATA=cmbData->Text.ToInt();
    PARITY=cmbParidad->Text;
    STOP=cmbStop->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSetup::FormCreate(TObject *Sender)
{
    // frmSetup->mSetConnection(frmComm->COM,frmComm->BAUD,frmComm->DATA,frmComm->PARITY,frmComm->STOP);    
}
//---------------------------------------------------------------------------

