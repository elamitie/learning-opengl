#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>

namespace lame {

	enum Key
	{
		W = SDL_SCANCODE_W,
		A = SDL_SCANCODE_A,
		S = SDL_SCANCODE_S,
		D = SDL_SCANCODE_D,
		RIGHT_ARROW = SDL_SCANCODE_RIGHT,
		LEFT_ARROW = SDL_SCANCODE_LEFT,
		UP_ARROW = SDL_SCANCODE_UP,
		DOWN_ARROW = SDL_SCANCODE_DOWN,
		SPACE = SDL_SCANCODE_SPACE,
		ENTER = SDL_SCANCODE_RETURN
	};

	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void HandleKeyDown(const SDL_Event& ev);
		void HandleKeyUp(const SDL_Event& ev);

		//std::vector<Key> getPressedKeys();

		static bool Pressed(Key key);
		static bool Clicked(Key key);

	private:
		static bool             mKeys[65536];
		static std::vector<Key> mPressedKeys;
	};

}