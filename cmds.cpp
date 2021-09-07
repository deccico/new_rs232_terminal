//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cmds.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int nCol,nFila;

TfrmTabla *frmTabla;
//---------------------------------------------------------------------------
__fastcall TfrmTabla::TfrmTabla(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTabla::FormCreate(TObject *Sender)
{
    gridCMD->Cells[0][0]="COMMAND";
    gridCMD->Cells[1][0]="RESPONSE";

   for(int i=1;i<45;i++){
    frmTabla->gridCMD->Cells[0][i]=frmMain->sGrilla[0][i];
    frmTabla->gridCMD->Cells[1][i]=frmMain->sGrilla[1][i];}
}
//---------------------------------------------------------------------------
void __fastcall TfrmTabla::BitBtn2Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TfrmTabla::mBuscar(AnsiString sCode)
{
   sCode=frmMain->mChauCaracter(sCode,' ');
   int c,i,l,m;

   sBuffer=sBuffer+sCode;


   for (c=1; c < gridCMD->RowCount; c++){
        i = sBuffer.Pos(gridCMD->Cells[0][c].UpperCase());
        if (i!=0){
          if (!frmMain->mSendPaq(gridCMD->Cells[1][c]))
            throw Exception("error sending data");
          else{
            l=gridCMD->Cells[1][c].Length();  //largo de la celda
            m=sBuffer.Length();               //largo del buffer
            if (l==m)    //largo de la celda es el mismo que el buffer
                sBuffer="";
            else if (i==1)    //ocurrencia al comienzo del buffer
                sBuffer=sBuffer.SubString(l+1,m-l);
            else if (i+l-1==m) //ocurrencia en el medio hasta el final
                sBuffer=sBuffer.SubString(i,i-1);
            else if (i+l!=m) //ocurrencia en el medio hasta el medio
                sBuffer=sBuffer.SubString(1,i-1)+sBuffer.SubString(i+l,m-(i+l)+1);
          }
        }
   }

   StatusBar1->SimpleText="Buffer= "+sBuffer;
   //for (int i=1; i < gridCMD->RowCount; i++){
   //     if (gridCMD->Cells[0][i].UpperCase()==sCode){
   //       if (!frmMain->mSendPaq(gridCMD->Cells[1][i]))
   //         throw Exception("error sending data");
   //     }
   //}
}
//---------------------------------------------------------------------------
void __fastcall TfrmTabla::BitBtn1Click(TObject *Sender)
{
   for (int i=1; i < gridCMD->RowCount; i++){
        gridCMD->Cells[0][i]="";
        gridCMD->Cells[1][i]="";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfrmTabla::gridCMDSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    nCol=ACol;
    nFila=ARow;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTabla::btnCHKClick(TObject *Sender)
{
    int i=gridCMD->Cells[nCol][nFila].Length();

    if (i!=8 && i!=10)
       throw Exception("This checksum only allow 3 bytes commands");

    gridCMD->Cells[nCol][nFila]=gridCMD->Cells[nCol][nFila].SubString(1,6)
                  +frmMain->mChecksum(gridCMD->Cells[nCol][nFila].SubString(3,4))
                  +gridCMD->Cells[nCol][nFila].SubString(i-1,2);
}
//---------------------------------------------------------------------------


void __fastcall TfrmTabla::chkOnTopClick(TObject *Sender)
{
    if (chkOnTop->Checked)
        frmTabla->FormStyle=fsStayOnTop;
    else
        frmTabla->FormStyle=fsNormal;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTabla::BitBtn3Click(TObject *Sender)
{
    sBuffer="";
    StatusBar1->SimpleText="Buffer= "+sBuffer;
}
//---------------------------------------------------------------------------

