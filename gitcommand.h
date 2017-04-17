/****************************************************************************
this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, print output and add command
*****************************************************************************/
#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include<wx/wxprec.h>
#include<loggers.h>
#ifndef WX_PRECOMP
    #include<wx/wx.h>
#endif // WX_PRECOMP

class wxProcess;               //forward declaration
class GitCommand
{
    public:
    GitCommand();              //constructor
    ~GitCommand();             //destructor

    static GitCommand* GetCommand();
    bool valid_command();
/**
Execut command and print message to wxText
*/
    int  Execute        (const wxString& command,wxTextCtrl* text);
/**
the overload version of Execute(),only Execute command
*/
    int Execute         (const wxString& command);
/**
some command function,
*/
    void commit         (const wxString& commit_message);
    void add            (const wxString& filename);
    void clone          (const wxString& link);
    void rm             (const wxString& filename);
    void config         (const wxString& name,const wxString& e_mail);
    void push           (const wxString& remotebranch);
/**
print message to log
*/
    void logmessage   (TextCtrlLogger* logger,int slot);
    void Diff();
    void patch();
    void init();
    void pull();

    private:
    wxProcess* process;
    friend class CommitmDialog;
    friend class CloneDialog;
    friend class BranchDialog;

};

#endif // GITCOMMAND_H





