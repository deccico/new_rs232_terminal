//recepción y procesamiento del paquete de datos desde el
//equipo remoto. Se comunica con tx para acciones consecuentes
//a la recepción de paquetes. Como en los acknowledges donde
//tx envia el paquete y rx recibe el acknowledge a la vez que
//avisa a tx quien re-enviara el paquete hasta recibir el aviso
//del acknowledge
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <time.h>
#include <stdio.h>
#include <dos.h>
#pragma hdrstop

#include "rx.h"
#include "Main.h"
#include "cmds.h"

extern HANDLE hComm;
const int maxint = 150; //cte del nro de elementos del buffer .INI
int nSize;
char InBuff[maxint];

//---------------------------------------------------------------------------
__fastcall TRead::TRead(bool CreateSuspended)
	: TThread(CreateSuspended)
{

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TRead::mProcesar()
{
  int i=0,InCode;
  AnsiString sCode,sAux,sText;

  //enciende luz de recepción
  if (!frmMain->TimerRx->Enabled) frmMain->TimerRx->Enabled=true;

  //prepara el string del paquete
    while (i<nSize)
    {     if (InBuff[i] == '\0')
            sText=sText+"0";
          else
            sText=sText+InBuff[i];
          i++;
    }

  //imprime los caracteres enviados
  frmMain->memoASCII->SetSelTextBuf(sText.c_str());

  i=1;
  while (i<sText.Length()+1)   //hasta fin de string
   {    if (sText[i] == '0'){
            if (InBuff[i-1]==0x00)
                InCode=0;
            else
            if (InBuff[i-1]==0x30)
                InCode=48;
        }
        else
            InCode=sText[i];

        sAux=sAux.IntToHex(InCode,2);
         //toma los caracteres correctos del ASCII extendido (2 ultimos)
        if (sAux.Length() > 2)
            sAux=sAux.SubString(sAux.Length()-1,2);
        sCode=sCode+sAux+" ";
        i++;
   }

   //actualiza output code buffer
   if (!frmMain->mnuDQAT->Checked)
       frmTabla->mBuscar(sCode);
   frmMain->memoHEXA->SetSelTextBuf(sCode.c_str());


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TRead::Execute()
{
	//thread code
  static int nRead;
  DWORD dwBytesRead;

  // destruye el objeto thread automat. cuando la thread termina

  FreeOnTerminate = true;

  while(1)
  {
    // CHEQUEA SI HAY CARACTERES EN EL BUFFER
    // TERMINA CUANDO SE DESTRUYE LA THREAD

    if(Terminated) return;

    ReadFile(hComm, InBuff, 110, &dwBytesRead, NULL);
    if(dwBytesRead)
    {
      nSize=dwBytesRead;
      InBuff[dwBytesRead] = 0; // NULL TERMINATE THE STRING
      Synchronize(mProcesar);
      for (int i=0;i<nSize;i++){
        InBuff[i]='\0';}
        nRead=nRead+nSize;
        frmMain->StatusLine->Panels->Items[1]->Text = AnsiString(nRead)+" bytes read";
    }
  }

}
//---------------------------------------------------------------------------


