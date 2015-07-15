#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <wx/string.h>

#define PARAMS_AMOUNT 6 // 5 + 1 for the header
#define FILE_HEADER "[Cypher Walker]"
#define PARAM_1 "LanguageID=" // default value is wxLANGUAGE_ENGLISH_CANADA
#define PARAM_2 "NewGameSoundFileName="
#define PARAM_2_DEFAULT_VALUE "greets.wav"
#define PARAM_3 "MakingMoveSoundFileName="
#define PARAM_3_DEFAULT_VALUE "movement.wav"
#define PARAM_4 "LostGameSoundFileName="
#define PARAM_4_DEFAULT_VALUE "gameover.wav"
#define PARAM_5 "NewHiScoreSoundFileName="
#define PARAM_5_DEFAULT_VALUE "newname.wav"


class ConfigFile
{
    public:
        ConfigFile();
        wxString *ReadFileContents();
        void NewFileContents();
        void WriteFileContents(wxString* paramTable);
        virtual ~ConfigFile();
        const wxString configFileName = wxT("config.ini");
    protected:
    private:
        void SaveFile(wxString& params);
};

#endif // CONFIGFILE_H
