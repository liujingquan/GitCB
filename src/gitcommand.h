/*this file is a part of gitcb plugin ,all the command are packaged in a class,
use the method can easily call the command function, and add command for future
*/
#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include<wx/wxprec.h>

#ifndef WX_PRECOMP
    #include<wx/wx.h>
#endif // WX_PRECOMP

class GitCommand
{
    public:
    GitCommand();
    ~GitCommand();
    void Execute();                 //execute the command
    static GitCommand* GetCommand();//use the pointer to get the command
/*all command function
*/
    void commit();
    void clone();
    void config();


    private:



};




#endif // GITCOMMAND_H





