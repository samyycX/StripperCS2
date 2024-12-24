/**
* ============================================================================ =
* StripperCS2
* Copyright(C) 2023 - 2024 Source2ZE
* ============================================================================ =
*
*This program is free software; you can redistribute it and /or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.If not, see < http://www.gnu.org/licenses/>.
*/

#pragma once

#include <funchook.h>
#include <utlstring.h>

namespace Hook
{

class IWorldRendererMgr;

class CSingleWorldRep
{
private:
	void* vtable;
public:
	CUtlString m_name;
	char pad[0x20];
	void* m_pCWorld;
};

typedef int (*CreateWorldInternal_t)(IWorldRendererMgr* pThis, CSingleWorldRep* singleWorld);
inline CreateWorldInternal_t g_pCreateWorldInternal = nullptr;
inline funchook_t* g_pHook = nullptr;

void Detour_WorldInit(IWorldRendererMgr* pThis, CSingleWorldRep* singleWorld);
bool SetupHook();
void Cleanup();

} // namespace Hook
