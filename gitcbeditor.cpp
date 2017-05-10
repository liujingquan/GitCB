#include "gitcbeditor.h"
#include "editormanager.h"

GitcbEditor::GitcbEditor()
            :geditor(nullptr)
{

}
GitcbEditor::~GitcbEditor()
{
    delete geditor;
}

bool GitcbEditor::Init()
{
    //geditor=Manager::Get()->GetEditorManager()->Open(_T("diff"),0,nullptr);

}

void GitcbEditor::Append(const wxString& text)
{

}
