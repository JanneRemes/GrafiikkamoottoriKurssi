/*
 *https://www.libsdl.org/release/SDL-1.2.15/docs/html/guidevideoopengl.html
 *
 * SDL OpenGL Tutorial.
 * (c) Michael Vance, 2000
 * briareos@lokigames.com
 *
 * Distributed under terms of the LGPL. 
 */
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include <stdio.h>
#include <stdlib.h>

static void quit_tutorial( int code )
{
    /*
     * Quit SDL so we can release the fullscreen
     * mode and restore the previous video settings,
     * etc.
     */
    SDL_Quit( );

    /* Exit program. */
    exit( code );
}

static void handle_key_down( SDL_keysym* keysym )
{

    /* 
     * We're only interested if 'Esc' has
     * been presssed.
     */
    switch( keysym->sym ) {
    case SDLK_ESCAPE:
        quit_tutorial( 0 );
        break;
    default:
        break;
    }

}

static void process_events( void )
{
    /* Our SDL event placeholder. */
    SDL_Event event;

    /* Grab all the events off the queue. */
    while( SDL_PollEvent( &event ) ) {

        switch( event.type ) {
        case SDL_KEYDOWN:
            /* Handle key presses. */
            handle_key_down( &event.key.keysym );
            break;
        case SDL_QUIT:
            /* Handle quit requests (like Ctrl-c). */
            quit_tutorial( 0 );
            break;
        }

    }

}

static void draw_screen( void )
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-0.5,-0.5,0.0);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(0.5,0.0,0.0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0,0.5,0.0);
  glEnd();

  SDL_GL_SwapBuffers( );
}

static void setup_opengl( int width, int height )
{
    /* Set the clear color. */
    glClearColor( 0, 0, 0, 0 );

    /* Setup our viewport. */
    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
}


int main( int argc, char* argv[] )
{
    const SDL_VideoInfo* info = NULL;
    int width = 0;
    int height = 0;
    int bpp = 0;
    int flags = 0;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        fprintf( stderr,
	     "Video initialization failed: %s\n",
             SDL_GetError( ) );
        quit_tutorial( 1 );
    }

    info = SDL_GetVideoInfo( );

    width = 640;
    height = 480;
    bpp = info->vfmt->BitsPerPixel;

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 ); //at least 5bpp
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    flags = SDL_OPENGL;

    if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 ) {
        fprintf( stderr, "Video mode set failed: %s\n",
             SDL_GetError( ) );
        quit_tutorial( 1 );
    }

    setup_opengl( width, height );

    while( 1 ) {
        process_events( );
        draw_screen( );
    }

    /* Never reached. */
    return 0;
}
