#ifndef __engine_wrap__
#define __engine_wrap__

#include <luajit/lua.h>
#include <luajit/lauxlib.h>
#include <luajit/lualib.h>

#include "include.h"
#include "c_engine.h"
#include "m_math.h"

typedef enum ldata_type
{
  lua_type_invalid = 0,
  lua_type_engine,
  lua_type_img,
  lua_type_tex,
  lua_type_mesh,
  lua_type_font,
  lua_type_mat4,
  lua_type_prng,
} ldata_type_t;

#define core_name "core"

#define engine_mt_name "__ENGINE_MT__"
#define img_mt_name "__IMG_MT__"
#define tex_mt_name "__TEX_MT__"
#define mesh_mt_name "__MESH_MT__"
#define mat4_mt_name "__MAT4_MT__"
#define font_mt_name "__FONT_MT__"
#define prng_mt_name "__PRNG_MT__"

#define shader_enum "__SHADER_E__"
#define draw_mode_enum "__DRAW_MODE_E__"
#define image_fmt_enum "__IMG_FMT_E__"
#define tex_filter_enum "__TEX_FILTER_E__"
#define tex_wrap_enum "__TEX_WRAP_E__"
#define fullscreen_enum "__FULLSCREEN_E__"
#define key_enum "__KEY_E__"

typedef struct lmat4
{
  mat4_t m;
} lmat4_t;

typedef struct ldata
{
  ldata_type_t type;
  void* ptr;
} ldata_t;

void create_ldata(
  lua_State* L, void* data, const char* mt, ldata_type_t type);
void* read_ldata(lua_State* L, int index, ldata_type_t expected);
engine_t* get_engine(lua_State* L);
void reg_funcs(lua_State* L, const luaL_Reg* funcs);
bool protected_do_file(lua_State* L, vfs_t* vfs, const char* file);
void raw_insert(lua_State* L, int t, int k, int pos);
const char* get_str_from_enum(lua_State* L, int e, const char* enum_table);
int get_enum_from_str(lua_State* L, const char* e, const char* enum_table);

void wrap(lua_State* L, engine_t* engine);
void wrap_engine(lua_State* L);
void wrap_enums(lua_State* L);
void wrap_tex(lua_State* L);
void wrap_log(lua_State* L);
void wrap_mesh(lua_State* L);
void wrap_mat4(lua_State* L);
void wrap_font(lua_State* L);
void wrap_prng(lua_State* L);

#endif
