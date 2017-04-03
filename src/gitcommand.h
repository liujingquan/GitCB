/****************************************************************************
this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, and add command for future
*****************************************************************************/
#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include "GitCB.h"
#include<wx/wxprec.h>

#ifndef WX_PRECOMP
    #include<wx/wx.h>
#endif // WX_PRECOMP

class GitCB;  //declaration
class GitCommand
{
    public:
    GitCommand();                   //constructor
    ~GitCommand();                  //destructor
//execute the command,but not sure on linux
    void Execute(const wxString& command,const wxString& comment);
    bool valid_command();
    static GitCommand* GetCommand();//use the pointer to get the command
/********************
all command function
********************/
    void commit(const wxString& commit_message);
    void init();
    void add(const wxString& filename);
    void clone(const wxString& link);
    void config(const wxString& name,const wxString& e_mail);
    void Diff();
    void push();
    wxString status();
    private:
    GitCB a;
   // wxArrayString output;
    //wxArrayString error;




};

#endif // GITCOMMAND_H





