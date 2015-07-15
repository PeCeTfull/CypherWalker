#include "ConfigFile.h"
#include <wx/wfstream.h>
#include <wx/sstream.h>
#include <wx/intl.h>

ConfigFile::ConfigFile()
{
    //ctor
}

wxString *ConfigFile::ReadFileContents()
{
    wxString *contents = new wxString[PARAMS_AMOUNT];
    wxString content;
    wxFileInputStream file(configFileName);
    wxStringOutputStream sOutput(&content);
    sOutput.Write(file);
    sOutput.Close();

    size_t newLinePos;
    for(int i = 0; i < PARAMS_AMOUNT; i++)
    {
        newLinePos = content.Find("\r\n");
        contents[i] = content.SubString(0, newLinePos - 1);
        content = content.SubString(newLinePos + 2, content.Length());
    }

    return contents;
}

void ConfigFile::SaveFile(wxString& params)
{
    wxStringInputStream sInput(params);
    wxFileOutputStream file(configFileName);
    file.Write(sInput);
    file.Close();
}

void ConfigFile::NewFileContents()
{
    wxString params = wxT(wxString::Format(wxT("%s\r\n%s%d\r\n%s%s\r\n%s%s\r\n%s%s\r\n%s%s"), FILE_HEADER, PARAM_1, wxLANGUAGE_ENGLISH_CANADA, PARAM_2, PARAM_2_DEFAULT_VALUE, PARAM_3, PARAM_3_DEFAULT_VALUE, PARAM_4, PARAM_4_DEFAULT_VALUE, PARAM_5, PARAM_5_DEFAULT_VALUE));

    SaveFile(params);
}

void ConfigFile::WriteFileContents(wxString* paramTable)
{
    wxString params = wxT(paramTable[0] + "\r\n" + paramTable[1] + "\r\n" + paramTable[2] + "\r\n" + paramTable[3] + "\r\n" + paramTable[4] + "\r\n" + paramTable[5]);

    SaveFile(params);
}

ConfigFile::~ConfigFile()
{
    //dtor
}
