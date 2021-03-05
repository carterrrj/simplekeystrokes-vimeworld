#include "includes.hpp"

#define color D3DCOLOR_RGBA
#define VK_WBUTTON 0x57
#define VK_ABUTTON 0x41
#define VK_SBUTTON 0x53
#define VK_DBUTTON 0x44

int APIENTRY DX(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prev_instance, _In_ LPWSTR p_cmd_line, _In_ int cmd_show) {
	try {

		directx::dx_overlay overlay("SunAwtFrame", "VimeWorld.ru", false);

		MSG m;
		ZeroMemory(&m, sizeof m);

		directx::dx_renderer renderer = overlay.create_renderer();
		do {
			if (PeekMessage(&m, overlay.get_overlay_wnd(), NULL, NULL, PM_REMOVE)) {
				TranslateMessage(&m);
				DispatchMessage(&m);
			}

			renderer.begin_rendering();

			// 
			renderer.draw_filled_rect(10, 450, 94, 26, color(0, 0, 0, 155));
			renderer.draw_filled_rect(10, 200 + 200 + 36, 94, 13, color(0, 0, 0, 155));

			if (GetAsyncKeyState(VK_ABUTTON)) {
				renderer.draw_filled_rect(10 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
				renderer.draw_filled_rect(10 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
			}
			else
			{
				renderer.draw_filled_rect(10, 200 + 200, 30, 35, color(0, 0, 0, 155));
			}
			if (GetAsyncKeyState(VK_SBUTTON)) {
				renderer.draw_filled_rect(10 + 32 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
				renderer.draw_filled_rect(10 + 32 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
			}
			else
			{
				renderer.draw_filled_rect(10 + 32, 200 + 200, 30, 35, color(0, 0, 0, 155));
			}
			if (GetAsyncKeyState(VK_DBUTTON)) {
				renderer.draw_filled_rect(10 + 32 + 32 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
				renderer.draw_filled_rect(10 + 32 + 32 + 3, 200 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
			}
			else
			{
				renderer.draw_filled_rect(10 + 32 + 32, 200 + 200, 30, 35, color(0, 0, 0, 155));
			}
			if (GetAsyncKeyState(VK_WBUTTON)) {
				renderer.draw_filled_rect(10 + 32 + 3, 200 - 37 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
				renderer.draw_filled_rect(10 + 32 + 3, 200 - 37 + 200 + 3, 30 - 7, 35 - 7, color(0, 0, 0, 155));
			}
			else
			{
				renderer.draw_filled_rect(10 + 32, 200 - 37 + 200, 30, 35, color(0, 0, 0, 155));
			}

			if (GetAsyncKeyState(VK_ABUTTON)) {
				renderer.draw_text("A", 16 + 3, 205 + 200 + 3, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana16);
			}
			else
			{
				renderer.draw_text("A", 16, 205 + 200, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana25);
			}
			if (GetAsyncKeyState(VK_SBUTTON)) {
				renderer.draw_text("S", 15 + 35 + 2, 205 + 200 + 3, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana16);
			}
			else
			{
				renderer.draw_text("S", 15 + 35, 205 + 200, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana25);
			}
			if (GetAsyncKeyState(VK_DBUTTON)) {
				renderer.draw_text("D", 15 + 35 + 32 + 1, 205 + 200 + 3, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana16);
			}
			else
			{
				renderer.draw_text("D", 15 + 35 + 32 - 2, 205 + 200, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana25);
			}
			if (GetAsyncKeyState(VK_WBUTTON)) {
				renderer.draw_text("W", 16 + 31 + 3, 205 - 35 + 200 + 1, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana16);
			}
			else
			{
				renderer.draw_text("W", 16 + 30, 205 - 35 + 200 - 3, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana25);
			}

			if (GetAsyncKeyState(VK_LSHIFT)) {
				renderer.draw_text("LSHIFT", 37, 436, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana12);
			}
			else
			{
				renderer.draw_text("LSHIFT", 37, 436, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana12);
			}

			if (GetAsyncKeyState(VK_SPACE)) {
				renderer.draw_text("____", 29, 442, D3DCOLOR_RGBA(255, 231, 51, 255), false, true, renderer.verdana25);
			}
			else
			{
				renderer.draw_text("____", 29, 442, D3DCOLOR_RGBA(255, 255, 255, 255), false, true, renderer.verdana25);
			}


			//
			renderer.end_rendering();

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		} while (m.message != WM_QUIT);

		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	catch (const std::exception& e) {

	}

	return true;
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	DX(0, 0, 0, 0);
	return 0;
}