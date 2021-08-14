#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>

MYMODCFG(net.rusjj.mymod.guid, AML Mod Template, 1.0, RusJJ)

//MYMOD(net.rusjj.mymod.guid, AML Mod Template Without Config, 1.0, RusJJ)

//NEEDGAME(net.rusjj.mygame)

//BEGIN_DEPLIST()
//    ADD_DEPENDENCY_VER(net.rusjj.aml, 1.0)
//END_DEPLIST()

uintptr_t pGameLibrary = 0;
ConfigEntry* pCfgMyBestEntry;

extern "C" void OnModLoad()
{
    logger->SetTag("Mod Template");
    
    pGameLibrary = aml->GetLib("libMyGame.so");
    if(pGameLibrary)
    {
        logger->Info("MyGame mod is loaded!");
    }
    else
    {
        logger->Error("MyGame mod is not loaded :(");
    }

    pCfgMyBestEntry = cfg->Bind("mySetting", "DefaultValue is 0?", "MyUniqueSection");
    pCfgMyBestEntry->SetString("DefaultValue is unchanged");
    pCfgMyBestEntry->SetInt(1);
    cfg->Save();
}