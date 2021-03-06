#ifndef Window_h
#define Window_h

class Window
{
	public:
		Window();

		bool init();

		void handleEvent (SDL_Event& e);

		void focus();

		void render();

		void free();

		double getWidth();
		double getHeight();

		bool hasMouseFocus();
		bool hasKeyboardFocus();
		bool isMinimized();
		bool isShown();

		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		int windowID;

		int width;
		int height;

		bool mouseFocus;
		bool keyboardFocus;
		bool fullScreen;
		bool minimized;
		bool shown;

};

#endif
