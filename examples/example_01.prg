/*
 *
 */

#include "hbsdl_image.ch"

PROCEDURE Main()

   LOCAL pWindow
   LOCAL pRenderer
   LOCAL aSurface
   LOCAL pTexture
   LOCAL lQuit := .F.
   LOCAL nEvent

   IF( SDL_Init( SDL_INIT_VIDEO ) != 0 )
      OutStd( e"Unable to initialize SDL: \n", SDL_GetError() )
      RETURN
   ENDIF

   pWindow := SDL_CreateWindow( "Example 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0 )
   IF( pWindow == NIL )
      OutStd( e"Could not create Window: \n", SDL_GetError() )
      RETURN
   ENDIF

   pRenderer := SDL_CreateRenderer( pWindow, - 1, SDL_RENDERER_ACCELERATED )
   IF( pRenderer == NIL )
      OutStd( e"Could not create Renderer: \n", SDL_GetError() )
      RETURN
   ENDIF

   IF( IMG_Init( IMG_INIT_PNG ) == -1 )
      OutStd( e"Could not create SDL2_image: \n", SDL_GetError() )
      RETURN
   ENDIF

   aSurface := IMG_Load( "assets/logo.png" )
   IF( aSurface == NIL )
      OutStd( e"Could not create Surface: \n", SDL_GetError() )
      RETURN
   ENDIF

   pTexture := SDL_CreateTextureFromSurface( pRenderer, aSurface )
   IF( pTexture == NIL )
      OutStd( e"Could not create Texture: \n", SDL_GetError() )
      RETURN
   ENDIF

   SDL_FreeSurface( aSurface )
   SDL_SetRenderDrawColor( pRenderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE )
   SDL_RenderClear( pRenderer )
   SDL_RenderCopy( pRenderer, pTexture, { 0, 0, 450, 450 }, { 0, 0, 450, 450 } )
   SDL_RenderPresent( pRenderer )

   DO WHILE( ! lQuit )

      SDL_WaitEvent( @nEvent )

      SWITCH( nEvent )

      CASE SDL_QUIT
         lQuit := .T.
         EXIT

      ENDSWITCH

   ENDDO

   SDL_Quit()
   IMG_Quit()

   RETURN
