package lime._internal.backend.flash;

import flash.ui.MultitouchInputMode;
import flash.ui.Multitouch;
import lime.app.Application;
import lime.media.AudioManager;
import lime.ui.Window;

@:access(lime.app.Application)
class FlashApplication
{
	private static var createFirstWindow:Bool;

	private var parent:Application;
	private var requestedWindow:Bool;

	private var initialized:Bool;

	public function new(parent:Application):Void
	{
		initialized = false;
		this.parent = parent;

		AudioManager.init();

		createFirstWindow = true;
		// Initial window is already created
		parent.createWindow({});
		createFirstWindow = false;
	}

	public function init():Void
	{
		if (!initialized) {
			Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;

			initialized = true;
		}
	}

	public function exec():Int
	{
		init();

		return 0;
	}

	public function batchUpdate(numEvents:Int):Int { return 0; }

	public function exit():Void {}
}
