#ifndef rxH
#define rxH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
//---------------------------------------------------------------------------
class TRead : public TThread
{
private:
  AnsiString sComando;    //descripción del comando que se espera recibir

protected:
  void __fastcall Execute();
    //procesa el buffer recibido
  void __fastcall mProcesar(void);
    //chequea si el comando recibido es de inicialización de handshake

public:
	__fastcall TRead(bool CreateSuspended);


};
//---------------------------------------------------------------------------
#endif
