// PabstMirror
// async send msg to a discord webhook
// Requires CPR (curl wrapper) - https://github.com/whoshuu/cpr (and put libcurl.dll in base arma folder)

#include <iostream>
#include <String>
#include <future>
#include "cpr/cpr.h"

#define VERSION_STR "v1.0.0"


extern "C" {
    __declspec(dllexport) void __stdcall RVExtension(char* output, int outputSize, const char* function);
    __declspec(dllexport) void __stdcall RVExtensionVersion(char* output, int outputSize);
    __declspec (dllexport) void __stdcall RVExtensionRegisterCallback(int(*callbackProc)(char const* name, char const* function, char const* data));
}

int(*callbackPtr)(char const* name, char const* function, char const* data) = nullptr;
std::future<void> fWorker;

void __stdcall RVExtensionRegisterCallback(int(*callbackProc)(char const* name, char const* function, char const* data))
{
    callbackPtr = callbackProc;
}


void postThread(const char * msg) {
    cpr::Response r = cpr::Post(
        cpr::Url{ "https://discordapp.com/api/webhooks/x/y" }, // don't commit this lol
        cpr::Payload{ {"content", msg}, {"username", "DLL BOT"} }
    );
    if (!callbackPtr) return;

    std::stringstream outputStr;
    outputStr << "Finished with code [" << r.status_code << "]"; // 200/204 is good, 400 is bad
    callbackPtr("POTATO_webhook", "Webhook", outputStr.str().c_str());
}

void __stdcall RVExtensionVersion(char* output, int outputSize) {
    strncpy(output, VERSION_STR, outputSize);
}
void __stdcall RVExtension(char* output, int outputSize, const char* function) {
    if (!strcmp(function, "version")) {
        RVExtensionVersion(output, outputSize);
        return;
    }

    if (fWorker.valid()) { fWorker.wait_for(std::chrono::seconds(1)); } // if worker is busy wait for finish
    fWorker = std::async(std::launch::async, &postThread, function); // start async so we don't block arma (~200ms to finish)

    strncpy(output, "Dispatched Webhook", outputSize);
}
