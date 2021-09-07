//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <vcl\sysutils.hpp>
#include <vcl\windows.hpp>
#include <vcl\messages.hpp>
#include <vcl\sysutils.hpp>
#include <vcl\classes.hpp>
#include <vcl\graphics.hpp>
#include <vcl\controls.hpp>
#include <vcl\forms.hpp>
#include <vcl\dialogs.hpp>
#include <vcl\stdctrls.hpp>
#include <vcl\buttons.hpp>
#include <vcl\extctrls.hpp>
#include <vcl\menus.hpp>
#include <inifiles.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
const nElem=100;  //constante que define la longitud del buffer de envío de comandos 
class TfrmMain : public TForm
{
__published:   
	TMainMenu *MainMenu;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *FilePrintItem;
	TMenuItem *FilePrintSetupItem;
	TMenuItem *FileExitItem;
	TMenuItem *EditUndoItem;
	TMenuItem *EditCutItem;
	TMenuItem *EditCopyItem;
	TMenuItem *EditPasteItem;
	TMenuItem *HelpContentsItem;
	TMenuItem *HelpSearchItem;
	TMenuItem *HelpHowToUseItem;
	TMenuItem *HelpAboutItem;
	TStatusBar *StatusLine;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPrintDialog *PrintDialog;
	TPrinterSetupDialog *PrintSetupDialog;
	TPanel *SpeedBar;
    TSpeedButton *btnPlay;
    TSpeedButton *btnStop;  // &Save
	TSpeedButton *SpeedButton3;  // E&xit
	TSpeedButton *SpeedButton4;
    TMenuItem *PortManager1;
    TMenuItem *OpenPort1;
    TMenuItem *ClosePort1;
    TMenuItem *N6;
    TMenuItem *FileTransfer1;
    TMenuItem *ClearScreen1;
    TMemo *memoASCII;
    TGroupBox *GroupBox1;
    TImage *img1;
    TImage *img0;
    TShape *Shape6;
    TLabel *Label6;
    TShape *shapeTx;
    TStaticText *lCStat;
    TLabel *Label1;
    TShape *Shape1;
    TShape *shapeRx;
    TEdit *txtAscii;
    TStaticText *StaticText1;
    TEdit *txtHexa;
    TStaticText *StaticText2;
    TBitBtn *btnAscii;
    TBitBtn *btnSend;
    TTimer *TimerTx;
    TTimer *TimerRx;
    TSpeedButton *btnClear;
    TSpeedButton *btnCHK;
    TBitBtn *BitBtn1;
    TBitBtn *btnSend2;
    TSpeedButton *cmdTabla;
    TMemo *memoHEXA;
    TMenuItem *Table1;
    TMenuItem *mnuDQAT;
    TMenuItem *N5;  // &About...
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ShowHint(TObject *Sender);
	void __fastcall FileNew(TObject *Sender);
	void __fastcall FileOpen(TObject *Sender);
	void __fastcall FileSave(TObject *Sender);
	void __fastcall FileSaveAs(TObject *Sender);
	void __fastcall FilePrint(TObject *Sender);
	void __fastcall FilePrintSetup(TObject *Sender);
	void __fastcall FileExit(TObject *Sender);
	void __fastcall EditUndo(TObject *Sender);
	void __fastcall EditCut(TObject *Sender);
	void __fastcall EditCopy(TObject *Sender);
	void __fastcall EditPaste(TObject *Sender);
	void __fastcall WindowTile(TObject *Sender);
	void __fastcall WindowCascade(TObject *Sender);
	void __fastcall WindowArrange(TObject *Sender);
	void __fastcall HelpContents(TObject *Sender);
	void __fastcall HelpSearch(TObject *Sender);
	void __fastcall HelpHowToUse(TObject *Sender);
	void __fastcall HelpAbout(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall btnAsciiClick(TObject *Sender);
    void __fastcall btnSendClick(TObject *Sender);
    void __fastcall TimerTxTimer(TObject *Sender);
    void __fastcall TimerRxTimer(TObject *Sender);
    void __fastcall ClearScreen1Click(TObject *Sender);
    void __fastcall btnClearClick(TObject *Sender);
    void __fastcall btnCHKClick(TObject *Sender);
    void __fastcall cmdTablaClick(TObject *Sender);
    void __fastcall Table1Click(TObject *Sender);
    void __fastcall mnuDQATClick(TObject *Sender);

private:        // private user declarations
        //valores leidos de coord.INI.
        int BUFFER;
        int TIMEDELAY;
        int TIMEOUT;
        int SEND;

        //data to transmit
        AnsiString sData[nElem];
        int nRep[nElem];
        //Flag envío
        bool bCommand;
        bool bEnvio;



public:         // public user declarations
	virtual __fastcall TfrmMain(TComponent* Owner);

        //valores leidos de coord.INI.
        AnsiString COM;
        int BAUD;
        int DATA;
        AnsiString PARITY;
        AnsiString STOP;

        void __fastcall mDesconectar();
        void __fastcall mConectar();
        AnsiString __fastcall mChauCaracter(AnsiString sCadena,AnsiString s);
        AnsiString __fastcall mEmpaquetar(AnsiString sComando);
        bool __fastcall mSendPaq(AnsiString sPaq);
        int __fastcall mTransmitir(HANDLE hhand, int ncaracter);
        int __fastcall TfrmMain::AnsiHexToIntDec(AnsiString sN);
        AnsiString __fastcall mChecksum(AnsiString sData);
        unsigned char __fastcall TfrmMain::mAsciiar(AnsiString sData);
        AnsiString sGrilla[2][45];  //la grilla de comando de frmTabla                    
};
//---------------------------------------------------------------------------
extern TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
