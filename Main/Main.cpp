#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class List {
protected:
    char ch;
    List* next;
public:
    void set(char c, List* n_c) {
        ch = c;
        next = n_c;
    }
    char info_ch() {
        return ch;
    }
    List* info_next() {
        return next;
    }
};
class Stack {
private:
    List* pres;
public:
    Stack() {
        pres = NULL;
    }
    ~Stack() {
        while (pres)
            pop();
    }
    bool st_empty()//Проверка на пустоту
    {
        return pres == NULL;
    }
    void push(char ch) //Добавление нового элемента
    {
        List* next_ch = new List;
        next_ch->set(ch, pres);
        pres = next_ch;
    }
    char peek() //Считывание головного элемента
    {
        if (!st_empty())
            return pres->info_ch();
        return '\0';
    }
    void pop() //Удаление головного элемента
    {
        if (!st_empty()) {
            List* past = pres->info_next();
            delete pres;
            pres = past;
        }
    }
    ostream& dump(ostream& os) {
        List* tmp = pres;
        while (tmp) {
            os << tmp->info_ch();
            tmp = tmp->info_next();
        }
        return os;
    }
};

bool zadacha(const string& str) {

    Stack st;
    char ch;
    char bracket;
    for (size_t i = 0; i < str.size(); ++i) {
        ch = str[i];
        switch (ch) {
        case '(':
        case '{':
        case '[':
            st.push(ch);
            st.dump(cout) << endl;
            break;

        case ')':
        case '}':
        case ']':
            if (st.st_empty())
                return false;
            bracket = st.peek();
            switch (bracket) {
            case '(': bracket = ')'; break;
            case '{': bracket = '}'; break;
            case '[': bracket = ']'; break;
            }
            if (bracket != ch)
                return false;
            st.pop();
            st.dump(cout) << endl;
            break;
        default:break;
        }
    }
    return st.st_empty() ? true : false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введите строку" << endl;
    getline(cin, str);
    cout << (zadacha(str) ? "Скобки в этой строке расставлены правильно" :
        "Скобки в этой строке расставлены неправильно") << endl;
    //system("PAUSE");
}