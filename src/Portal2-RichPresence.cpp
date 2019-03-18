#include "engine\iserverplugin.h"
#include "chapters.h"
#include <time.h>

#pragma warning(push)
#pragma warning(disable: 4005)
#include "discord_rpc.h"
#pragma warning(pop)

class CDiscordRichPresence : public IServerPluginCallbacks {
private:
	const char* m_pMapName;
public:
	bool Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) {
		Discord_Initialize("555440913292460034", nullptr, 1, "620"); // we don't need handlers since portal 2 doesn't really have joinable servers normally

		// assuming that we load when the game first starts up
		DiscordRichPresence rp;
		memset(&rp, 0, sizeof(rp));
		rp.details = "In Menus";
		rp.startTimestamp = time(0);
		rp.largeImageKey = "logo";
		Discord_UpdatePresence(&rp);
		return true;
	}

	void Unload() {
		Discord_Shutdown();
	}

	const char *GetPluginDescription() { return "Portal2-RichPresence, IntriguingTiles"; }

	void LevelInit(char const *pMapName) {
		m_pMapName = pMapName;
	}

	void ServerActivate(edict_t *pEdictList, int edictCount, int clientMax) {
		DiscordRichPresence rp;
		memset(&rp, 0, sizeof(rp));
		rp.state = GetChapterName(m_pMapName);
		rp.details = clientMax == 1 ? "Single Player" : "Co-op";
		rp.startTimestamp = time(0);
		rp.largeImageKey = "logo";
		rp.largeImageText = m_pMapName;
		Discord_UpdatePresence(&rp);
	}

	void LevelShutdown() {
		// i know that this happens between level changes but this is the best i can do
		DiscordRichPresence rp;
		memset(&rp, 0, sizeof(rp));
		rp.details = "In Menus";
		rp.startTimestamp = time(0);
		rp.largeImageKey = "logo";
		Discord_UpdatePresence(&rp);
	}

	void Pause() {}
	void UnPause() {}
	void GameFrame(bool simulating) {}
	void ClientActive(edict_t *pEdict) {}
	void ClientFullyConnect(edict_t *pEntity) {}
	void ClientDisconnect(edict_t *pEntity) {}
	void ClientPutInServer(edict_t *pEntity, char const *playername) {}
	void SetCommandClient(int index) {}
	void ClientSettingsChanged(edict_t *pEdict) {}
	PLUGIN_RESULT ClientConnect(bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen) { return PLUGIN_CONTINUE; }
	PLUGIN_RESULT ClientCommand(edict_t *pEntity, const CCommand &args) { return PLUGIN_CONTINUE; }
	PLUGIN_RESULT NetworkIDValidated(const char *pszUserName, const char *pszNetworkID) { return PLUGIN_CONTINUE; }
	void OnQueryCvarValueFinished(QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue) {}
	void OnEdictAllocated(edict_t *edict) {}
	void OnEdictFreed(const edict_t *edict) {}
};

CDiscordRichPresence g_Plugin;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CDiscordRichPresence, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, g_Plugin);