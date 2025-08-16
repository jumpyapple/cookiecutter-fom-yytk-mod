#include <YYToolkit/YYTK_Shared.hpp>

using namespace Aurie;
using namespace YYTK;

static YYTK::YYTKInterface* g_ModuleInterface = nullptr;
static const char* const VERSION = "{{ cookiecutter.version }}";

EXPORTED AurieStatus ModulePreinitialize(
	IN AurieModule* Module,
	IN const fs::path& ModulePath
)
{
	UNREFERENCED_PARAMETER(Module);
	UNREFERENCED_PARAMETER(ModulePath);

	return AURIE_SUCCESS;
}

EXPORTED AurieStatus ModuleInitialize(
	IN AurieModule* Module,
	IN const fs::path& ModulePath
)
{
	UNREFERENCED_PARAMETER(Module);
	UNREFERENCED_PARAMETER(ModulePath);

	AurieStatus last_status = AURIE_SUCCESS;

	g_ModuleInterface = YYTK::GetInterface();
	if (!g_ModuleInterface)
		return AURIE_MODULE_DEPENDENCY_NOT_RESOLVED;

	g_ModuleInterface->Print(CM_LIGHTAQUA, "[{{ cookiecutter.project_slug }} %s] - Plugin starting ...", VERSION);

	g_ModuleInterface->Print(CM_LIGHTGREEN, "[{{ cookiecutter.project_slug }} %s] - Plugin started!", VERSION);

	return last_status;
}

EXPORTED AurieStatus ModuleUnload(
	IN AurieModule* Module,
	IN const fs::path& ModulePath
)
{
	UNREFERENCED_PARAMETER(Module);
	UNREFERENCED_PARAMETER(ModulePath);

	return AURIE_SUCCESS;
}