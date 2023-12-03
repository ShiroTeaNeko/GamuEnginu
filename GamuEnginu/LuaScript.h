#pragma once
#include <lua.hpp>
#include <string>
#include <luabridge3/LuaBridge/LuaBridge.h>

namespace MyGameEngine
{
	class LuaScript
	{
	private:
	protected:
		lua_State *luaState;
		void ReportErrors(lua_State *luaState,int status);
	public:
		LuaScript();
		~LuaScript();
		void SetScript(std::string scriptName);
		void Update(float deltaTime);
	};
}

