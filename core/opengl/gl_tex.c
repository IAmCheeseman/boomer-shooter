#include "gl_tex.h"

#include <glad/glad.h>

#include "c_mem.h"
#include "g_tex.h"
#include "gl_type_conv.h"

static void create_tex(tex_t* tex, img_fmt_t fmt, void* data, vec2i_t size)
{
  uint32_t gl_fmt = img_fmt_to_gl(fmt);

  uint32_t handle;

  glGenTextures(1, &handle);
  glBindTexture(GL_TEXTURE_2D, handle);
  glTexImage2D(
    GL_TEXTURE_2D,
    0, gl_fmt, size.x, size.y,
    0, gl_fmt, GL_UNSIGNED_BYTE, data);

  log_debug("loaded texture %d", handle);

  uint32_t* handle_ptr = (uint32_t*)mem_alloc(sizeof(uint32_t));
  *handle_ptr = handle;

  tex->handle = handle_ptr;

  gl_tex_set_filter(tex, tex_filter_nearest, tex_filter_nearest);
  gl_tex_set_wrap(tex, tex_wrap_rep, tex_wrap_rep);
}

tex_t gl_tex_load_from_img(const img_t* img)
{
  tex_t tex;

  tex.size = img->size;
  tex.fmt = img->fmt;

  create_tex(&tex, img->fmt, img->data, img->size);

  return tex;
}

tex_t gl_tex_1x1_color(color_t color)
{
  tex_t tex;

  tex.size = (vec2i_t){1, 1};
  tex.fmt = img_fmt_rgba8;

  uint8_t data[4];
  color_to_bytes(color, &data[0], &data[1], &data[2], &data[3]);

  create_tex(&tex, tex.fmt, data, tex.size);

  return tex;
}

void gl_tex_destroy(tex_t* tex)
{
  uint32_t handle = *((uint32_t*)tex->handle);
  glDeleteTextures(1, &handle);
  log_debug("destroyed texture %d", handle);
  mem_destroy(tex->handle);
}

void gl_tex_bind(const tex_t* tex, uint8_t slot)
{
  uint32_t handle = 0;
  if (tex != NULL) handle = *((uint32_t*)tex->handle);
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, handle);
}

void gl_tex_gen_mipmap(tex_t* tex)
{
  if (
    tex->min_filter == tex_filter_nearest ||
    tex->min_filter == tex_filter_linear
  ) {
    log_warning(
      "min texture filter for texture %d is not a mipmap filter; "
      "generated mipmaps will not make a difference",
      *((uint32_t*)tex->handle));
  }

  gl_tex_bind(tex, 0);
  glGenerateMipmap(GL_TEXTURE_2D);
}

void gl_tex_set_filter(
  tex_t* tex,
  tex_filter_t min,
  tex_filter_t mag)
{
  tex->min_filter = min;
  tex->mag_filter = mag;

  if (
    mag != tex_filter_nearest &&
    mag != tex_filter_linear
  ) {
    log_warning(
      "mag texture filter for texture %d is a mipmap filter and will not make "
      "a difference",
      *((uint32_t*)tex->handle));
  }
  
  gl_tex_bind(tex, 0);
  glTexParameteri(
    GL_TEXTURE_2D,
    GL_TEXTURE_MIN_FILTER,
    tex_filter_to_gl(min)
  );
  glTexParameteri(
    GL_TEXTURE_2D,
    GL_TEXTURE_MAG_FILTER,
    tex_filter_to_gl(mag)
  );
}

void gl_tex_set_wrap(
  tex_t* tex,
  tex_wrap_t x_wrap,
  tex_wrap_t y_wrap)
{
  tex->x_wrap = x_wrap;
  tex->y_wrap = y_wrap;
  
  gl_tex_bind(tex, 0);
  glTexParameteri(
    GL_TEXTURE_2D,
    GL_TEXTURE_WRAP_S,
    tex_wrap_to_gl(x_wrap)
  );
  glTexParameteri(
    GL_TEXTURE_2D,
    GL_TEXTURE_WRAP_T,
    tex_wrap_to_gl(y_wrap)
  );
}
