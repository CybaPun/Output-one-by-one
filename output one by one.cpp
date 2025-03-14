#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// 模拟键盘输入函数
void simulateKeystrokes(const string& text) {
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));

    for (char c : text) {
        // 按下事件
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = 0;
        inputs[0].ki.wScan = c;
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        // 释放事件
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0;
        inputs[1].ki.wScan = c;
        inputs[1].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        SendInput(2, inputs, sizeof(INPUT));
        Sleep(35); // 控制输入速度（毫秒）
    }
}

int main() {
    string inputText;
    
    cout << "请粘贴或输入文本内容（按或者复制内容含回车结束）:\n";
    getline(cin, inputText);

    cout << "即将输入 " << inputText.length() << " 个字符\n"
         << "请在5秒内将光标定位到目标位置..." << endl;
    
    // 给用户5秒时间定位光标
    for (int i = 5; i > 0; --i) {
        cout << "倒计时: " << i << " 秒" << endl;
        Sleep(1000);
    }

    cout << "开始输入..." << endl;
    simulateKeystrokes(inputText);

    cout << "\n输入完成！" << endl;
    return 0;
}