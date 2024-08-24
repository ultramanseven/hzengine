#include "Hazel.h"

class Sandbox : public HzEngine::Application {
public :
	Sandbox() {

	}

	~Sandbox() {

	}
};

HzEngine::Application* HzEngine::CreateApplication() {
	return new Sandbox();
}