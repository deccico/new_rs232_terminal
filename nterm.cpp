//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("nterm.res");
USEFORM("Main.cpp", frmMain);
USEFORM("setup.cpp", frmSetup);
USEUNIT("rx.cpp");
USEUNIT("rx.cpp");
USEFORM("about.cpp", frmAbout);
USE("nterm.todo", ToDo);
USEFORM("cmds.cpp", frmTabla);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->CreateForm(__classid(TfrmTabla), &frmTabla);
         Application->CreateForm(__classid(TfrmSetup), &frmSetup);
         Application->CreateForm(__classid(TfrmAbout), &frmAbout);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
