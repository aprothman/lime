#ifndef LIME_SDL_APPLICATION_H
#define LIME_SDL_APPLICATION_H


#include <SDL.h>
#include <app/Application.h>
#include <app/ApplicationEvent.h>
#include <graphics/RenderEvent.h>
#include <system/ClipboardEvent.h>
#include <system/SensorEvent.h>
#include <ui/DropEvent.h>
#include <ui/GamepadEvent.h>
#include <ui/JoystickEvent.h>
#include <ui/KeyEvent.h>
#include <ui/MouseEvent.h>
#include <ui/TextEvent.h>
#include <ui/TouchEvent.h>
#include <ui/WindowEvent.h>
#include "SDLWindow.h"


namespace lime {


	class SDLApplication : public Application {

		public:

			SDLApplication ();
			~SDLApplication ();

			virtual int Exec ();
			virtual void Init ();
			virtual int Quit ();
			virtual void SetFrameRate (double frameRate);
			virtual bool Update ();
			virtual int BatchUpdate(int numEvents);

			void RegisterWindow (SDLWindow *window);

		private:

			void HandleEvent (SDL_Event* event);
			void ProcessClipboardEvent (SDL_Event* event);
			void ProcessDropEvent (SDL_Event* event);
			void ProcessGamepadEvent (SDL_Event* event);
			void ProcessJoystickEvent (SDL_Event* event);
			void ProcessKeyEvent (SDL_Event* event);
			void ProcessMouseEvent (SDL_Event* event);
			void ProcessSensorEvent (SDL_Event* event);
			void ProcessTextEvent (SDL_Event* event);
			void ProcessTouchEvent (SDL_Event* event);
			void ProcessWindowEvent (SDL_Event* event);
			int WaitEvent (SDL_Event* event);
			int GetPendingEvents (SDL_Event* event, int NumEvents);

			static void UpdateFrame ();
			static void UpdateFrame (void*);
			static int WatchEvent (void* userData, SDL_Event* event);

			static SDLApplication* currentApplication;

			bool active;
			SDL_Event* eventQueue;
			int queueLength;
			int queueMaxLength;
			ApplicationEvent applicationEvent;
			ClipboardEvent clipboardEvent;
			Uint32 currentUpdate;
			double framePeriod;
			DropEvent dropEvent;
			GamepadEvent gamepadEvent;
			JoystickEvent joystickEvent;
			KeyEvent keyEvent;
			Uint32 lastUpdate;
			MouseEvent mouseEvent;
			Uint32 nextUpdate;
			RenderEvent renderEvent;
			SensorEvent sensorEvent;
			TextEvent textEvent;
			TouchEvent touchEvent;
			WindowEvent windowEvent;

	};


}


#endif