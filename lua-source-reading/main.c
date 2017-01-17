// LuaTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int luaAdd()
{
	int sum = 0;
	lua_State *L = NULL;
	int iErrCode = 0;
	int iRet = 0;

	L = luaL_newstate();  //�����߳�ջ��ȫ��ջ
	//luaopen_base(L);
	luaL_openlibs(L);     //��ӱ�׼��

	// 	luaL_requiref(L, "clca", luaopen_clca, 1);
	// 	lua_pop(L, 1);  /* remove lib */
	// 	luaL_requiref(L, "equation", luaopen_Equation, 1);
	// 	lua_pop(L, 1);  /* remove lib */

	iErrCode = luaL_loadfile(L, "123.lua");
	lua_pcall(L, 0, LUA_MULTRET, 0);


	lua_getglobal(L, "add");
	lua_pushnumber(L, 3);
	lua_pushnumber(L, 5);
	iRet = lua_pcall(L, 2, 1, 0);
	//string wsRet = (string)lua_tostring(L, -1);
	sum = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	printf("The sum is %d\n", sum);
	lua_close(L);
	return sum;
}

int main(int argc, char* argv[])
{
	int a = 0, b = 2;

	//	Test();
	luaAdd();
	//	LuaEngineTest();
	//	system("pause");
	return 0;
}

