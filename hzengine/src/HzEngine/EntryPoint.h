#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern HzEngine::Application* HzEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = HzEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif