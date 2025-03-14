#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ģ��������뺯��
void simulateKeystrokes(const string& text) {
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));

    for (char c : text) {
        // �����¼�
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = 0;
        inputs[0].ki.wScan = c;
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        // �ͷ��¼�
        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0;
        inputs[1].ki.wScan = c;
        inputs[1].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        SendInput(2, inputs, sizeof(INPUT));
        Sleep(35); // ���������ٶȣ����룩
    }
}

int main() {
    string inputText;
    
    cout << "��ճ���������ı����ݣ������߸������ݺ��س�������:\n";
    getline(cin, inputText);

    cout << "�������� " << inputText.length() << " ���ַ�\n"
         << "����5���ڽ���궨λ��Ŀ��λ��..." << endl;
    
    // ���û�5��ʱ�䶨λ���
    for (int i = 5; i > 0; --i) {
        cout << "����ʱ: " << i << " ��" << endl;
        Sleep(1000);
    }

    cout << "��ʼ����..." << endl;
    simulateKeystrokes(inputText);

    cout << "\n������ɣ�" << endl;
    return 0;
}