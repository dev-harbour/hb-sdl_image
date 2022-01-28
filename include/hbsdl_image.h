#ifndef HB_SDL_IMAGE_H_
#define HB_SDL_IMAGE_H_

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"
#include "hbstack.h"

#include <SDL2/SDL_image.h>

HB_EXTERN_BEGIN

extern HB_EXPORT SDL_RWops * hb_rwops_Param( int iParam );

extern HB_EXPORT void        hb_surface_Return( SDL_Surface * pSurface );

HB_EXTERN_END

#define UNUSED( x ) ( ( void ) ( x ) )
#define HB_ERR_ARGS() ( hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS ) )

#endif /* HB_SDL_IMAGE_H_ */
