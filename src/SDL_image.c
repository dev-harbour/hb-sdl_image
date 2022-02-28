/*
 * SDL library: SDL_image.c
 * version 2.0.18
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hbsdl_image.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* SDL_RWops */
static HB_GARBAGE_FUNC( hb_rwops_Destructor )
{
   SDL_RWops ** ppRWops = ( SDL_RWops ** ) Cargo;

   if( * ppRWops )
   {
      * ppRWops = NULL;
   }
}

static const HB_GC_FUNCS s_gcRWopsFuncs =
{
   hb_rwops_Destructor,
   hb_gcDummyMark
};

SDL_RWops * hb_rwops_Param( int iParam )
{
   SDL_RWops ** ppRWops = ( SDL_RWops ** ) hb_parptrGC( &s_gcRWopsFuncs, iParam );

   if( ppRWops && * ppRWops )
   {
      return * ppRWops;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

// extern DECLSPEC int SDLCALL IMG_Init(int flags);
HB_FUNC( IMG_INIT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( IMG_Init( hb_parni( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC void SDLCALL IMG_Quit(void);
HB_FUNC( IMG_QUIT )
{
   IMG_Quit();
}

// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadTyped_RW(SDL_RWops *src, int freesrc, const char *type);
HB_FUNC( IMG_LOADTYPED_RW )
{
   SDL_RWops * src = hb_rwops_Param( 1 );

   if( src && hb_param( 2, HB_IT_INTEGER ) != NULL &&
              hb_param( 3, HB_IT_STRING ) != NULL )
   {
      hb_surface_Return( IMG_LoadTyped_RW( src, hb_parni( 2 ), hb_parc( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC SDL_Surface * SDLCALL IMG_Load(const char *file);
HB_FUNC( IMG_LOAD )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_surface_Return( IMG_Load( hb_parc( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern DECLSPEC SDL_Surface * SDLCALL IMG_Load_RW(SDL_RWops *src, int freesrc);

// #if SDL_VERSION_ATLEAST(2,0,0)
// extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture(SDL_Renderer *renderer, const char *file);
// extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTexture_RW(SDL_Renderer *renderer, SDL_RWops *src, int freesrc);
// extern DECLSPEC SDL_Texture * SDLCALL IMG_LoadTextureTyped_RW(SDL_Renderer *renderer, SDL_RWops *src, int freesrc, const char *type);
// #endif /* SDL 2.0 */

// extern DECLSPEC int SDLCALL IMG_isICO(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isCUR(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isBMP(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isGIF(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isJPG(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isLBM(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isPCX(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isPNG(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isPNM(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isSVG(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isTIF(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isXCF(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isXPM(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isXV(SDL_RWops *src);
// extern DECLSPEC int SDLCALL IMG_isWEBP(SDL_RWops *src);

// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadICO_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadCUR_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadBMP_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadGIF_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadJPG_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadLBM_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadPCX_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadPNG_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadPNM_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadSVG_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadTGA_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadTIF_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadXCF_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadXPM_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadXV_RW(SDL_RWops *src);
// extern DECLSPEC SDL_Surface * SDLCALL IMG_LoadWEBP_RW(SDL_RWops *src);

// extern DECLSPEC SDL_Surface * SDLCALL IMG_ReadXPMFromArray(char **xpm);

// extern DECLSPEC int SDLCALL IMG_SavePNG(SDL_Surface *surface, const char *file);
// extern DECLSPEC int SDLCALL IMG_SavePNG_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst);
// extern DECLSPEC int SDLCALL IMG_SaveJPG(SDL_Surface *surface, const char *file, int quality);
// extern DECLSPEC int SDLCALL IMG_SaveJPG_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst, int quality);
