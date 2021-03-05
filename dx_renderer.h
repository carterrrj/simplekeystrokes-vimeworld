#pragma once
#include <string>
#include <thread>

#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

namespace directx {
	class dx_renderer {
	private: 
		struct D3DTLVERTEX {
			float x, y, z, rhw;
			unsigned long color;
		};

	public:
		dx_renderer( ) { }
		dx_renderer( IDirect3DDevice9* device );
		~dx_renderer( );

		void begin_rendering( );
		void end_rendering( );

		int get_fps( );

		void draw_line( int x0, int y0, int x1, int y1, unsigned long color );
		void draw_rect( int x, int y, int w, int h, unsigned long color );
		void draw_filled_rect( int x, int y, int w, int h, unsigned long color );
		void draw_outlined_rect( int x, int y, int w, int h, unsigned long color );
		void draw_box(int x, int y, int w, int h, int lw, unsigned long color );
		void draw_text( std::string text, int x, int y, unsigned long color, bool center, bool outline, ID3DXFont* font);

		RECT get_text_dimensions( std::string text );

		ID3DXFont* verdana12 = nullptr;
		ID3DXFont* verdana16 = nullptr;
		ID3DXFont* verdana25 = nullptr;

	private:
		int m_fps = 0;
		IDirect3DDevice9* m_device = nullptr;
		ID3DXLine* m_line = nullptr;
	};
}