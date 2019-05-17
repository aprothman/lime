#ifndef LIME_SDL_WINDOW_H
#define LIME_SDL_WINDOW_H


#include <SDL.h>
#include <app/Application.h>
#include <graphics/ImageBuffer.h>
#include <ui/Cursor.h>
#include <ui/Window.h>


namespace lime {


	class SDLWindow : public Window {

		public:

			SDLWindow (Application* application);
			~SDLWindow ();

			virtual void Create(int width, int height, int flags, const char* title);

			virtual void Alert (const char* message, const char* title);
			virtual void Close ();
			virtual void ContextFlip ();
			virtual void* ContextLock (bool useCFFIValue);
			virtual void ContextMakeCurrent ();
			virtual void ContextUnlock ();
			virtual void Focus ();
			virtual void* GetContext ();
			virtual const char* GetContextType ();
			// virtual Cursor GetCursor ();
			virtual int GetDisplay ();
			virtual void GetDisplayMode (DisplayMode* displayMode);
			virtual int GetHeight ();
			virtual uint32_t GetID ();
			virtual bool GetMouseLock ();
			virtual double GetScale ();
			virtual bool GetTextInputEnabled ();
			virtual int GetWidth ();
			virtual int GetX ();
			virtual int GetY ();
			virtual void Move (int x, int y);
			virtual void ReadPixels (ImageBuffer *buffer, Rectangle *rect);
			virtual void Resize (int width, int height);
			virtual bool SetBorderless (bool borderless);
			virtual void SetCursor (Cursor cursor);
			virtual void SetDisplayMode (DisplayMode* displayMode);
			virtual bool SetFullscreen (bool fullscreen);
			virtual void SetIcon (ImageBuffer *imageBuffer);
			virtual bool SetMaximized (bool maximized);
			virtual bool SetMinimized (bool minimized);
			virtual void SetMouseLock (bool mouseLock);
			virtual bool SetResizable (bool resizable);
			virtual void SetTextInputEnabled (bool enabled);
			virtual const char* SetTitle (const char* title);
			virtual void WarpMouse (int x, int y);

			SDL_Renderer* sdlRenderer;
			SDL_Texture* sdlTexture;
			SDL_Window* sdlWindow;

		protected:

			SDL_GLContext context;
			int contextHeight;
			int contextWidth;

	};


}


#endif