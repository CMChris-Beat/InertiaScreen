#define BLINKER_WIFI

#include <Blinker.h>
#include <Blinker/BlinkerDebug.h>

String input;

char auth[] = "f9f034ea42d3";
char ssid[] = "HUAWEI-0J1AF5";
char pswd[] = "aA010516";

// 新建组件对象
BlinkerButton Button1("btn-slow");
BlinkerButton Button2("btn-medium");
BlinkerButton Button3("btn-quick");

void button1_callback(const String& state) {
    BLINKER_LOG("get button state: ", state);
    input = "1";
}

void button2_callback(const String& state) {
    BLINKER_LOG("get button state: ", state);
    input = "2";
}

void button3_callback(const String& state) {
    BLINKER_LOG("get button state: ", state);
    input = "3";
}