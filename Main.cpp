//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Main.h"
#include "setup.h"
#include "rx.h"
#include "about.h"
#include "cmds.h"

// GLOBAL VARIABLES
HANDLE hComm = NULL;
TRead *ReadThread;
COMMTIMEOUTS ctmoNew = {0}, ctmoOld;

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
   //build the .ini
   TIniFile *ini;

   bCommand=false;
   bEnvio=false;

   //inicializo buffer de comandos
   for (int i=0;i<nElem;i++)
    nRep[i]=0;

   ini = new TIniFile(
   ChangeFileExt( Application->ExeName, ".INI" ) );
   Top     =  ini->ReadInteger( "Form", "Top", 137 );
   Left    =  ini->ReadInteger( "Form", "Left", 190 );
   Width    =  ini->ReadInteger( "Form", "Width", 542 );
   Height    =  ini->ReadInteger( "Form", "Height", 366 );

   COM = ini->ReadString("Connection", "Com number","Com2");
   BAUD = ini->ReadInteger("Connection", "Baud Rate",9600);
   DATA = ini->ReadInteger("Connection", "Data Bits",8);
   PARITY = ini->ReadString("Connection", "Parity","N");
   STOP = ini->ReadString("Connection", "Stop Bits","1");
   SEND = ini->ReadInteger("Handshake", "Send",3000);
   //TIMEDELAY = ini->ReadInteger("Handshake", "Time Delay",350);
   for(int i=1;i<45;i++){
    sGrilla[0][i]=ini->ReadString("Command Table", "Answer "+AnsiString(i),"");
    sGrilla[1][i]=ini->ReadString("Command Table", "Question "+AnsiString(i),"");}

   delete ini;
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	Application->OnHint = ShowHint;
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::ShowHint(TObject *Sender)
{
    StatusLine->Panels->Items[2]->Text = Application->Hint;
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FileNew(TObject *Sender)
{
	//--- Add code to create a new file ---
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FileOpen(TObject *Sender)
{
    frmSetup->ShowModal();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FileSave(TObject *Sender)
{
        bEnvio=false;
        mDesconectar();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FileSaveAs(TObject *Sender)
{
	if (SaveDialog->Execute())
	{
		//--- Add code to save current file under SaveDialog->FileName ---
	}
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FilePrint(TObject *Sender)
{
	if (PrintDialog->Execute())
	{
		//---- Add code to print current file ----
	}
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FilePrintSetup(TObject *Sender)
{
	PrintSetupDialog->Execute();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::FileExit(TObject *Sender)
{
	Close();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::EditUndo(TObject *Sender)
{
	//---- Add code to perform Edit Undo ----
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::EditCut(TObject *Sender)
{
	//---- Add code to perform Edit Cut ----
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::EditCopy(TObject *Sender)
{
	//--- Add code to perform Edit Copy ----
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::EditPaste(TObject *Sender)
{
	//---- Add code to perform Edit Paste ----
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::WindowTile(TObject *Sender)
{
	Tile();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::WindowCascade(TObject *Sender)
{
	Cascade();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::WindowArrange(TObject *Sender)
{
	ArrangeIcons();
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::HelpContents(TObject *Sender)
{
	Application->HelpCommand(HELP_CONTENTS, 0);
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::HelpSearch(TObject *Sender)
{
	Application->HelpCommand(HELP_PARTIALKEY, Longint(""));
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::HelpHowToUse(TObject *Sender)
{
	Application->HelpCommand(HELP_HELPONHELP, 0);
}
//----------------------------------------------------------------------------
void __fastcall TfrmMain::HelpAbout(TObject *Sender)
{
    frmAbout->Show();
}
//----------------------------------------------------------------------------

void __fastcall TfrmMain::FormResize(TObject *Sender)
{
    int nAlto=frmMain->Height,
        nAncho=frmMain->Width,i,j;

    i = (nAlto-174) / 2;
    j = nAncho-8;

    memoASCII->Height=i;
    memoHEXA->Height=i;
    memoASCII->Width=j;
    memoHEXA->Width=j;
    memoHEXA->Top=memoASCII->Top+memoASCII->Height+7;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
     static BOOL FirstTime = TRUE;

    if (FirstTime) {             //set things according to the .ini
        FirstTime = FALSE;
        this->Top = Top;
        this->Left = Left;
        this->Width = Width;
        this->Height = Height;
        //TimeReSend->Interval = TIMEDELAY;

        frmSetup->mSetConnection(COM,BAUD,DATA,PARITY,STOP);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteInteger( "Form", "Top", Top );
   ini->WriteInteger( "Form", "Left", Left );
   ini->WriteInteger( "Form", "Width", Width );
   ini->WriteInteger( "Form", "Height", Height );

   frmSetup->mExtractConnection(COM,BAUD,DATA,PARITY,STOP);
   ini->WriteString("Connection", "Com number",COM);
   ini->WriteInteger("Connection", "Baud Rate",BAUD);
   ini->WriteInteger("Connection", "Data Bits",DATA);
   ini->WriteString("Connection", "Parity",PARITY);
   ini->WriteString("Connection", "Stop Bits",STOP);
   ini->WriteInteger("Handshake", "Send",SEND);
   //ini->WriteInteger("Handshake", "Time Delay",TIMEDELAY);

   for(int i=1;i<45;i++){
        ini->WriteString("Command Table", "Answer "+AnsiString(i),frmTabla->gridCMD->Cells[0][i]);
        ini->WriteString("Command Table", "Question "+AnsiString(i),frmTabla->gridCMD->Cells[1][i]);}

   delete ini;
   mDesconectar();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//realiza la desconección del puerto serie usado
void __fastcall TfrmMain::mDesconectar()
{
  //chequea que no se este desconectado
  if(!hComm)
         return;


  // terminar la thread
  if (ReadThread != NULL) ReadThread->Terminate();

  // CERRAR EL PUERTO SI ESTA ABIERTO
  if(hComm != INVALID_HANDLE_VALUE)
  {
    Sleep(250); // ESPERA QUE TERMINE LA THREAD
    SetCommTimeouts(hComm, &ctmoOld);
    CloseHandle(hComm);
  }
  Beep();
  img0->Visible=true;
  img1->Visible=false;
  lCStat->Caption="OFF";
  btnSend->Enabled=false;
  btnSend2->Enabled=false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Conecta con el puerto serie correspondiente
void __fastcall TfrmMain::mConectar()
{
 mDesconectar();
 DCB dcbCommPort;
 AnsiString sPuerto; //nombre del puerto a conectar
 AnsiString sParamCom,sData,sParidad; //parámetros de comunicación

// sParamCom="9600,N,8,1";

 sParidad=frmSetup->cmbParidad->Text.SubString(1,1);
 sParamCom=frmSetup->cmbBaudios->Text+","+sParidad+","+frmSetup->cmbData->Text+","+frmSetup->cmbStop->Text;


 sPuerto=frmSetup->cmbPort->Text;
 if (sPuerto.IsEmpty()){
        ShowMessage("You must select a port");
        return;}

  // ABRIR EL COMM PORT.

  hComm = CreateFile(sPuerto.c_str(),
                      GENERIC_READ | GENERIC_WRITE,
                      0,
                      0,
                      OPEN_EXISTING,
                      0,
                      0);


  // chequea si sirve el puerto
  if(hComm == INVALID_HANDLE_VALUE)
        {Beep();
         ShowMessage("Error connecting at "+sPuerto);
  //cerrar el puerto si esta abierto
	if(hComm) {
            Sleep(250); // WAIT FOR THREAD TO FINISH
            SetCommTimeouts(hComm, &ctmoOld);
    	    CloseHandle(hComm);
  }

         return;
         }

  // SETEAR LOS COMM TIMEOUTS.

  GetCommTimeouts(hComm,&ctmoOld);
  ctmoNew.ReadTotalTimeoutConstant = 100;
  ctmoNew.ReadTotalTimeoutMultiplier = 0;
  ctmoNew.WriteTotalTimeoutMultiplier = 0;
  ctmoNew.WriteTotalTimeoutConstant = 0;
  SetCommTimeouts(hComm, &ctmoNew);

  // setear parametros de comunicacion BAUD RATE, PARITY, WORD SIZE
  // y STOP BITS.
  // BuildCommDCB debe ser un puntero a STRING.
  // BuildCommDCB() DEFAULTS TO NO HANDSHAKING.

  dcbCommPort.DCBlength = sizeof(DCB);
  GetCommState(hComm, &dcbCommPort);
  BuildCommDCB(sParamCom.c_str(), &dcbCommPort);
  SetCommState(hComm, &dcbCommPort);

  // ACTIVAr la THREAD.
  // THE FALSE ARGUMENT SIMPLY MEANS IT HITS THE
  // GROUND RUNNING RATHER THAN SUSPENDED.

  ReadThread = new TRead(false);
  Beep();
  img0->Visible=false;
  img1->Visible=true;
  lCStat->Caption="ON";
  frmSetup->Close();
  btnSend->Enabled=true;
  btnSend2->Enabled=true;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//quita un caracter en el primer argumento especificado en el segundo argumento
AnsiString __fastcall TfrmMain::mChauCaracter(AnsiString sCadena,AnsiString s)
{
    AnsiString sSinBlancos;
    int i;
    i=sCadena.Length();

    for (int c=1;c<i+1;c++)
        if (sCadena.SubString(c,1)!= s)
            sSinBlancos=sSinBlancos+sCadena[c];
     return sSinBlancos;
};
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnAsciiClick(TObject *Sender)
{
  AnsiString sPaket;
  
  //empaqueto el comando
  sPaket=mEmpaquetar(txtAscii->Text);

  if (sPaket=="-1")       //error
       throw Exception("Invalid packet");

  txtHexa->Text=sPaket;

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
AnsiString __fastcall TfrmMain::mEmpaquetar(AnsiString sComando)
{
  AnsiString sTop,sCmd,sFSN;
  AnsiString sPaquete,sHeader,sTail,sProcess,s,sData;
  int nTop,msg;
  int j;
  char *c,car;

  //sComando=sComando.UpperCase(); //mayusculas
  sComando=mChauCaracter(sComando,' '); //quita blancos
  if (sComando.IsEmpty())
        return "-1";
  sData=sComando;

  s.SetLength(1);

  for (int i=1;i<=sData.Length();i++){
       s= sData.SubString(i,1);
       c= s.c_str();
       car = (char) *c;
       j=toascii(car);
       sProcess = sProcess + sProcess.IntToHex(j,2);
  }

  return sProcess;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnSendClick(TObject *Sender)
{
  if (!mSendPaq(txtHexa->Text))
    throw Exception("error sending data");
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Procesamiento y transmisión del paquete. Chequea conexión
bool __fastcall TfrmMain::mSendPaq(AnsiString sPaq)
{
        static int nSent;
        AnsiString sCmd;
        int msg;

        sPaq=mChauCaracter(sPaq,' ');
        sPaq=sPaq.UpperCase();
        for( int n=1; n <= sPaq.Length() ;n=n+2)
        {      sCmd = sPaq.SubString(n,2);
               msg = AnsiHexToIntDec(sCmd);
               if (msg == - 1)
                   {Beep();
                    ShowMessage("You must input a correct number");
                    return false;
                    }
               if ( mTransmitir(hComm,msg) < 0 )
                   {return false;}
        } //fin for

        nSent=nSent+ (sPaq.Length() / 2);
        StatusLine->Panels->Items[0]->Text = AnsiString(nSent)+" bytes sent";
        return true;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//transmite el caracter hasta que se vacie en el buffer segun
//condiciones de transmision
//pre HANDLE (puerto serie) y caracter valido
//post caracter transmitido en el puerto => return 0; o error => return < 0
int __fastcall TfrmMain::mTransmitir(HANDLE hhand, int ncaracter)
{
    int ntries=SEND; //nro de intentos de transmisión del caracter .INI
    int nresult=0; //resultado de la operacion de transmision
    AnsiString sError;

     //reemplazar por un label que indique estado de conexión
    if (!hhand)   //chequea conexión al puerto
      { Beep();
        ShowMessage("Error opening serial port");
        return -1;
       }

    while ( (nresult == 0) && (ntries != 0) )
        {ntries--;
         nresult=TransmitCommChar(hhand, ncaracter);
         if(!TimerTx->Enabled) TimerTx->Enabled=true;
         }

    if (ntries==0) sError = "Time Out";
    if (nresult == 0) sError=sError+" Byte not transmited";
    if (ntries==0 || nresult == 0)
        {Beep();
         ShowMessage(sError);
         return -2;
         }

    return 0;            //funcion terminada coorectamente
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//convierte un AnsiString con valor en hexadecimal a su valor en entero
int __fastcall TfrmMain::AnsiHexToIntDec(AnsiString sN)
{
        AnsiString scar,snum=sN;
        __int32 h,nnumero=0;
        int expo,num=0,nlong=snum.Length();

        for(int i=1;i<=nlong;i++)
        {
          scar=snum[i];
          if (scar >= '0' && scar <= '9') snum[i]='0';
          switch (snum[i])
          {
                case 'A' : num=10;break;
                case 'B' : num=11;break;
                case 'C' : num=12;break;
                case 'D' : num=13;break;
                case 'E' : num=14;break;
                case 'F' : num=15;break;
                case '0' : num=scar.ToInt();break;
          }
          expo=nlong-i;

          h=1;
          for (int v=1;v<=expo;v++){
            h=16*h;
          }
          //f=(Power(16,expo));
          //f=nnumero+num*f;
          //nnumero=f;
          nnumero = nnumero + num*h;
        }//fin For

        return nnumero;
}
//--fin AnsiIntToHex----------------------------------------------------



//enciende y apaga la luz de transmisión una vez que se
//habilita el timer
void __fastcall TfrmMain::TimerTxTimer(TObject *Sender)
{
        static bool bApagar;

        if (bApagar)
           { shapeTx->Brush->Color=clWhite;
             bApagar=false;
             TimerTx->Enabled=false; }
        else
           { shapeTx->Brush->Color=clLime;
             bApagar=true;  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::TimerRxTimer(TObject *Sender)
{
        static bool bApagar;

        if (bApagar)
           { shapeRx->Brush->Color=clWhite;
             bApagar=false;
             TimerRx->Enabled=false; }
        else
           {  shapeRx->Brush->Color=clLime;
              bApagar=true;  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ClearScreen1Click(TObject *Sender)
{
    memoASCII->Clear();
    memoHEXA->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClearClick(TObject *Sender)
{
    memoASCII->Clear();
    memoHEXA->Clear();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//Calcula el checksum de la cadena haciendo un XOR de todos los bits recibidos
AnsiString __fastcall TfrmMain::mChecksum(AnsiString sData)
{
    AnsiString s, sLow, sHigh;
    unsigned char nAscii,nT,nHigh,nLow;
    char cHigh,cLow;

    for (int i=1; i < sData.Length()+1; i=i+2){
        s= sData.SubString(i,2);
        nAscii=mAsciiar(s);
        if (i!=1)
            nT=nAscii^nT;  //xor 
        else
            nT=nAscii;     //1era vez
    }


    //expando los bits
    nHigh = (nT / 0x10);
    nLow = (nT & 0x0F);

    if (nHigh > 0x09)
        nHigh=nHigh+55;
    else
        nHigh=nHigh+48;
    if (nLow > 0x09)
        nLow=nLow+55;
    else
        nLow=nLow+48;

    cHigh=nHigh;
    cLow=nLow;
    sHigh = cHigh;
    sLow = cLow;

    return sHigh+sLow;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnCHKClick(TObject *Sender)
{
    int i=txtHexa->Text.Length();

    if (i!=8 && i!=10)
       throw Exception("This checksum only allow 3 bytes commands");

    txtHexa->Text=txtHexa->Text.SubString(1,6)
                  +mChecksum(txtHexa->Text.SubString(3,4))
                  +txtHexa->Text.SubString(i-1,2);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
unsigned char __fastcall TfrmMain::mAsciiar(AnsiString sData)
{
    unsigned char nAscii;
    AnsiString s;

    s=sData.SubString(1,1);

    if (s>='0' && s<= '9')
        nAscii = (s.ToInt() * 16);
    else{
        if (s=='A')
             nAscii=10*16;
        else if (s=='B')
             nAscii=11*16;
        else if (s=='C')
             nAscii=12*16;
        else if (s=='D')
             nAscii=13*16;
        else if (s=='E')
             nAscii=14*16;
        else if (s=='F')
             nAscii=15*16;
    }

    s = sData.SubString(2,1);

    if (s >= '0' && s <= '9')
        nAscii = nAscii + s.ToInt();
    else{
        if (s=='A')
             nAscii = nAscii + 10;
        else if (s=='B')
             nAscii = nAscii + 11;
        else if (s=='C')
             nAscii = nAscii + 12;
        else if (s=='D')
             nAscii = nAscii + 13;
        else if (s=='E')
             nAscii = nAscii + 14;
        else if (s=='F')
             nAscii = nAscii + 15;
    }

    return nAscii;

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::cmdTablaClick(TObject *Sender)
{
    frmTabla->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Table1Click(TObject *Sender)
{
    cmdTablaClick(NULL);    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuDQATClick(TObject *Sender)
{
    mnuDQAT->Checked = !mnuDQAT->Checked;
}
//---------------------------------------------------------------------------

